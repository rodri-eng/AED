#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<long long int, int> Dijkstra(int n, long long int P, long long int Q, long long int M)
{
    const long long int INF = 1LL << 62;

    vector<long long int> D(n + 1, INF);
    vector<int> tramos(n + 1, n + 1);
    vector<bool> listo(n + 1, false);

    D[1] = 0;
    tramos[1] = 0;

    for (int iter = 0; iter < n; iter++)
    {
        int u = -1;

        for (int v = 1; v <= n; v++)
        {
            if (listo[v])
                continue;

            if (u == -1 ||
                D[v] < D[u] ||
                (D[v] == D[u] && tramos[v] < tramos[u]))
            {
                u = v;
            }
        }

        if (u == -1 || D[u] == INF)
            break;

        listo[u] = true;

        if (u == n)
            break;

        for (int v = 1; v <= n; v++)
        {
            if (listo[v])
                continue;

            long long int w = ((u + v) * P + 1LL * u * v * Q) % M + 1;

            long long int nuevoTiempo = D[u] + w;
            int nuevosTramos = tramos[u] + 1;

            if (nuevoTiempo < D[v] ||
                (nuevoTiempo == D[v] && nuevosTramos < tramos[v]))
            {
                D[v] = nuevoTiempo;
                tramos[v] = nuevosTramos;
            }
        }
    }

    return {D[n], tramos[n]};
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    long long int P, Q, M;
    cin >> n >> P >> Q >> M;

    auto resp = Dijkstra(n, P, Q, M);

    cout << resp.first << ' ' << resp.second << '\n';

    return 0;
}
