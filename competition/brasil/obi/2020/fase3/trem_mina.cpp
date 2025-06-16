/*
    A ideia é que necessariamente precisamos percorrer um ciclo que seja pelo menos do tamanho do trem
    Então, pré-calculamos os ciclos, marcando quais arestas pertencem a cada um dos ciclos e calculando o tamanho dos ciclos
    Depois, podemos usar dijskra com um heap, com tempo de O(e log e) para encontrar a menor distância para cada ciclo 
    Por fim, calculamos o resultado para a query como o menor valor de distancia + comprimento ciclo para todos os ciclos maiores ou iguais ao comprimento do trem
*/

#include <bits/stdc++.h>

using namespace std;

int v, e;
vector<int> cycles;
vector<int> visited;
vector<vector<pair<int, int>>> graph;

int qtd_ciclos = 0;
int dfs(int current, int previous){
    if(visited[current]) return 0;

    visited[current] = 1;
    int r = 0;
    for (auto u : graph[current])
    {
        int p = u.first;
        if(p != previous){
            if(visited[p] && cycles[current] == 0){
                qtd_ciclos ++;
                cycles[current] = qtd_ciclos;                     
                r = p + 1;           
            } else{
                int r2 = dfs(p, current);
                if(r2){
                    cycles[current] = cycles[p];
                    if(r2 - 1 == current){
                        r = 0;
                    } else{
                        r = r2;
                    }
                }
            }
        }
    }    
    return r;
}

int dfs_ciclo(int current, int prev, int c){
    if(visited[current]) return 0;
    visited[current] = 1;    
    for (auto u : graph[current])
    {
        int p = u.first, d = u.second;

        if(cycles[p] == c && p != prev){
            return d + dfs_ciclo(p, current, c);
        }
    }
    
    return 0;
}

int main(){
    cin >> v >> e;
    graph.resize(v);
    visited.resize(v);
    cycles.resize(v);

    for (int i = 0; i < e; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    // encontrar ciclos     
    for (int i = 0; i < v; i++)
    {
        if(!visited[i]){
            dfs(0, -1);
        }
    }

    fill(visited.begin(), visited.end(), 0);
    // calcular tamanho dos ciclos
    vector<int> ciclos_tamanho(qtd_ciclos + 1);
    for (int i = 0; i < v; i++)
    {                   
        if(cycles[i] != 0 && ciclos_tamanho[cycles[i]] == 0){            
            int tamanho = dfs_ciclo(i, -1, cycles[i]);            
            ciclos_tamanho[cycles[i]] = tamanho;
        }
    }


    

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, t;
        cin >> x >> t;
        x--;

        fill(visited.begin(), visited.end(), -1);
        priority_queue<pair<int, int>> pq;
        pq.push({0, x});
        
        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            int p = front.second, d = -front.first;            
            if(visited[p] != -1) continue;
            visited[p] = d;

            for (auto u : graph[p])
            {
                pq.push({-(u.second + d), u.first});
            }
            
        }

        int big = 1e6 + 1;
        vector<int> dst_cycles(qtd_ciclos + 1, big);
        for (int j = 0; j < v; j++)
        {
            if(visited[j] == -1) continue;
            int c = cycles[j];
            dst_cycles[c] = min(dst_cycles[c], visited[j]);
        }
        

        int ans = big;        
        for (int j = 1; j < qtd_ciclos + 1; j++)
        {            
            if(ciclos_tamanho[j] >= t) ans = min(ans, 2 * dst_cycles[j] + ciclos_tamanho[j]);
        }

        if(ans == big) ans = -1;
        
        cout << ans << endl;

    }
    
    
    
}
