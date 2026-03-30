#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    
    vector<vector<pair<int,int>>> adj(n);
    for(auto &f : flights){
        adj[f[0]].push_back({f[1], f[2]});
    }

    vector<int> dist(n, INT_MAX);
    dist[src] = 0;

    queue<tuple<int,int,int>> q;
    q.push({0, src, 0});

    while(!q.empty()){
        auto [stops, node, cost] = q.front();
        q.pop();

        if(stops > k) continue;

        for(auto &it : adj[node]){
            int next = it.first;
            int price = it.second;

            if(cost + price < dist[next]){
                dist[next] = cost + price;
                q.push({stops + 1, next, dist[next]});
            }
        }
    }

    return dist[dst] == INT_MAX ? -1 : dist[dst];
}

int main(){
    int n = 3;
    vector<vector<int>> flights = {
        {0,1,100},
        {1,2,100},
        {0,2,500}
    };
    
    int src = 0, dst = 2, k = 1;

    cout << findCheapestPrice(n, flights, src, dst, k);

    return 0;
}