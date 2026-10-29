#include <iostream>
#include <vector>

using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int f, c;

  cin >> f >> c;

  vector<string> terreno(f);

  for (int i = 0; i < f; ++i)
    cin >> terreno[i];

  vector<int> parcela_deg(5, 0);

  for (int i = 0; i < f; ++i) {
    for (int j = 0; j < c; ++j) {
      if (terreno[i][j] == '.')
        continue;
      int unit_parcel_deg = 0;
      for (int k = 0; k < 4; ++k) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x < 0 or y < 0 or x >= f or y >= c)
          continue;
        if (terreno[x][y] == '#')
          ++unit_parcel_deg;
      }
      ++parcela_deg[unit_parcel_deg];
    }
  }

  int perimetro = 0;
  for (int i = 0; i < 5; ++i) {
    perimetro += (4 - i) * (parcela_deg[i]);
  }

  cout << perimetro;

  for (auto elem : parcela_deg) {
    cout << " " << elem;
  }

  return 0;
}
