import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	static BigInteger mul(BigInteger x, long y, BigInteger M)
	{
		if(y == 0) return BigInteger.ONE;
		if(y % 2 == 0) return mul(x.multiply(x).mod(M), y / 2, M).mod(M);
		else return mul(x.multiply(x).mod(M), y / 2, M).multiply(x).mod(M);
	}
	static long calc(BigInteger k1)
	{
		long x = 1;
		while(true)
		{
			long res = mul(k1, x, BigInteger.valueOf(1000000000000l)).longValue();
			if(x == res && res > 100000000000l) return res;
			x = res;
		}
	}
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		BigInteger a = BigInteger.ONE;
		int cas = 0;
		while(true)
		{
			cas++;
			a = cin.nextBigInteger();
			if(a.compareTo(BigInteger.ZERO) == 0) break;
			long ans = calc(a);
			System.out.println("Case " + cas + ": Public Key = " + a + " Private Key = " + ans);
		}
	}
}
