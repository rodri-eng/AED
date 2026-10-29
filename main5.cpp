#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);
  int n, m, q;

  cin >> n >> m >> q;

  vector<vector<int>> amigos(n);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    amigos[a - 1].push_back(b);
    amigos[b - 1].push_back(a);
  }

  for (auto elem : amigos) {
    sort(elem.begin(), elem.end());
  }

  for (int i = 0; i < q; ++i) {
    int u, v;
    cin >> u >> v;
    int amigos_comun = 0;
    --u;
    --v;

    vector<int> menor_cant_amigos;
    int mayor_cant_amigos = 0;
    if (amigos[u].size() > amigos[v].size()) {
      menor_cant_amigos = amigos[v];
      mayor_cant_amigos = u;
    } else {
      menor_cant_amigos = amigos[u];
      mayor_cant_amigos = v;
    }

    for (int j = 0; j < menor_cant_amigos.size(); ++j) {
      if (menor_cant_amigos.size() > 0) {
        auto it = find(amigos[mayor_cant_amigos].begin(),
                       amigos[mayor_cant_amigos].end(), menor_cant_amigos[j]);
        if (it != amigos[mayor_cant_amigos].end()) {
          ++amigos_comun;
        }
      } else {
        break;
      }
    }
    cout << amigos_comun << "\n";
  }

  return 0;
}
