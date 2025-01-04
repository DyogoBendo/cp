//https://codeforces.com/contest/295/problem/A

#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long

signed main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    

    vector<ll> add(n + 2, 0);

    vector<tuple<int, int, int>> operations;

    for (int i = 0; i < m; i++)
    {        
        int l, r, d;
        cin >> l >> r >> d;

        operations.push_back({l, r, d});
    }    

    vector<ll> execute(m + 2, 0);
    while(k--){
        int x, y;
        cin >> x >> y;
        execute[x] ++;  
        execute[y+1] --;
    }

    for (int i = 0; i < m; i++)
    {
        execute[i + 1] += execute[i];        
        int l = get<0>(operations[i]), r = get<1>(operations[i]), d = get<2>(operations[i]);
        int e = execute[i + 1];
        
        add[l] += (e * d);
        add[r + 1] -= (e * d);
    }            

    for (int i = 1; i <= n; i++)
    {
        add[i] += add[i - 1];           
        cout << v[i] + add[i] << " ";
    }
    cout << endl;
}