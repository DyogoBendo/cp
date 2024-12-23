#include <bits/stdc++.h>

using namespace std;

int main(){
     freopen("taming.in", "r", stdin);
	 freopen("taming.out", "w", stdout);

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }


    // a ideia é que se temos um valor, fixo, sabemos exatamente quais os valores para todos os anteriores. 
    // Para ter a maior quantidade de breakout, significa que sempre que temos um livre, temos um breakout novo
    // já para ter a maior quantidade, então todas as sequencias até chegar em um valor fixo representam apenas um
    

    bool possible = true;

    for (int i = 0; i < n; i++)
    {
        int x = v[i];
        if(x == -1) continue;
        else{
            int cnt = 0;
            while(x){
                if(v[i - x] != cnt && v[i - x] != -1){
                    possible = false;
                }
                v[i - x] = cnt;
                cnt ++;
                x--;
            }
        }
    }

    if(v[0] != 0 && v[0] != -1) possible = false;
    v[0] = 0;

    if(!possible){
        cout << -1 << endl;
        return 0;
    }

    int required = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == 0) required ++;
    }
    int ansmx =0, ansmn = 0, active_sequence = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i] == -1){
            ansmx ++;
        } 
    }
    
    
    cout << required << " " << ansmx + required << endl;
    
}