/*
 *  =======================
 *  Permutation of a string
 *  =======================
 *
 *                STATE SPACE TREE OF [A, B, C]
 *                       0
 *          A            B            C
 *        B   C        A   C        B   A
 *      C      B     C      A     A       B
 *    ABC     ACB   BAC    BCA   CBA     CAB    (LEAF NODES)
 *
 *
 *   Getting results by - BACKTRACKING
 *   Finding All possible permutations[A, B, C] - BRUTE FORCE
 *
 *  - Have to use RECURSION to achieve BACKTRACKING
 *  - And with help of BACKTRACKING we perform BRUTE FORCE
 */


#include <stdio.h>


int Perm(char S, int k)
{

}



int main()
 {
    char S[] = "ABC";
    Perm(S, 0);
    return 0;
 }