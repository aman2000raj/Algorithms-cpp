#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n){
        for(int i=0; i<n; i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }

    int Find(int k){
        // if k is not parent
        if(parent[k] != k) {
            //path compression
            parent[k] = Find(parent[k]);
        }
        return parent[k];
    }

    void Union(int u, int v){
        int parentU = Find(u);
        int parentV = Find(v);
        if(parentU == parentV){
            return;
        }
        if(rank[parentU] < rank[parentV]){
            parent[parentU] = parentV;
        } else if(rank[parentV] < rank[parentU]){
            parent[parentV] = parentU;
        } else{
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }
};

struct node{
    int u, v, wt;
    node(int first, int second, int weight){
        u = first;
        v = second;
        wt = weight;
    }
};
bool comp(node a, node b){
    return a.wt < b.wt;
}
int main()
{
    int N, m;
    cin >> N >> m;
    vector<node> edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
    sort(begin(edges), end(edges), comp);
    
    DisjointSet s(N);
    int cost = 0;
    vector<pair<int, int>> mst;

    for(auto it: edges){
        if(s.Find(it.v) != s.Find(it.u)){
            cost += it.wt;
            mst.push_back({it.u, it.v});
            s.Union(it.u, it.v); 
        }
    }
    cout << "Minimum Cost Spanning Tree: " << cost << endl;
    for(auto it : mst) cout << it.first << " -- " << it.second << endl;
    return 0;
}
