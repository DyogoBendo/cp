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

int op1[] = {1, 0, -1};


void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for(int i = 0; i < n; i++) cin >> v[i];

    auto check = [&](){
        set<int> ap;
        int curr = -1;
        for(int i = 0; i < n; i++){
            if(v[i] != curr){
                if(ap.count(curr)) return false;
                ap.insert(curr);
                curr = v[i];
            }
        }
        if(ap.count(curr)) return false;
        return true;
    };

    if(check()){
        cout << "YES" << endl;
        return;
    }

    map<int, vector<pair<int, int>>> mp;

    int curr = v[0], cnt = 1;
    for(int i = 1; i < n; i++){
        if(v[i] != curr){
            mp[curr].push_back({i - cnt, i-1});
            curr = v[i];
            cnt = 1;
        } else{
            cnt++;
        }
    }
    mp[curr].push_back({n - cnt, n-1});

    vector<int> p1, p2;
    for(auto [x, k] : mp){
        if(sz(k) == 1) continue;
        
        p1.push_back(k[0].first);
        p1.push_back(k[0].second);
        p2.push_back(k.back().first);
        p2.push_back(k.back().second);
    }

    bool found = false;
    auto apply = [&](int x, int y){
        if(x >= n) return;
        if(y >= n) return;
        if(x < 0) return;
        if(y < 0) return;
        swap(v[x], v[y]);
        found |= check();
        swap(v[x], v[y]);
    };

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int a = 0; a < 3; a++){
                for(int b = 0; b < 3; b++){
                    apply(p1[i] + op1[a], p2[j] + op1[b]);
                }
            }
        }
    }

    cout << (found ? "YES" : "NO") << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}