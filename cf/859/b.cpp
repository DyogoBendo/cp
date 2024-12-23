#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int even = 0;
    int odd = 0;
    vector<int> e;
    vector<int> o;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(x % 2){
            o.push_back(x);
            odd += x;
        } else{
             even += x;
             e.push_back(-x);
        }
        
    }

    if(odd >= even){
        cout << "NO" << endl;
        return;
    }    
    cout << "YES" << endl;
    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}