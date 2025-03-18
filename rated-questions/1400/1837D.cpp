#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int abre = 0;
    int fecha = 0;

    for (auto c : s)
    {
        if(c == '(') abre ++;
        else fecha++;
    }

    if(abre!= fecha){
        cout << -1 <<endl;
        return;
    }

    vector<int> ans(n, 1);

    auto check1 = [&](){
        bool possible = true;
        queue<int> q;    
        for (int i = 0; i < n; i++)
        {
            if(s[i] == '('){            
                q.push(i);
            } else{
                if(!q.empty()){
                    int a = q.front();q.pop();
                    ans[a] = 0;
                    ans[i] = 0;
                } else{
                    possible = false;
                }
            }
        }    
        return possible;
    };

    auto check2 = [&](){
        bool possible = true;
        int x = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            if(s[i] == '('){            
                x++;
            } else{
                if(x){
                    x--;
                } else{
                    possible = false;
                }
            }
        }    
        return possible;
    };

    bool single = check1() || check2();        
    cout << (single?1 : 2) << endl;
    for (int i = 0; i < n; i++)
    {
        cout << (single? 1 : ans[i] + 1) << " ";
    }
    cout << endl;    
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}