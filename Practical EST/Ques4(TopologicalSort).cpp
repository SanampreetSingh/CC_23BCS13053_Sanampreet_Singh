#include<bits/stdc++.h>
using namespace std;

vector<int> TopoogicalSort(int V,int E,vector<vector<int>>&edges){
    vector<int>inorder(V,0);
    vector<vector<int>>adj(V);
    vector<int>ans;
    queue<int>q;
    for(int i =0;i<E;i++){
        int u =edges[i][0];
        int v =edges[i][1];
        inorder[v]++;
        adj[u].push_back(v);
    }
    for(int i =0;i<V;i++){
        if(inorder[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int node=q.front();
        q.pop();
        ans.push_back(node);
        for(auto ele:adj[node]){
            inorder[ele]--;
            if(inorder[ele]==0){
                q.push(ele);
            }
        }
    }
    return ans;
}


void printv(vector<int>&ans){
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}

 int main(){
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
    int V,E;
    cin>>V>>E;
    vector<vector<int>>edges(E);
    for(int i =0;i<E;i++){
        int u,v;
        cin>>u>>v;
        edges[i].push_back(u);
        edges[i].push_back(v);
    }
    vector<int>ans=TopoogicalSort(V,E,edges);  
    printv(ans);
      return 0;
      }
