#include<cstdio>

int n,m;
bool used[110];
int num[1000];
bool solve(int M, int N, int num[]) 
{
    for (int i = 0; i < N; i++) 
    {
        used[i] = false;
    }
    for (int k = 0, w = 0; k < N; k++) 
    {
        int idx = -1;
        for (int i = 0; i < N; i++) 
        {
            if (!used[i] && w - num[i] >= -M && (idx == -1 || num[idx] < num[i])) 
            {
                idx = i;
            }
        }
        if (idx == -1) 
        {
            return false;
        }
		//printf("< %d > ",num[idx]);
        used[idx] = true;
        if (w + num[idx] <= M) 
        {
            w += num[idx];
        } 
        else {
            w -= num[idx];
        }
        if (w < 0) 
        {
            w = -w;
        }
    }
    return true;
}

int main()
{
	while(1){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	printf("%d\n",solve(m,n,num));}
	return 0;
}

