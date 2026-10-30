#include <iostream>
#include <queue>

using namespace std;

bool estaEnLaCola(queue<int> q, int val)
{
    bool encontrado = false;
    queue<int> aux;

    while (!q.empty())
    {
        int actual = q.front();
        if (actual == val)
        {
            encontrado = true;
        }
        aux.push(actual);
        q.pop();
    }

    while (!aux.empty())
    {
        q.push(aux.front());
        aux.pop();
    }

    return encontrado;
}

// otra foram
/*
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    deque<int> dq = {10, 20, 30, 40};
    int val = 20;

    auto it = find(dq.begin(), dq.end(), val);

    if (it != dq.end()) {
        cout << "Existe";
    } else {
        cout << "No existe";
    }

    return 0;
}

*/