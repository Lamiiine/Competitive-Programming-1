import java.util.*;

public class Main
{
	public static final int MAX = 15;
	public static final int OO = 1000000;
	public static Scanner sc = new Scanner(System.in);
	public static int memo[][] = new int[1 << MAX][102];
	public static int n, m;
	public static int arr[] = new int[102];
	public static void init_memo()
	{
		for (int i= 0; i < (1 << MAX); ++i)
			for (int j = 0; j < 102; ++j)
				memo[i][j] = -1;
	}
	public static int dp(final int mask, final int j)
	{
		if (memo[mask][j] != -1) return memo[mask][j];
		if (mask == 0) return memo[mask][j] = 0;
		if (j == m) return memo[mask][j] = OO;
		return memo[mask][j] = Math.min(dp(mask, j + 1), 1 + dp(mask ^ arr[j], j + 1));
	}
	public static void read()
	{
		n = sc.nextInt();
		m = sc.nextInt();
		for (int i = 0; i < m; ++i)
		{
			int mask = 0;
			for (int j = 0; j < n; ++j)
				if (sc.nextInt() == 1)
					mask |= (1 << j);
			arr[i] = mask;
		}
	}
	public static void main(String[] args)
	{
		int TC = sc.nextInt();
		for (int tc = 1; tc <= TC; ++tc)
		{
			init_memo();
			read();
			final int ans = dp((1 << n) - 1, 0);
			System.out.print("Case " + tc + ": ");
			System.out.println(ans == OO ? "IMPOSSIBLE" : ans);
		}
	}
}

