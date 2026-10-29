#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int n, m, q;

  cin >> n >> m >> q;

  unordered_map<string, int> cant_conexiones;

  for (int i = 0; i < m; ++i) {
    string x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    string complete_key = x + ":" + y;
    ++cant_conexiones[complete_key];
  }

  for (int i = 0; i < q; ++i) {
    string x, y;
    cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
    string complete_key = x + ":" + y;
    auto it = cant_conexiones.find(complete_key);
    if (it != cant_conexiones.end()) {
      cout << it->second << "\n";
    } else {
      cout << "0" << "\n";
    }
  }

  return 0;
}
