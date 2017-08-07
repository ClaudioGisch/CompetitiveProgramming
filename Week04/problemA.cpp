#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <iostream>

#define NMAX 9
#define MAXCANDIDATES 9

#define TRUE  1
#define FALSE 0

using namespace std;

//Back to the 8-Queens | UVa Id:11085
//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=16&page=show_problem&problem=2026

static int solution_count;
int input[NMAX];

void process_solution (int a[], int k, int n)
{
  int i;                        /* counter */
  solution_count++;
}

int is_a_solution (int a[], int k, int n)
{
  return (k == n);
}

void construct_candidates (int a[], int k, int n, int c[], int *ncandidates)
{
  int i, j;                     /* counters */
  int legal_move;              /* might the move be legal? */

  *ncandidates = 0;
  for (i = 1; i <= n; i++)
    {
      legal_move = TRUE;
      for (j = 1; j < k; j++)
        {
          if (abs ((k) - j) == abs (i - a[j]))  /* diagonal threat */
            legal_move = FALSE;
          if (i == a[j])        /* column threat */
            legal_move = FALSE;
        }
      if (legal_move == TRUE)
        {
          c[*ncandidates] = i;
          *ncandidates = *ncandidates + 1;
        }
    }
}

int backtrack (int a[], int k, int n, int moves)
{
  int c[MAXCANDIDATES];         /* candidates for next position */
  int ncandidates;              /* next position candidate count */
  int i;                        /* counter */
  int minMoves = 100;
  if (is_a_solution (a, k, n)){
    process_solution (a, k, n);
    return moves;
  }
  else
    {
      k = k + 1;
      construct_candidates (a, k, n, c, &ncandidates);
      for (i = 0; i < ncandidates; i++)
        {
          int aux = moves;
          if(input[k] != c[i]){
            aux++;
          }
          a[k] = c[i];
          aux = backtrack (a, k, n, aux);
          if(aux < minMoves){
            minMoves = aux;
          }
        }
    }
  return minMoves;
}

int main ()
{
    int a[NMAX];
    int cont = 1;                  /* solution vector */
    while(cin >> input[1]){
        for(int i = 2; i < 9; i++){
            cin >> input[i];
        }
        cout << "Case " << cont << ": " << backtrack (a, 0, 8, 0) << endl;
        cont ++;
    }
}
