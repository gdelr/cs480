#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include "puzzle.h"

using namespace std;

//this class is used as a friend class for comparing two puzzles based on h1
class Puzzle_Compare{
public:
  bool operator()(Puzzle &lhs,Puzzle &rhs){
    if(lhs.numberOfMisplacedTiles() > rhs.numberOfMisplacedTiles())
      return true;
    return false;
  }
};
//this class is used as a friend class for comparing two puzzles based on h2
class Puzzle_CompareH2{
public:
  bool operator()(Puzzle &lhs,Puzzle &rhs){
    if(lhs.numberOfMisplacedTiles() > rhs.numberOfMisplacedTiles())
      return true;
    return false;
  }
};


class Graph{
  queue<Puzzle*> Q;

  //=========================================================
  //This notation is used so that i can use my custom comparators
  //what I am comparing, the underlining data structure, the comparator
  //priority queue for h1
  priority_queue<Puzzle, vector<Puzzle>,Puzzle_Compare>PQ;
  //priority queue for h2
  priority_queue<Puzzle, vector<Puzzle>,Puzzle_CompareH2>PQ2;
  //=========================================================
  
  stack<Puzzle*> S;
  list<Puzzle> foundStates;
  list<Puzzle>::iterator itt;

  list<Puzzle> adj;

public:
  Graph(Puzzle *s){
    //g is for gray. Gray means that a node is known, but not all of its adj notes are
    (*s).color='g';
    Q.push(s);
    S.push(s);
    PQ.push(*s);
    PQ2.push(*s);
  }

  //returns 0 if the goal is found
  int BFS(){
    while(Q.size()!=0){
      //check if the goal is found 
      if((*Q.front()).isGoalState()){
	cout<<"Goal found"<<endl;
	(*Q.front()).printState();
	return 0;
      }
      else{
	//if the goal is not discover the next node in the queue

//checks the adj nodes and add them to the Queue if they are not there
//------------------------------------------------------------------------------------	
	if((*Q.front()).canMoveUp()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*Q.front()).upChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    Q.push(temp);
	    cout<<"Queue Size: "<<Q.size()<<endl;
	  }
	}
        if((*Q.front()).canMoveDown()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*Q.front()).downChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    Q.push(temp);
	    cout<<"Queue Size: "<<Q.size()<<endl;
	  }
	}
	if((*Q.front()).canMoveLeft()){
	  bool found=false;

	  Puzzle *temp=new Puzzle((*Q.front()).leftChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    Q.push(temp);
	    cout<<"Queue Size: "<<Q.size()<<endl;
	  }
	}
	if((*Q.front()).canMoveRight()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*Q.front()).rightChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    Q.push(temp);
	    cout<<"Queue Size: "<<Q.size()<<endl;
	  }
	}
//------------------------------------------------------------------------------------
	
	(*Q.front()).printState();
	//the current node is discoverd and is added to the list of known nodes
	foundStates.push_back((*Q.front()));
	//removes current node
	Q.pop();
	cout<<"List Size: "<<foundStates.size()<<endl;
	cout<<"Queue Size: "<<Q.size()<<endl;
	
      }
    }
    return -1;
  }


  int DFS(){
    while(S.size()!=0){
      //check if the goal is found 
      if((*S.top()).isGoalState()){
	cout<<"Goal found"<<endl;
	(*S.top()).printState();
	return 0;
      }
      else{
	//if the goal is not discover the next node in the queue

//checks the adj nodes and add them to the Queue if they are not there
//------------------------------------------------------------------------------------	
	if((*S.top()).canMoveUp()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*S.top()).upChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    S.emplace(temp);
	    cout<<"StackS Size: "<<S.size()<<endl;
	  }
	}
        if((*S.top()).canMoveDown()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*S.top()).downChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    S.emplace(temp);
	    cout<<"StackS Size: "<<S.size()<<endl;
	  }
	}
	if((*S.top()).canMoveLeft()){
	  bool found=false;

	  Puzzle *temp=new Puzzle((*S.top()).leftChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    S.emplace(temp);
	    cout<<"StackS Size: "<<S.size()<<endl;
	  }
	}
	if((*S.top()).canMoveRight()){
	  bool found=false;
	  Puzzle *temp=new Puzzle((*S.top()).rightChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    //cout<<"==="<<endl;
	    S.emplace(temp);
	    cout<<"StackS Size: "<<S.size()<<endl;
	  }
	}
//------------------------------------------------------------------------------------
	
	(*S.top()).printState();
	//the current node is discoverd and is added to the list of known nodes
	foundStates.push_back((*S.top()));
	//removes current node
	S.pop();
	cout<<"List Size: "<<foundStates.size()<<endl;
	cout<<"StackS Size: "<<S.size()<<endl;
	
      }
    }
    return -1;
  }

//=========================================================================
//Both h1 and h2 are the same as BFS
//The only difference is that when a new element is added it is now added to a priority queue
//With the two custom comparitors the priority queue does all the work

//The structure of h1 and h2 are as such:
//Is the current sate the goal?
//if not it will attempt to add the 4 possible moves to the queue
//it will add them to the queue if the move is valid and if the move is new
//after that it will pop the current state and start over
//it will do this until there is either no more moves or until it finds the goal

//PQ is for h1
//PQ2 is for h2

//The implementation of h1 and h2 are part of Puzzle.h
  int h1(){
    while(PQ.size()!=0){
      //check if the goal is found
      Puzzle temp=PQ.top();
      if(temp.isGoalState()){
	cout<<"Goal found"<<endl;
	temp.printState();
	return 0;
      }
      else{
	Puzzle current= PQ.top();
	PQ.pop();
	if(current.canMoveUp()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.upChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ.push(*temp);
	  }
	}
        if(current.canMoveDown()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.downChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ.push(*temp);
	  }
	}
        if(current.canMoveLeft()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.leftChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ.push(*temp);
	  }
	}
        if(current.canMoveRight()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.rightChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ.push(*temp);
	    cout<<"Queue Size: "<<PQ.size()<<endl;
	  }
	}
	current.printState();
	foundStates.push_back(current);
      }
    }
    return -1;
  }

  int h2(){
    while(PQ2.size()!=0){
      //check if the goal is found
      Puzzle temp=PQ2.top();
      if(temp.isGoalState()){
	cout<<"Goal found"<<endl;
	temp.printState();
	return 0;
      }
      else{
	Puzzle current= PQ2.top();
	PQ2.pop();
	if(current.canMoveUp()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.upChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ2.push(*temp);
	  }
	}
        if(current.canMoveDown()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.downChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ2.push(*temp);
	  }
	}
        if(current.canMoveLeft()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.leftChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ2.push(*temp);
	  }
	}
        if(current.canMoveRight()){
	  bool found=false;
	  Puzzle *temp=new Puzzle(current.rightChild().currentState);
	  itt=foundStates.begin();
	  while(itt!=foundStates.end()){
	    if(*itt==*temp){
	      //(*itt).printState();
	      //(*temp).printState();
	      found=true;
	      break;
	    }
	    itt++;
	  }
	  if(!found){
	    PQ2.push(*temp);
	    cout<<"Queue Size: "<<PQ2.size()<<endl;
	  }
	}
	current.printState();
	foundStates.push_back(current);
      }
    }
    return -1;
  }
};



#endif 
