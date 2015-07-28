#include <cstdio>
#include <cstring>

const int MAXN = 4000000;

char c[300][5];

char buffer[MAXN+5];

inline int max(int a, int b) {
	return a > b ? a : b;
}

inline bool isalpha(const char c) {
	return (c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z');
}

void init() {
	strcpy(c[0x0e], "`~");
	strcpy(c[0x16], "1!");
	strcpy(c[0x1e], "2@");
	strcpy(c[0x26], "3#");
	strcpy(c[0x23], "4$");
	strcpy(c[0x2e], "5%");
	strcpy(c[0x36], "6^");
	strcpy(c[0x3d], "7&");
	strcpy(c[0x3e], "8*");
	strcpy(c[0x46], "9(");
	strcpy(c[0x22], "0)");
	strcpy(c[0x4e], "-_");
	strcpy(c[0x55], "=+");
	strcpy(c[0x66], "\b\b");
	strcpy(c[0x0d], "\t\t");
	strcpy(c[0x15], "qQ");
	strcpy(c[0x1d], "wW");
	strcpy(c[0x24], "eE");
	strcpy(c[0x2c], "rR");
	strcpy(c[0x2d], "tT");
	strcpy(c[0x35], "yY");
	strcpy(c[0x3c], "uU");
	strcpy(c[0x43], "iI");
	strcpy(c[0x44], "oO");
	strcpy(c[0x4d], "pP");
	strcpy(c[0x54], "[{");
	strcpy(c[0x5b], "]}");
	strcpy(c[0x5d], "\\|");
	//c[0x58], "cabslock"
	strcpy(c[0x1c], "aA");
	strcpy(c[0x1b], "sS");
	strcpy(c[0x25], "dD");
	strcpy(c[0x2b], "fF");
	strcpy(c[0x33], "gG");
	strcpy(c[0x34], "hH");
	strcpy(c[0x3b], "jJ");
	strcpy(c[0x42], "kK");
	strcpy(c[0x4b], "lL");
	strcpy(c[0x4c], ";:");
	strcpy(c[0x52], "'\"");
	strcpy(c[0x5a], "\n\n");
	//c[0x12], "lshift");
	strcpy(c[0x1a], "zZ");
	strcpy(c[0x45], "xX");
	strcpy(c[0x29], "cC");
	strcpy(c[0x2a], "vV");
	strcpy(c[0x32], "bB");
	strcpy(c[0x31], "nN");
	strcpy(c[0x3a], "mM");
	strcpy(c[0x41], ",<");
	strcpy(c[0x49], ".>");
	strcpy(c[0x4a], "/?");
	//c[0x59], "rshift");
	strcpy(c[0x21], "  ");
}


const int cab = 0x58, lshift = 0x12, rshift = 0x59, over = 0xf0;

inline char getShift(int signal, int shift, bool capslock) {
	if ((shift && !capslock) || (!shift && capslock)) {
		if (shift) {
			return c[signal][1];
		} else {
			if (isalpha(c[signal][0])) {
				return c[signal][1];
			} else {
				return c[signal][0];
			}
		}
	} else {
		if (!shift) {
			return c[signal][0];
		} else {
			if (isalpha(c[signal][0])) {
				return c[signal][0];
			} else {
				return c[signal][1];
			}
		}
	}
}

char ans[MAXN+5];
int ans_cnt;

inline bool scan(char *&s, int &signal) {
	if ((*s) == '\0') {
		return false;
	}
	signal = (isalpha(s[0]) ? (s[0]-'A'+10) : (s[0]-'0'))*16+(isalpha(s[1]) ? (s[1]-'A'+10) : (s[1]-'0'));
	s += 2;
	return true;
}

int main() {
	init();
	char chr;
	int signal, shift;
	bool capslock;
	char *s;
	while (gets(buffer) != NULL) {
		capslock = false;
		shift = 0;
		s = buffer;
		ans_cnt = 0;
		while (scan(s, signal)) {
			//printf("#%d\n", s-buffer);
			//printf("#%X\n", signal);
			if (signal == cab) {
				capslock = !capslock;
			} else if (signal == lshift) {
				shift ++;
			} else if (signal == rshift) {
				shift ++;
			} else if (signal == over) {
				scan(s, signal);
				//printf("#%d\n", s-buffer);
				//printf("#%X\n", signal);
				if (signal == cab) {
					//capslock = false;
				} else if (signal == lshift) {
					shift --;
				} else if (signal == rshift) {
					shift --;
				} else {
				}
			} else {
				chr = getShift(signal, shift, capslock);
				if (chr == '\b') {
					ans_cnt = max(0, ans_cnt-1);
				} else {
					ans[ans_cnt++] = chr;
				}
			}
		}
		ans[ans_cnt] = '\0';
		/*for (int i = 0; i < ans_cnt; i++) {
		  if (ans[i+1] == '\b' || ans[i] == '\b') {
		  continue;
		  } else {
		  putchar(ans[i]);
		  }
		  }*/
		puts(ans);
		//fflush(stdout);
	}
	return 0;
}
