import java.io.*;
import java.math.*;
import java.util.*;

public class Main{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		BigInteger A = cin.nextBigInteger();
		BigInteger B = cin.nextBigInteger();
		System.out.println(A.add(B));
	}
}
