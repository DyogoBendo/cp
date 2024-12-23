#include <bits/stdc++.h>

#define int long long
using namespace std;

signed main(){
    int n, e, q;
    cin >> n >> e;

    int maior_todos = 1;

    while(maior_todos < 1e9 + 1){
        maior_todos *= 2;
    }    


    int v = 0;

    set<int> s;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v ^= x; 
    }

    for (int i = 0; i < e; i++)
    {
        int x; 
        cin >> x;        
        int inicio = 0;
        int p = 1;
        
        while(x){            
            if(x % 2 == 0){
                inicio += p;
            }            
            p *= 2;
            x /= 2;            
        }
        
        s.insert(inicio);
        for (int j = p; j <= maior_todos; j*= 2)
        {            
            inicio += j;
            s.insert(inicio);
        }
    
    }

    cin >> q;
    int ans = 0;
    if(s.find(v) != s.end()){
            ans ++;
    }
    for (int i = 0; i < q; i++)
    {
        char c;
        int x;
        cin >> c >> x;

        v^= x;        

        if(s.find(v) != s.end()){
            ans ++;
        }
    }

    cout << ans << endl;
}