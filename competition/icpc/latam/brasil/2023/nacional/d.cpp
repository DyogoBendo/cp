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

    int n;
    cin >> n;    

    vector<string> words(n);
    for(int i = 0; i < n; i++) cin >> words[i];

    vector<string> guess(n);
    for(int i = 0; i < n; i++){
        string curr = "";
        for(int j = 0; j < 5; j++){
            if(words[0][j]== words[i][j]) curr += "*";
            else{
                bool found = false;
                for(int k = 0; k<= 5; k++) if(words[0][k] == words[i][j]) found = true;
                if(found) curr += "!";
                else curr += "X";
            }
        }
        guess[i] = curr;
    }

    int g;
    cin >> g;
    for(int i = 0; i < g; i++){
        string curr;
        cin >> curr;
        int cnt = 0;
        for(auto s : guess)  if(s == curr) cnt++;
        cout << cnt << endl;
    }
}