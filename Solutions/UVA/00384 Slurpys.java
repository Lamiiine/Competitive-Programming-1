import java.util.*;

public class Main
{
	public static String line;
	public static boolean slurpy(int i, int j){
		for (int k = i; k <= j; ++k)
			if (slimp(i, k) && slump(k + 1, j))
				return true;
		return false;
	}
	public static boolean slump(int i, int j){
		if (i > j) return false;
		if (line.charAt(i) != 'D' && line.charAt(i) != 'E') return false;
		++i;
		if (i > j) return false;
		if (line.charAt(i) != 'F') return false;
		++i;
		while(i <= j && line.charAt(i) == 'F') ++i;
		if (i > j) return false;
		return i == j && line.charAt(i) == 'G' || slump(i, j);
	}
	public static boolean slimp(int i, int j){
		if (i > j) return false;
		if (line.charAt(i) != 'A') return false;
		++i;
		if (i > j)
			// there is a single character in this string
			return false;
		if (i == j)
			// must be a two-character slimp!
			return line.charAt(i) == 'H';
		return line.charAt(i) == 'B' && line.charAt(j) == 'C' && slimp(i + 1, j - 1) || line.charAt(j) == 'C' && slump(i, j - 1);
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt(); sc.nextLine();
		System.out.println("SLURPYS OUTPUT");
		while(TC-- > 0)
		{
			line = sc.nextLine();
			System.out.println(slurpy(0, line.length() - 1) ? "YES" : "NO");
		}
		System.out.println("END OF OUTPUT");
	}
}
/*
2
AHDFG
DFGAH
*/
