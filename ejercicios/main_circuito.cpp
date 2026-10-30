#include<iostream>
#include <vector>
using namespace std;
 
int main()
{
 
    cin.tie(0) -> sync_with_stdio(false);
    
    int maxNum, numImput;
    
    cin >> maxNum >> numImput;
    
    vector<int> aristas(maxNum, 0);
    
    for(int i = 0; i < numImput; ++i ){
    
    int x;
    int y;
    cin >> x >> y;
    --x;
    --y;
    ++aristas[x];
    ++aristas[y];
    }
 
    int impares=0;
    for(int i = 0; i < aristas.size(); ++i){
    if(aristas[i] % 2 == 1){
    ++impares;
    }
    }
    
    if (impares == 0){
        cout << "CIRCUITO";
    }else if(impares == 2){
        cout << "CAMINO";
    }else{
        cout << "IMPOSIBLE";
    }
 
    return 0;
}