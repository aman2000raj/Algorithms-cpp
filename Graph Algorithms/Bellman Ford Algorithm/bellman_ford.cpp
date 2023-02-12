#include <bits/stdc++.h>
using namespace std;

struct node
{
    int u;
    int v;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

int main()
{
    int N=6, m=7;
    //cin >> N >> m;
    vector<node> edges = {node(3,2,6), node(5,3,1), node(0,1,5), node(1,5,-3), node(1,2,-2), node(3,4,-2), node(2,4,3)};
    // for (int i = 0; i < m; i++)
    // {
    //     int u, v, wt;
    //     cin >> u >> v >> wt;
    //     edges.push_back(node(u, v, wt));
    // }
    int src=0;
    //cin >> src;

    vector<int> dist(N, 1000000);

    dist[src] = 0;
    // loop for vertex-1 times 1st.
    for (int i = 1; i <= N - 1; i++)
    {
        for (auto it : edges)
        {
            if (dist[it.u] + it.wt < dist[it.v])
            {
                dist[it.v] = dist[it.u] + it.wt;
            }
        }
    }
    int flag = 0;
    // itrate one more time if value of dist array element decreas, then negative loop detected.
    for (auto it : edges)
    {
        if (dist[it.u] + it.wt < dist[it.v])
        {
            cout << " Negative Cycle";
            flag = 1;
            break;
        }
    }

    if (!flag)
    {
        for (int i = 0; i < N; i++)
        {
            cout << i << " " << dist[i] << endl;
        }
    }
    return 0;
}
