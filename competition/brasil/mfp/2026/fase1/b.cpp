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

#define int ll

signed main(){
    darvem;
    string sa, sp;
    cin >> sa >> sp;

    vector<int> cnt_a(26), cnt_p(26);

    int qtd_a = sz(sa), qtd_p = sz(sp);
    for(int i = 0; i < sz(sa); i++){
        cnt_a[sa[i] - 'a']++;
    }

    for(int i = 0; i < sz(sp); i++){
        cnt_p[sp[i] - 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        int t, k;
        string s;
        cin >> t;

        if(t == 1){
            cin >> k >> s;

            for(int i = 0; i < sz(s); i++){
                cnt_a[s[i] - 'a'] += k;
                qtd_a += k;
            }

        } else if(t == 2){
            cin >> k >> s;
            for(int i = 0; i < sz(s); i++){
                cnt_p[s[i] - 'a'] += k;
                qtd_p += k;
            }
        } else{
            int pa = 0, pp = 0;
            bool ada_wins, found = false;;
            for(int i = 0; i < 26; i++){
                pa += cnt_a[i];
                pp += cnt_p[i];
                if(cnt_a[i] == cnt_p[i]) continue;

                found = true;
                int falta_a = qtd_a - pa;
                int falta_p = qtd_p - pp;
                if(cnt_a[i] < cnt_p[i]){
                    if(falta_a == 0){
                        ada_wins = true;
                    } else ada_wins = false;
                } else{
                    if(falta_p == 0) ada_wins = false;
                    else ada_wins = true;
                }
                break;
            }

            if(!found) cout << "EMPATE\n";
            else if(ada_wins) cout << "ADA\n";
            else cout << "PY\n";
        }   
    }
}