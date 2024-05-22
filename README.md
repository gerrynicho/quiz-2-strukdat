# quiz-2-strukdat

### Note
Due to some syntax, this program requires C++11 or above for it to run properly.

## Problem 1
Write a recursive function to print the depth-first traversal of a tree, i.e., choosing left branches first.

### Solution
Reading from the problem statement, post-order traversal can be used to traverse the tree from its left branches first then to the right by using recursion. Then, we need to print the node's value after the traversal from leaves to root.

```cpp
void printDepthFirst (Node *root) {
    if (root != nullptr) {
		printDepthFirst(root -> left);
		printDepthFirst(root -> right);
		printf("%d ", root -> data);
	}
}
```
By simply checking if the root's value is not `nullptr`, we can know that the root has a value so there won't be any errors while printing the value.
Output:
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/a89e975e-0356-4126-8f7c-7d833fc47a69)

Time Complexity: O(Number of Nodes)

## Problem 2
Write a recursive function to print all nodes at the k-th level in the binary tree.

### Solution
With the structure of the function requested by the problem being `void printKthLevel(Node *root, int k)`, it can be difficult to know which level the node root parameter is. To solve this issue, we can use the `static` keyword where it declares the variable only once and the value of the variable will be retained between function calls. We can declare a static variable named `lvl` (`static int lvl = 0;`) to keep track of the level of the node that the `Node *root` is in.
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
For problem 2, the current binary search tree will look like the image above.

Running program:
![prob-2](./images/prob-2.png)
Time Complexity: O(Number of Nodes)

## Problem 3
Write a recursive function to calculate the sum of all nodes in the binary tree.

### Solution
To solve this problem, we can assume that every root has at least one child, the recursive goes from getting the root's value, then add with its children values.

```cpp
int sumOfNodes(Node *root) {
    if (root==nullptr) return 0;
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}
```
Now when the root is equal to `nullptr`, we can assume that its value is 0 since there is no root to begin with. That is the base case of the recursion. 
![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/105376097/f925952d-ed38-4108-bc11-871bcaa025a1)

Time Complexity: O(Number of Nodes)

## Problem 4
Write a recursive function which multiplies by three every node of the tree.

### Solution
Since the parameter of the function is pointer, meaning if we want to alternate or change a value from the root, simply call `triple(root)`.
To solve this problem, we need to traverse the tree and multiply every node that is visited with the value 3.

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

## Problem 6
Write a recursive function to check if the binary tree is height-balanced (the difference between the heights of the left and right subtrees of any node is not more than 1).

### Solution
To check if the tree is balanced or not, a function needs to be created to recursively check both the left and right subtree where the height difference is not more than 1. To check the height, the function will use the `height()` function below.

```cpp
int height(Node *root) {
	if (root == nullptr) {
		return -1;
	}
	int u = height(root -> left);
	int v = height(root -> right);
	if (u > v) {
		return u + 1;
	} else {
		return v + 1;
	}
}
```

Below is the `isBalancedHelper()` function.

```cpp
int isBalancedHelper(Node *root) {
    int left = height(root->left);
    int right = height(root->right);
    if(abs(left - right) <= 1) {
        return 1;
    }
    else {
        return 0;
    }
}
```

It will create two variables which are `left` and `right` where both of the variables will hold the result of the `height()` function for each subtree. It will then check if the difference between `left` and `right` is not more than 1, it will return 1, else it will return 0.

Below is the visualization of the current tree.

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/51798ee3-135e-4dfd-9291-977d07bfbb76)

Because the left subtree and the right subtree have a height difference of more than 1, the tree is not balanced.

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/8c2c2ef9-38e9-4c4f-b0b0-977a84c80f51)

## Problem 7
Write a recursive function to delete a particular data.

### Solution

Below is the implementation of the `delNode()` function.

```cpp
Node *delNode(Node *root, int delData) {
    if(root == nullptr) {
        return nullptr;
    }

    if(delData < root->data) {
        root->left = delNode(root->left, delData);
    }
    else if(delData > root->data) {
        root->right = delNode(root->right, delData);
    }
    else {
        if(root->left == nullptr) {
            Node *temp = root;
            root = root->right;
            free(temp);
        }
	else if(root->right == nullptr) {
            Node *temp = root;
            root = root->left;
            free(temp);
        }
	else {
            Node *temp = min(root->right);
            root->data = temp->data;
            root->right = delNode(root->right, temp->data);
        }
    }
    return root;
}
```

It first will traverse the tree until `root` is pointing to the node holding the data of `delData` using `if(delData < root->data)` and `else if(delData > root->data)`. It can then be going to two results, either the node is not found where it will return nothing from `if(root == nullptr)`, or the node is found where the deletion can begin.

After `root` is already pointing to the node that is going to be deleted, it will check for both the left child and the right child. If the left child is empty, then the right child will replace the position of the current node, but if the right child is empty, then the left child will replace the position of the current node. If both the left child and the right child are not empty, the smallest node in the right subtree (found using the function `min()`) will replace the position of the current node.

After all the `delNode()` function calls in the main program, below is the visualization of the new tree.

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/82291f9a-e387-4d73-974e-e3cfd4dfdd53)

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/71dd5e7c-2bde-4180-89b7-cce36c26db72)

## Problem 8
Write a recursive function to find the parent node of a given child data.

### Solution
![prob-8-bst](./images/prob-8-bst.png)
For problem 8, the current binary search tree will look like the image above.
![prob-8](./images/prob-8.png)

## Problem 9
Write a recursive function to find the children node of a given parent data.
### Solution
![prob-8-bst](./images/prob-8-bst.png)
For problem 9, the current binary search tree will look like the image above
![prob-9](./images/prob-9.png)

## Problem 10
Write a recursive function to convert the binary tree to a doubly linked list in place. The left pointer of the tree should act as the previous pointer and the right pointer should act as the next pointer.

### Solution
To solve this problem, two functions will be used which are `convertToDLL()` and `convertToDLLHelper()`.

```cpp
Node *convertToDLL(Node *root) {
    Node *head = nullptr;
    Node *prev = nullptr;
    convertToDLLHelper(root, &head, &prev);
    return head;
}
```

```cpp
void convertToDLLHelper(Node *root, Node **head, Node **prev) {
    if(root == nullptr) {
        return;
    }

    convertToDLLHelper(root->left, head, prev);

    if(*prev == nullptr) {
        *head = root;
    }
    else {
        root->left = *prev;
        (*prev)->right = root;
    }
    *prev = root;

    convertToDLLHelper(root->right, head, prev);
}
```

`convertToDLL()` here will be used to declare `Node *head` and `Node *prev` as `nullptr` and will call `convertToDLLHelper()` using the previously declared variables. In the `convertToDLLHelper()` function, it will first traverse recursively to the left until the leftmost node using `convertToDLLHelper(root->left, head, prev)`. After that, if the `*prev` value is `nullptr`, it means that `root` is currently pointing to the leftmost node. So the `*head` can be set to the current node. Otherwise, it will link the current node (`*root`) with the previous node (`*prev`) by setting the `left` pointer of the current node to the previous node, and the `right` pointer of the previous node to the current node. `*prev` can then be updated to the current node to keep track of the last processed node. It will then recursively call the `convertToDLLHelper()` function on the right subtree to process nodes on the right.

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/36cf11e2-758a-484f-8d5c-96363c71fadc)

![image](https://github.com/gerrynicho/quiz-2-strukdat/assets/117896200/13dbab78-d31b-4a0f-8ab7-7347fde713c4)
