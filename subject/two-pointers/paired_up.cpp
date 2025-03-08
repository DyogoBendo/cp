// https://usaco.org/index.php?page=viewproblem2&cpid=738

#include <bits/stdc++.h>

#define int long long

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main(){
    setIO("pairup");

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].second >> v[i].first;
    }

    sort(v.begin(), v.end());

    int l = 0, r= n-1, ans = 0;
    while(l <= r){
        int qtd_smaller = v[l].second;
        int qtd_bigger = v[r].second;
        ans = max(ans, v[l].first + v[r].first);        

        if(qtd_smaller <= qtd_bigger){            
            l ++;
            v[r].second -= qtd_smaller;
        } 
        if(qtd_bigger <= qtd_smaller){
            v[l].second -= qtd_bigger;
            r--;            
        }
    }
    cout << ans << endl;
    
}