import java.util.*;

public class Main
{
	public static final int N = 15, M = 42;
	public static final int OO = 1000000;
	public static Scanner sc = new Scanner(System.in);
	public static int memo[][] = new int[1 << N][M];
	public static int n, m;
	public static int arr[] = new int[M];
	public static void init_memo()
	{
		for (int i= 0; i < (1 << N); ++i)
			for (int j = 0; j < M; ++j)
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
			int k = sc.nextInt(), mask = 0;
			while(k-- > 0)
				mask |= (1 << sc.nextInt());
			arr[i] = mask;
		}
	}
	public static void solve()
	{
		int q = sc.nextInt(); sc.nextLine();
		while(q-- > 0)
		{
			final int ans = dp(sc.nextInt(2), 0);
			System.out.println(ans == OO ? -1 : ans);
		}
	}
	public static void main(String[] args)
	{
		int TC = sc.nextInt();
		for (int tc = 1; tc <= TC; ++tc)
		{
			init_memo();
			read();
			System.out.println("Case " + tc + ":");
			solve();
			System.out.println();
		}
	}
}

