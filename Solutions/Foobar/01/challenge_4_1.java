public class Main
{
	public	final static int MAX = 53;
	public final static int S = 52;
	public final static int T = 51;
	public final static int OO = 1000000000;
	
	public static int res[][];
	public static int vis[];
	public static int visId;
	public static void initRes()
	{
		res = new int[MAX][];
		for (int i = 0; i < MAX; ++i)
		{
			res[i] = new int[MAX];
		}
		
		for (int i = 0; i < MAX; ++i)
		{
			for (int j = 0; j < MAX; ++j)
			{
				res[i][j] = 0;
			}
		}
	}
	public static void initVis()
	{
		visId = 0;
		vis = new int[MAX];
		for (int i = 0; i < MAX; ++i)
		{
			vis[i] = 0;
		}
	}
	
	public static int dfs(final int i, final int curFlow)
	{
		if (curFlow == 0 || vis[i] == visId)
		{
			return 0;
		}
		vis[i] = visId;
		if (i == T)
		{
			return curFlow;
		}
		for (int j = 0; j < MAX; ++j)
		{
			if (res[i][j] != 0)
			{
				final int f = dfs(j, Math.min(curFlow, res[i][j]));
				if (f != 0)
				{
					res[i][j] -= f;
					res[j][i] += f;
					return f;
				}
			}
		}
		return 0;
	}
    public static int answer(int[] entrances, int[] exits, int[][] path)
    {
    	initRes();
    	initVis();
    	for (int i = 0; i < path.length; ++i)
    	{
    		for (int j = 0; j < path[i].length; ++j)
    		{
    			res[i][j] = path[i][j];
    		}
    	}
    	for (int e : entrances)
    	{
    		res[S][e] = OO;
    	}
    	for (int e : exits)
    	{
    		res[e][T] = OO;
    	}
    	int ans = 0;
    	while(true)
    	{
    		++visId;
    		final int cur = dfs(S, OO);
    		if (cur == 0)
    		{
    			break;
    		}
    		ans += cur;
    	}
    	return ans;
    }
}

