import java.math.*;
import java.util.*;
import java.lang.*;

public class Main
{
    public static final int MAX = 32;
    public static final int OO = 100000000;
    public static final int C = 5;
    public static final int D = 4;
    public static int dist[][][][] = new int[MAX][MAX][C][D];
    public static int vis[][][][] = new int[MAX][MAX][C][D];
    public static int vis_id = 0;
    public static int n, m;
    public static char arr[][] = new char[MAX][];
    public static void first_init()
    {
        for (int i = 0; i < MAX; ++i)
            for (int j = 0; j < MAX; ++j)
                for (int k = 0; k < C; ++k)
                    for (int t = 0; t < D; ++t)
                        vis[i][j][k][t] = 0;
    }
    public static point s, t;
    /*
                dx  dy
    0: north    -1  0
    1: east     0   1
    2: south    1   0
    3: west     0   -1
    */
    public static int dx[] = {-1, 0, 1, 0};
    public static int dy[] = {0, 1, 0, -1};
    
    public static void bfs()
    {
        LinkedList<state> q = new LinkedList<state>();
        q.add(new state(s.x, s.y, 0, 0));
        dist[s.x][s.y][0][0] = 0;
        vis[s.x][s.y][0][0] = vis_id;
        while(!q.isEmpty())
        {
            final state i = q.remove();
            final int cur_dist = dist[i.x][i.y][i.c][i.d];
            // rotate
            for (int j = -1; j <= 1; j += 2)
            {
                final state k = new state(i.x, i.y, i.c, (i.d + j + 4) & 3);
                if (vis[k.x][k.y][k.c][k.d] != vis_id)
                {
                    vis[k.x][k.y][k.c][k.d] = vis_id;
                    dist[k.x][k.y][k.c][k.d] = cur_dist + 1;
                    q.add(k);
                }
            }
            // move
            final state k = new state(i.x + dx[i.d], i.y + dy[i.d], (i.c + 1) % C, i.d);
            if (k.x >= 0 && k.x < n && k.y >= 0 && k.y < m && arr[k.x][k.y] != '#' && vis[k.x][k.y][k.c][k.d] != vis_id)
            {
                vis[k.x][k.y][k.c][k.d] = vis_id;
                dist[k.x][k.y][k.c][k.d] = cur_dist + 1;
                q.add(k);
            }
        }
    }
    
    public static void init()
    {
        ++vis_id;
    }
    
    public static Scanner sc = new Scanner(System.in);
    public static void read()
    {
        for (int i = 0; i < n; ++i)
            arr[i] = sc.nextLine().toCharArray();
    }
    public static void find_source_target()
    {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (arr[i][j] == 'S')
                    s = new point(i, j);
                else if (arr[i][j] == 'T')
                    t = new point(i, j);
    }
    public static void main(String[] args)
    {
        first_init();
        for (int tc = 1; true; ++tc)
        {
            n = sc.nextInt();
            m = sc.nextInt();
            if (n == 0 && m == 0) break;
            if (tc != 1) System.out.println();
            System.out.println("Case #" + tc);
            sc.nextLine();
            read();
            init();
            find_source_target();
            Arrays.fill(dist[t.x][t.y][0], OO);
            bfs();
            int ans = OO;
            for (int i = 0; i < 4; ++i)
                ans = Math.min(ans, dist[t.x][t.y][0][i]);
            System.out.println((ans == OO) ? "destination not reachable" : "minimum time = " + ans + " sec");
        }
    }
}
class point
{
    int x, y;
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
}
class state
{
    int x;
    int y;
    int c;
    int d;
    state(int _x, int _y, int _c, int _d)
    {
        x = _x;
        y = _y;
        c = _c;
        d = _d;
    }
}
/*
1 3
S#T
10 10
#S.......#
#..#.##.##
#.##.##.##
.#....##.#
##.##..#.#
#..#.##...
#......##.
..##.##...
#.###...#.
#.....###T
0 0
*/
