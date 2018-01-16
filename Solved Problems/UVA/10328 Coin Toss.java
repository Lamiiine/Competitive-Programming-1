import java.util.*;
import java.math.*;
public class Main{
	static BigInteger memo[][][] = new BigInteger[105][105][2];
	static int n, k;
	public static void init_memo()
	{
		// set memo[n]
		for (int j = 0; j <= n; ++j)
		{
			for (int done = 0; done < 2; ++done)
			{
				memo[n][j][done] = (done == 1 || j >= k) ? BigInteger.ONE : BigInteger.ZERO;
			}
		}
		
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j >= 0; --j)
			{
				for (int done = 0; done < 2; ++done)
				{
					memo[i][j][done] = memo[i + 1][j + 1][(done == 1|| j + 1 >= k) ? 1 : 0].add(memo[i + 1][0][(done == 1 || j >= k) ? 1 : 0]);
				}
			}
		}
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			n = sc.nextInt();
			k = sc.nextInt();
			init_memo();
			System.out.println(memo[0][0][0]);
		}
	}
}

