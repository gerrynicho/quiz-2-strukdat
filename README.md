![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/600f87e5-720a-4808-a648-070590e4d35d)# quiz-2-strukdat

### Problem 1
1. Write a recursive function to print the depth-first traversal of a tree, i.e., choosing left
branches first. [5 points]

### Solution
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
By simply checking if the root isn't NULL, we can know that the root has value so there won't be any errors while printing the value
Output:
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/a89e975e-0356-4126-8f7c-7d833fc47a69)

Time Complexity: O(Number of Nodes)

### Problem 3
3. Write a recursive function to calculate the sum of all nodes in the binary tree. [5 points]
int sumOfNodes(Node *root)

### Solution
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

### Problem 4
4. Write a recursive function which multiplies by three every node of the tree. [5 points]
void triple(Node *root)

### Solution
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
