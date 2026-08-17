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

const int MAXW = 900;

signed main(){
    darvem;

    int n, h, w;
    cin >> n >> h >> w;

    vector<tuple<int, int, int>> books(n);
    for(int i = 0; i < n; i++){
        int f, s;
        cin >> f >> s;
        books[i] = {f, s, i+1};
    }

    sort(books.rbegin(), books.rend());

    bool can = true;
    vector<int> standing;
    int curr_stand_width = 0;
    for(int i = 0; i < n and can; i++){
        // use the currently the largest in the bottom, so all the previous should be used as standing
        int left_width = w - curr_stand_width - get<0>(books[i]);
        int left_height = h - get<1>(books[i]);

        if(left_width >= 0){
            vector<int> curr_laying;
            curr_laying.push_back(get<2>(books[i]));
    
            // do magic    
            vector<int> dp(left_width+1);                       
    
            dp[0] = -1;
            int mx = 0;
            for(int j = i+1; j < n; j++){
                if(get<0>(books[j]) > h) continue;
                for(int k = left_width - get<1>(books[j]); k >= 0; k--){
                    if(dp[k] and !dp[k+get<1>(books[j])]) dp[k + get<1>(books[j])] = j, mx = max(mx, k + get<1>(books[j]));
                }
            }
            
            vector<int> is_standing(n), curr_standing;
            int curr = mx;
            dbg(curr, dp[curr]);
            while(dp[curr] != -1){
                dbg(dp[curr], get<2>(books[dp[curr]]));
                is_standing[dp[curr]] = 1;
                curr_standing.push_back(get<2>(books[dp[curr]]));

                curr = curr - (get<1>(books[dp[curr]]));
            }
                
            for(int j = i+1; j < n; j++) if(!is_standing[j]){
                left_height -= get<1>(books[j]);
                curr_laying.push_back(get<2>(books[j]));
            }

            if(left_height >= 0 and sz(curr_standing) + sz(standing) > 0){
                cout << "upright";
                for(auto x: standing) cout << " " << x;
                for(auto x: curr_standing) cout << " " << x;
                cout << endl;

                cout << "stacked";
                for(auto x : curr_laying) cout << " " << x;
                cout << endl;
                return 0;
            }
        }


        if(get<0>(books[i]) <= h) curr_stand_width += get<1>(books[i]);
        else can = false;

        if(curr_stand_width > w) can = false;

        standing.push_back(get<2>(books[i]));
    }

    cout << "impossible" << endl;
}