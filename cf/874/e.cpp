#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            a[i] --;
        }
        
        int oc = 0, cc =0;
        for (int i = 0; i < n; i++)
        {
            if(visited[i]) continue;
            int x = i;
            int p = x; // previous
            int pp = x; // previous previous

            while(!visited[x]){
                visited[x] = 1;
                int y = a[x];                
                pp = p;
                p = x;
                x = y;
            }

            if(x == pp){ // significa que visitamos até 2, ou seja, temos um "ciclo aberto"
                oc ++;
            } else{
                if(x == i){ // se terminamos onde começamos, e não em um ciclo aberto            
                    cc ++;
                }

                // se terminamos em um ciclo aberto, vale o mesmo que o ciclo aberto existente que se ele conecta, então não fazemos nada
            }            
        }
                
        // o minimo são todos os ciclos fechados, e se existir um ciclo aberto, eles se juntando.
        // o maximo seria os ciclos fechados e os ciclos  abertos de forma independente. 
        cout << cc + (oc > 0) << " " << cc + oc << endl;
    }
}