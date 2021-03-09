#include <iostream>
#include "../include/puzzle.h"
#include "../include/Graph.h"

using namespace std;
int main(){
  
  int initialState[5][5]={{ 3,17, 9, 5,21},
			  {11, 0,13,19,10},
			  { 6,24,22, 1,20},
			  {16,14, 4,12,15},
			  {18, 8,23, 2, 7}};
  
  Puzzle s(initialState);
  Graph g(&s);
  //g.DFS();
  //g.BFS();

  //g.h1();
  g.h2();
  
  return 0;
  
}
