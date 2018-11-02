import java.util.*;

public class Main
{
	static Scanner sc = new Scanner(System.in);
	static String pre, in;
	static void parse(final int pre_i, final int pre_j, final int in_i, final int in_j)
	{
		if (pre_i >= pre_j) return;
		final int k = in.indexOf(pre.charAt(pre_i), in_i) - in_i;	// number of characters in left subtree 
		parse(pre_i + 1, pre_i + k + 1, in_i, in_i + k);
		parse(pre_i + k + 1, pre_j, in_i + k + 1, in_j);
		System.out.print(pre.charAt(pre_i));
	}
	public static void main(String[] args)
	{
		while(sc.hasNext())
		{
			String[] line = sc.nextLine().split(" ");
			pre = line[0]; in = line[1];
			parse(0, pre.length(), 0, in.length());
			System.out.println();
		}
	}
}

