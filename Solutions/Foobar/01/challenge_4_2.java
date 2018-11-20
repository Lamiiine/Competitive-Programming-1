/*
Bringing a Gun to a Guard Fight
===============================

Uh-oh - you've been cornered by one of Commander Lambdas elite guards! Fortunately, you grabbed a beam weapon from an abandoned guardpost while you were running through the station, so you have a chance to fight your way out. But the beam weapon is potentially dangerous to you as well as to the elite guard: its beams reflect off walls, meaning youll have to be very careful where you shoot to avoid bouncing a shot toward yourself!

Luckily, the beams can only travel a certain maximum distance before becoming too weak to cause damage. You also know that if a beam hits a corner, it will bounce back in exactly the same direction. And of course, if the beam hits either you or the guard, it will stop immediately (albeit painfully). 

Write a function answer(dimensions, your_position, guard_position, distance) that gives an array of 2 integers of the width and height of the room, an array of 2 integers of your x and y coordinates in the room, an array of 2 integers of the guard's x and y coordinates in the room, and returns an integer of the number of distinct directions that you can fire to hit the elite guard, given the maximum distance that the beam can travel.

The room has integer dimensions [1 < x_dim <= 1000, 1 < y_dim <= 1000]. You and the elite guard are both positioned on the integer lattice at different distinct positions (x, y) inside the room such that [0 < x < x_dim, 0 < y < y_dim]. Finally, the maximum distance that the beam can travel before becoming harmless will be given as an integer 1 < distance <= 10000.

For example, if you and the elite guard were positioned in a room with dimensions [3, 2], you_position [1, 1], guard_position [2, 1], and a maximum shot distance of 4, you could shoot in seven different directions to hit the elite guard (given as vector bearings from your location): [1, 0], [1, 2], [1, -2], [3, 2], [3, -2], [-3, 2], and [-3, -2]. As specific examples, the shot at bearing [1, 0] is the straight line horizontal shot of distance 1, the shot at bearing [-3, -2] bounces off the left wall and then the bottom wall before hitting the elite guard with a total shot distance of sqrt(13), and the shot at bearing [1, 2] bounces off just the top wall before hitting the elite guard with a total shot distance of sqrt(5).

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit solution.java

Test cases
==========

Inputs:
    (int list) dimensions = [3, 2]
    (int list) captain_position = [1, 1]
    (int list) badguy_position = [2, 1]
    (int) distance = 4
Output:
    (int) 7

Inputs:
    (int list) dimensions = [300, 275]
    (int list) captain_position = [150, 150]
    (int list) badguy_position = [185, 100]
    (int) distance = 500
Output:
    (int) 9

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
*/

package com.google.challenges; 

import java.util.*;

public class Answer {
	static ArrayList<Point> points;
	static long SqrDistance;
	static Point Captain;
	static Point BadGuy;
	static long width;
	static long height;
	
	static long num_x;
	static long num_y;
	public static void generate_row(Point start)
	{
		points.add (new Point(start));
		for (long i = 0, x = start.X + 2l * width; i <= num_x; i += 2, x += 2l * width)
		{
			points.add(new Point(x, start.Y, start.IsBadGuy));
		}
		
		for (long i = 0, x = start.X - 2l * width; i <= num_x; i += 2, x -= 2l * width)
		{
			points.add(new Point(x, start.Y, start.IsBadGuy));
		}
	}
	public static void generate_column(Point start)
	{
		generate_row(start);
		for (long j = 0, y = start.Y + 2l * height; j <= num_y; j += 2, y += 2l * height)
		{
			generate_row(new Point(start.X, y, start.IsBadGuy));
		}
		
		for (long j = 0, y = start.Y - 2l * height; j <= num_y; j += 2, y -= 2l * height)
		{
			generate_row(new Point(start.X, y, start.IsBadGuy));
		}
	}
	
