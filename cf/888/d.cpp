#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<long long> values(n, 0);
    vector<long long> checked(n + 1, 0);

    for (int i = 1; i < n; i++)
    {
        long long x;
        cin >> x;
        values[i] = x;
    }

    long long rep = 0;    

    for (int i = 1; i < n; i++)
    {
        long long v = values[i] - values[i - 1];        
        if(v > n){
            rep = v;
            continue;
        }
        if(!checked[v]){
            checked[v] = 1;
        } else{
            rep = v;
        }
    }    
    
    long long missingA = 0;
    long long missingB = 0;

    int found = 0;

    for (int i = 1; i <= n; i++)
    {
        if(!checked[i]){
            if(!missingA) missingA = i;
            else missingB = i;
        } else{
            found ++;
        }       
    }

    if(found < n - 2){
        cout << "NO" << endl;
        return;
    }
    
    if(missingA + missingB == rep || found == n - 1){
        cout << "YES" << endl;        
    } else{
        cout << "NO" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}