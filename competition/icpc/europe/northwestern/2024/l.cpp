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

signed main(){
    darvem;

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<int> shelves(n), books(m);
    for(int i = 0; i < n; i++) cin >> shelves[i];
    for(int i = 0; i < m; i++) cin >> books[i];

    sort(shelves.begin(), shelves.end());
    sort(books.begin(), books.end());
    auto check = [&](int k){
        int curr = 0;                
        int av = k ? y : x;
        for(int i = 0; i < m; i++){
            while(curr < n and books[i] > shelves[curr]){
                curr ++;
                av = curr < k ? y : x;
            } 
            if(curr == n) return false;
            av--;
            if(av == 0){
                curr ++;
                av = curr < k ? y : x;
            }
        }
        return true;
    };

    int lo = 0, hi = n+1;
    while(lo < hi){
        int mid = (hi - lo) / 2 + lo;
        if(check(mid)) lo = mid + 1;
        else hi = mid;
    }
    if(lo == 0) cout << "impossible" << endl;
    else cout << lo-1 << endl;
}