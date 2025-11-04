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

const int MAX = 1e3+1;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

signed main(){
    darvem;

    int n = 5;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;

    ll ans = 0;
    vector<int> removed(n);
    while(1){
        bool update = false;
        for(int i = 0; i < n; i++) if(!removed[i]){
            auto [x, y] = v[i];
            dbg(i, x, y);
            bool left = false, right= false, top= false, bot= false;
            int cnt = 0;
            for(int j = 0; j < n; j++) if(i != j and !removed[j]){                
                auto [x2, y2] = v[j];
                dbg(j, x2, y2);
                if(x2 == x and y2 == y) removed[j] = 1;
                else{
                    cnt++;
                    if(x2 <= x) left = true;
                    if(x2 >= x) right = true;
                    if(y2 <= y) bot = true;
                    if(y2 >= y) top = true;
                }
            }
            if(cnt >= 1){                
                if(!left){
                    v[i].first++;
                    ans++;
                    update=true;
                } 
                if(!right){
                    v[i].first--;
                    ans++;
                    update=true;  
                }                 
                if(!bot){
                    ans++;
                    update=true; 
                    v[i].second++;
                } 
                if(!top){
                    ans++;
                    update=true; 
                    v[i].second--;            
                } 
            }
            dbg(i, x, y, left, right, top, bot, ans);
        }
        if(!update) break;
    }
    
    vector<int> xv, yv;
    for(int i = 0; i < n; i++) if(!removed[i]){
        dbg(i);
        xv.push_back(v[i].first);
        yv.push_back(v[i].second);
    }
    sort(xv.begin(), xv.end());
    sort(yv.begin(), yv.end());

    int l = xv[0], r = xv.back(), b = yv[0], t = yv.back();

    ans += 2*(t - b) + 2*(r - l);    
    for(int i = 0; i < 5; i++)if(!removed[i]){
        auto [mx, my] = v[i];    
        if(my != b and my != t and mx != l and mx != r){    
            dbg(mx, my, t-b, r-l);        
            ans += min(t - b, r - l);
        }
        
    }
    
    cout << ans << endl;
    
    
}