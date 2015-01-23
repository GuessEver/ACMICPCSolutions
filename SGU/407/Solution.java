import java.io.*;
import java.util.*;
import java.math.*;

public class Solution {
    public static void main(String[] args) {
        int n, m;
        Scanner cin = new Scanner (System.in);
        n = cin.nextInt();
        m = cin.nextInt();
        BigInteger f[][] = new BigInteger[5010][3];
		for(int i = 0; i < n+1; i++)
			for(int j = 0; j < 3; j++)
				f[i][j] = BigInteger.ZERO;
		f[0][0] = BigInteger.ONE;
		for(int i = 1; i <= m; i++)
		{
			f[i][0] = f[i-1][1];
			f[i][1] = f[i-1][1].multiply(new BigInteger("2"));
			f[i][1] = f[i][1].add(f[i-1][0].multiply(new BigInteger(new Integer(n).toString())));
		}
		if(m == 0) System.out.println(1);
		else System.out.println(f[m][0]);
    }
}
