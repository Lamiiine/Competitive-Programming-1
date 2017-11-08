import java.util.*;

/**
 *
 * @author Bishoy
 */
public class Main {
    public static class edge{
        int f, t, c;
        public edge(int _f, int _t, int _c)
        {
            f = _f;
            t = _t;
            c = _c;
        }
        public edge(){}
    }
    public static class cmp implements Comparator<edge>
    {
        @Override
        public int compare(edge x, edge y)
        {
            return x.c < y.c ? -1 : x.c == y.c ? 0 : 1;
        }
    }
    public final static int MAX = 202;
    public final static int OO = 1000000000;
    
    public static ArrayList<edge> A = new ArrayList<edge>();
    public static int adj[][] = new int [MAX][];
    public static int p[] = new int[MAX];
    public static int n, m;
    public static int ans;
    public static boolean error_flag;
    public static int group[] = new int[MAX];
    public static int get_p(final int i)
    {
        return ((i == p[i]) ? i : (p[i] = get_p(p[i])));
    }
    public static boolean same(final int i, final int j)
    {
        return get_p(i) == get_p(j);
    }
    public static void unite(final int i, final int j)
    {
        p[get_p(j)] = get_p(i);
    }
    public static boolean connected()
    {
        final int parent = get_p(1);
        for (int i = 2; i <= n; ++i)
            if (parent != get_p(i))
                return false;
        return true;
    }
    public static void first_init_adj()
    {
        for (int i = 0; i < MAX; ++i)
            adj[i] = new int[MAX];
    }
    public static void init()
    {
        A.clear();
        
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                adj[i][j] = OO;
        for (int i = 0; i < MAX; ++i)
            p[i] = i;
        for (int i = 0; i < MAX; ++i)
            group[i] = 0;
        ans = 0;
        error_flag = false;
    }
    public static void read(Scanner sc)
    {
        m = sc.nextInt();
        for (int a, b, c, i = 0; i < m; ++i)
        {
            a = sc.nextInt();
            b = sc.nextInt();
            c = sc.nextInt();
            adj[b][a] = adj[a][b] = Math.min(adj[a][b], c);
            A.add(new edge(a, b, c));
            if (group[a] == 2 || group[b] == 1)
                error_flag = true;
            group[a] = 1; group[b] = 2;
        }
    }
    public static void combine_by_negative()
    {
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (adj[i][j] <= 0)
                {
                    ans += adj[i][j];
                    unite(i, j);
                }
    }
    public static void combine_by_positive()
    {
        for (final edge e : A)
            if (!same(e.f, e.t))
            {
                unite(e.f, e.t);
                ans += e.c;
            }
    }
    public static void main(String[] args) {
        first_init_adj();
        Scanner sc = new Scanner(System.in);
        while(true)
        {
            n = sc.nextInt();
            if (n == 0) break;
            init();
            read(sc);
            A.sort(new cmp());
            combine_by_negative();
            combine_by_positive();
            System.out.println(error_flag || !connected() ? "Invalid data, Idiot!" : ans);
        }
    }
    
}
/*
6
9
1 4 1
2 4 2
3 4 3
1 5 2
2 5 3
3 5 2
1 6 3
2 6 1
3 6 2
6
10
1 2 3
1 4 1
2 4 2
3 4 3
1 5 2
2 5 3
3 5 2
1 6 3
2 6 1
3 6 2
4
4
1 3 5
1 4 -3
2 3 2
2 4 -6
0
*/