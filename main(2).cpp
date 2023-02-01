#include<iostream>

using namespace std;
const int N=2;
struct Queue
{
    int elements[N],nwaiting,front;
    void initialize()
    {
        nwaiting=0;
        front=0;
    }
    bool insert(int v)
    {
        if(nwaiting>=N)
            return false;
        elements[(front+nwaiting)%N]=v;
        nwaiting++;
        return true;
    }
    bool remove(int &v)
    {
        if (nwaiting == 0)
        {
            return false;
        }
        v= elements[front];
        front=(front+1)%N;
        nwaiting--;
        return true;
    }
};

int main()
{
    Queue q;
    q.initialize();
    while (true)
    {
        char c; 
        cin>>c;
        if (c=='d' || c=='D')
        {
            int driver;
            cin>>driver;
            if(!q.insert(driver)) 
            {
                cout<<"Queue is full \n";
                break;
            }
        }
        else if (c=='c' || c=='C')
        {
            int driver;
            if(!q.remove(driver)) 
            {
                cout<<"No Taxi Avaliable \n";
                break;
            }
            else cout<<"Assigning"<<driver<<endl;
        }  
    }
    return 0;
}