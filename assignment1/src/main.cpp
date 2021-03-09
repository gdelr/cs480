#include <iostream>
#include <iomanip>

#include "../include/puzzle.h"
#include "../include/Graph.h"

using namespace std;

int main(){
  
  int initialState[5][5]={{ 9,24, 3, 5,17},
			  { 6, 0,13,19,10},
			  {11,21,12, 1,20},
			  {16, 4,14,22,15},
			  { 8,18,23, 2, 7}};
  
  
  /*
  int initialState[5][5]={{1 , 2, 3, 4, 5},
		       { 6, 7, 8, 9,10},
		       {11,12,13,14,15},
		       {16,17,18,19,20},
		       {21,22,23,0,24}};
  
  */
  Puzzle s(initialState);

  Graph g(&s);
  g.DFS();
  //g.BFS();
  
  return 0;
  
}
