#include<stdio.h>
#include <string.h>
#include<stdbool.h> 
#define INF 9999999
#define V 9
int G[V][V] = {
  {0, 4, 0, 0, 0, 0, 0, 8, 0},
  {4, 0, 8, 0, 0, 0, 0, 11, 0},
  {0, 8, 0, 7, 0, 4, 0, 0, 2},
  {0 , 0, 7, 0, 9, 14, 0, 0, 0},
  {0, 0, 0, 9, 0, 10, 0, 0, 0},
  {0, 0, 4, 14, 10, 0, 2, 0, 0},
  {0, 0, 0, 0, 0, 2, 0, 1, 6},
  {8, 11, 0, 0, 0, 0, 1, 0, 7},
  {0, 0, 2, 0, 0, 0, 6, 7, 0}};
int main() {
  int no_edge,i,j;  
  int selected[V];
  memset(selected, false, sizeof(selected));
  no_edge = 0;
  selected[0] = true;

  int x;  
  int y;  
  printf("Edge : Weight\n");

  while (no_edge < V - 1) {
    int min = INF;
    x = 0;
    y = 0;
    for (i = 0; i < V; i++) {
      if (selected[i]) {
        for (j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) {  
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    selected[y] = true;
    no_edge++;
  }
  return 0;
}
/*
Time Complexity analysis
    Best Case: O(E*log V)
    Worst Case: O((V+E)*log V)
    Average Case: O((V+E)*log V),
    where E is the no. of edges and V is the no. of vertices
*/
