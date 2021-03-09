#ifndef PUZZLE_H
#define PUZZLE_H

#include <iostream>
#include <iomanip>
using namespace std;

class Puzzle {
  int goalState[5][5]={{1 , 2, 3, 4, 5},
		       { 6, 7, 8, 9,10},
		       {11,12,13,14,15},
		       {16,17,18,19,20},
		       {21,22,23,24,0}};
  
      
  void swap(int x1, int y1, int x2, int y2){
    int temp= currentState[x1][y1];
    currentState[x1][y1]=currentState[x2][y2];
    currentState[x2][y2]=temp;
  }
  
public:
  int currentState[5][5];
  //w is for white. White is an undiscorved puzzle state 
  char color='w';
  
  Puzzle(int cs[][5]){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	currentState[i][j]=cs[i][j];
      }
    }
  }

  bool isGoalState(){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	if(currentState[i][j]!=goalState[i][j])
	  return false;
      }
    }
    return true;
  }

  void printState(){
      string line = "|--- --- --- ---";
      cout<<line;
      for(int i=0;i<5;i++){
	cout<<"|"<<endl<<"|";
	for(int j=0;j<5;j++){
	  cout<<setfill('0')<<setw(2);
	  cout<<currentState[i][j]<<" ";
	}
      }
      cout<<"|"<<endl<<line<<"|"<<endl;
  }

  int getBlankX(){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	if(currentState[i][j]==0){
	  //cout<<"Found at ("<<i<<","<<j<<")"<<endl;
	  return i;
	}
      }
    }
    return -1;
  }

  int getBlankY(){
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	if(currentState[i][j]==0){
	  //cout<<"Found at ("<<i<<","<<j<<")"<<endl;
	  return j;
	}
      }
    }
    return -1;
  }

  int getValueAt(int x, int y){
    if(x<=4&&x>=0 &&
       y<=4&&y>=00)
      return currentState[x][y];
    else
      return -1;
  }

  //moves the blank space left
  int moveLeft(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x,y-1)==-1)
      return -1; //invalid move
    else{
      swap(x,y,x,y-1);
    }
    return 0;
  }

  bool canMoveLeft(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x,y-1)==-1)
      return false; //invalid move
    return true;
  }
  bool canMoveRight(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x,y+1)==-1)
      return false; //invalid move
    return true;
  }
  bool canMoveUp(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x-1,y)==-1)
      return false; //invalid move
    return true;
  }
  bool canMoveDown(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x+1,y)==-1)
      return false; //invalid move
    return true;
  }

  int moveUp(){
    int x=getBlankX();
    int y=getBlankY();
    if(getValueAt(x-1,y)==-1)
      return -1; //invalid move
    else{
      swap(x,y,x-1,y);
    }
    return 0;
  }
  
  int moveRight(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x,y+1)==-1)
      return -1; //invalid move
    else{
      swap(x,y,x,y+1);
    }
    return 0;
  }

  int moveDown(){
    int x=getBlankX();
    int y=getBlankY();

    if(getValueAt(x+1,y)==-1)
      return -1; //invalid move
    else{
      swap(x,y,x+1,y);
    }
    return 0;
  }

  //returns the state of the puzzle after a move
  Puzzle leftChild(){
    Puzzle v(currentState);
    v.moveLeft();
    return v;
  }
  Puzzle rightChild(){
    Puzzle v(currentState);
    v.moveRight();
    return v;
  }
  Puzzle upChild(){
    Puzzle v(currentState);
    v.moveUp();
    return v;
  }
  Puzzle downChild(){
    Puzzle v(currentState);
    v.moveDown();
    return v;
  }

  bool operator==(const Puzzle &b)const {
    for(int i=0;i<5;i++){
      for(int j=0;j<5;j++){
	if(currentState[i][j]!=b.currentState[i][j])
	  return false;
      }
    }
    return true;
  }
};

#endif 
