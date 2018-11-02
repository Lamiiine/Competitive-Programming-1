import java.util.*;

public class Main
{
	public static final String SIMPLE = "SIMPLE ";
	public static final String FULLY_GROWN = "FULLY-GROWN";
	public static final String MUTAGENIC = "MUTAGENIC";
	public static final String MUTANT = "MUTANT";
	public static String s;
	public static boolean match_simple(final int i, final int j)
	{
		return i == j && s.charAt(i) == 'A';
	}
	public static boolean match_fully_grown(final int i, final int j)
	{
		return j >= i + 2 && s.charAt(j) == 'B' && s.charAt(j - 1) == 'A' && match_o(i, j - 2);
	}
	public static boolean match_mutagenic(final int i, final int j)
	{
		return j >= i + 2 && s.charAt(i) == 'B' && s.charAt(j) == 'A' && match_o(i + 1, j - 1);
	}
	public static boolean match_o(final int i, final int j)
	{
		if (i > j) return false;
		return match_simple(i, j) || match_fully_grown(i, j) || match_mutagenic(i, j);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt(); sc.nextLine();
		while(TC-- > 0)
		{
			s = sc.nextLine();
			final int l = s.length() - 1;
			System.out.println(match_simple(0, l) ? SIMPLE : match_fully_grown(0, l) ? FULLY_GROWN : match_mutagenic(0, l) ? MUTAGENIC : MUTANT);
		}
	}
}
/*
4
A
AAB
BAAB
BAABA
*/
