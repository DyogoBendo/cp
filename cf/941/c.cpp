#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    set<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.insert(x);
    }

    vector<int> values;

    for (auto x: v)
    {
        values.push_back(x);
    }
    

    if(values.size() == 1){
        cout << "Alice" << endl;
        return;
    }
    
    if(values[values.size() - 1] % 2){
        cout << "Bob" << endl;
    } else{
        cout << "Alice" << endl;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t --) solve();
}