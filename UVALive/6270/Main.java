import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		BigInteger f[] = new BigInteger[10100];
		f[1] = BigInteger.valueOf(1);
		f[2] = BigInteger.valueOf(3);
		for(int i = 3; i <= 10000; i++)
			f[i] = f[i-1].add(f[i-2]);
		while(cin.hasNextInt())
		{
			int n = cin.nextInt();
			System.out.println(f[n]);
		}
	}
}
