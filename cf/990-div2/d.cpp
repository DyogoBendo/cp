#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++)
    {        
        cin >> v[i].first;
        v[i].second = i;
    }

    sort(v.begin(), v.end());

    vector<int> ans(n);
    
    int idx = -1;        
    vector<int> found_values;    
    vector<int> missing;    
    for (int i = 0; i < n; i++)
    {
        if(v[i].second > idx){                                    
            found_values.push_back(v[i].first);
            idx = v[i].second;
        } else{
            missing.push_back(v[i].first + 1);
        }
    }    
    
    int found = 0;
    int a = 0;
    int b = 0;

    for (int i = 0; i < n; i++)
    {        
        if(a == found_values.size()){            
            ans[i] = missing[b];
            b++;
        }
        else if(b == missing.size()){            
            ans[i] = found_values[a] + found;
            a++;
        } else{            
            if(missing[b] < found_values[a] + found){                
                found = 1;                
                ans[i] = missing[b];
                b++;
            } else{                
                ans[i] = found_values[a] + found;
                a++;
            }
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}