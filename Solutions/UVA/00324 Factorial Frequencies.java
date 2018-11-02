package Main;
import java.util.Scanner;
import java.math.BigInteger;
/* package whatever; // don't place package name! */
import java.lang.*;
import java.io.*;
import java.math.*;
/* Name of the class has to be "Main" only if the class is public. */

class Main {

    public static BigInteger[][] memo = new BigInteger[102][10010];
    static int w, n, h;

    public static void init_memo() {
        for (int i = 0; i <= n; ++i) {
            memo[w][i] = BigInteger.ONE;
        }
        for (int i = 0; i <= w; ++i) {
            memo[i][0] = BigInteger.ONE;
        }
        for (int i = w - 1; i >= 0; --i) {
            for (int j = 1; j <= n; ++j) {
                memo[i][j] = BigInteger.ZERO;
                final int k = Math.min(j, h);
                for (int t = 0; t <= k; ++t) {
                    memo[i][j] = memo[i][j].add(memo[i + 1][j - t]);
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        w = sc.nextInt();
        h = sc.nextInt();
        init_memo();
        System.out.println(memo[0][n].add(BigInteger.valueOf(-Math.min(h + 1, n / w + 1))));
    }
}
