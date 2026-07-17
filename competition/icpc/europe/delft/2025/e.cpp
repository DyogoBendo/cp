#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int) a.size())
#define ll long long
#define ld long double

void dbg_out(string s) { cerr << endl; }
template<typename H, typename... T>
void dbg_out(string s, H h, T... t){
    do {cerr << s[0]; s = s.substr(1);
    } while (sz(s) && s[0] != ',');
    cerr << " = " << h;
    dbg_out(s, t...);
}

#ifdef DEBUG
#define dbg(...) dbg_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int MAXN = 1e3 + 10;
int v[MAXN];
bool found = false;
int n;
int limit = 0;

void query(int l, int r){
    l++, r++;
    cout << l << " " << r << endl;
    for(int i = 0; i < n; i++) cin >> v[i];
    int p;
    cin >> p;
    if(p >= 70) found = true;
}

void solution(){
    cin >> n;

    while(!found and limit < 125){
        limit++;
        vector<int> psum(n+1);
        for(int i = 1; i <= n; i++) psum[i] = psum[i-1] + v[i-1];

        int l = -1, r = -1, bst = -1, tam = -1;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                int tot_one = 2*(psum[j+1] - psum[i]);
                int expected = j - i + 1;
                if(expected - tot_one > bst){
                    bst = expected - tot_one;
                    l = i;
                    r = j;
                    tam = j - i + 1;
                } else if(expected - tot_one == bst and (j -i + 1) > tam){
                    l = i;
                    r = j;
                    tam = j - i + 1;
                }
            }
        }
        query(l, r);
    }

    assert(limit < 125);
}

signed main(){
    fastio;
    int cases = 1;

    for (int i = 0; i < cases; i++)
    {
        solution();
    }
    
}