import java.util.Arrays;

public class Answer
{
    public static boolean[][] G;
    public static int[][] memo;
    public static int width;
    public static int height;
    public static boolean isSmoke(int a, int b, int c, int d)
    {
    	int counter = 0;
    	if (a != 0) ++counter;
    	if (b != 0) ++counter;
    	if (c != 0) ++counter;
    	if (d != 0) ++counter;
    	return counter == 1;
    }
    
    public static boolean valid(int c, int a, int b)
    {
    	for (int i = 0; i < height - 1; ++i)
    	{
    		if (G[i][c] != isSmoke(a & (1 << i), a & (1 << (i + 1)), b & (1 << i), b & (1 << (i + 1))))
    		{
    			return false;
    		}
    	}
    	
    	return true;
    }
    
    // column number and mask!
    public static int dp(int c, int mask)
    {
    	// base case!
    	if (c == width)
    	{
    		return 1;
    	}
    	
    	// memory!
    	if (memo[c][mask] != -1)
    	{
    		return memo[c][mask];
    	}
    	
    	// recursive step!
    	memo[c][mask] = 0;
    	for (int j = 0; j < (1 << height); ++j)
    	{
    		if (valid(c - 1, mask, j))
    		{
    			memo[c][mask] += dp(c + 1, j);
    		}
    	}
    	
    	return memo[c][mask];
    }
    
    public static int answer(boolean[][] g)
    {
        G = g;
        height = g.length + 1;
        width = g[0].length + 1;
        memo = new int[width][];
        for (int i = 0; i < width; ++i)
        {
        	memo[i] = new int[1 << height];
        }
        
        for (int i = 0; i < width; ++i)
        {
        	Arrays.fill(memo[i], -1);
        }
        
        int ans = 0;
        for (int i = 0; i < (1 << height); ++i)
        {
        	ans += dp(1, i);
        }
        
        return ans;
    }
}

