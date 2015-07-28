#include <cstdio>
#include <cstring>
#include <cctype>
const int N = 1000000 + 10;
char c[300][5];
int num[300];
void init() {
	num['0'] = 0;
	num['1'] = 1;
	num['2'] = 2;
	num['3'] = 3;
	num['4'] = 4;
	num['5'] = 5;
	num['6'] = 6;
	num['7'] = 7;
	num['8'] = 8;
	num['9'] = 9;
	num['A'] = 10;
	num['B'] = 11;
	num['C'] = 12;
	num['D'] = 13;
	num['E'] = 14;
	num['F'] = 15;
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
	strcpy(c[0x52], "\'\"");
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

char s[N];
int brake = 0xF0, Lshift = 0x12, Rshift = 0x59, capsLock = 0x58;
bool press_shift_L = 0, press_shift_R = 0, press_capsLock = 0, release_capsLock = 1;

char get(int code, bool press_shift, bool press_capsLock)
{
	if(isalpha(c[code][0]))
	{
		bool status = (press_shift ^ press_capsLock);
		return c[code][status];
	}
	else {
		bool status = press_shift;
		return c[code][status];
	}
}

char str[N];
int len = 0;

int main()
{
	init();
	while(scanf("%s", s) == 1)
	{
		press_shift_L = press_shift_R = press_capsLock = 0; release_capsLock = 1;
		len = 0;
		for(int i = 0; s[i]; i += 2)
		{
			int code = num[s[i]] * 16 + num[s[i+1]];
			if(code == brake)
			{
				i += 2;
				code = num[s[i]] * 16 + num[s[i+1]];
				if(code == Lshift)
				{
					press_shift_L = 0;
				}
				else if(code == Rshift)
				{
					press_shift_R = 0;
				}
				else if(code == capsLock)
				{
					if(!release_capsLock)
					{
						release_capsLock = 1;
						//press_capsLock ^= 1;
					}
				}
			}
			else{
				if(code == Lshift)
				{
					press_shift_L = 1;
				}
				else if(code == Rshift)
				{
					press_shift_R = 1;
				}
				else if(code == capsLock)
				{
					if(release_capsLock)
					{
						press_capsLock ^= 1;
						release_capsLock = 0;
					}
				}
				else {
					char chr = get(code, press_shift_L || press_shift_R, press_capsLock);
					if(chr == '\b')
					{
						if(len > 0) len--;
					}
					else {
						str[len++] = chr;
					}
				}
			}
		}
		str[len] = 0;
		puts(str);
	}
	return 0;
}
