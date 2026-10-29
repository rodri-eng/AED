#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int n, m, q;

  cin >> n >> m >> q;

  vector<pair<int, int>> agenda;
  vector<vector<int>> vecinos(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    agenda.push_back({u, v});
    vecinos[u].push_back(v);
    vecinos[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    sort(vecinos[i].begin(), vecinos[i].end());
  }

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      int u, k;
      cin >> u >> k;

      if (k > vecinos[u].size()) {
        cout << "-1" << "\n";
      } else {

        cout << vecinos[u][k - 1] << "\n";
      }
    } else if (x == 2) {
      int u, menor_igual_num;

      cin >> u >> menor_igual_num;

      auto indice =
          upper_bound(vecinos[u].begin(), vecinos[u].end(), menor_igual_num);

      cout << (indice - vecinos[u].begin()) << "\n";
    }
  }
  return 0;
}
