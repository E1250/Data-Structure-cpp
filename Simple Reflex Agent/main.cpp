#include<iostream>
using namespace std;
#include <stdlib.h> /* srand, rand */

// user defined data type;
enum locations{A,B};
enum status{clean,dirty};
enum actions{nothing,move_left,move_right,suck};

class Environment{
private:
    int EnvrLocations[2];
public:
    Environment(){
        setEnvr();
    }


    void setEnvr(){
        cout<<"--- Environment Setting ---"<<endl;
        int ran = rand()%10;
        if (ran<5){
            EnvrLocations[A] = clean;
            EnvrLocations[B] = dirty;
        }
        else{
            EnvrLocations[A] = dirty;
            EnvrLocations[B] = clean;
        }
    }

    int getStatus(int location){
        return EnvrLocations[location];
    }

    void setStatus(int location,int status){
        EnvrLocations[location] = status;
    }


    void printStatus(int agentLocatoin){
        cout<<"--- Environment Status ---"<<endl;
        if(getStatus(A)==clean){
            cout<<"A: clean"<<endl;
        }
        else{
            cout<<"A: dirty"<<endl;
        }

        if (getStatus(B) == clean)
        {
            cout << "B: clean" << endl;
        }
        else
        {
            cout << "B: dirty" << endl;
        }
    }
};

class Agent{
public:
    int vacuumeAction(int location , int status){
        if(status==dirty){
            return suck;
        }
        else{
            if(location==A){
                return move_right;
            }
            else{
                return move_left;
            }
        }
    }

};

int main (){
    Environment e;
    Agent a;
    int currentLocatoin = A;
    int agentAction;
    for (int i = 0; i < 10; i++)
    {
        e.printStatus(currentLocatoin);

        if (e.getStatus(A) == clean && e.getStatus(B)==clean)
        {
            agentAction=nothing;
            cout<<"Agent: nothing"<<endl;
            e.setEnvr();
        }

        else
        {
            agentAction = a.vacuumeAction(currentLocatoin,e.getStatus(currentLocatoin));
            if (agentAction == suck)
            {
                cout << "Agent: suck" << endl;
                e.setStatus(currentLocatoin, clean);
            }
            else
            {
                if (agentAction == move_right)
                {
                    cout << "Agent: move right" << endl;
                    currentLocatoin = B;
                }
                else
                {
                    cout << "Agent: move left" << endl;
                    currentLocatoin = A;
                }
            }
            
         }
        
    }
    
return 0;

}
