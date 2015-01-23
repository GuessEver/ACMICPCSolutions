import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		//Scanner cin = new Scanner(System.in);
		BigInteger ONE = BigInteger.valueOf(1);
		BigInteger ZERO = BigInteger.valueOf(0);
		BigInteger a[] = new BigInteger[3010];
		int T = cin.nextInt();
		for(int cas = 1; cas <= T; cas++)
		{
			int n = cin.nextInt();
			for(int i = 1; i <= n; i++)
			{
				int x = cin.nextInt();
				a[i] = BigInteger.valueOf(x);
			}
			BigInteger ans = ZERO;
			BigInteger C = ONE;
			BigInteger II = ONE;
			BigInteger m = BigInteger.valueOf(n-1);
			boolean sign = true;
			for(int i = n; i >= 1; i--)
			{
				if(n == 1)
				{
					ans = a[n];
					break;
				}
				BigInteger tmp = a[i].multiply(C);
				if(sign) ans = ans.add(tmp);
				else ans = ans.subtract(tmp);
				sign = !sign;
				//System.out.print("(C = " + C + "     ans = " + ans + ")");
				C = C.multiply(m).divide(II);
				m = m.subtract(ONE);
				II = II.add(ONE);
			}
			System.out.println(ans);
		}
	}
}
