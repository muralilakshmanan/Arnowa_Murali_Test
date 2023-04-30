#include <stdio.h>
#include <stdlib.h>

#define MAX_N 20

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int sum(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->value + sum(node->left) + sum(node->right);
}

void printTree(Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->value);
    printTree(root->left);
    printTree(root->right);
}

void printValidTrees(int* arr, int n) {
    if (n == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        Node* root = newNode(arr[i]);
        int leftSum = 0;
        for (int j = 0; j < i; j++) {
            Node* leftSubtree = newNode(arr[j]);
            root->left = leftSubtree;
            leftSum += arr[j];
            int rightSum = 0;
            for (int k = i+1; k < n; k++) {
                Node* rightSubtree = newNode(arr[k]);
                root->right = rightSubtree;
                rightSum += arr[k];
                if (sum(root->right) > sum(root->left)) {
                    printTree(root);
                    printf("\n");
                }
                root->right = NULL;
            }
            root->left = NULL;
        }
        if (leftSum == 0 || sum(root->right) > sum(root->left)) {
            printTree(root);
            printf("\n");
        }
        free(root);
    }
}

int main() {
    int n, arr[MAX_N];
    printf("Enter the size of the array (up to %d): ", MAX_N);
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Valid binary trees:\n");
    printValidTrees(arr, n);

    return 0;
}
