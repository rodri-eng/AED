#include <iostream>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int n, m;

  cin >> n >> m;

  vector<vector<int>> amigos(n + 1);

  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    // --x;
    // --y;
    amigos[x].push_back(y);
    amigos[y].push_back(x);
  }

  cout << "amigos formados:" << "\n";

  for (int i = 0; i < amigos.size(); ++i) {
    for (int j = 0; j < amigos[i].size(); ++j) {
      cout << amigos[i][j] << " ";
    }
    cout << "\n";
  }

  vector<int> amigos_del_amigo;

  for (int i = 1; i < amigos.size(); ++i) {
    for (int j = 0; j < amigos[i].size(); ++j) {
      amigos_del_amigo.push_back(amigos[i][j]);
    }
    for (int k = 1; k < amigos.size(); ++k) {
    }
    if (amigos[i][j]) {
    }
    amigos_del_amigo.clear();
  }

  return 0;
}
