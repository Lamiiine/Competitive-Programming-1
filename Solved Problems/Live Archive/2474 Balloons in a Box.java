import java.math.*;
import java.util.*;

public class Main
{
	public final static double PI = Math.acos(-1.0);
	public static Point p;
	public static Point q;
	public static int n;
	public static double ans = 0.0;
	public static ArrayList<Integer> stack = new ArrayList<Integer> ();
	public static ArrayList<Point> centers = new ArrayList<Point> ();

	public static void rec(final int mask)
	{
		if (mask == ((1 << n) - 1))
		{
			// done ordering balloons
			ArrayList<Balloon> balloons = new ArrayList<Balloon> ();
			for (int i = 0; i < n; ++i)
			{
				final Point cur = centers.get(stack.get(i));
				double radius = Math.min(Math.min(Math.min(p.dx(cur), q.dx(cur)), Math.min(p.dy(cur), q.dy(cur))), Math.min(p.dz(cur), q.dz(cur)));
				for (Balloon b : balloons)
				{
					radius = Math.min(radius, b.center.dist(cur) - b.radius);
				}
				
				if (radius < 0.0)
				{
					continue;
				}
				
				balloons.add(new Balloon(cur, radius));
			}
			
			double cur = 0.0;
			for (Balloon b : balloons)
			{
				cur += b.volume();
			}
			
			ans = Math.max(ans, cur);
		}
		else
		{
			for (int i = 0; i < n; ++i)
			{
				if ((mask & (1 << i)) == 0)
				{
					stack.add(i);
					rec(mask | (1 << i));
					stack.remove(stack.size() - 1);
				}
			}
		}
	}
	public static void init()
	{
		stack.clear();
		centers.clear();
		ans = 0.0;
	}
	public static boolean between(final int a, final int b, final int c)
	{
		return a >= Math.min(b, c) && a <= Math.max(b, c);
	}
	public static boolean insideBox(Point c)
	{
		return between(c.x, p.x, q.x) && between(c.y, p.y, q.y) && between(c.z, p.z, q.z);
	}
	public static ArrayList<Point> cleanCenters()
	{
		ArrayList<Point> ans = new ArrayList<Point> ();
		for (Point c : centers)
		{
			if (insideBox(c))
			{
				ans.add(c);
			}
		}
		return ans;
	}
	public static void read(Scanner sc)
	{
		int x, y, z;
		x = sc.nextInt();
		y = sc.nextInt();
		z = sc.nextInt();
		p = new Point(x, y, z);
		x = sc.nextInt();
		y = sc.nextInt();
		z = sc.nextInt();
		q = new Point(x, y, z);
		for (int i = 0; i < n; ++i)
		{
			x = sc.nextInt();
			y = sc.nextInt();
			z = sc.nextInt();
			centers.add(new Point(x, y, z));
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		for (int tc = 1; ; ++tc)
		{
			n = sc.nextInt();
			if (n == 0)
			{
				break;
			}
			
			init();
			read(sc);
			
			centers = cleanCenters();
			n = centers.size();
			
			rec(0);
			System.out.println(String.format("Box %d: %.0f\n", tc, Math.abs((p.x - q.x) * (p.y - q.y) * (p.z - q.z)) - ans));
		}
	}
	
	static class Point
	{
		int x, y, z;
		public Point(int _x, int _y, int _z)
		{
			this.x = _x;
			this.y = _y;
			this.z = _z;
		}
		public Point()
		{
			this.x = this.y = this.z = 0;
		}
		
		public int dx(Point other)
		{
			return Math.abs(this.x - other.x);
		}
		public int dy(Point other)
		{
			return Math.abs(this.y - other.y);
		}
		public int dz(Point other)
		{
			return Math.abs(this.z - other.z);
		}
		public double dist(Point other)
		{
			int x = this.dx(other), y = this.dy(other), z = this.dz(other);
			return Math.sqrt(x * x + y * y + z * z);
		}
	}
	static class Balloon
	{
		public Point center;
		public double radius;
		public Balloon(Point c, double r)
		{
			this.center = c;
			this.radius = r;
		}
		
		public double volume()
		{
			return (4.0 / 3.0) * PI * this.radius * this.radius * this.radius;
		}
	}
}

/*
2
0 0 0
10 10 10
3 3 3
7 7 7
0
*/

