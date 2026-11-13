#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> Dijkstra(int src, int n, vector<vector<pair<int, int>>> &G)
{
    vector<int> D(n, numeric_limits<int>::max());
    D[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
    Q.emplace(0, src);
    while (!Q.empty())
    {
        int u, d;
        tie(d, u) = Q.top();
        Q.pop();
        if (D[u] != d)
            continue;
        for (auto &e : G[u])
        {
            int v, w;
            tie(v, w) = e;
            if (D[v] > D[u] + w)
            {
                D[v] = D[u] + w;
                Q.emplace(D[v], v);
            }
        }
    }
    return D;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    return 0;
}
