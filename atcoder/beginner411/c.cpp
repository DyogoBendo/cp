#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, q;
    cin >> n >> q;

    int cnt = 0;

    vector<int> v(n + 1, 0);
    while(q--){
        int a;
        cin >> a;

        if(v[a] == 0){
            v[a] = 1;

            int increase = 0; 
            
            if((a == 1 or v[a - 1] == 0) and (a == n or v[a+1] == 0)){                
                increase = 1;            
            } 
            else if((a > 1 and v[a - 1] == 1) and (a <= n and v[a+1] == 1)){                
                increase = -1;                        
            } 

            cnt += increase;            
        } else{
            v[a] = 0;
            int increase = 0; 
            
            if((a == 1 or v[a - 1] == 0) and (a == n or v[a+1] == 0)){                
                increase = -1;            
            } 
            else if((a > 1 and v[a - 1] == 1) and (a <= n and v[a+1] == 1)){                
                increase = 1;                        
            } 
            
            cnt += increase;

        }
        cout << cnt << endl;

    }
}