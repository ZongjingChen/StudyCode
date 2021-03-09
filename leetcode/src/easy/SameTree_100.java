package easy;

/**
 * leet #100
 * 
 * @author zongjing
 *
 */
public class SameTree_100 {
	
	public static void main(String[] args) {
		
	}
	
	//recursion
	public boolean isSameTree(TreeNode p, TreeNode q) {
		
		if(p == null ^ q == null) {
			return false;
		}
		else if(p == null && q == null) {
			return true;
		}
		
        return p.val == q.val && isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}
