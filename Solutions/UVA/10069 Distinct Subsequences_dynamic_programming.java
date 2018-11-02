import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;
class Main
{
	public static BigInteger [][]memo = new BigInteger[10100][];
	/* memo[i][j] holds the number of subsequences of a[i, a.length() - 1]
	 * that match b[j, b.length() - 1]
	 */
	static String a, b;
	public static void init(){
		// initialize memory
		for (int i = 0; i < a.length(); ++i)
		{
			for (int j = 0; j < b.length(); ++j)
				// initially all values are unknown
				memo[i][j] = BigInteger.valueOf(-1);
			/* if you reach the end of b, record 1 match
			 * this is to support the claim of the call of
			 * of dp(i + 1, j + 1) at label "bishoy"
			 * when j reaches b.length() - 1
			 */
			memo[i][b.length()] = BigInteger.ONE;
		}
		// from the end of a and onward, no matches are found
		for (int j = 0; j < b.length(); ++j)
			memo[a.length()][j] = BigInteger.ZERO;
		// end of b, as explained above
		memo[a.length()][b.length()] = BigInteger.ONE;
	}
	public static BigInteger dp(int i, int j){
		if (!memo[i][j].equals(BigInteger.valueOf(-1)))
		return memo[i][j];
		/* return the number of matches of b[j, b.length() - 1] in
		 * a[i + 1, a.length() - 1] where b[j] occurs beyong i
		 * + the number of matches where b[j] occurs at i (if it does)
		 */
		if (a.charAt(i) == b.charAt(j))
// bishoy:
			return memo[i][j] = dp(i + 1, j + 1).add(dp(i + 1, j));
		return memo[i][j] = dp(i + 1, j);
	}
	public static void first_memo_init(){
		for (int i = 0; i < 10100; ++i)
		memo[i] = new BigInteger[105];
	}
	public static void main (String[] args)
	{
		first_memo_init();
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt(); sc.nextLine();
		while(TC-- > 0){
			a = sc.nextLine();
			b = sc.nextLine();
			init();
			System.out.println(dp(0, 0));
		}
	}
}
