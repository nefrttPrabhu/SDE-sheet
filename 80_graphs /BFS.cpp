
/*
S1. define queue
S2. create a visited array
S3. adjecency list
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0}; 
        vis[0] = 1; 
        queue<int> q;

        q.push(0); // gets the 1st node of the graph
        vector<int> bfs; 
      
        while(!q.empty())// iterate till the queue is empty 

        {
            int node = q.front(); // get the topmost element in the queue
            q.pop(); // node mai store kar liya then q ke top se pop kar diya
            bfs.push_back(node); //wahi fir bfs jo output chahiye usmai dla diya
            
            for(auto it : adj[node]) // traverse for all its neighbours and ye list given hoti hi 
            {
                // if the neighbour has previously not been visited, 
                // store in Q and mark as visited 
                if(!vis[it]) {
                    vis[it] = 1; 
                    q.push(it); 
                }
            }
        }
        return bfs; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector <int> &ans) {
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}

int main() 
{
    vector <int> adj[6];
    
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 0, 4);

    Solution obj;
    vector <int> ans = obj.bfsOfGraph(5, adj);
    printAns(ans);

    return 0;
}
