# Solve Tree Problems Recursively

- 'Top-down' Solution
- 'Bottom-up' Solution
- Conclusion

## 'Top-down' Solution

'Top-down' means that in each recursion level, we will visit the node first to come up with some values, and pass these values to its children when calling the function recursively. So the 'top-down' solution can be considered as kind of **preorder** traversal (root->left->right). To be specific, the recursion function `top_down(root, params)` works like this:

```cpp
1. return specific value for null value
2. update the answer if needed			// answer <-- params
3. left_ans = top_down(root.left, left_params)	// left_params <-- root.val, params
4. right_ans = top_down(root.right, right_params) //rigth_params <-- root.val, params
5. return the answer if needed 			// answer <-- left_ans, right_ans
```

For instance, consider this problem: given a binary tree, find its maximum depth.

The pseudocode for the recursion function maximum_depth(root, depth):

```cpp
1. return if root is null
2. if root is a leaf node:
3.      answer = max(answer, depth)         // update the answer if needed
4. maximum_depth(root.left, depth + 1)      // call the function recursively for left child
5. maximum_depth(root.right, depth + 1)     // call the function recursively for right child
```

C++ Solution:

```cpp
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
```

## 'Bottom-up' Solution

'Bottom-up' is another recursion solution. In each recursion level, we will firstly call the functions recursively for all the children nodes and then come up with the answer according to the return values and the value of the root node itself. This process can be regarded as kind of postorder traversal. Typicall, a 'bottom-up' recursion function `bottom_up(root)` will be like this:

```cpp
1. return specific value for null node
2. left_ans = bottom_up(root.left)          // call function recursively for left child
3. right_ans = bottom_up(root.right)        // call function recursively for right child
4. return answers                           // answer <-- left_ans, right_ans, root.val
```

Here is the pseudocode for the recursion function `maximum_depth(root)`:

```cpp
1. return 0 if root is null                 // return 0 for null node
2. left_depth = maximum_depth(root.left)
3. right_depth = maximum_depth(root.right)
4. return max(left_depth, right_depth) + 1  // return depth of the subtree rooted at root
```

C++ Solution:

```cpp
int maximum_depth(TreeNode* root) {
	if (!root) {
		return 0;                                 // return 0 for null node
	}
	int left_depth = maximum_depth(root->left);	
	int right_depth = maximum_depth(root->right);
	return max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
}
```

## Conclusion

When you meet a tree problem, ask yourself two questions: 

1. can you determine some parameters to help the node know the answer of itself? 
2. Can you use these parameters and the value of the node itself to determine what should be the parameters parsing to its children?

If the answers are both yes, try to solve this problem using a "top-down" recursion solution.

Or you can think the problem in this way: **for a node in a tree, if you know the answer of its children, can you calculate the answer of the node**? If the answer is yes, solving the problem recursively from bottom up might be a good way.
