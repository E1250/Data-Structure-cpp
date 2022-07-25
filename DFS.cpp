#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// create used variables and lists
int InitialState,goalState,Numofedge,from,to,depth[1000009];
bool visited[1000009];
stack<int> OpenList;
vector<int> adj[1000009],ClosedList;

// create the state space graph
void StateSpaceGraph(){
    cout<<"Enter the number of edges: ";
    cin>>Numofedge;
    cout<<"Enter the edges";
    for(int i=0;i<Numofedge;i++){
        cin>>from>>to;
        adj[from].push_back(to);
    }
}

void DFS (int start){
    visited[start] = true;
    OpenList.push(start);
    while (!OpenList.empty()){
        int currentState = OpenList.top();
        OpenList.pop();
        ClosedList.push_back(currentState);
        if (currentState == goalState)
        {
            cout << "The goal state is: " << currentState << endl;
            cout << "The depth of the goal state is: " << depth[currentState] << endl;
            return;
        }
        for (auto state : adj[currentState])  
        {
            DFS(state);
        }

    }
}
void Display(){
    cout<<"the path is: ";
    for(int i=0;i<ClosedList.size();i++){
        cout<<ClosedList[i]<<" ";
    }
}


int main(){
    StateSpaceGraph();
    cout<<"Enter the initial state: ";
    cin>>InitialState;
    cout<<"Enter the goal state: ";
    cin>>goalState;
    DFS(InitialState);
    Display();
    return 0;
}
