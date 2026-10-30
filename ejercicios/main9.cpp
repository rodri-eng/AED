#include <iostream>
#include <queue>

using namespace std;

bool estaEnLaCola(queue<int> q, int valorBuscado)
{
    bool encontrado = false;
    queue<int> colaAuxiliar;

    while (!q.empty())
    {
        int actual = q.front();
        if (actual == valorBuscado)
        {
            encontrado = true;
        }
        colaAuxiliar.push(actual);
        q.pop();
    }

    while (!colaAuxiliar.empty())
    {
        q.push(colaAuxiliar.front());
        colaAuxiliar.pop();
    }

    return encontrado;
}

// otra foram
/*
#include <iostream>
#include <deque>
#include <algorithm>

int main() {
    std::deque<int> dq = {10, 20, 30, 40};
    int valorBuscado = 20;

    auto it = std::find(dq.begin(), dq.end(), valorBuscado);

    if (it != dq.end()) {
        std::cout << "El elemento esta en la cola.\n";
    } else {
        std::cout << "El elemento no esta.\n";
    }

    return 0;
}

*/