#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int INF = 1e9;
int n, w, lst;
vector<int> ans;
vector<int> wsz;

bool check(int max_line){    
    vector<int> dp(n, INF);
    dp[0] = 0;

    vector<int> prev(n, -1);        

    int bst = INF, ln = -1;
    for (int i = 0; i < n; i++)
    {                    
        int curr = wsz[i];
        for (int j = 0; j < max_line; j++)
        {            
            if(i + j + 1 >= n){
                if(curr + dp[i] < bst){
                    ln = i;
                }
                bst = min(curr + dp[i], bst);
            } else{
                if(curr + dp[i] + 1 < dp[i+j+1]){                    
                    dp[i+j+1] = curr + dp[i] + 1;
                    prev[i+j+1] = i;                    
                }                
                curr = max(curr, wsz[i + j + 1]);
            }

        }             
    }       
    if(bst <= w){        
        for(int i = 0; i < n; i++)ans[i] = prev[i];                
        lst = ln;
        return true;
    }
    return false;
}

signed main(){
    darvem;

    cin >> n >> w;
    ans.resize(n);
    wsz.resize(n);

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
        wsz[i] = (int) words[i].size();
    }    
    
    int lo = 0, hi = n + 1;
    while(lo < hi){        
        int m = (hi - lo) / 2 + lo;                   

        if(check(m)){            
            hi = m;
        } else{            
            lo = m + 1;
        }        
    }    

    vector<int> sza;
    vector<vector<string>> words_ans;    
    
    int st = lst, en = n;

    
    while(en > 0){
        int curr = 0;                
        vector<string> wa;
        for(int i = en - 1; i>=st; i--){
            curr = max(curr, wsz[i]);            
            wa.push_back(words[i]);
        }
        en = st;
        st = ans[st];
        reverse(wa.begin(), wa.end());
        words_ans.push_back(wa);
        sza.push_back(curr);
    }

    reverse(sza.begin(), sza.end());
    reverse(words_ans.begin(), words_ans.end());

    cout << hi << " " << sza.size() << endl;
    for (auto sz : sza)
    {
        cout << sz << " ";
    }
    cout << endl;    
    
    for (int i = 0; i < hi; i++)
    {
        for (int j = 0; j < (int) words_ans.size(); j++)
        {
            string s = words_ans[j].size() > i ? words_ans[j][i] : " ";
            cout << left << setw(sza[j] + 1) << s;
        }
        cout << endl;
    }      
}