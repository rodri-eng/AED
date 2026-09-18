#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

const unsigned int OFFSET = 2e9;

inline int get_hash_value(long long key, int m) {
  key += OFFSET;
  const int B = 311;
  const int MOD = 1e9 + 7;
  int hash_value = 0;
  while (key > 0) {
    int d = key % 10;
    hash_value = (1ll * hash_value * B + (d + 1)) % MOD;
    key /= 10;
  }
  return hash_value % m;
}

inline int get_hash_value(const string &key, int m) {
  const int B = 311;
  const int MOD = 1e9 + 7;
  int hash_value = 0;
  for (char c : key) {
    int val = c - 'a' + 1;
    hash_value = (1ll * hash_value * B + val) % MOD;
  }
  return hash_value % m;
}

template <typename key_type, typename value_type> struct my_map {
  int m;
  int _size;
  vector<vector<pair<key_type, value_type>>> chains;

  my_map(int m = 1) : m(m), _size(0) { chains.resize(m); }

  int _hash(const key_type &key) const { return get_hash_value(key, m); }

  value_type &operator[](const key_type &key) {
    int chain_position = _hash(key);
    int at = 0;
    while (at < (int)chains[chain_position].size() &&
           chains[chain_position][at].first != key) {
      ++at;
    }
    if (at == (int)chains[chain_position].size()) {
      chains[chain_position].emplace_back(key, value_type());
      ++_size;
    }
    return chains[chain_position][at].second;
  }

  bool has_key(const key_type &key) const {
    int chain_position = _hash(key);
    int at = 0;
    while (at < (int)chains[chain_position].size() &&
           chains[chain_position][at].first != key) {
      ++at;
    }
    return at != (int)chains[chain_position].size();
  }

  void erase(const key_type &key) {
    int chain_position = _hash(key);
    int at = 0;
    while (at < (int)chains[chain_position].size() &&
           chains[chain_position][at].first != key) {
      ++at;
    }
    if (at != (int)chains[chain_position].size()) {
      if (at + 1 < (int)chains[chain_position].size()) {
        swap(chains[chain_position][at], chains[chain_position].back());
      }
      chains[chain_position].pop_back();
      --_size;
    }
  }

  int size() const { return _size; }

  bool empty() const { return _size == 0; }

  void print() const {
    for (int i = 0; i < m; ++i) {
      cout << "Bucket " << i << ":\n";
      for (const auto &e : chains[i]) {
        cout << "  " << e.first << " --> " << e.second << "\n";
      }
      cout << "End bucket\n";
    }
  }
};

int main() {

  int n;
  int T;

  cin >> n >> T;

  my_map<int, int> frec(2 * n);

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int complemento = T - x;

    if (frec.has_key(complemento)) {
      cout << "SI";
      return 0;
    }

    frec[x] = 1;
  }

  cout << "NO";

  return 0;
}
