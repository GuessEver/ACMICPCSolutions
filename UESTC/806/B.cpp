#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

char str[100010];
bool hash[30];
int  cnt_num = 0 , cnt_color = 0 , len , head , tail;

void solve(){
    if (cnt_color & 1){
        printf("Yes\n");
        return;
    }   //cnt_color odd
    else{
        if (head == 0 || tail == len - 1){
            if (cnt_num & 1){
                printf("Yes\n");
                return ;
            }
        }   //  '?' at head or tail
        else{
            if (str[head - 1] != str[tail + 1] && (cnt_num & 1)){
                printf("Yes\n");
                return ;
            }
        }   //  '?' in the middle
    }   //cnt_color even
    printf("No\n");
}   //solve

int main(){
    memset(hash , 0 , sizeof(hash));
    scanf("%s" , str);
    len = strlen(str);
    head = len - 1;
    tail = 0;
    for (int i = 0;i < len;i ++){
        if (str[i] == '?'){
            cnt_num ++;
            if (i < head)   head = i;
            if (i > tail)   tail = i;
        }   //  '?'
        else{
            if (!hash[str[i] - 'a']){
                hash[str[i] - 'a'] = true;
                cnt_color ++;
            }   // !hash[str[i] - 'a']
        }   //  not '?'
    }   //for i _ len
    solve();
    return 0;
}   //main
