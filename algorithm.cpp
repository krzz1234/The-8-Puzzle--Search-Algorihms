
#include "algorithm.h"
#include "graphics.h"

#include <stack>
#include <vector>

using namespace std;





///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  UC with Strict Expanded List
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string uc_explist(string const initialState, string const goalState, int& pathLength, int &numOfStateExpansions, int& maxQLength,
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;



    // cout << "------------------------------" << endl;
    // cout << "<<uc_explist>>" << endl;
    // cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= 0; 
	numOfStateExpansions = 0; 

	Puzzle *current_state = new Puzzle(initialState, goalState);
	Puzzle *temp_state = new Puzzle(*current_state);

	vector<Puzzle*> Q;
	vector<Puzzle*> explist;
	Q.push_back(current_state);
	make_heap(Q.begin(), Q.end());
	explist.push_back(current_state);

	bool contains = false;
	bool existsInQ = false;
	bool q_added = false;
    
    while(!current_state->goalMatch()){
    	// If goal state is reached return path
    	if(Q.empty()){
    		numOfDeletionsFromMiddleOfHeap=0;
		    numOfLocalLoopsAvoided=0;
		    numOfAttemptedNodeReExpansions=0;
		    maxQLength= 0; 
			numOfStateExpansions = 0;
    		return "";
    	} else {
    		if(current_state->canMoveUp()){
    			temp_state = current_state->moveUp();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    // If state is not in the explist
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getPathLength() < Q[i]->getPathLength()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveRight()){
    			temp_state = current_state->moveRight();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
		    		for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    				q_added = true;			    			
			    			if(temp_state->getPathLength() < Q[i]->getPathLength()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveDown()){
    			temp_state = current_state->moveDown();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getPathLength() < Q[i]->getPathLength()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());			    				
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveLeft()){
    			temp_state = current_state->moveLeft();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    				q_added = true;			    			
			    			if(temp_state->getPathLength() < Q[i]->getPathLength()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		numOfStateExpansions++;
    	}
    	if(maxQLength < Q.size()){
    		maxQLength = Q.size();
    	}
    	int lowest_path = 99999;
    	int indx = 0;
    	for(int i=0; i<Q.size(); i++){
    		if(lowest_path > Q[i]->getPathLength()){
    			lowest_path = Q[i]->getPathLength();
    			current_state = Q[i];
    			indx = i;
    		}
    	}
    	Q.erase(Q.begin()+indx);
    	numOfDeletionsFromMiddleOfHeap++;
    	//explist.push_back(current_state);
    	// cout<<"path: "<<current_state->getPath()<<endl;
    	// cout << "Q size: "<<Q.size()<<" explist size: "<<explist.size()<<endl;
    	// cout<<"Tostring "<<current_state->toString()<<endl;
    }


	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = current_state->getPath(); 
	pathLength = path.size();
	return path;		
		
}




///////////////////////////////////////////////////////////////////////////////////////////
//
// Search Algorithm:  A* with the Strict Expanded List
//
// Move Generator:  
//
////////////////////////////////////////////////////////////////////////////////////////////
string aStar_ExpandedList(string const initialState, string const goalState, int& pathLength, int &numOfStateExpansions, int& maxQLength,
                               float &actualRunningTime, int &numOfDeletionsFromMiddleOfHeap, int &numOfLocalLoopsAvoided, int &numOfAttemptedNodeReExpansions, heuristicFunction heuristic){
											 
   string path;
   clock_t startTime;
   
   numOfDeletionsFromMiddleOfHeap=0;
   numOfLocalLoopsAvoided=0;
   numOfAttemptedNodeReExpansions=0;


    // cout << "------------------------------" << endl;
    // cout << "<<aStar_ExpandedList>>" << endl;
    // cout << "------------------------------" << endl;
	actualRunningTime=0.0;	
	startTime = clock();
	srand(time(NULL)); //RANDOM NUMBER GENERATOR - ONLY FOR THIS DEMO.  YOU REALLY DON'T NEED THIS! DISABLE THIS STATEMENT.
	maxQLength= 0; 
	numOfStateExpansions = 0; 

	Puzzle *current_state = new Puzzle(initialState, goalState);
	Puzzle *temp_state = new Puzzle(*current_state);
	current_state->updateHCost(heuristic);
	current_state->updateFCost();

	vector<Puzzle*> Q;
	vector<Puzzle*> explist;
	Q.push_back(current_state);
	make_heap(Q.begin(), Q.end());
	explist.push_back(current_state);

	bool contains = false;
	bool existsInQ = false;
	bool q_added = false;
	bool explist_contains = false;
    
    while(!current_state->goalMatch()){
    	// If goal state is reached return path
    	if(Q.empty()){
    		numOfDeletionsFromMiddleOfHeap=0;
		    numOfLocalLoopsAvoided=0;
		    numOfAttemptedNodeReExpansions=0;
		    maxQLength= 0; 
			numOfStateExpansions = 0;
    		return "";
    	} else {
    		if(current_state->canMoveUp()){
    			temp_state = current_state->moveUp();
    			temp_state->updateHCost(heuristic);
    			temp_state->updateFCost();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    // If state is not in the explist
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getFCost() < Q[i]->getFCost()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveRight()){
    			temp_state = current_state->moveRight();
    			temp_state->updateHCost(heuristic);
    			temp_state->updateFCost();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
		    		for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getFCost() < Q[i]->getFCost()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveDown()){
    			temp_state = current_state->moveDown();
    			temp_state->updateHCost(heuristic);
    			temp_state->updateFCost();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getFCost() < Q[i]->getFCost()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		if(current_state->canMoveLeft()){
    			temp_state = current_state->moveLeft();
    			temp_state->updateHCost(heuristic);
    			temp_state->updateFCost();
    			// If temp_state is already in the explist flag to true
    			for(int i=0; i<explist.size(); i++){
		    		if(temp_state->toString() == explist[i]->toString()){	
		    			contains = true;
			    	}
			    }
			    if(!contains){
			    	explist.push_back(temp_state);
			    	for(int i=0; i<Q.size(); i++){
			    		if(temp_state->toString() == Q[i]->toString()){
			    			q_added = true;
			    			if(temp_state->getFCost() < Q[i]->getFCost()){
			    				Q.erase(Q.begin()+i);
			    				numOfDeletionsFromMiddleOfHeap++;
			    				Q.push_back(temp_state);
		    					push_heap(Q.begin(), Q.end());
			    			}			    			
			    		}
		    		}
		    		if(!q_added){
		    			Q.push_back(temp_state);
    					push_heap(Q.begin(), Q.end());
		    		}
		    		q_added = false;
			    } else {
			    	numOfAttemptedNodeReExpansions++;
			    	delete temp_state;
			    }
			    existsInQ = false;
			    contains = false;
    		}
    		numOfStateExpansions++;
    	}
    	if(maxQLength < Q.size()){
    		maxQLength = Q.size();
    	}
    	int lowest_FCost = 99999;
    	int indx = 0;
    	for(int i=0; i<Q.size(); i++){
    		if(lowest_FCost > Q[i]->getFCost()){
    			lowest_FCost = Q[i]->getFCost();
    			current_state = Q[i];
    			indx = i;
    		}
    	}
    	Q.erase(Q.begin()+indx);
    	numOfDeletionsFromMiddleOfHeap++;

    	// cout<<"path: "<<current_state->getPath()<<endl;
    	// cout << "Q size: "<<Q.size()<<" explist size: "<<explist.size()<<endl;
    	// cout<<"Tostring "<<current_state->toString()<<endl;
    	current_state->updateHCost(heuristic);
		current_state->updateFCost();
    }


	
	
//***********************************************************************************************************
	actualRunningTime = ((float)(clock() - startTime)/CLOCKS_PER_SEC);
	path = current_state->getPath(); 
	pathLength = path.size();
	return path;		
		
}







	