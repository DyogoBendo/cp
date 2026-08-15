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

int notes[] = {1, 2, 5, 10, 20, 50, 100, 200, 500};
const int MAXN = 1e4 + 10;
bitset<MAXN> dp;

bool check(int x, vector<int> &v){
    if(x & 1) return false;
    dp.reset();

    dp.set(0);
    for(int i = 0; i < sz(v); i++) dp |= dp << v[i];    
    
    return dp[x/2];
}

void add(int x, int y, vector<int> &v){
    while(y--) v.push_back(x);
}

signed main(){
    darvem;

    int n;
    cin >> n;

    int cur1, cur2, cur5, cur10, cur20, cur50, cur100, cur200;
    for(int a1 = 0; a1 <= 1; a1++){        
        cur1 = a1*1;           

        for(int a2 = 0; a2 <= 4; a2++){
            cur2 = a2*2;            
            if(cur1 + cur2 > n) break;

            for(int a5 = 0; a5 <= 1; a5++){
                cur5 = a5*5;
                if(cur1 + cur2 + cur5 > n) break;

                for(int a10 = 0; a10 <= 1; a10++){
                    cur10 = a10*10;
                    if(cur1 + cur2 + cur5 + cur10 > n) break;

                    for(int a20 = 0; a20 <= 4; a20++){
                        cur20 = a20*20;
                        if(cur1 + cur2 + cur5 + cur10 + cur20 > n) break;

                        for(int a50 = 0; a50 <= 1; a50++){
                            cur50 = a50*50;
                            if(cur1 + cur2 + cur5 + cur10 + cur20 + cur50 > n) break;
                            for(int a100 = 0; a100 <= 1; a100++){
                                cur100 = a100*100;
                                if(cur1 + cur2 + cur5 + cur10 + cur20 + cur50 + cur100 > n) break;
                                for(int a200 = 0; cur1 + cur2 + cur5 + cur10 + cur20 + cur50 + cur100 + a200*200 <= n; a200++){
                                    cur200 = a200*200;
                                    if(cur1 + cur2 + cur5 + cur10 + cur20 + cur50 + cur100 + cur200 > n) break;

                                    int rem = n - (cur1 + cur2 + cur5 + cur10 + cur20 + cur50 + cur100 + cur200);
                                    if(rem%500 == 0){
                                        int a500 = rem/500;                                        

                                        vector<int> cand;
                                        add(1, a1, cand);
                                        add(2, a2, cand);
                                        add(5, a5, cand);
                                        add(10, a10, cand);
                                        add(20, a20, cand);
                                        add(50, a50, cand);
                                        add(100, a100, cand);
                                        add(200, a200, cand);
                                        add(500, a500, cand);

                                        if(!check(n, cand)){
                                            cout << sz(cand) << endl;
                                            for(auto x : cand) cout << x << " ";
                                            cout << endl;
                                            return 0;
                                        }
                                    }                                     
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    cout << "splittable" << endl;

}