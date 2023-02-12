#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    unordered_map<int, int> parent;
    unordered_map<int, int> rank;
    public:
    void makeSet(vector<int> const &graph){
        // create 'n' disjoint set (one for each item)
        for(int i:graph){
            parent[i] = i;
            rank[i] = 0;
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

void printSets(vector<int> const &graph, DisjointSet& ds){
    for(int i:graph){
        cout <<"Parent of "<< i <<" is "<< ds.Find(i) << ' ';
    }
    cout << "\n";
}

int main(){
    vector<int> graph = {1, 2, 3, 4, 5, 6, 7};
    // intialize 'DisjointSet' class
    DisjointSet ds;
    
    ds.makeSet(graph);
    printSets(graph, ds);

    ds.Union(1, 2);
    printSets(graph, ds);

    ds.Union(2, 3);
    printSets(graph, ds);

    ds.Union(4, 5);
    printSets(graph, ds);

    ds.Union(6, 7);
    printSets(graph, ds);

    ds.Union(5, 6);
    printSets(graph, ds);

    ds.Union(3, 7);
    printSets(graph, ds);

    return 0;
}
