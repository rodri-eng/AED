#include <iostream>

#include <vector>

#include <algorithm>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int n, m, q;

  cin >> n >> m >> q;

  vector<pair<int, int>> agenda;
  vector<vector<int>> contactos(n + 1);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    agenda.push_back({u, v});
    contactos[u].push_back(v);
    contactos[v].push_back(u);
  }

  for (int i = 1; i <= n; ++i) {
    sort(contactos[i].begin(), contactos[i].end());
  }

  for (int i = 0; i < q; ++i) {
    int x;
    cin >> x;
    if (x == 1) {
      int u, k;

      cin >> u >> k;
      if (contactos[u].size() < k) {
        cout << "-1" << "\n";
      } else {
        cout << contactos[u][k - 1] << "\n";
      }
    } else if (x == 2) {
      int v, k;
      cin >> v >> k;
      auto iter = upper_bound(contactos[v].begin(), contactos[v].end(), k);
      cout << (iter - contactos[v].begin()) << "\n";
    }
  }

  return 0;
}
