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

char oc[26];
char ocw[26];

const int B1 = 257, B2 = 3023;
const int M1 = 1e9+9, M2 = 1e9+7;

signed main(){
    darvem;

    string n, h;
    cin >> n >> h;    
    
    for(int i = 0; i < sz(n); i++) oc[n[i] - 'a']++;
    for(int i = 0; i < sz(n) - 1; i++) ocw[h[i] - 'a']++;

    vector<int> hash1(sz(h) + 1);
    vector<int> powb1(sz(h) + 1);

    vector<int> hash2(sz(h) + 1);
    vector<int> powb2(sz(h) + 1);

    powb1[0] = 1; powb2[0] = 1;
    for(int i = 0; i < sz(h); i++){
        hash1[i + 1] = ((1LL * hash1[i] * B1) + h[i]) % M1;
        powb1[i+1] =  1LL * powb1[i] * B1 % M1;

        hash2[i + 1] = ((1LL * hash2[i] * B2) + h[i]) % M2;
        powb2[i+1] =  1LL * powb2[i] * B2 % M2;
    }

    set<pair<int, int>> st;    
    
    for(int i = sz(n) - 1; i < sz(h); i++){
        ocw[h[i] - 'a']++;
        
        bool permt = true;
        for(int j = 0; j < 26; j++){
            if(oc[j] != ocw[j]){                
                permt = false;
                break;
            } 
        }

        if(permt){            
            int x1 = (hash1[i] + M1 - (1LL * hash1[i - sz(n) + 1] * powb1[sz(n) - 1]) % M1 ) % M1;             
            int x2 = (hash2[i] + M2 - (1LL * hash2[i - sz(n) + 1] * powb2[sz(n) - 1]) % M2 ) % M2;             
            st.insert({x1, x2});                        
        }

        ocw[h[i - sz(n) + 1] - 'a']--;
    }        

    cout << st.size() << endl;
}