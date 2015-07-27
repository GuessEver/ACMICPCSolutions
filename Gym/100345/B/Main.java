import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static void main(String args[]) throws IOException
	{
		Scanner cin = new Scanner(new File("derangements.in"));
		PrintWriter cout = new PrintWriter(new File("derangements.out"));
		BigInteger a[] = new BigInteger[210];
		for(int i = 1; i <= 205; i++) a[i] = BigInteger.ZERO;
		a[1] = BigInteger.valueOf(1);
		for(int i = 2; i <= 200; i++)
		{
			int sign = 1;
			if(i % 2 == 1) sign = -1;
			BigInteger tmp = BigInteger.valueOf(2).multiply(BigInteger.valueOf(i));
			a[i] = a[i-1].multiply(tmp).add(BigInteger.valueOf(sign));
		}
		while(cin.hasNextInt())
		{
			int n = cin.nextInt();
			cout.println(a[n]);
		}
		cin.close();
		cout.close();
	}
}
