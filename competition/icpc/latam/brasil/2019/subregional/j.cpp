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

    int n, k;
    cin >> n >> k;
    
    k--;    
    map<char, int> mp = {{'A', 0}, {'D', 10}, {'Q', 11}, {'J',12}, {'K',13}};
    vector<vector<int>> curr_cards(n, vector<int>(14));
    vector<int> mico_state(n);
    mico_state[k] = 1;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < 4; j++){
            int x = s[j] >= '1' and s[j] <= '9' ? s[j] - '0' : mp[s[j]];
            curr_cards[i][x]++;
        } 
    }

    for(int i = 0; i < n; i++)if(i != k){        
        for(int j = 0; j < 14; j++) if(curr_cards[i][j] == 4){
            cout << i+1 << endl;
            return 0;
        }
    }   

    int curr_player = k;
    while(1){
        int prox_player = (curr_player+1) % n;
        if(mico_state[curr_player] == 2){
            mico_state[curr_player] = 0;
            mico_state[prox_player] = 1;
        } else{
            if(mico_state[curr_player] == 1) mico_state[curr_player] = 2;
            int cnt = 5, card = -1;
            for(int i = 0; i < 14; i++){
                int c = curr_cards[curr_player][i];
                if(c and c < cnt){
                    cnt = c;
                    card= i;
                }
            }
            curr_cards[curr_player][card]--;
            curr_cards[prox_player][card]++;
        }
        if(mico_state[curr_player] == 0){
            for(int i = 0; i < 14; i++) if(curr_cards[curr_player][i] == 4){
                cout << curr_player + 1 << endl;
                return 0;
            }
        }        
        curr_player = prox_player;
    }
}