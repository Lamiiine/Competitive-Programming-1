import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Kool {
	static final long INF = 2000000000000000000L;

	static int[] fail;
	static String P;
	
	static int[] lens;

	public static int kmpSearch(String T) {
		int i = 0, j = -1;
		int M = P.length(), N = T.length();
		while (i < N) {
			while (j >= 0 && T.charAt(i) != P.charAt(j))
				j = fail[j];

			++i;
			++j;
			if (j == M) {
				return i - j;
				//j = fail[j];
			}
		}
		return i - j;
	}

	public static void kmpPreprocess() {
		int i = 0, j = -1;
		int M = P.length();
		fail = new int[M + 1];
		fail[i] = j;
		while (i < M) {
			while (j >= 0 && P.charAt(i) != P.charAt(j))
				j = fail[j];

			++i;
			++j;
			fail[i] = j;
		}
	}


	public static long[][] identityMatrix(int N, boolean allInf) {

		long[][] res = new long[N][N];
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				if (i == j && !allInf) {
					res[i][j] = 0;
				} else {
					res[i][j] = INF;
				}
			}
		}
		return res;
	}

	public static long[][] matrixMult(long[][] A, long[][] B) {
		int N = A.length;
		long[][] res = identityMatrix(N, true);
		for (int k = 0; k < N; ++k) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					res[i][j] = Math.min(res[i][j], A[i][k] + B[k][j]);
				}
			}
		}
		return res;
	}

	
	public static long[][] matrixPower(long[][] M, int exp) {
		int N = M.length;
		long[][] res = identityMatrix(N, false);
		while (exp > 0) {
			if ((exp & 1) > 0) {
				res = matrixMult(res, M);
			}
			M = matrixMult(M, M);
			exp >>= 1;
		}
		return res;
	}

	public static void main(String[] args) throws FileNotFoundException, IOException {
		BufferedReader br = new BufferedReader(new FileReader("kool.in"));
		int T = Integer.parseInt(br.readLine());
		while (T-- > 0) {
			StringTokenizer st = new StringTokenizer(br.readLine());

			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			String[] names = new String[N];
			for (int i = 0; i < N; ++i) {
				names[i] = br.readLine();
			}

			long[][] dis = new long[N][N];
			lens = new int[N];
			for (int i = 0; i < N; ++i) {
				P = names[i];
				lens[i] = names[i].length();
				kmpPreprocess();
				for (int j = 0; j < N; ++j) {
					// dis[j][i] = the intersection length if putting names[i] after names[j]
					dis[j][i] = names[j].length() - kmpSearch(names[j]);
					//System.out.printf("%s -- %s, %d\n", names[j], names[i], dis[j][i]);
				}
			}

			long[][] base = new long[N][N];
			
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < N; ++j) {
					base[i][j] = names[j].length() - dis[i][j];
					//System.out.printf("%s -- %s, costs additionally %d\n", names[i], names[j], base[i][j]);
				}
			}

			long[][] res = matrixPower(base, M - 1);
			
			long ans = INF;
			
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < N; ++j)
					ans = Math.min(ans, names[i].length() + res[i][j]);
			
			System.out.println(ans);

		}
	}
}