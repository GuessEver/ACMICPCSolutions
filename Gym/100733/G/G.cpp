#include <cstdio>
#include <cstring>
#define MAXN 200

using namespace std;

char s[MAXN+5], c[MAXN*2];
int main() {
   for (char i = 'a'; i <= 'z'; i++) {
       c[i] = 'A'+i-'a';
   }
   for (char i = 'A'; i <= 'Z'; i++) {
       c[i] = 'a'+i-'A';
   }
   c['+'] = '*';
   c['*'] = '+';
   c['('] = '(';
   c[')'] = ')';
   scanf("%s", s); 
   bool change = false;
   int len = strlen(s);
   for (int i = 0; i < len; i++) {
       if (s[i] == '[') {
           change = !change;
           s[i] = '(';
       } else if (s[i] == ']') {
           change = !change;
           s[i] = ')';
       } else if (change) {
           s[i] = c[s[i]];
       }
   }
   puts(s);
}
