#include <stdio.h>
#include <stdlib.h>
#define newline printf("\n\n")
using namespace std;

typedef struct MyNode {
	int data;
	struct MyNode *left;
	struct MyNode *right;
} Node;

Node *node;

void init() {
	node = nullptr;
}

void clear(Node **node) {
	*node = nullptr;
}

int isEmpty(Node *node) {
	if (node == nullptr) return 1;
	else return 0;
}

void insert(Node **root, int newData) {
	if ((*root) == nullptr) {
		Node *newNode;
		newNode = new Node;
		newNode -> data = newData;
		newNode -> left = nullptr;
		newNode -> right = nullptr;
		(*root) = newNode;
		(*root) -> left = nullptr;
		(*root) -> right = nullptr;
		printf("%d has been inserted by insert()\n", newData);
	} else if (newData < (*root) -> data) {
		insert(&(*root) -> left, newData);
	} else if (newData > (*root) -> data) {
		insert(&(*root) -> right, newData);
	} else if (newData == (*root) -> data) {
		printf("%d has existed in the tree\n", newData);
	}
}

void preOrder(Node *root) {
	if (root != nullptr) {
		printf("%d ", root -> data);
		preOrder(root -> left);
		preOrder(root -> right);
	}
}

void inOrder(Node *root) {
	if (root != nullptr) {
		inOrder(root -> left);
		printf("%d ", root -> data);
		inOrder(root -> right);
	}
}

void postOrder(Node *root) {
	if (root != nullptr) {
		postOrder(root -> left);
		postOrder(root -> right);
		printf("%d ", root -> data);
	}
}

typedef struct myQNode {
	Node *node;
	myQNode *next;
} QNode;

typedef struct myQueue {
	QNode *front;
	QNode *rear;
} Queue;

Queue *createQ() {
	Queue *queue = new Queue;
	queue -> front = nullptr;
	queue -> rear = nullptr;
	return queue;
}

int isEmptyQ(Queue *queue) {
	return queue -> front == nullptr;
}

void enQueue(Queue *queue, Node *newNode) {
	QNode *qNode;
	qNode = new QNode;
	qNode -> node = newNode;
	qNode -> next = nullptr;
	if (isEmptyQ(queue)) {
		queue -> front = qNode;
		queue -> rear = qNode;
	} else {
		queue -> rear -> next = qNode;
		queue -> rear = qNode;
	}
}

Node *deQueue(Queue *queue) {
	if (isEmptyQ(queue)) {
		printf("Queue is empty.\n");
		return nullptr;
	}
	QNode *temp = queue -> front;
	Node *node = temp -> node;
	queue -> front = queue -> front -> next;
	free(temp);
	return node;
}

Node *getFront(Queue *queue) {
    if (queue -> front == nullptr) {
        printf("Queue is empty.\n");
        return nullptr;
    }
    return queue -> front -> node;
}

void levelOrder(Node *root) {
    if (root == nullptr) {
        printf("Tree is empty.\n");
        return;
    }
    Queue *queue = new Queue;
	queue = createQ();
    enQueue(queue, root);
    while (!isEmptyQ(queue)) {
        Node *n = getFront(queue);
        // Visit the node
        printf("%d ", n -> data);
        if (n -> left != nullptr) {
        	// Enqueue left child if exists
            enQueue(queue, n -> left);
        }
        if (n -> right != nullptr) {
        	// Enqueue right child if exists
            enQueue(queue, n -> right);
        }
        // Dequeue the processed node
        deQueue(queue);
    }
}

Node *search(Node *root, int data) {
	if (root == nullptr) {
		printf("%d cannot be found by search()\n", data);
		return nullptr;
	} else if (data < root -> data) {
		return search(root -> left, data);
	} else if (data > root -> data) {
		return search(root -> right, data);
	} else if (data == root -> data) {
		printf("%d has been found by search()\n", data);
		return root;
	}
}

