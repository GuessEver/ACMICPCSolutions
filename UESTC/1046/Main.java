import java.io.*;
import java.util.*;
import java.math.*;

public class Main{
	static BigInteger calc(String a)
	{
		if(a.length() > 2 && a.charAt(0) == '0' && (a.charAt(1) == 'x' || a.charAt(1) == 'X'))
		{
			a = a.substring(2);
			return new BigInteger(a, 16);
		}
		else if(a.length() > 1 && a.charAt(0) == '0')
		{
			a = a.substring(1);
			return new BigInteger(a, 8);
		}
		else return new BigInteger(a, 10);
	}
	public static void main(String args[])
	{
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter cout = new PrintWriter(new BufferedOutputStream(System.out));
		String a = cin.next(); BigInteger x = calc(a);
		String b = cin.next(); BigInteger y = calc(b);
		cout.println(x.add(y));
		cin.close(); cout.close();
	}
}
