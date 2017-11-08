import java.util.*;
import java.math.*;
public class Main{
	static BigInteger memo[][] = new BigInteger[52][4004];
	final static BigInteger NEGONE = BigInteger.valueOf(-1);
	static int f, n, s;
	public static void init_memo()
	{
		for (int i = 0; i < 52; ++i)
		{
			for (int j = 0; j < 4004; ++j)
			{
				memo[i][j] = NEGONE;
			}
		}
	}
	
	public static BigInteger dp(final int i, final int j)
	{
		if (!memo[i][j].equals(NEGONE))
		{
			return memo[i][j];
		}
		if (i == 0 || j == 0)
		{
			return memo[i][j] = (i == 0 && j == 0) ? BigInteger.ONE : BigInteger.ZERO;
		}
		memo[i][j] = BigInteger.ZERO;
		for (int k = Math.min(j, f); k >= 1; --k)
		{
			memo[i][j] = memo[i][j].add(dp(i - 1, j - k));
		}
		return memo[i][j];
	}
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			f = sc.nextInt();
			n = sc.nextInt();
			s = sc.nextInt();
			init_memo();
			System.out.println(dp(n, s).toString() + "/" + BigInteger.valueOf(f).pow(n).toString());
		}
	}
}

