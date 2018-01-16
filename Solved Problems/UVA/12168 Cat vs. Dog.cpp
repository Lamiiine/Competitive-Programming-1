import java.util.*;

public class Main
{
	public static final int MAX = 512;

	
	
	public static int head[] = new int[MAX], to[] = new int[MAX * MAX * 2], nxt[] = new int[MAX * MAX * 2], en;
	public static void add_edge(final int i, final int j)
	{
		nxt[en] = head[i];
		head[i] = en;
		to[en] = j;
		++en;
	}
	public static void add_bi_edge(final int i, final int j)
	{
		add_edge(i, j);
		add_edge(j, i);
	}
	
	public static void construct_graph()
	{
		for (int i = 0; i < v; ++i)
			for (int j = i + 1; j < v; ++j)
				if (arr[i].first.equals(arr[j].second) || arr[i].second.equals(arr[j].first))
					add_bi_edge(i, j);
	}
	

	
	public static int[] match = new int[MAX];
	public static int[] vis = new int[MAX];
	public static int vis_id = 0;
	public static void first_init()
	{
		for (int i = 0; i < vis.length; ++i)
			vis[i] = 0;
	}
	public static boolean dfs(final int i){
		if (vis[i] == vis_id) return false;
		vis[i] = vis_id;
		for (int j = head[i]; j != -1; j = nxt[j])
		{
			final int k = to[j];
			if (match[k] == -1 || dfs(match[k]))
			{
				match[i] = k;
				match[k] = i;
				return true;
			}
		}
		
		return false;
	}
	public static int max_match()
	{
		int ans = 0;
		++vis_id;
		for (int i = 0; i < v; ++i, ++vis_id)
			if (match[i] == -1)
				dfs(i);
		for (int i = 0; i < v; ++i)
			if (match[i] != -1)
				++ans;
		return ans / 2;
	}
	
	
	
	
	public static voter[] arr = new voter[MAX];
	public static int c, d, v;
	public static Scanner sc = new Scanner(System.in);
	public static void init()
	{
		for (int i = 0; i < head.length; ++i)
			head[i] = -1;
		en = 0;
		for (int i = 0; i < match.length; ++i)
			match[i] = -1;
	}
	
	public static void read()
	{
		c = sc.nextInt();
		d = sc.nextInt();
		v = sc.nextInt();
		sc.nextLine();
		for (int i = 0; i < v; ++i)
		{
			String[] line = sc.nextLine().split(" ");
			arr[i] = new voter(line[0], line[1]);
		}
	}
	public static void main(String[] args)
	{
		first_init();
		int TC = sc.nextInt();
		while(TC-- > 0)
		{
			init();
			read();
			construct_graph();
			System.out.println(v - max_match());
		}
	}
}

class voter
{
	String first, second;
	voter(String _first, String _second)
	{
		first = _first;
		second = _second;
	}
}

