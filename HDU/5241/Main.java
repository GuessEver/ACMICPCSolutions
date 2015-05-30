import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	static BigInteger mul(BigInteger x, int y)
	{
		if(y == 0) return BigInteger.valueOf(1);
		if(y % 2 == 0) return mul(x.multiply(x), y / 2);
		return mul(x.multiply(x), y / 2).multiply(x);
	}
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		for(int cas = 1; cas <= T; cas++)
		{
			int n = cin.nextInt();
			BigInteger res = mul(BigInteger.valueOf(32), n);
			System.out.println("Case #" + cas + ": " + res);
		}
	}
}
