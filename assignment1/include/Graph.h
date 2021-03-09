#ifndef BREADTH_FIRST_SEARCH_H
#define BREADTH_FIRST_SEARCH_H
#include <queue>
#include <stack>
#include <list>
#include <iostream>
#include "puzzle.h"

using namespace std;

class Graph{
  queue<Puzzle*> Q;
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

  
};



#endif 
