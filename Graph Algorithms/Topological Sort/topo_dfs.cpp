#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> graph[], vector<bool>& vis, stack<int>& st){
    vis[node] = true;
    for(auto it: graph[node]){
        if(vis[it] == 0){
            dfs(it, graph, vis, st);
        }
    }
    st.push(node);
}
void topologicalSort(int& N, vector<int> graph[]){
    stack<int> st;
    vector<bool> vis(N, false);
    for(int i=0; i<N; i++){
        if(vis[i] == 0){
            dfs(i, graph, vis, st);
        }
    }
    vector<int> topo;
    while(!st.empty()){
        topo.push_back(st.top());
        st.pop();
    }
    for(int i: topo) cout << i << " ";
}

int main(int argc, char const *argv[])
{
    int N = 6, E=6;
    vector<int> graph[N];
    for(int i=0; i<E; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
    }
    topologicalSort(N, graph);
    return 0;
}

