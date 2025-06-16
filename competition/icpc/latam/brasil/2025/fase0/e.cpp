#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

signed main(){
    darvem;

    int y, k;
    cin >> y >> k;

    vector<int> divisores;

    for (int i = 1; i * i <= y; i++)
    {
        if(y % i == 0){
            divisores.push_back(i);
            if(y/i != i){
                divisores.push_back(y/i);
            }
        }
    }
    
    sort(divisores.begin(), divisores.end());

    int x = 1;
    int idx = 0;
    while(k && idx < divisores.size() - 1){
        int iprox = idx+1;
        while(iprox < divisores.size()){
            if(divisores[iprox] % divisores[idx] == 0) break;
            iprox++;
        }        
        int prox = divisores[iprox];
        int dst = (prox - x) / divisores[idx];

        k -= min(k, dst);        
        x += dst * divisores[idx];
        idx = iprox;
    }

    if(k){
        x += k*y;
    }
    cout << x << endl;
    
}