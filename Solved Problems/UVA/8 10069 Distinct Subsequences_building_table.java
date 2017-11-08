import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
class Main
{
	public static String a;
	public static String b;
	public static BigInteger[][] x= new BigInteger[10100][];
	/* x[i][j] holds the number of subsequences of prefix a[0, i] that match
	 * the first j characters of b[0, j]
	*/
	public static void init(){
		for(int i = 0; i < 10100; ++i)
		x[i] = new BigInteger[105];
	}
	public static void solve(){
		// initially, no subsequences of b are found in a[0, 0]
		for (int i = 0; i < 105; ++i)
		x[0][i] = BigInteger.ZERO;
		/* if the first character of a matches the first character of b,
		 * then x[0][0] = 1, because we have found k subsequences of a[0, i]
		 * that match b[0, j] (i = j = 0; k = 1)
		 */
		if (a.charAt(0) == b.charAt(0)) x[0][0] = BigInteger.ONE;
		for (int i = 1; i < a.length(); ++i)
		{
			// we initialize the number to that found at the previous character
			for (int j = 0; j < b.length(); ++j)
			x[i][j] = x[i-1][j];
			for (int j = 0; j < b.length(); ++j)
				// if you found a matching character
				if (b.charAt(j) == a.charAt(i))
				// if it's at the beginning, increment x[i][0]
				if (j == 0) x[i][j] = x[i][j].add(BigInteger.ONE);
				/* else, then all subsequences of length j - 1
				 * ending at or before i will become subsequences
				 * of length j ending at i
				 */
				else x[i][j] = x[i][j].add(x[i-1][j-1]);
		}
	}
	public static void main (String[] args)
	{
			init();
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		sc.nextLine();
		while(TC-- > 0){
			a = sc.nextLine();
			b = sc.nextLine();
			solve();
			/* print the number of subsequences ending at or before
			 * the last character of a that match all up to the last
			 * character of b
			 */
			System.out.println(x[a.length() - 1][b.length()-1]);
		}
	}
}
