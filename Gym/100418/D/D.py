n = int(input())-1
ans = (n*(n+1)//2+n*(n+1)*(n*2+1)//6+n**2*(n+1)**2//2)%(10**9+7)
print(ans)
