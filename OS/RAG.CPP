
/******************************************************************************
* RAG: Resource allocation graph                                              *

*******************************************************************************/

#include<bits/stdc++.h>

using namespace std;

#define MAX 1001
int rag[MAX][MAX];

//int wait[MAX][MAX];

list<int>adj[MAX];




int process[MAX];

int resources[MAX];

int num_proc,num_res; /*for storing number of processes and resources respectively */

void read_rag()
{
    int i,j,k;            /*For traversing array & matrices*/


cout<<"Enter the number of processes: ";
cin>>num_proc;
cout<<"Enter number of resources: ";
cin>>num_res;

/*cout<<"Enter process id of the processes"<<endl;

for(i=0;i<num_proc;i++)
    cin>>process[i];
cout<<"Enter the number of resources available for each type of resource\n";


for(i=0;i<num_res;i++)
    cin>>resources[i];
*/
cout<<"Enter the resource allocation graph\n";
for(i=0;i<num_proc;i++)
{
    for(j=0;j<num_res;j++)
    {
        cin>>rag[i][j];
    }

}

cout<<"The resource allocation graph for entered details:\n";

for(i=0;i<num_proc;i++)
{
    for(j=0;j<num_res;j++)
    {cout<<rag[i][j]<<" ";

    }
    cout<<endl;
}



}

bool isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;

        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }

    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

bool isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[num_proc];
    bool *recStack = new bool[num_proc];
    for(int i = 0; i < num_proc; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }

    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < num_proc; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;

    return false;
}



int wait_graph()
{
    read_rag();
    int i,j,k;


    for(i=0;i<num_proc;i++)
    {
        for(j=0;j<num_res;j++)
        {
            if(rag[i][j]==-1)
            {
                for(k=0;k<num_proc;k++)
                {
                    if(rag[k][j]==1)
                    {
                        adj[i].push_back(k);
                        break;
                    }
                }
            }
        }

    }



 if(isCyclic()==1)
    cout<<"There is deadlock in the system\n";

 else
    cout<<"No deadlock detected\n";





}

int main()
{

wait_graph();










}
