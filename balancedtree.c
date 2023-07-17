#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

struct Node* createNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

    return y;
}

int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));

    int balance = getBalanceFactor(node);

    // Left Left Case
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;

            free(temp);
        } else {
            struct Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    int balance = getBalanceFactor(root);

    // Left Left Case
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void displayPreOrder(FILE* outputFile, struct Node* root) {
    if (root != NULL) {
        fprintf(outputFile, "%d ", root->key);
        displayPreOrder(outputFile, root->left);
        displayPreOrder(outputFile, root->right);
    }
}

void displayInOrder(FILE* outputFile, struct Node* root) {
    if (root != NULL) {
        displayInOrder(outputFile, root->left);
        fprintf(outputFile, "%d ", root->key);
        displayInOrder(outputFile, root->right);
    }
}

void displayPostOrder(FILE* outputFile, struct Node* root) {
    if (root != NULL) {
        displayPostOrder(outputFile, root->left);
        displayPostOrder(outputFile, root->right);
        fprintf(outputFile, "%d ", root->key);
    }
}

int main() {
    struct Node* root = NULL;
    int numNodes, i, s, e, key;

    // Seed the random number generator
    srand(time(NULL));

    FILE* inputFile = fopen("input.txt", "r");
    FILE* outputFile = fopen("output.txt", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    fscanf(inputFile, "%d%d", &s, &e);
    fscanf(inputFile, "%d", &numNodes);

    // Generate random numbers and insert them into the AVL tree
    fprintf(outputFile, "Generated Numbers: ");
    for (i = 0; i < numNodes; i++) {
        key = rand() % (e - s + 1) + s;
        fprintf(outputFile, "%d ", key);
        root = insert(root, key);
    }
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Pre-order traversal of the AVL tree: ");
    displayPreOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "In-order traversal of the AVL tree: ");
    displayInOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Post-order traversal of the AVL tree: ");
    displayPostOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fscanf(inputFile, "%d", &key);
    root = deleteNode(root, key);

    fprintf(outputFile, "Pre-order traversal after deleting %d: ", key);
    displayPreOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "InOrder traversal after deleting %d: ", key);
    displayInOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Postorder traversal after deleting %d: ", key);
    displayPostOrder(outputFile, root);
    fprintf(outputFile, "\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