	public static void generate(Point start)
	{
		generate_column(start);
		generate_column(new Point(-start.X, start.Y, start.IsBadGuy));
		generate_column(new Point(start.X, -start.Y, start.IsBadGuy));
		generate_column(new Point(-start.X, -start.Y, start.IsBadGuy));
	}
	
	public static ArrayList<Point> clean(ArrayList<Point> input)
	{
		ArrayList<Point> ans = new ArrayList<Point> ();
		for (Point p : input)
		{
			if (p.sqrDistance(Captain) <= SqrDistance)
			{
				ans.add(new Point(p.X - Captain.X, p.Y - Captain.Y, p.IsBadGuy));
			}
		}
		
		return ans;
	}
	
	public static int answer(int[] dimensions, int[] captain_position, int[] badguy_position, int distance)
	{
		width = dimensions[0];
		height = dimensions[1];
		Captain = new Point(captain_position[0], captain_position[1], false);
		BadGuy = new Point(badguy_position[0], badguy_position[1], true);
		SqrDistance = (long) distance * distance;
		
		num_x = distance / width + 100l;
		num_y = distance / height + 100l;
		
		points = new ArrayList<Point> ();
		generate(Captain);
		generate(BadGuy);
		points = clean(points);
		Collections.sort(points, new PointComparator());
		// for (Point p : points) System.out.println(p.X + " " + p.Y + " " + p.IsBadGuy);
		int ans = 0;
		for (int i = 1; i < points.size();)
		{
			Point cur = points.get(i);
			if (cur.IsBadGuy)
			{
				++ans;
			}
			
			while(i < points.size() && cur.sameVector(points.get(i)))
			{
				++i;
			}
		}
		
		return ans;
	}

	public static class Point
	{
		public long X, Y;
		public boolean IsBadGuy;
		public Point (long x, long y, boolean isBadGuy)
		{
			this.X = x;
			this.Y = y;
			this.IsBadGuy = isBadGuy;
		}
		public int quadrant()
		{
			return this.X >= 0 ? (this.Y >= 0 ? 1 : 4) : (this.Y >= 0 ? 2 : 3);
		}
		public Point(Point p)
		{
			this.X = p.X;
			this.Y = p.Y;
			this.IsBadGuy = p.IsBadGuy;
		}
		
		public long sqrDistance (Point other)
		{
			long dx = this.X - other.X;
			long dy = this.Y - other.Y;
			return dx * dx + dy * dy;
		}
		public long cross(Point other)
		{
			return this.X * other.Y - this.Y * other.X;
		}
		
		public boolean sameVector(Point other)
		{
			return (this.quadrant() == other.quadrant()) && (this.cross(other) == 0l);
		}
	}
	
	
	public static class PointComparator implements Comparator<Point>
	{
		@Override
		public int compare(Point a, Point b)
		{
			int qa = a.quadrant(), qb = b.quadrant();
			if (qa != qb) {
				return Integer.compare(qa, qb);
			}

			long c = a.cross(b);
			if (c != 0) {
				return Long.compare(0l, c);
			}

			if (Math.abs(a.X) != Math.abs(b.X)) {
				return Long.compare(Math.abs(a.X), Math.abs(b.X));
			}
			if (Math.abs(a.Y) != Math.abs(b.Y)) {
				return Long.compare(Math.abs(a.Y), Math.abs(b.Y));
			}

			return Boolean.compare(a.IsBadGuy, b.IsBadGuy);
		}
		
		public int compare2(Point a, Point b)
		{
		    if (a.X == 0l && a.Y == 0l)
			{
				return -1;
			}
			if (b.X == 0l && a.Y == 0l)
			{
				return 1;
			}
			
			int ans = Double.compare(Math.atan2(a.Y, a.X), Math.atan2(b.Y, b.X));
			if (ans != 0)
			{
				return ans;
			}
			if (Math.abs(a.X) != Math.abs(b.X)) {
				return Long.compare(Math.abs(a.X), Math.abs(b.X));
			}
			return Boolean.compare(a.IsBadGuy, b.IsBadGuy);
		}
	}

}
