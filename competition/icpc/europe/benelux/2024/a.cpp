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

    int n, m, r;
    cin >> n >> m >> r;

    vector<tuple<string, int, int>> submissions(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        submissions[i] = {s, 0, i+1};        
    } 

    int idx = n - 1;
    while(1){
        if(idx < 0) break;        
        auto &[submission, pos, id] = submissions[idx];
        dbg(submission, pos, id);
        if(pos == m){
            idx --;
            continue;
        }
        pos++;
        if(submission[pos-1] == 'P'){            
            string result;
            cin >> result >> result;
            dbg(result);
            int cnt = 0;
            int i = 6;
            while(result[i] == 'y') cnt++, i++;
            for(int j = 0; j < cnt; j++) swap(submissions[idx-j], submissions[idx-j-1]);
        }
    }    

    for(int i = 0; i < n; i++) if(get<2>(submissions[i]) == r) cout << i+1 << endl;
}