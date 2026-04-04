#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(0); cin.tie(0)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int) (a).size()
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do{ cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

int exists[11][11][26];

signed main(){
    darvem;

    int n, m;
    cin >> n;
    vector<int> av(n), bv(n);
    for(int i = 0; i < n; i++) cin >> av[i] >> bv[i];

    cin >> m;
    vector<string> vs(m);
    for(int i = 0; i < m; i++) cin >> vs[i];    

    for(int i = 0; i < m; i++){
        int tam = sz(vs[i]);
        for(int j = 0; j < tam; j++){
            exists[tam][j][vs[i][j] - 'a'] = 1;
        }
    }

    for(int i = 0; i < m; i++){
        int tam = sz(vs[i]);
        if(tam != n){
            cout << "No" << endl;
            continue;
        }
        bool possible = true;
        for(int j = 0; j < n; j++){            
            if(!exists[av[j]][bv[j]-1][vs[i][j] - 'a']) possible = false;
        }

        cout << (possible ? "Yes" : "No") << endl;
    }
}