int count(Node *root) {
	if (root == nullptr) {
		return 0;
	} else {
		return count(root -> left) + count(root -> right) + 1;
	}
}

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

Node *min(Node *root) {
	if (root == nullptr) {
		return nullptr;
	} else if (root -> left == nullptr) {
		return root;
	} else {
		return min(root -> left);
	}
}

Node *max(Node *root) {
	if (root == nullptr) {
		return nullptr;
	} else if (root -> right == nullptr) {
		return root;
	} else {
		return max(root -> right);
	}
}

void leaf(Node *root) {
	if (root == nullptr) {
		printf("Tree is empty.\n");
	}
	if (root -> left != nullptr) {
		leaf(root -> left);
	}
	if (root -> right != nullptr) {
		leaf(root -> right);
	}
	if (root -> left == nullptr && root -> right == nullptr) {
		printf("%d ", root -> data);
	}
}

//soal 1
void printDepthFirst (Node *root) {
    if (root != nullptr) {
		printDepthFirst(root -> left);
		printDepthFirst(root -> right);
		printf("%d ", root -> data);
	}
}

// soal 2
void printKthLevel(Node *root, int k) {
	static int lvl = 0;
	if (root) {
		if (lvl == k) {
			printf("%d ", root->data, lvl);
		} else {
			lvl++;
			printKthLevel(root->left, k);
			printKthLevel(root->right, k);
			lvl--;
		}
	}
}

// soal 3
int sumOfNodes(Node *root) {
    if (root==nullptr) return 0;
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

//soal 4
void triple (Node *root) {
    if (root == nullptr) return;
    root->data*=3;
    triple(root->left);
    triple(root->right);
}

//soal 5
void mirror (Node *root) {
    if (root == nullptr) return;
    Node *tmp;
    tmp=nullptr;
    mirror(root->left);
    mirror(root->right);
    tmp=root->left;
    root->left=root->right;
    root->right=tmp;
}

// soal 8
Node *findParent(Node *root, int *childData) {
	static Node *parent = root;
	static bool flag = 0;
	if(root) {
		// printf("%d %d\n", root->data, *childData);
		if(root->data == *childData) {
			flag = 1;
		}
		if(!flag){
			parent = root;
			if(*childData < root->data) {
				// printf("left\n");
				findParent(root->left, childData);
			} else if(*childData > root->data) {
				// printf("right\n");
				findParent(root->right, childData);
			}
		}
	}
	return parent;
}

int main() {
	printf("Create a root, it's an empty node...\n");
	Node *root;
	root = nullptr;
    printf("Clear the tree ...\n");
	clear(&root);
	printf("Build a tree ...\n");
	insert(&root, 6);
	insert(&root, 3);
	insert(&root, 10);
	insert(&root, 1);
	insert(&root, 5);
	insert(&root, 7);
	insert(&root, 8);
	insert(&root, 9);

	// Soal Quiz
	// soal 1
	newline;
	printDepthFirst(root);
	newline;

	// soal 2
	printf("Input for Kth level nodes (input for k): ");
    int k;scanf("%d", &k);
    printf("Printing Kth level nodes: ");
    printKthLevel(root, k);
	newline;

	// soal 3
    int sum=sumOfNodes(root);
    printf("The sum of current nodes: %d",sum);
	newline;

	// soal 4
    triple(root);
    sum=sumOfNodes(root);
    printf("The sum of current nodes: %d",sum);
	newline;

	// soal 5
    printf("Mirroring tree\nPrinting Depth First Traversal of the mirrored tree: \n");
    mirror(root);
    printDepthFirst(root);
	newline;

	mirror(root);

	// soal 8
	printf("Enter Child Data: ");
	int child_data; scanf("%d", &child_data);
	Node* parent_node = findParent(root, &child_data);
	printf("%d", parent_node->data);
	newline;
 	return 0;
}
