/*
Gearing Up for Destruction
==========================

As Commander Lambda's personal assistant, you've been assigned the task of configuring the LAMBCHOP doomsday device's axial orientation gears. It should be pretty simple - just add gears to create the appropriate rotation ratio. But the problem is, due to the layout of the LAMBCHOP and the complicated system of beams and pipes supporting it, the pegs that will support the gears are fixed in place.

The LAMBCHOP's engineers have given you lists identifying the placement of groups of pegs along various support beams. You need to place a gear on each peg (otherwise the gears will collide with unoccupied pegs). The engineers have plenty of gears in all different sizes stocked up, so you can choose gears of any size, from a radius of 1 on up. Your goal is to build a system where the last gear rotates at twice the rate (in revolutions per minute, or rpm) of the first gear, no matter the direction. Each gear (except the last) touches and turns the gear on the next peg to the right.

Given a list of distinct positive integers named pegs representing the location of each peg along the support beam, write a function answer(pegs) which, if there is a solution, returns a list of two positive integers a and b representing the numerator and denominator of the first gear's radius in its simplest form in order to achieve the goal above, such that radius = a/b. The ratio a/b should be greater than or equal to 1. Not all support configurations will necessarily be capable of creating the proper rotation ratio, so if the task is impossible, the function answer(pegs) should return the list [-1, -1].

For example, if the pegs are placed at [4, 30, 50], then the first gear could have a radius of 12, the second gear could have a radius of 14, and the last one a radius of 6. Thus, the last gear would rotate twice as fast as the first one. In this case, pegs would be [4, 30, 50] and answer(pegs) should return [12, 1].

The list pegs will be given sorted in ascending order and will contain at least 2 and no more than 20 distinct positive integers, all between 1 and 10000 inclusive.

Languages
=========

To provide a Python solution, edit solution.py
To provide a Java solution, edit solution.java

Test cases
==========

Inputs:
    (int list) pegs = [4, 30, 50]
Output:
    (int list) [12, 1]

Inputs:
    (int list) pegs = [4, 17, 50]
Output:
    (int list) [-1, -1]

Use verify [file] to test your solution and see how it does. When you are finished editing your code, use submit [file] to submit your answer. If your solution passes the test cases, it will be removed from your home folder.
*/

package com.google.challenges; 
import java.math.*;
public class Answer {
    public static final int[] invalid = new int[]{-1, -1};
    public static int[] diff;
    
    public static int gcd(int a, int b)
    {
        return BigInteger.valueOf(a).gcd(BigInteger.valueOf(b)).intValue();
    }
    public static void normalize(int[] arr)
    {
        final int d = gcd(arr[0], arr[1]);
        arr[0] /= d;
        arr[1] /= d;
    }
    public static int[] sub(int[] a, int[] b)
    {
        int[] ans = new int[]{a[0] * b[1] - b[0] * a[1], a[1] * b[1]};
        normalize(ans);
        return ans;
    }
    public static boolean valid(int[] ret)
    {
        return ret[0] >= ret[1] && ret[0] > 0 && ret[1] > 0;
    }
    public static boolean valid_sequence(int[] cur)
    {
        if (!valid(cur))
        {
            return false;
        }
        
        for (int i = 0; i < diff.length; ++i)
        {
            if (!valid(cur = sub(new int[]{diff[i], 1}, cur)))
            {
                return false;
            }
        }
        
        return true;
    }
    public static int[] answer(int[] pegs)
    {
        diff = new int[pegs.length - 1];
        for (int i = 0; i < diff.length; ++i)
        {
            diff[i] = pegs[i + 1] - pegs[i];
        }
        
        int ans = 0;
        for (int i = 0; i < diff.length; ++i)
        {
            if ((i & 1) == 0)
            {
                ans += diff[i]; // add equation
            }
            else
            {
                ans -= diff[i]; // subtract equation
            }
        }
        
        if (ans <= 0)
        {
            return invalid;
        }
        /*
         * Case 1:
         * ans = r1 - r2
         * ans = r1 - 0.5r1
         * r1 = ans * 2
         * Case 2:
         * ans = r1 + r2
         * ans = r1 + 0.5r1
         * r1 = ans * 2 / 3
        */
        int[] ret = new int[]{ans * 2, (diff.length & 1) == 1 ? 3 : 1};
        normalize(ret);
        return valid_sequence(ret) ? ret : invalid;
    }
}

