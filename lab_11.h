#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>

struct Node {
    char data[20];
    struct Node* left, * right;
};
typedef struct Node* PNode_t;


PNode_t MakeTree(char Expr[], int first, int last);
int Priority(char c);
float CalcTree(PNode_t Tree);
void LPK (PNode_t Tree);
void KLP (PNode_t Tree);
void LKP (PNode_t Tree);
int maxDepth(struct Node* Tree);
int NodeCount(struct Node* Tree);
void print_Tree(PNode_t tree, int level);
void DeleteTree(struct Node* Tree);


