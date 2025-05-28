#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int x, y, k;

    cin >> x >> y >> k;


    map<int, int> factorsx, factorsy;
    
    for (int i = 2; i * i <= x; i++)
    {
        int cnt = 0;
        while(x % i == 0){
            cnt++;
            x /= i;
        }
        
        if(cnt){
            factorsx[i] = cnt;            
        }
    }
    
    if(x > 1){
        factorsx[x] =1;                
    }
    
    for (int i = 2; i * i <= y; i++)
    {
        int cnt = 0;
        while(y % i == 0){
            cnt++;
            y /= i;
        }
        
        if(cnt){
            factorsy[i] = cnt;            
        }
    }
    
    if(y > 1){
        factorsy[y] =1;                
    }
    
    int ans = 0;
    bool possible = true;    
    priority_queue<int> qrem, qins;
    for (auto [p, cnt] : factorsx)
    {        
        // cout << "p: " << p << " cnt: " << cnt << endl;
        if(factorsy[p] != cnt){
            if(p > k){
                possible = false;
                break;
            } 

            if(factorsy[p] > cnt){
                int diff = factorsy[p] - cnt;
                while(diff--){
                    qins.push(-p);
                }
            } else{
                int diff = abs(factorsy[p] - cnt);
                while(diff--){
                    qrem.push(-p);
                }
            }   
        }        
    }
        
    for (auto [p, cnt] : factorsy)
    {
        if(!factorsx[p]){
             if(p > k){
                possible = false;
                break;
            } 
            int diff = cnt;
            while(diff--){
                qins.push(-p);
            }
        }
    }

    bool here = false;
    while(!qins.empty()){
        if(qins.size() == 1){
            ans ++;
            qins.pop();
        } else{
            int t1 = qins.top(); qins.pop();
            int t2 = qins.top();qins.pop();
            if(t1 * t2 <= k){
                here = true;
                qins.push(-t1*t2);
            } else{
                ans += 2;
            }
        }
    }

    while(!qrem.empty()){
        if(qrem.size() == 1){
            ans ++;
            qrem.pop();
        } else{
            int t1 = qrem.top(); qrem.pop();
            int t2 = qrem.top();qrem.pop();
            if(t1 * t2 <= k){
                here = true;
                qrem.push(-t1*t2);
            } else{
                ans += 2;
            }
        }        
    }
    
    cout << (possible ? ans - here : -1) << endl;
}


signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}