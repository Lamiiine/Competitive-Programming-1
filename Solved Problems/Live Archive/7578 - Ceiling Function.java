import java.util.*;
public class Main
{
	public static int n;
	public static int k;
	public static Node[] arr;
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext())
		{
			n = sc.nextInt();
			k = sc.nextInt();
			arr = new Node[n];
			for (int i = 0; i < n; ++i)
			{
				arr[i] = new Node();
				for (int j = 0; j < k; ++j)
				{
					arr[i].insert(sc.nextInt());
				}
			}
			
			int ans = 0;
			for (int i = 0; i < n; ++i)
			{
				boolean flag = true;
				for (int j = 0; j < i; ++j)
				{
					if (arr[i].equals(arr[j]))
					{
						flag = false;
						break;
					}
				}
				
				if (flag) ++ans;
			}
			
			System.out.println(ans);
		}
	}
	
	public static class Node
	{
		Node left;
		Node right;
		int value;
		public Node()
		{
			this.value = -1;
			this.left = this.right = null;
		}
		public boolean isEmpty()
		{
			return this.value == -1;
		}
		public void insert(final int val)
		{
			if (this.isEmpty())
			{
				this.value = val;
				this.left = new Node();
				this.right = new Node();
			}
			else if (this.value < val)
			{
				this.right.insert(val);
			}
			else
			{
				this.left.insert(val);
			}
		}
		public boolean equals(Node other)
		{
			if (this.isEmpty() && other.isEmpty()) return true;
			if (this.isEmpty() || other.isEmpty()) return false;
			return this.left.equals(other.left) && this.right.equals(other.right);
		}
	}
}
/*
5 3
2 7 1
3 1 4
1 5 9
2 6 5
9 7 3
3 4
3 1 2 40000
3 4 2 1
33 42 17 23
*/
