import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.*;

public class Main {
	static BigInteger[][] C = new BigInteger[110][110];
	static BigInteger[] ans = new BigInteger[110];
	static BigInteger[] pow2 = new BigInteger[110];
	static BigInteger Two = new BigInteger("2");
	static void pre() {
		pow2[0] = BigInteger.ONE;
		C[0][0] = BigInteger.ONE;
		for(int i = 1; i <= 100; ++i){
			pow2[i] = pow2[i - 1].multiply(Two);
			C[i][0] = C[i][i] = BigInteger.ONE;
			for(int j = 1; j < i; ++j)
				C[i][j] = C[i - 1][j].add(C[i - 1][j - 1]);
		}
		ans[0] = ans[1] = ans[2] = BigInteger.ONE;
		for(int i = 3; i <= 100; ++i){
			ans[i] =  new BigInteger(String.valueOf(- 2 * i + 2));
			for(int j = 0; j < i; ++j){
				ans[i] = ans[i].add(ans[j].multiply(pow2[j]).multiply(C[i - 1][j]));
			}
			ans[i] = ans[i].subtract(ans[i - 1]); 
			
		}
	}

	public static void main(String[] args) throws FileNotFoundException {
		// TODO Auto-generated method stub
		pre();
		Scanner cin = new Scanner(new File("trains.in"));
		PrintWriter cout = new PrintWriter(new File("trains.out"));
		int n = cin.nextInt();
		cout.println(ans[n].toString());
		cin.close();
		cout.close();
	}

}
