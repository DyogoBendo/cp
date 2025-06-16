#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int K = 16112024;

signed main(){
    darvem;

    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<int> divisores;

    for (int i = 1; i * i <= K; i++)
    {
        if(K % i == 0){
            divisores.insert(i);
            divisores.insert(K/i);
        }
    }
    
    map<int, vector<int>> m;
    m[1] = vector<int>();
    for (int i = 0; i < n; i++)
    {
        vector<pair<int, vector<int>>> add;

        for (auto [x, s] : m)
        {
            if(divisores.count(x * v[i])){
                vector<int> tmp = s;
                tmp.push_back(v[i]);
                add.push_back({x * v[i], tmp});
            }
        }
        for (auto [x, s] : add)
        {            
            m[x] = s;
        }                
    }

    cout << m[K].size() << endl;
    for (auto a : m[K])
    {
        cout << a << " ";
    }
    if(m[K].size()) cout << endl;
}