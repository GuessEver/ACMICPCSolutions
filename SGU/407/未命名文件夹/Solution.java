import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public static void main(String[] args) {
        int n, m;
        Scanner cin = new Scanner (System.in);
        n = cin.nextInt();
        m = cin.nextInt();
        BigInteger f[][] = new BigInteger[1010][5010];
		for(int i = 0; i <= n+1; i++)
			for(int j = 0; j <= m+1; j++)
				f[i][j] = BigInteger.ZERO;
        for(int i = 1; i <= n; i++)
        	f[i][1] = BigInteger.ONE;
		for(int j=2;j<=m;j++)
		{
			for(int i=1;i<=n;i++)
		        f[0][j] = f[0][j].add(f[i][j-1]);
			f[1][j] = f[1][j].add(f[n][j-1]).add(f[2][j-1]).add(f[0][j-1]);
			for(int i=2;i<n;i++)
			{
				f[i][j] = f[i][j].add(f[i-1][j-1]).add(f[i+1][j-1]).add(f[0][j-1]);
			}
			f[n][j] = f[n][j].add(f[n-1][j-1]).add(f[1][j-1]).add(f[0][j-1]);
		}
		if(m == 0) System.out.println(1);
		else System.out.println(f[0][m]);
    }
}
