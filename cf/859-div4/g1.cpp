#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    vector<long long> v;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        v.push_back(x);
    }

    sort(v.begin(), v.end());
    

    int possible = 1;
    long long current_biggest = 0;
    for (int i = 0; i < n; i++)
    {
        if(!possible) break;
        if(i == 0){
            if(v[i] > 1) possible = 0;
            else current_biggest = 1;
        }
        else{
            if(v[i] <= current_biggest){
                current_biggest += v[i];
            }
            else{
                possible = 0;
            }
        }
    }

    if(possible) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}