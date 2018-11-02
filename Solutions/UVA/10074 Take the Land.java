import java.util.*;
public class Main
{
    public static final int MAX = 128;
    public static final int OO = 1000000;
    
    public static int n, m;
    public static int arr[][] = new int[MAX][MAX];
    public static Scanner sc = new Scanner(System.in);
    public static int acc[][] = new int[MAX][MAX];
    public static void comp_acc()
    {
        for (int i = 0; i < n; ++i)
            acc[i][m] = 0;
        for (int i = 0; i < n; ++i)
            for (int j = m - 1; j >= 0; --j)
                acc[i][j] = (arr[i][j] == 1) ? 0 : 1 + acc[i][j + 1];
    }
    public static void read()
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                arr[i][j] = sc.nextInt();
    }
    public static int solve()
    {
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
            {
                int cur = OO, num = 0;
                for (int k = i; k < n && cur != 0; ++k)
                {
                    ++num;
                    cur = Math.min(cur, acc[k][j]);
                    ans = Math.max(ans, cur * num);
                }
            }
        
        return ans;
    }
    public static void main(String[] args)
    {
        while(true)
        {
            n = sc.nextInt();
            m = sc.nextInt();
            if (n == 0 && m == 0) break;
            read();
            comp_acc();
            System.out.println(solve());
        }
    }
}
/*
6 7
0 1 1 0 1 1 0
0 0 0 0 0 1 0
1 0 0 0 0 0 1
0 1 0 0 0 0 1
1 1 0 0 0 1 0
1 1 0 1 1 0 0
0 0
*/
