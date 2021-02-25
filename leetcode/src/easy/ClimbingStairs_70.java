package easy;

/**
 * leetcode problem #70
 * 
 * You are climbing a staircase. It takes n steps to reach the top.
 * 
 * Each time you can either climb 1 or 2 steps. 
 * In how many distinct ways can you climb to the top?
 * 
 * @author zongjing
 *
 */
public class ClimbingStairs_70 {
	public static void main(String[] args) {
		System.out.println(solution(45));
		System.out.println(solution2(45));
	}
	
	public static int solution(int n) {
		/*
		 * Too time-consuming
		 */
        if(n == 1) {
        	return 1;
        }
        else if (n == 2) {
        	return 2;
        }
        else if(n == 3) {
        	return 3;
        }
        
        else {
        	return solution(n - 1) + solution(n - 2);
        }
    }
	
	// no recursion
	public static int solution2(int n) {
		if(n == 1) {
			return 1;
		}
		
		else {
			int first = 1;
			int second = 2;
			for(int i = 3; i <= n; i++) {
				int third = first + second;
				first = second;
				second = third;
			}
			return second;
		}		
	}
	
	
	
	
	
	
}
