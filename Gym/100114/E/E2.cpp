#include <cstdio>
#define TYPE char
const char ten = 10;
const char zero = 0;
int num[20], cnt[20];
TYPE a[ten][ten];
int ans[ten];

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sum = zero;
    for(TYPE i = zero; i < ten; i++)
    {
        scanf("%d", &num[i]);
        sum += num[i];
    }
    if(sum == 31)
    for(TYPE x1 = zero; x1 < ten; ++x1)
        for(TYPE x5 = zero; x5 < ten && x5 * x1 < ten; ++x5)
            for(TYPE x8 = zero; x8 < ten && x8 * x1 < ten; ++x8)
                for(TYPE x7 = zero; x7 < ten && x7 * x1 < ten; ++x7)
                    for(TYPE x6 = zero; x6 < ten && x6 * x1 < ten; ++x6)
                        for(TYPE x2 = zero; x2 < ten; ++x2)
                            for(TYPE x3 = zero; x3 < ten; ++x3)
                                for(TYPE x4 = zero; x4 < ten; ++x4)
                                {
                                    a[1][1] = x8 * x4;
                                    a[1][2] = x8 * x3 + a[1][1] / ten;
                                    a[1][1] %= ten;
                                    a[1][3] = x8 * x2 + a[1][2] / ten;
                                    a[1][2] %= ten;
                                    a[1][4] = x8 * x1 + a[1][3] / ten;
                                    a[1][3] %= ten;
                                    if(a[1][4] >= ten) continue;
                                    a[2][1] = x7 * x4;
                                    a[2][2] = x7 * x3 + a[2][1] / ten;
                                    a[2][1] %= ten;
                                    a[2][3] = x7 * x2 + a[2][2] / ten;
                                    a[2][2] %= ten;
                                    a[2][4] = x7 * x1 + a[2][3] / ten;
                                    a[2][3] %= ten;
                                    if(a[2][4] >= ten) continue;
                                    a[3][1] = x6 * x4;
                                    a[3][2] = x6 * x3 + a[3][1] / ten;
                                    a[3][1] %= ten;
                                    a[3][3] = x6 * x2 + a[3][2] / ten;
                                    a[3][2] %= ten;
                                    a[3][4] = x6 * x1 + a[3][3] / ten;
                                    a[3][3] %= ten;
                                    if(a[3][4] >= ten) continue;
                                    a[4][1] = x5 * x4;
                                    a[4][2] = x5 * x3 + a[4][1] / ten;
                                    a[4][1] %= ten;
                                    a[4][3] = x5 * x2 + a[4][2] / ten;
                                    a[4][2] %= ten;
                                    a[4][4] = x5 * x1 + a[4][3] / ten;
                                    a[4][3] %= ten;
                                    if(a[4][4] >= ten) continue;
                                    ans[1] = a[1][1];
                                    ans[2] = a[1][2] + a[2][1];
                                    ans[3] = a[1][3] + a[2][2] + a[3][1] + ans[2] / ten;
                                    ans[2] %= ten;
                                    ans[4] = a[1][4] + a[2][3] + a[3][2] + a[4][1] + ans[3] / ten;
                                    ans[3] %= ten;
                                    ans[5] = a[2][4] + a[3][3] + a[4][2] + ans[4] / ten;
                                    ans[4] %= ten;
                                    ans[6] = a[3][4] + a[4][3] + ans[5] / ten;
                                    ans[5] %= ten;
                                    ans[7] = a[4][4] + ans[6] / ten;
                                    ans[6] %= ten;
                                    if(ans[7] >= ten) continue;
                                    for(TYPE i = zero; i < ten; ++i) cnt[i] = zero;
                                    for(TYPE i = 1; i <= 7; ++i) ++cnt[ans[i]];
                                    for(TYPE i = 1; i <= 4; ++i)
                                        for(TYPE j = 1; j <= 4; ++j)
                                            ++cnt[a[i][j]];
                                    ++cnt[x1]; ++cnt[x2]; ++cnt[x3]; ++cnt[x4];
                                    ++cnt[x5]; ++cnt[x6]; ++cnt[x7]; ++cnt[x8];
                                    bool flag = zero;
                                    for(TYPE i = zero; i < ten; ++i)
                                        if(cnt[i] != num[i]) {flag = 1; break;}
                                    if(flag) continue;
                                    printf("%d\n", x1 * 1000 + x2 * 100 + x3 * 10 + x4);
                                    printf("%d\n", x5 * 1000 + x6 * 100 + x7 * 10 + x8);
                                    return zero;
                                }
    puts("-1\n-1");
    return zero;
}
