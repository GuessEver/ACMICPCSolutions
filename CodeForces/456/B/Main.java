import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		String s = cin.next();
		BigInteger n = new BigInteger(s);
		BigInteger twenty = new BigInteger("20");
		BigInteger four = new BigInteger("4");
		BigInteger five = new BigInteger("5");
		//System.out.println(n);
		BigInteger tmp1 = n.divide(twenty);
		BigInteger tmp2 = n.mod(twenty);
		n = n.mod(four);
		int nn = n.intValue();
		//System.out.println(nn);
		BigInteger res[] = new BigInteger[30];
		for(int i = 0; i < 30; i++) res[i] = new BigInteger("0");
		for(int i = 1; i <= 20; i++)
		{
			res[i] = res[i-1];
			int tmp = 1;
			for(int j = 1; j <= nn; j++)
				tmp  = tmp % 5 * i % 5;
			BigInteger ttt = BigInteger.valueOf(tmp);
			res[i].add(ttt);
			res[i].mod(five);
		}
		int tt = tmp2.intValue();
		BigInteger ans = tmp1.multiply(res[20]).mod(five);
		ans = ans.add(res[tt]);
		System.out.println(ans);
	}
}
