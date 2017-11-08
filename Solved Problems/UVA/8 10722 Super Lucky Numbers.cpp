import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

class Main
{
	/*
	 * memo[i][j] is the number of super lucky numbers
	 * with a prefix of i digits whose where the last of those
	 * i digits is j
	 */
	static BigInteger[][] memo = new BigInteger[105][2];
	static int b, n;
	static BigInteger dp(int i, int j)
	{
		if (!memo[i][j].equals(BigInteger.valueOf(-1)))
		{
			return memo[i][j];
		}
		if (j == 0)
		{
			// can use 3
			return memo[i][j] = (dp(i + 1, 0).multiply(BigInteger.valueOf(b - 1))).add(dp(i + 1, 1));
		}
		else
		{
			return memo[i][j] = (dp(i + 1, 0).multiply(BigInteger.valueOf(b - 2))).add(dp(i + 1, 1));
		}
	}
	public static void init_memo()
	{
		for (int i = 0; i < 105; ++i)
		memo[i][0] = memo[i][1] = BigInteger.valueOf(-1);
		
		memo[n][0] = memo[n][1] = BigInteger.ONE;
	}
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc = new Scanner(System.in);
		while(true)
		{
			b = sc.nextInt();
			n = sc.nextInt();
			if (b == 0 && n == 0)
			{
				break;
			}
			init_memo();
			System.out.println(dp(1, 1).add(dp(1, 0).multiply(BigInteger.valueOf(b - 2))));
		}
	}
}
