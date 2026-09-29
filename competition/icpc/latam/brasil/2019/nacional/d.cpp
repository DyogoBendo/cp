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

const ld PI = acos(-1.0);
const ld EPS = 1e-11;

const int B = 1001;
vector<pair<int, int>> pts[B]; 

signed main(){
    darvem;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
        pair<int, int> p;
        int b;
        cin >> p.first >> p.second >> b;        
        pts[b].push_back(p);
    }

    vector<double> angles;

    for(int i = 0; i < B; i++){
        for(int j = 0; j < i; j++){
            for(auto a : pts[i]){
                for(auto b : pts[j]){
                    angles.push_back(atan2(a.second - b.second, a.first - b.first));
                }
            }
        }
    }

    if(!(sz(angles))){
        cout << "Y" << endl;
        return 0;
    }

    sort(angles.begin(), angles.end());

    double max_gap = 0;
    for (int i = 0; i < angles.size() - 1; i++) {
        max_gap = max(max_gap, angles[i+1] - angles[i]);
    }

    double wrap_around_gap = (2.0 * PI - angles.back()) + angles.front();
    max_gap = max(max_gap, wrap_around_gap);

    cout << (max_gap >= PI - EPS ? "Y" : "N") << endl;    
}