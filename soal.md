# Soal 1
Write a recursive function to print the depth-first traversal of a tree, i.e., choosing left
branches first.
```c
void printDepthFirst(Node *root)
```

# Soal 2
Write a recursive function to print all nodes at the k-th level in the binary tree. [5 points]
```c
void printKthLevel(Node *root, int k)
```

# Soal 3
Write a recursive function to calculate the sum of all nodes in the binary tree. [5 points]
```c
int sumOfNodes(Node *root)
```

# Soal 4
Write a recursive function which multiplies by three every node of the tree. [5 points]
```c
void triple(Node *root)
```

# Soal 5
Write a recursive function to create a mirror image of the binary tree. [5 points]
```c
void mirror(Node *root)
```

# Soal 6
Write a recursive function to check if the binary tree is height-balanced (the difference
between the heights of the left and right subtrees of any node is not more than 1). [5 points]
```c
int isBalancedHelper(Node *root)
```
You may use the following helper function:
```c
int isBalancedHelper(Node *root)
```
Where you utilise the function int height(Node *root) that is already defined in 04treeQFull.cpp

# Soal 7
Write a recursive function to delete a particular data. [20 points]
```c
Node *delNode(Node *root, int delData)
```
You may use the following helper function:
```c
Node *minValueNode(Node *node)
```
Where you find the minimum value of the node from the tree.

# Soal 8
Write a recursive function to find the parent node of a given child data. [20 points]
```c
Node *findParent(Node *root, int *childData)
```

# Soal 9
Write a recursive function to find the children node of a given parent data. [20 points]
```
Node *findChild(Node *root, int parentData)
```
Where you utilise the function `Node *search(Node *root, int data)` that
already defined in 04treeQFull.cpp

# Soal 10
Write a recursive function to convert the binary tree to a doubly linked list in place. The
left pointer of the tree should act as the previous pointer and the right pointer should act
as the next pointer. [10 points]
Node *convertToDLL(Node *root)
You may use the following helper function:
void convertToDLLHelper(Node *root, Node **head, Node **prev)
You may also use the following function for DLL PreOrder traversal:
```c
void preOrderDLL(Node *head) {
    Node *current = head;
    while (current != nullptr) {
        printf("%d ", current->data);
        current = current->right;
    }
}
```

Form a group of max 3 students, then make a report, the content is as follows:
• Algorithms/methods,
• Source codes,
• The running results and analysis of your programs.