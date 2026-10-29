#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {

  cin.tie(0)->sync_with_stdio(false);

  int A, B, x, y;

  // vaciar A o vaciar B
  // Llenar A o Llenar B
  // pasar el contenido de A a B hasta que se llene o A se vacie
  // o Pasar el contenido de B a A hasta que se llene o B se vacie

  cin >> A >> B >> x >> y;

  int initial_x = x;
  int initial_y = y;

  pair<int, int> par_busqueda_entradas = {x, y};
  int cant_aristas = 0;
  vector<pair<int, int>> estados;

  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      if (i == 0 and j == 0) {
        cant_aristas += 2;
      } else if (i == A and j == B) {
        cant_aristas += 2;
      } else if (i == A and j == 0) {
        cant_aristas += 3;
      } else if (i == 0 and j == B) {
        cant_aristas += 3;
      } else if (i > 0 and j > 0 and i < A and j < B) {
        cant_aristas += 6;
      } else {
        cant_aristas += 4;
      }
    }
  }

  int entradas = 0;

  for (int i = 0; i <= A; ++i) {
    for (int j = 0; j <= B; ++j) {
      if (i == 0 and j == 0) {
        for (int k = 0; k < 2; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = A;
          } else {
            par_actual.second = B;
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i == A and j == B) {
        for (int k = 0; k < 2; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = 0;
          } else {
            par_actual.second = 0;
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i == A and j == 0) {
        for (int k = 0; k < 3; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = 0;
          } else if (k == 2) {
            par_actual.second = B;
          } else {
            // Llenar segundo envase correcto
            if ((par_actual.first + par_actual.second) <= B) {
              par_actual.second = par_actual.first + par_actual.second;
              par_actual.first = 0;
            } else if ((par_actual.first + par_actual.second) > B) {
              int valor_min_trasbase = abs(B - par_actual.second);
              par_actual.first = par_actual.first - valor_min_trasbase;
              par_actual.second = B;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i == 0 and j == B) {
        for (int k = 0; k < 3; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = A;
          } else if (k == 2) {
            par_actual.second = 0;
          } else {
            // llenar primer envase correcto
            if ((par_actual.first + par_actual.second) <= A) {
              par_actual.first = par_actual.first + par_actual.second;
              par_actual.second = 0;
            } else if ((par_actual.first + par_actual.second) > A) {
              int valor_min_trasbase = abs(A - par_actual.first);
              par_actual.second = par_actual.second - valor_min_trasbase;
              par_actual.first = A;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i > 0 and j > 0 and i < A and j < B) {
        for (int k = 0; k < 6; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = 0;
          } else if (k == 1) {
            par_actual.second = 0;
          } else if (k == 2) {
            par_actual.first = A;
          } else if (k == 3) {
            par_actual.second = B;
          } else if (k == 4) {
            // segundo envase
            if ((par_actual.first + par_actual.second) <= B) {
              par_actual.second = par_actual.first + par_actual.second;
              par_actual.first = 0;
            } else if ((par_actual.first + par_actual.second) > B) {
              int valor_min_trasbase = abs(B - par_actual.second);
              par_actual.first = par_actual.first - valor_min_trasbase;
              par_actual.second = B;
            }
          } else if (k == 5) {
            if ((par_actual.first + par_actual.second) <= A) {
              par_actual.first = par_actual.first + par_actual.second;
              par_actual.second = 0;
            } else if ((par_actual.first + par_actual.second) > A) {
              int valor_min_trasbase = abs(A - par_actual.first);
              par_actual.second = par_actual.second - valor_min_trasbase;
              par_actual.first = A;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i == 0 and (j > 0 and j < B)) {
        for (int k = 0; k < 4; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.second = 0;
          } else if (k == 1) {
            par_actual.first = A;
          } else if (k == 2) {
            par_actual.second = B;
          } else {
            // llenar primero
            if ((par_actual.first + par_actual.second) <= A) {
              par_actual.first = par_actual.first + par_actual.second;
              par_actual.second = 0;
            } else if ((par_actual.first + par_actual.second) > A) {
              int valor_min_trasbase = abs(A - par_actual.first);
              par_actual.second = par_actual.second - valor_min_trasbase;
              par_actual.first = A;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if (i == A and (j > 0 and j < B)) {
        for (int k = 0; k < 4; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = 0;
          } else if (k == 1) {
            par_actual.second = B;
          } else if (k == 2) {
            par_actual.second = 0;
          } else {
            // llenar segundo
            if ((par_actual.first + par_actual.second) <= B) {
              par_actual.second = par_actual.first + par_actual.second;
              par_actual.first = 0;
            } else if ((par_actual.first + par_actual.second) > B) {
              int valor_min_trasbase = abs(B - par_actual.second);
              par_actual.first = par_actual.first - valor_min_trasbase;
              par_actual.second = B;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if ((i > 0 and i < A) and j == 0) {
        for (int k = 0; k < 4; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = A;
          } else if (k == 1) {
            par_actual.second = B;
          } else if (k == 2) {
            par_actual.first = 0;
          } else {
            // llenar segundo
            if ((par_actual.first + par_actual.second) <= B) {
              par_actual.second = par_actual.first + par_actual.second;
              par_actual.first = 0;
            } else if ((par_actual.first + par_actual.second) > B) {
              int valor_min_trasbase = abs(B - par_actual.second);
              par_actual.first = par_actual.first - valor_min_trasbase;
              par_actual.second = B;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      } else if ((i > 0 and i < A) and j == B) {
        for (int k = 0; k < 4; ++k) {
          pair<int, int> par_actual = {i, j};
          if (k == 0) {
            par_actual.first = A;
          } else if (k == 1) {
            par_actual.second = 0;
          } else if (k == 2) {
            par_actual.first = 0;
          } else {
            // llenar primero
            if ((par_actual.first + par_actual.second) <= A) {
              par_actual.first = par_actual.first + par_actual.second;
              par_actual.second = 0;
            } else if ((par_actual.first + par_actual.second) > A) {
              int valor_min_trasbase = abs(A - par_actual.first);
              par_actual.second = par_actual.second - valor_min_trasbase;
              par_actual.first = A;
            }
          }
          if (par_actual == par_busqueda_entradas) {
            ++entradas;
          }
        }
      }
    }
  }

  cout << cant_aristas << " " << entradas;

  return 0;
}
