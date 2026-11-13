#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const long long int INF = 1LL << 62;

vector<long long int> Dijkstra(
    int src,
    int n,
    const vector<vector<pair<int, int>>> &G)
{
    vector<long long int> D(n + 1, INF);
    D[src] = 0;

    priority_queue<pair<long long int, int>> Q;
    Q.emplace(0, src);

    while (!Q.empty())
    {
        long long int d = -Q.top().first;
        int u = Q.top().second;
        Q.pop();

        if (D[u] != d)
            continue;

        for (const auto &e : G[u])
        {
            int v = e.first;
            int w = e.second;

            if (D[v] > d + w)
            {
                D[v] = d + w;
                Q.emplace(-D[v], v);
            }
        }
    }

    return D;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<pair<int, int>>> G(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }

    vector<long long int> dist1 = Dijkstra(1, n, G);
    vector<long long int> distA = Dijkstra(a, n, G);
    vector<long long int> distB = Dijkstra(b, n, G);

    long long int ruta1 = INF;
    long long int ruta2 = INF;

    if (dist1[a] != INF && distA[b] != INF && distB[n] != INF)
        ruta1 = dist1[a] + distA[b] + distB[n];

    if (dist1[b] != INF && distB[a] != INF && distA[n] != INF)
        ruta2 = dist1[b] + distB[a] + distA[n];

    long long int respuesta = min(ruta1, ruta2);

    if (respuesta == INF)
        cout << -1 << '\n';
    else
        cout << respuesta << '\n';

    return 0;
}
