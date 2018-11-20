import java.util.*;

public class Main {
    public static void main(String[] args)
    {
    	Scanner sc = new Scanner(System.in);
    	int d = sc.nextInt();
    	int[][] m = new int[d][];
    	for (int i = 0; i < d; ++i)
    	m[i] = new int[d];
    	for (int i =0; i < d; ++i)
    	for (int j = 0; j < d; ++j)
    	m[i][j] = sc.nextInt();
    	int[] ans = answer(m);
    	for (int x : ans)
    	System.out.println(x);
    }
    
    public static int[] answer(int[][] m)
    {
        // get dimension
        int dimension = m.length;
        for (int i = 0; i < dimension; ++i)
        {
            if (m[i].length != dimension)
            {
                throw new IllegalArgumentException("invlaid matrix dimensions");
            }
            if (m[i][i] != 0)
            {
                // throw new IllegalStateException("a state can transition to itsef!");
            }
        }
        
        // get row sum
        int[] rowSum = new int[dimension];
        for (int i = 0; i < dimension; ++i)
        {
            rowSum[i] = 0;
            for (int j = 0; j < dimension; ++j)
            {
                rowSum[i] += m[i][j];
            }
        }
        
        ArrayList<rational> ans = new ArrayList<rational>();
        for (int i = 0; i < dimension; ++i)
        {
            if (rowSum[i] == 0)
            {
                // now we need to create a matrix for this terminal state
                rational[][] matrix = new rational[dimension][];
                for (int j = 0; j < dimension; ++j)
                    matrix[j] = new rational[dimension + 1];
                // matrix[][] is the augmented matrix of a system,
                // where x_j = the probability of s_j reaching s_i, for all j
                for (int j = 0; j < dimension; ++j)
                {
                    if (rowSum[j] == 0)
                    {
                        // j is a terminal state
                        for (int k = 0; k < dimension; ++k)
                        {
                            matrix[j][k] = new rational((j == k) ? 1L : 0L, 1L);
                        }
                        matrix[j][dimension] = new rational((i == j) ? 1L : 0L, 1L);
                    }
                    else
                    {
                        // j is a nonterminal state
                        for (int k = 0; k < dimension; ++k)
                        {
                            matrix[j][k] = (j == k)
                                ? new rational (-1L, 1L)
                                : new rational(m[j][k], rowSum[j]);
                        }
                        matrix[j][dimension] = new rational(0, 1);
                    }
                }
                ans.add(solve(matrix)[0]);
            }
        }
        long denominator = 1L;
        for (rational r : ans)
            denominator = lcm(denominator, r.y);
        int[] intAns = new int[ans.size() + 1];
        for (int i = 0; i < ans.size(); ++i)
        {
            intAns[i] = (int) (ans.get(i).x * (denominator / ans.get(i).y));
        }
        intAns[ans.size()] = (int) denominator;
        return intAns;
    }
    
    public static long gcd(long a, long b)
    {
        return (b == 0) ? a : gcd(b, a % b);
    }
    
    public static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }
 
    // gaussian elimination algorithm!
    public static rational[] solve(rational[][] matrix)
    {
        int n = matrix.length;
        for (int c = 0; c < n - 1; ++c)
        {
            for (int i = c + 1; i < n; ++i)
            {
                rational factor = matrix[i][c].div(matrix[c][c]);
                for (int k = n; k >= c; --k)
                matrix[i][k] = matrix[i][k].sub(matrix[c][k].mul(factor));
            }
        }
        
        rational[] ans = new rational[n];
        for (int j = n - 1; j >= 0; --j)
        {
            rational t = new rational(0L, 1L);
            for (int k = j + 1; k < n; ++k)
            {
                t = t.add(matrix[j][k].mul(ans[k]));
            }
            ans[j] = matrix[j][n].sub(t).div(matrix[j][j]);
        }
        return ans;
    }
    
    
    public static class rational
    {
        public long x;
        public long y;
        public rational(long _x, long _y)
        {
            this.x = _x;
            this.y = _y;
        }
        public rational add(rational other)
        {
            rational ans = new rational(this.x * other.y + this.y * other.x, this.y * other.y);
            ans.normalize();
            return ans;
        }
        public rational sub(rational other)
        {
            return this.add(new rational(-other.x, other.y));
        }
        public rational mul(rational other)
        {
            rational ans = new rational(this.x * other.x, this.y * other.y);
            ans.normalize();
            return ans;
        }
        public rational div(rational other)
        {
            return this.mul(new rational(other.y, other.x));
        }
        public void normalize()
        {
            long z = gcd(this.x, this.y);
            this.x /= z;
            this.y /= z;
        }
        public static long gcd(long a, long b)
        {
            return (b == 0) ? a : gcd(b, a % b);
        }
        public static long lcm(long a, long b)
        {
            return a * (b / gcd(a, b));
        }
    }
}
