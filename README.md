# quiz-2-strukdat

### Note
Due to some syntax, this program requires C++11 or above for it to run properly.

## Problem 1
1. Write a recursive function to print the depth-first traversal of a tree, i.e., choosing left
branches first. [5 points]

### Solution
#### Completed by Mathias Adya Diwangkara Suganda - 5025231015
Reading from the problem statement, we can use Post-Order traversal where we traverse the tree from its left branches first then to the right by using recursion. Then we need to print the node's value after the traversal from leaves to root.

```cpp
void printDepthFirst (Node *root) {
    if (root != nullptr) {
		printDepthFirst(root -> left);
		printDepthFirst(root -> right);
		printf("%d ", root -> data);
	}
}
```
By simply checking if the root isn't NULL, we can know that the root has a value so there won't be any errors while printing the value
Output:
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/a89e975e-0356-4126-8f7c-7d833fc47a69)

Time Complexity: O(Number of Nodes)

## Problem 2
2. Write a recursive function to print all nodes at the k-th level in the binary tree. [5 points]
### Solution
#### Completed by Gerry Nicholas - 5025231017
With the structure of the function requested by the problem being `void printKthLevel(Node *root, int k)`, it can be difficult to know which level the node root parameter is. To solve this issue, we can use the `static` keyword where it declares the variable only once and the value of the variable will be retained between function calls. we can declare a static variable named lvl (`static int lvl = 0;`) to keep track of the level of the node that the `Node *root` is in. 
```cpp
void printKthLevel(Node *root, int k) {
	static int lvl = 0; // first declaration of lvl will be lvl = 0, after this declaration, the value of lvl will be retained between function calls
	if (root) { // check if the node actually exists
		if (lvl == k) {
			printf("%d ", root->data); // print the value of the node if the level of the node is equal to k
		} else {
			lvl++; // reminder that we need to manually add and subtract the level when we traverse to other nodes
			printKthLevel(root->left, k);
			printKthLevel(root->right, k);
			lvl--;
		}
	}
}
```
![prob-2-bst](./images/prob-2-bst.png)
For problem 2, the current binary search tree will look like the image above

Running program:
![prob-2](./images/prob-2.png)
Time Complexity: O(Number of Nodes)

## Problem 3
3. Write a recursive function to calculate the sum of all nodes in the binary tree. [5 points]
int sumOfNodes(Node *root)

### Solution
#### Completed by Mathias Adya Diwangkara Suganda - 5025231015
To solve this problem, we can assume that every root has atleast one child, the recursive goes from getting the root's value, then add with its children values. 

```cpp
int sumOfNodes(Node *root) {
    if (root==nullptr) return 0;
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}
```
Now when the root is equal to null, we can assume that its value is 0 since there is no root to begin with. That is the base case of the recursion. 
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/f925952d-ed38-4108-bc11-871bcaa025a1)

Time Complexity: O(Number of Nodes)

## Problem 4
4. Write a recursive function which multiplies by three every node of the tree. [5 points]
void triple(Node *root)

### Solution
#### Completed by Mathias Adya Diwangkara Suganda - 5025231015
Since the parameter of the function is pointer, meaning if we want to alternate or change a value from the root simply call ```triple(root)```.
To solve this problem we simply just need to traverse the root and multiply every node that we visit with the value 3.

```cpp
void triple (Node *root) {
    if (root == nullptr) return;
    root->data*=3;
    triple(root->left);
    triple(root->right);
}
```
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/c770707c-591a-4fcf-bffe-1246e6d77818)

Time Complexity: O(Number of Nodes)

## Problem 8
8. Write a recursive function to find the parent node of a given child data. [20 points]
### Solution
#### Completed by Gerry Nicholas - 5025231017
![prob-8-bst](./images/prob-8-bst.png)
For problem 8, the current binary search tree will look like the image above
![prob-8](./images/prob-8.png)
## Problem 9
9. Write a recursive function to find the children node of a given parent data. [20 points]
### Solution
#### Completed by Gerry Nicholas - 5025231017
![prob-8-bst](./images/prob-8-bst.png)
For problem 9, the current binary search tree will look like the image above
![prob-9](./images/prob-9.png)