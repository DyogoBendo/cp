#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int is_2pow(int x){
    int curr = 1;
    while(curr <= 8){
        if(x == curr) return 1;
        curr <<=1;
    }
    return 0;    
}

void solve(){
    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        if(v[i] % 5 == 0){
            if(s.size() && !s.count(v[i])){
                cout << "No" << endl;
                return;
            }
            s.insert(v[i]);
            if(v[i] % 10 != 0){
                s.insert(v[i] + 5);
            } else{
                s.insert(v[i] - 5);
            }
        }
    }
    

    int cnt[3] = {};    

    for (int i = 0; i < n; i++)
    {
        if(v[i] % 5 == 0){            
            cnt[0] ++;
        } 
        else{
            int lst_digit = v[i] % 10;
            int second_digit = (v[i] / 10) % 10;         
            

            if(second_digit % 2 == is_2pow(lst_digit)){                  
                cnt[1] ++;
            }else{                
                cnt[2] ++;
            } 
        }
    }
    
    int total = (cnt[0] != 0) + (cnt[1] != 0) + (cnt[2] != 0);    
    
    if(total > 1){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}