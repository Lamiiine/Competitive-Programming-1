import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Hope {
	final static int MAX = 1500000;
	static final boolean[] isPrime = new boolean[MAX];
	static final ArrayList<Integer> primes = new ArrayList<>();
	
	public static void sieve() {
		Arrays.fill(isPrime, true);
		isPrime[0] = isPrime[1] = false;
		for (int i = 2; i * i < MAX; ++i) {
			if (isPrime[i]) {
				for (int j = i * i; j < MAX; j += i) {
					isPrime[j] = false;
				}
			}
		}
		
		for (int p = 0; p < MAX; ++p) {
			if (isPrime[p]) {
				primes.add(p);
			}
		}
	}
	
	public static long gcd(long a, long b) {
		if (b == 0) {
			return a;
		} else {
			return gcd(b, a % b);
		}
	}
	
	public static long sqrt(long x) {
		long beg = 1, end = x;
		while (beg + 1 < end) {
			long mid = (beg + end) / 2;
			if (mid <= x /mid) {
				beg = mid;
			} else {
				end = mid;
			}
		}
		if (beg * beg == x) {
			return beg;
		}
		return 0;
	}
	
	public static int solve(final long[] arr) {
		int res = 0;
		for (int i = 0; i < primes.size(); ++i) {
			int e = 0, p = primes.get(i);
			for (int j = 0; j < arr.length; ++j) {
				while (arr[j] % p == 0) {
					arr[j] /= p;
					++e;
				}
			}
			res = Math.max(res, e);
		}
		HashSet<Long> primesRemaining = new HashSet<>();
		for (int i = 0; i < arr.length; ++i) {
			if (arr[i] > 1) {
				long r = sqrt(arr[i]);
				if (r > 1) {
					primesRemaining.add(r);
				}
				primesRemaining.add(arr[i]);
			}
		}
		for (int i = 0; i < arr.length; ++i) {
			for (int j = i; j < arr.length; ++j) {
				long r = gcd(arr[i], arr[j]);
				if (r > 1) {
					primesRemaining.add(r);
				}
			}
		}
		for (Long p : primesRemaining) {
			int e = 0;
			for (int i = 0; i < arr.length; ++i) {
				long n = arr[i];
				while (n % p == 0) {
					n /= p;
					++e;
				}
			}
			res = Math.max(res, e);
		}
		return res;
	}
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		sieve();
		BufferedReader br = new BufferedReader(new FileReader("hope.in"));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {

			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			long[] arr = new long[N];
			for (int i = 0; i < N; ++i) {
				arr[i] = Long.parseLong(st.nextToken());
			}
			
			System.out.println(solve(arr));
		}
	}
}