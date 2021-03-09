package easy;

/**
 * leet #101
 * 
 * @author zongjing
 *
 */
public class SymmetricTree_101 {
	
	public static void main(String[] args) {
		
	}
	
	// just call the helper method
	public boolean isSymmetric(TreeNode root) {
        return helper(root, root);
    }
	
	// same as sameTree, change left tree and right tree
	public boolean helper(TreeNode p, TreeNode q) {
		
		if(p == null ^ q == null) {
			return false;
		}
		else if(p == null && q == null) {
			return true;
		}
		
        return p.val == q.val && helper(p.left, q.right) && helper(p.right, q.left);
    }
}

