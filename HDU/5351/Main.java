import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	static BigInteger f[] = new BigInteger[1010];
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		int T = cin.nextInt();
		f[0] = BigInteger.valueOf(0);
		f[1] = f[2] = BigInteger.valueOf(1);
		for(int i = 3; i <= 1000; i++)
			f[i] = f[i-1].add(f[i-2]);
		for(int cas = 1; cas <= T; cas++)
		{
			int n = cin.nextInt();
			BigInteger m = cin.nextBigInteger();
			for(int i = 1; i <= 1000; i++)
			{
				if(f[i].compareTo(m.add(BigInteger.valueOf(1))) == 1)
				{
					System.out.println(m.subtract(f[i-2]).mod(BigInteger.valueOf(258280327)));
					break;
				}
			}
		}
	}
}
