/*
 * Don't delete this code
 * Study it!
 */
import java.util.*;

public class Main
{
	public static String line;
	public static int i;
	public static boolean flag;
	public static int get_integer()
	{
		if (i >= line.length() || !Character.isDigit(line.charAt(i))) 
		{
			flag = false;
			return 0;
		}
		int ans = 0;
		while(i < line.length() && Character.isDigit(line.charAt(i)))
		{
			ans = ans * 10 + line.charAt(i++) - '0';
		}
		
		return ans;
	}
	public static int get_factor()
	{
		if (i >= line.length())
		{
			flag = false;
			return 0;
		}
		if (line.charAt(i) == '(')
		{
			++i;
			int ans = get_expression();
			if (!flag)
			{
				return 0;
			}
			if (i >= line.length() || line.charAt(i) != ')')
			{
				flag = false;
				return 0;
			}
			++i;
			return ans;
		}
		else if (Character.isDigit(line.charAt(i)))
		{
			return get_integer();
		}
		else
		{
			flag = false;
			return 0;
		}
	}
	public static int get_expression()
	{
		int ans = get_component();
		if (!flag)
		{
			return 0;
		}
		while(true)
		{
			if (i == line.length())
				break;
			final char c = line.charAt(i);
			if (c == '-')
			{
				++i;
				ans -= get_component();
				if (!flag) return 0;
			}
			else if (c == '+')
			{
				++i;
				ans += get_component();
				if (!flag) return 0;
			}
			else break;
		}
		
		return ans;
	}
	public static int get_component()
	{
		int ans = get_factor();
		if (!flag)
		{
			return 0;
		}
		while(true)
		{
			if (i == line.length())
			{
				break;
			}
			final char c = line.charAt(i);
			if (c == '*')
			{
				++i;
				ans *= get_component();
			}
			else if (c == '/')
			{
				++i;
				ans /= get_component();
			}
			else break;
		}
		return ans;
	}
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int TC = sc.nextInt();
		sc.nextLine();
		while(TC-- > 0)
		{
			flag = true;
			String temp = sc.nextLine();
			StringBuilder s = new StringBuilder();
			for (int i = 0; i < temp.length(); ++i)
			{
				if (!Character.isSpace(temp.charAt(i)))
				{
					s.append(temp.charAt(i));
				}
			}
			
			line = s.toString();
			if (line.isEmpty())
			{
				System.out.println("ERROR");
				continue;
			}
			i = 0;
			final int ans = get_expression();
			System.out.println(flag && i == line.length() ? ans : "ERROR");
		}
	}
}

