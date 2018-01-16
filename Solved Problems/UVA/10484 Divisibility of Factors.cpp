import java.util.*;
public class Main
{
	public static final int MAX = 100;
	public static ArrayList<Integer> primes = new ArrayList<Integer>();
	public static int[] count = new int[MAX + 10];	// count of occurences of the primes
	public static void sieve()
	{
		boolean[] bs = new boolean[MAX + 10];
		for (int i = 0; i < bs.length; ++i)
			bs[i] = true;
		bs[0] = bs[1] = false;
		for (int i = 2; i <= MAX; ++i)
			if (bs[i])
			{
				primes.add(i);
				for (int j = i * i; j <= MAX; j += i)
					bs[j] = false;
			}
	}
	
	public static ArrayList<Integer> factorize(int x)
	{
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < primes.size() && x != 1; ++i)
		{
			final int p = primes.get(i);
			while(x % p == 0)
			{
				ans.add(p);
				x /= p;
			}
		}
		if (x != 1) ans.add(x);
		return ans;
	}
	public static void init()
	{
		for (int i = 0; i < count.length; ++i)
			count[i] = 0;
	}
	public static long solve()
	{
		for (int i = 0; i < count.length; ++i)
			if (count[i] < 0) return 0L;
		long ans = 1L;
		for (int i = 0; i < count.length; ++i)
			ans *= (long)(count[i] + 1L);
		return ans;
	}
	public static Scanner sc = new Scanner(System.in);
	public static void main(String[] args)
	{
		sieve();
		while(true)
		{
			int n = sc.nextInt();
			int d = sc.nextInt();
			if (n == 0 && d == 0) break;
			init();
			for (int i = 2; i <= n; ++i)
			{
				ArrayList<Integer> A = factorize(i);
				for (Integer p : A)
				{
					++count[(int)p];
				}
			}
			boolean flag = true;
			ArrayList<Integer> A = factorize(d);
			if (!A.isEmpty() && A.get(A.size() - 1) >= MAX)
			{
				System.out.println(0);
			}
			else
			{
				for (Integer p : A)
					--count[p];
				System.out.println(solve());
			}
		}
	}
}

