package medium;


/**
 * leet #5
 * 
 * @author zongjing
 *
 */
public class LongestPString_05 {
	public static void main(String[] args) {
		String s = "a";
		String s1 = "aaa";
		String s2 = "aba";
		String s3 = "abb";
		String s4 = "abadacad";
		String s6 = "abcdefGFedcba";
		System.out.println(longestPalindrome(s));
		System.out.println(longestPalindrome(s1));
		System.out.println(longestPalindrome(s2));
		System.out.println(longestPalindrome(s3));
		System.out.println(longestPalindrome(s4));
		System.out.println(longestPalindrome(s6));

	}
	
	public static String longestPalindrome(String s) {
        if(s.length() == 1) {
        	return s;
        }
        
        String result = s.substring(0, 1);
        
        int rightPointer = 1;
        int leftPointer = 0;
        int maxLen = 1;
        
        // use right pointer to retrive the whole string
        while(rightPointer < s.length()) {
        	
        	//if we find two sequential chars are equal, this is the smallest palindrome.
        	//we can extend this palidrome by decrease left and increase right index. 
        	if(s.charAt(rightPointer) == s.charAt(leftPointer)) {
        		int left = leftPointer;
        		int right = rightPointer;
        		
        		//if two chars are equal, compare the lenth with the maxLen and store if it is longer.
        		while (right < s.length() && left >= 0 && s.charAt(right) == s.charAt(left)) {
        			if(right - left + 1 > maxLen) {
        				result = s.substring(left , right + 1);
        				maxLen = right - left + 1;
        			}
        			left--;
        			right++;
        		}        		
        	}
        	
        	//make right pointer add 1 and repeat previous procedure for the case like "aba"
    		rightPointer ++;  
    		if(rightPointer >= s.length()) {
    			break;
    		}
    		if(s.charAt(rightPointer) == s.charAt(leftPointer)) {
        		int left = leftPointer;
        		int right = rightPointer;
        		
        		while (right < s.length() && left >= 0 && s.charAt(right) == s.charAt(left)) {
        			if(right - left + 1 > maxLen) {
        				result = s.substring(left , right + 1);
        				maxLen = right - left + 1;
        			}
        			left--;
        			right++;
        		}        		
        	}	
    		leftPointer ++;        	
        }
        
        return result;
    }
}
