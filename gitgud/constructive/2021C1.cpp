#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, q1;
    cin >> n >> m >> q1;

    queue<int> q;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    set<int> s;

    bool possible = true;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;

        if(s.find(x) != s.end()) continue;

        if(q.front() == x){
            q.pop();
            s.insert(x);
        } else{
            possible = false;
        }
    }

    if(!possible) cout << "TIDAK" << endl;
    else cout << "YA" << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}