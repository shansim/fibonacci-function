#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag {
    ADD,
    SUB,
    MUL,
    DIV,
    ABS,
    FIB,
    LIT
} TypeTag;

typedef struct Node {
    TypeTag type;
    int value;
    struct Node *left;
    struct Node *right;
} Node;

#define MAXN 100
int fib[MAXN];

// Function to create a new node with value and type
Node* makeNode(TypeTag type, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->type = type;
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to calculate the value of a node
int calc(Node* node) {
    if (node->type == ADD) {
        return calc(node->left) + calc(node->right);
    }
    else if (node->type == SUB) {
        return calc(node->left) - calc(node->right);
    }
    else if (node->type == MUL) {
        return calc(node->left) * calc(node->right);
    }
    else if (node->type == DIV) {
        return calc(node->left) / calc(node->right);
    }
    else if (node->type == ABS) {
        return abs(calc(node->left));
    }
    else if (node->type == FIB) {
        return fibonacci(calc(node->left));
    }
    else if (node->type == LIT) {
        return node->value;
    }
    printf("Invalid node type %d\n", node->type);
    exit(1);
}

// Fibonacci function using dynamic programming
int fibonacci(int n) {
    if (n <= 1)
        return n;

    if (fib[n] != -1)
        return fib[n];

    fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}

// Macro to define function-like syntax for creating nodes
#define makeFunc(type) \
    ({ \
        Node* _func(int a, int b) { \
            Node* newNode = makeNode(type, 0); \
            newNode->left = makeNode(LIT, a); \
            newNode->right = makeNode(LIT, b); \
            return newNode; \
        } \
        _func; \
    })

// Macro to define function-like syntax for creating value nodes
#define makeValue(value) makeNode(LIT, value)

int main() {
    int i;
    for (i = 0; i < MAXN; i++) {
        fib[i] = -1;
    }

    Node *add = (*makeFunc(ADD))(10, 6);
    Node *mul = (*makeFunc(MUL))(5, 4);
    Node *sub = (*makeFunc(SUB))(calc(add),calc(mul));
    Node *fibo = (*makeFunc(SUB))(abs(calc(sub)),fibonacci(abs(calc(sub))));

    printf("add : %d\n", calc(add));
    printf("mul : %d\n", calc(mul));
    printf("sub : %d\n", calc(sub));
    printf("fibo : %d\n", calc(fibo));

    return 0;
}

