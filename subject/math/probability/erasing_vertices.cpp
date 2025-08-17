#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int n;
void dfs(int curr, vector<string> &g, vector<int> &visited){
    if(visited[curr]) return;
    visited[curr] = 1;

    for(int i = 0; i < n; i++){
        if(g[curr][i] == '1') dfs(i, g, visited);
    }
    
}

signed main(){
    darvem;

    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];

    vector<int> arrive(n);

    for(int i = 0; i < n; i++){
        vector<int> visited(n);
        dfs(i, g, visited);
        for(int j = 0; j < n; j++){
            if(visited[j]) arrive[j]++;
        }
    }

    double ans = 0;
    for(int i = 0; i < n; i++){
        ans += (double) 1.0 / arrive[i];
    }

    cout << fixed << setprecision(12) << ans << endl;

}