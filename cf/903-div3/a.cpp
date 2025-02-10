#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    string x, s;
    cin >> n >> m;
    cin >> x >> s;

    // preciso achar o index inicial que aparece o primeiro caracter 

    vector<int> index(m,  -1);

    int current = 0;
    for (int i = 0; i < m; i++)
    {
        int started = current;
        int found = 1;

        while(x[current] != s[i]){
            current ++;

            if(current == n) current = 0;
            if(current == started){
                break;
                found = 0;
            }
        }
        cout << "i: " << i << endl;
        cout << "current: " << current << endl;
        cout << endl;
        if(!found) continue;
        index[i] = current;
    }

    int possible = 1;
    for (int i = 0; i < m; i++)
    {        
        if(index[i] == -1) possible = 0;
    }

    int ans = 0;
    for (int i = 1; i < m; i++)
    {        
        if(index[i] == index[i - 1] + 1) continue;
        if(index[i] == 0 && index[i - 1] == n - 1) continue;        
        possible = 0;
    }
    
    
    if(possible) {
        int si = index[0];
        int size = n - si;
        while(size < m){
            size += n;
            n += n;
            ans ++;
        }
        cout << ans << endl;
    } else{
        cout << -1 << endl;
    }
    

}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}