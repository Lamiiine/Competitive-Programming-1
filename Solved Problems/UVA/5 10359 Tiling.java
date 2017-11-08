import java.util.*;
import java.math.*;

public class Main
{
	public static final int MAX = 256;
	public static BigInteger memo[] = new BigInteger[MAX];
	public static void init()
	{
		memo[0] = memo[1] = BigInteger.ONE;
		for (int i = 2; i < MAX; ++i)
			memo[i] = memo[i - 1].add(memo[i - 2]).add(memo[i - 2]);
	}
	public static void main(String[] args)
	{
		init();
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
			System.out.println(memo[sc.nextInt()]);
	}
}

