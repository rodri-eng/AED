#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int maxNum, numImput;

  cin >> maxNum >> numImput;
  vector<pair<int, int>> seguidores;

  for (int i = 0; i < numImput; ++i) {
    int x, y;
    cin >> x >> y;
    pair<int, int> seg_form(x, y);
    seguidores.push_back(seg_form);
  }

  int parejas = 0;
  vector<int> nums(maxNum + 1, 0);

  sort(seguidores.begin(), seguidores.end());

  for (int i = 0; i < seguidores.size(); ++i) {
    ++nums[seguidores[i].second];

    pair<int, int> inverso(seguidores[i].second, seguidores[i].first);

    if (binary_search(seguidores.begin(), seguidores.end(), inverso)) {
      ++parejas;
    }
  }

  int mayor_seg = 1;

  for (int i = 1; i < nums.size(); ++i) {
    if (nums[i] > nums[mayor_seg]) {
      mayor_seg = i;
    }
  }

  cout << (parejas / 2) << " " << (mayor_seg) << " " << nums[mayor_seg];

  return 0;
}
