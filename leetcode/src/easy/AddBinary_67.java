package easy;

/**
 * leet problem #67
 * 
 * Given two binary strings a and b, return their sum as a binary string.
 * 
 * @author zongjing
 *
 */
public class AddBinary_67 {
	public static void main(String[] args) {
		String a = "11010";
		String b = "10100101";
		System.out.println(solution(a, b));
	}
	
	public static String solution(String a, String b) {
        boolean carry = false;
        int n;
        String sub;
        if(a.length() > b.length()) {
        	n = b.length();
        	sub = a.substring(0, a.length() - n);
        	a = a.substring(a.length() - n);
        }
        else {
        	n = a.length();
        	sub = b.substring(0, b.length() - n);
        	b = b.substring(b.length() - n);
        }
        StringBuilder result = new StringBuilder();
        for(int i = n - 1; i >= 0; i--) {
        	if(a.charAt(i) == '0' && b.charAt(i) == '0') {
        		if(carry) {
        			result.insert(0, '1');
        			carry = false;
        		}
        		else {
        			result.insert(0, '0');
        		}
        	}
        	else if(a.charAt(i) == '1' && b.charAt(i) == '1') {
        		if(carry) {
        			result.insert(0, '1');
        		}
        		else {
        			result.insert(0, '0');
        			carry = true;
        		}
        	}
        	else {
        		if(carry) {
        			result.insert(0, '0');
        		}
        		else {
        			result.insert(0, '1');
        		}
        	}
        }
        
        if(!carry) {
        	result.insert(0, sub);
        }
        else {
        	int i = sub.length() - 1;
        	while(i >= 0 && sub.charAt(i) == '1') {
        		i--;
        		result.insert(0, '0');
        	}
        	result.insert(0, '1');
        	if(i > 0) {
        		result.insert(0, sub.substring(0, i));
        	}
        }
        
        return result.toString();
    }
}
