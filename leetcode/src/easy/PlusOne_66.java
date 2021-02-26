package easy;

/**
 * leet problem #66
 * 
 * Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
 * The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
 * You may assume the integer does not contain any leading zero, except the number 0 itself.
 * 
 * @author zongjing
 *
 */
public class PlusOne_66 {
	public static void main(String[] args) {
		
	}
	
	public static int[] solution(int[] digits) {
		
        int i = digits.length - 1;
        digits[i] ++;
        while(i > 0 && digits[i] == 10) {
        	digits[i] = 0; 
        	i--;
        	digits[i]++;
        }
        
        //check if we need one more digit (make a new array)
        if(digits[0] != 10) {
    		return digits;
    	}
        
        //return a new array with all zeros except the first digit is 1.
    	else {
    		int[]result = new int[digits.length + 1];
    		result[0] = 1;
    		return result;
    	}
    }
}
