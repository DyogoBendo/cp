#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    
    priority_queue<int> veiculos;


    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        veiculos.push(-v);
    }

    priority_queue<pair<int, int>> mecanicos;

    for (int i = 0; i < m; i++)
    {
        int f;
        cin >> f;
        mecanicos.push({0, f});
    }
    
    
    int ans= 0;
    while(!veiculos.empty()){
        auto v = veiculos.top();
        veiculos.pop();

        auto mecanico = mecanicos.top();mecanicos.pop();

        ans -= mecanico.first;

        mecanicos.push({(mecanico.first + mecanico.second * v), mecanico.second});
    }

    cout << ans << endl;
}