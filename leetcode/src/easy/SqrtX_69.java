package easy;

/**
 * leet problem #69
 * 
 * Given a non-negative integer x, compute and return the square root of x.
 * 
 * Since the return type is an integer, the decimal digits are truncated, 
 * and only the integer part of the result is returned.
 * 
 * @author zongjing
 *
 */
public class SqrtX_69 {
	public static void main(String[] args) {
		int x = 3424;
		System.out.println(solution2(x));
	}
	
	// Newton's Method 牛顿迭代法
	// Xn+1 = Xn - f(Xn)/f'(Xn)
	public static int solution(int x) {
		
		double diff = x;
		double guess = x;
		while(diff >= 0.1) {
			double prev = guess;
			guess = guess / 2.0 + x /(2 * guess);
			diff = (int)(prev - guess);
		}
		return (int)guess;
		
		// better solution
//		long n = x;
//		while(n * n > x) {
//			n = (n + x / n)/2;
//		}
//		return (int)n;
	}
	
	//binary search
	public static int solution2(int x) {
		if(x == 0) {
			return 0;
		}
		int left = 1;
		int right = x;
		while(true) {
			int mid = (left + right) / 2;
			if(mid == x / mid) {
				return mid;
			}
			else if(mid > x / mid) {
				right = mid - 1;
			}
			else {
				if(mid + 1 > x / (mid + 1)) {
					return mid;
				}
				left = mid + 1;
			}
		}
	}
}
