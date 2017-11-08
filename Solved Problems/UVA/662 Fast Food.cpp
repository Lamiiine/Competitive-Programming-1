import java.util.*;

public class Main
{
	public static final int N = 205;
	public static final int K = 32;
	public static final int INF = 100000000;
	
	public static int n, k;
	public static int arr[] = new int[N];
	
	// this is my DP memory table
	public static int memo[][][] = new int[N][N][K];

	// initalize all to -1
	public static void init_memo()
	{
		for (int i = 0; i < N; ++i)
			for (int j = 0; j < N; ++j)
				for (int k = 0; k < K; ++k)
					memo[i][j][k] = -1;
	}

	/* dp(i, j, k) = minimum cost of covering restaurants
	 * knowing that you have k depts left, and that you need
	 * to cover all restaurants starting at j (restaurant j - 1
	 * is the last one covered), and you are currently considering
	 * restaurent #i for a depot
	 * */
	public static int dp(final int i, final int j, final int k)
	{
		// memory
		if (memo[i][j][k] != -1) return memo[i][j][k];
		// base case
		if (i == n || j == n || k == 0)
		{
			// if you run out of both restaurants and depots, return 0
			// if you run out of either of them alone, return infinity
			return memo[i][j][k] = (i == n && j == n && k == 0) ? 0 : INF;
		}
		// recursion
		// either do not build a depot at i
		memo[i][j][k] = dp(i + 1, j, k);
		// or build one!
		int cost = 0;
		for (int t = j; t < i; ++t)
			cost += arr[i] - arr[t];
		
		for (int t = i; t < n; ++t)
		{
			cost += arr[t] - arr[i];
			memo[i][j][k] = Math.min(memo[i][j][k], cost + dp(t + 1, t + 1, k - 1));
		}
		
		return memo[i][j][k];
	}
	// this method tracks the optimal DP path!
	public static void path(final int i, final int j, final int k, final int counter)
	{
		if (i == n || j == n || k == 0) return;
		final int ans = dp(i, j, k);
		if (ans == dp(i + 1, j, k))
		{
			path(i + 1, j, k, counter);
			return;
		}
		int cost = 0;
		for (int t = j; t < i; ++t)
			cost += arr[i] - arr[t];
		for (int t = i; t < n; ++t)
		{
			cost += arr[t] - arr[i];
			if (cost + dp(t + 1, t + 1, k - 1) == ans)
			{
				System.out.println("Depot " + counter + " at restaurant " + (i + 1) + " serves restaurant" + ((j == t) ? (" " + (j + 1)) : ("s " + (j + 1) + " to " + (t + 1))));
				path(t + 1, t + 1, k - 1, counter + 1);
				return;
			}
		}
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		for(int tc = 1; true; ++tc)
		{
			n = sc.nextInt();
			k = sc.nextInt();
			if (n == 0 && k == 0) break;
			for (int i = 0; i < n; ++i)
				arr[i] = sc.nextInt();
			init_memo();
			System.out.println("Chain " + tc);
			path(0, 0, k, 1);
			System.out.println("Total distance sum = " + dp(0, 0, k));
			System.out.println();
		}
	}
}

