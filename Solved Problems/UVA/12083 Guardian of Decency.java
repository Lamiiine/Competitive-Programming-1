import java.util.*;

public class Main
{	
	public static final int MAX = 512;
	public static Scanner sc = new Scanner(System.in);
	public static student[] A = new student[MAX];
	public static int n;
	// graph stuff
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
	
	// dfs stuff
	public static int match[] = new int[MAX];
	public static int vis[] = new int[MAX], vis_id = 0;
	public static boolean dfs(final int i)
	{
		if(vis[i] == vis_id) return false;
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
		++vis_id;
		for (int i = 0; i < n; ++i, ++vis_id)
			if (match[i] == -1)
				dfs(i);
		int ans = 0;
		for (int i = 0; i < n; ++i)
			if (match[i] != -1) ++ans;
		return ans/2;
	}

	// reading stuff
	public static void read()
	{
		n = sc.nextInt(); sc.nextLine();
		for (int i = 0; i < n; ++i)
		{
			String[] arr = sc.nextLine().split(" ");
			A[i] = new student(Integer.parseInt(arr[0]), arr[1].charAt(0), arr[2], arr[3]);
		}
	}
	public static boolean valid_couple(final student x, final student y)
	{
		if (Math.abs(x.h - y.h) > 40) return false;
		if (x.g == y.g) return false;
		if (!x.m.equals(y.m)) return false;
		if (x.s.equals(y.s)) return false;
		return true;
	}
	public static void construct_graph()
	{
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (valid_couple(A[i], A[j]))
					add_bi_edge(i, j);
	}
	public static void init()
	{
		for (int i = 0; i < MAX; ++i)
			head[i] = -1;
		en = 0;
		for (int i = 0; i < MAX; ++i)
			match[i] = -1;
	}
	public static void first_init()
	{
		for (int i = 0; i < n; ++i)
			vis[i] = 0;
	}
	public static void main(String[] args)
	{
		first_init();
		int TC = sc.nextInt();
		while(TC-->0)
		{
			init();
			read();
			construct_graph();
			System.out.println(n - max_match());
		}
	}
}


class student
{
	int h;
	char g;
	String m;
	String s;
	student(){}
	student(int _h, char _g, String _m, String _s)
	{
		h = _h;
		g = _g;
		m = _m;
		s = _s;
	}
}

