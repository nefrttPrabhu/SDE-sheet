//Q: find the number of proviencies then calculate the sum of the ceil of the sqare root of the number of nodes present in the provience
//   no. of nodes in 5 proviences: 5 + 2 + 1 + 1 + 1

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& vis, int node, int &count){
    vis[node] = 1;
    count++;

    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(adj, vis, it, count);
        }
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> a = {1, 3, 4, 1, 2, 7};
    vector<int> b = {7, 5, 2, 6, 1, 2};

    vector<vector<int>> adj(n + 1);
    vector<int> vis(n + 1, 0);
    vector<int> ans;

    int sum = 0;

    for(int i = 0; i < a.size(); i++){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }

    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            int count = 0; //keeping it outside if will also give same result coz if is checking whom to allow go in and whom not to aise cnt uper he baar baar zero ho rha per andder dfs mai ja he nhi par rha hai coz the if is keeping the check
            dfs(adj, vis, i, count);
            ans.push_back(count); 
        }
    }

    for(auto it : ans){
        sum += ceil(sqrt(it));
    }

    cout << sum << endl;
    return 0;
}
