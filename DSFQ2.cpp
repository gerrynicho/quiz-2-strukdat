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
	return nullptr;
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

// Problem 1
void printDepthFirst (Node *root) {
    if (root != nullptr) {
		printDepthFirst(root -> left);
		printDepthFirst(root -> right);
		printf("%d ", root -> data);
	}
}

// Problem 2
void printKthLevel(Node *root, int k) {
	static int lvl = 0;
	if (root) {
		if (lvl == k) {
			printf("%d ", root->data);
		} else {
			lvl++;
			printKthLevel(root->left, k);
			printKthLevel(root->right, k);
			lvl--;
		}
	}
}

// Problem 3
int sumOfNodes(Node *root) {
    if (root==nullptr) return 0;
    return root->data+sumOfNodes(root->left)+sumOfNodes(root->right);
}

// Problem 4
void triple (Node *root) {
    if (root == nullptr) return;
    root->data*=3;
    triple(root->left);
    triple(root->right);
}

// Problem 5
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

Node* getMirroredRoot() {
	static Node* mirrored_root = nullptr; // Declare the mirrored_root variable as a static variable
	extern void mirror(Node*);
	mirror(nullptr);
	return mirrored_root;
}

// Problem 6
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

// Problem 7
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

// Problem 8
Node* findParent(Node* root, int* childData) {
	static Node* parent = nullptr;
	if (root) {
		if(root->data > *childData){
			parent = root;
			findParent(root->left, childData);
		} else if (root->data < *childData) {
			parent = root;
			findParent(root->right, childData);
		} else {
			return parent;
		}
		return parent;
	}
	return nullptr;
}

// Problem 9
Node* findChild(Node* root, int parentData) {
    Node* node = search(root, parentData);
    if (!node) {
        return nullptr;
    }
    Node* res = new Node;
    if(node->left && node->right) {
        res->data = node->left->data;
        res->right = new Node;
        res->right->data = node->right->data;
    } else if(node->left) {
        res->data = node->left->data;
    } else if(node->right) {
        res->data = node->right->data;
    } else {
        delete res;
        res = nullptr;
    }
    return res;
}

// Problem 10
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

Node *convertToDLL(Node *root) {
    Node *head = nullptr;
    Node *prev = nullptr;
    convertToDLLHelper(root, &head, &prev);
    return head;
}

void preOrderDLL(Node *head) {
    Node *current = head;
    while(current != nullptr) {
        printf("%d ", current->data);
        current = current->right;
    }
}


int main() {
	printf("Create a root, it's an empty node...\n");
	Node *root;
	root = nullptr;
    printf("Clear the tree...\n");
	clear(&root);
	printf("Build a tree...\n");
	insert(&root, 6);
	insert(&root, 3);
	insert(&root, 10);
	insert(&root, 1);
	insert(&root, 5);
	insert(&root, 7);
	insert(&root, 8);
	insert(&root, 9);

	// Quiz Problems
	// Problem 1
	printf("\nPrinting depth first traversal of the tree:\n");
	printDepthFirst(root);
	newline;

	// Problem 2
	printf("Input for k-th level nodes: ");
    int k;
	scanf("%d", &k);
    printf("Printing k-th level nodes: ");
    printKthLevel(root, k);
	newline;

	// Problem 3
    int sum = sumOfNodes(root);
    printf("The sum of current nodes: %d", sum);
	newline;

	// Problem 4
	printf("Tripling the value of the nodes...\n");
    triple(root);
    sum = sumOfNodes(root);
    printf("The sum of current nodes: %d", sum);
	newline;

	// Problem 5
    printf("Mirroring tree\nPrinting depth first traversal of the mirrored tree: \n");
    mirror(root);
    printDepthFirst(root);
	newline;

	mirror(root); // unmirror the root

	// Problem 6
	printf("Checking if the tree is balanced...\n");
	if(isBalancedHelper(root)) {
		printf("The tree is balanced");
	}
	else {
		printf("The tree is not balanced");
	}
	newline;

	// Problem 7
	printf("Deleting some nodes of the tree...");
	delNode(root, 3);
	delNode(root, 1);
	newline;

	inOrder(root);
	newline;
	
	// Problem 8
	printf("Enter child data: ");
	int child_data;
	scanf("%d", &child_data);
	Node *parent_node = findParent(root, &child_data);
	if(parent_node) {
		printf("The parent data of the child: %d", parent_node->data);
	} else {
		printf("Node has no parent/No such node");
	}
	newline;

	// Problem 9
	printf("Enter Parent Data: ");
	int parent_data; scanf("%d", &parent_data);
	Node* child_node = findChild(root, parent_data);
	if(child_node) {
		printf("Child Node: %d", child_node->data);
		if(child_node->right) {
			printf("\nSecond Child: %d", child_node->right->data);
		}
	}
	newline;

	// Problem 10
	Node *head = convertToDLL(root);
	preOrderDLL(head);

 	return 0;
}
