#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 5e4;
const int MOD = 1e9+7;

ll dp[MAXN];
vector<int> palindromes;

void get_pal(){
    vector<vector<string>> pal(6);

    for (int i = 1; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(i == 1){
                pal[i].push_back(to_string(j));
                if(j != 0){
                    palindromes.push_back(j);
                }
            }
            else if(i == 2){
                string curr = to_string(j) + to_string(j);
                pal[i].push_back(curr);
                if(j != 0){
                    palindromes.push_back(stoi(curr));
                }
            } else{                
                for (auto p : pal[i - 2])
                {                    
                    string curr = to_string(j);
                    curr += p;
                    curr += to_string(j);
                    pal[i].push_back(curr);     
                    if(j != 0){
                        palindromes.push_back(stoi(curr));
                    }                  
                }                
            }
        }        
    }
            
}

void init(){
    get_pal();
    dp[0] = 1;    
    
    for (auto p : palindromes){
        for (int i = 0; i < MAXN; i++)
        {
            int x = i + p;
            if(x >= MAXN) break;
            dp[x] += dp[i];
            dp[x] %= MOD;
        }
        
    }
}

void solve(){
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

signed main(){
    init();
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}