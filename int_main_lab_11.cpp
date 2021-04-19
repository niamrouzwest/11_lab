#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <iostream>
#include "lab_11.h"

int main() {
    char s[40];
    PNode_t Tree;
    printf("Vvedite vash primer: ");
    gets_s(s);
    Tree = MakeTree(s, 0, strlen(s) - 1);
    printf("\nOtvet = %f \n\n", CalcTree(Tree));
    printf("Visota dereva: %d\n", maxDepth(Tree));
    printf("\nKolicestvo uzlov dereva: %d\n", NodeCount(Tree));
    printf("\nObhodi:\n");
    printf("LPK: ");
    LPK(Tree);
    printf("\n");
    printf("KLP: ");
    KLP(Tree);
    printf("\n");
    printf("LKP: ");
    LKP(Tree);
    printf("\n");
    print_Tree(Tree, 0);
    return 0;
}
