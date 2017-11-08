import java.util.*;

public class Main
{
	public static String line;
	public static int i;
	public static ArrayList<ArrayList<Literal>> formula = new ArrayList<ArrayList<Literal>> ();
	public static boolean used[] = new boolean[26];
	public static boolean truth[] = new boolean[26];
	public static Literal get_literal()
	{
		Literal ans = new Main.Literal();
		final char c = line.charAt(i++);
		if (c == '~')
		{
			ans.n = true;
			ans.v = line.charAt(i++);
			return ans;
		}
		ans.n = false;
		ans.v = c;
		return ans;
	}
	public static ArrayList<Literal> get_clause()
	{
		ArrayList<Literal> ans = new ArrayList<Literal>();
		while(line.charAt(i) != ')')
		{
			++i;
			ans.add(get_literal());
		}
		++i;
		return ans;
	}
	public static void parse()
	{
		i = 0;
		
		formula.clear();
		while(i < line.length())
		{
			formula.add(get_clause());
			++i;
		}
	}
	public static void test_parser()
	{
		for (int i = 0; i < formula.size(); ++i)
		{
			for (int j = 0; j < formula.get(i).size(); ++j)
			{
				final char v = formula.get(i).get(j).v;
				final boolean p = formula.get(i).get(j).n;
				System.out.print(!p ? v : "~" + v);
			}
			System.out.println();
		}
	}
	public static boolean is_true(ArrayList<Literal> a)
	{
		// if v is true, neg has to be false
		// if v is false, neg has to be true
		for (int i = 0; i < a.size(); ++i)
		{
			final int v = (a.get(i).v - 'a');
			final boolean n = a.get(i).n;
			final boolean x = (n ? !truth[v] : truth[v]);
			if (!x) return false;
		}
		return true;
	}
	public static boolean rec(final int i)
	{
		if (i == 26)
		{
			for (int j = 0; j < formula.size(); ++j)
			{
				if (is_true(formula.get(j)))
				{
					return true;
				}
			}
			
			return false;
		}
		
		if (!used[i])
		{
			return rec(i + 1);
		}
		
		truth[i] = false;
		if (rec(i + 1)) return true;
		truth[i] = true;
		if (rec(i + 1)) return true;
		
		return false;
	}
	
	public static boolean solve()
	{
		for (int i = 0; i < formula.size(); ++i)
		{
			boolean flag = true;
			for (int j = 0; flag && j < formula.get(i).size(); ++j)
			{
				final char v = formula.get(i).get(j).v;
				final boolean n = formula.get(i).get(j).n;
				for (int k = j + 1; k < formula.get(i).size(); ++k)
				{
					final char u = formula.get(i).get(k).v;
					final boolean m = formula.get(i).get(k).n;
					if (v == u && n != m)
						flag = false;
				}
			}
			if (flag) return true;
		}
		return false;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		sc.nextLine();
		while(TC-- > 0)
		{
			line = sc.nextLine();
			parse();
			for (int i = 0; i < 26; ++i)
				used[i] = false;
			for (int i = 0; i < formula.size(); ++i)
			for (int j = 0; j < formula.get(i).size(); ++j)
				used[formula.get(i).get(j).v - 'a'] = true;
			// test_parser();
			System.out.println(solve() ? "YES" : "NO");
		}
	}
	
	private static class Literal
	{
		public char v;
		public boolean n;
		public Literal()
		{
			v = 'a';
			n = false;
		}
	}
}

