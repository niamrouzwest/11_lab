#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include "lab_11.h"

int Priority(char c) {
    switch (c) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    }
    return 100;
}

PNode_t MakeTree(char Expr[], int first, int last) {

    int MinPrt, i, k, prt;
    int nest = 0;
    PNode_t Tree = new Node;
    MinPrt = 100;
    for (i = first; i <= last; i++) {
        if (Expr[i] == '(') {
            nest++;
            continue;
        }
        if (Expr[i] == ')') {
            nest--;
            continue;
        }
        if (nest > 0)
            continue;

        prt = Priority(Expr[i]);
        if (prt <= MinPrt) {
            MinPrt = prt;
            k = i;
        }
    }
    if (MinPrt == 100)
        if (Expr[first] == '(' && Expr[last] == ')') {
            free(Tree);
            return MakeTree(Expr, first + 1, last - 1);
        }
        else {
            k = last - first + 1;
            strncpy(Tree->data, Expr + first, k);
            Tree->data[k] = '\0';
            Tree->left = NULL;
            Tree->right = NULL;
            return Tree;
        }
    Tree->data[0] = Expr[k];
    Tree->data[1] = '\0';
    Tree->left = MakeTree(Expr, first, k - 1);
    Tree->right = MakeTree(Expr, k + 1, last);
    return Tree;
}

float CalcTree(PNode_t Tree) {
    float num1, num2;
    if (!Tree->left)
        return atof(Tree->data);
    num1 = CalcTree(Tree->left);
    num2 = CalcTree(Tree->right);
    switch (Tree->data[0]) {
    case '+': return num1 + num2;
    case '-': return num1 - num2;
    case '*': return num1 * num2;
    case '/': return num1 / num2;
    }
    return 0;
}

void LPK(PNode_t Tree)
{
    if (Tree)
    {
        LPK(Tree->left);
        LPK(Tree->right);
        printf("%s ", Tree->data);
    }
}

void KLP(PNode_t Tree)
{
    if (Tree)
    {
        printf("%s ", Tree->data);
        KLP(Tree->left);
        KLP(Tree->right);
    }
}

void LKP(PNode_t Tree)
{
    if (Tree)
    {
        LKP(Tree->left);
        printf("%s ", Tree->data);
        LKP(Tree->right);
    }
}



int maxDepth(struct Node* Tree)
{
    if (Tree == NULL)
        return 0;
    else
    {

        int lDepth = maxDepth(Tree->left);
        int rDepth = maxDepth(Tree->right);


        if (lDepth > rDepth)
            return(lDepth + 1);
        else return(rDepth + 1);
    }
}

int NodeCount(struct Node* Tree)
{
    if (Tree->left == NULL && Tree->right == NULL)
        return 1;
    int left, right;
    if (Tree->left != NULL)
        left = NodeCount(Tree->left);
    else
        left = 0;
    if (Tree->right != NULL)
        right = NodeCount(Tree->right);
    else
        right = 0;

    return left + right + 1;
}

void print_Tree(PNode_t tree, int level)
{
    if (tree)
    {
        print_Tree(tree->left, level + 1);
        for (int i = 0; i < level; i++) std::cout << "   ";
        std::cout << tree->data << std::endl;
        print_Tree(tree->right, level + 1);
    }
}

void DeleteTree(struct Node* Tree)
{
    DeleteTree(Tree->left);
    DeleteTree(Tree->right);
    delete Tree;
}
