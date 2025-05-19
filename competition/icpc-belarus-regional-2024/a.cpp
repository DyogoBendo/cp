#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<int> dst;

    map<int, int> m, ml;    

    for (int i = 0; i < n-1; i++)
    {
        int x = v[i+1]-v[i];
        if(!ml[x]){
            ml[x] = i;
        }        
        dst.push_back(x);
    }        

    vector<int> ans, curr;    
    auto solve = [&](int x, int l){   
        vector<int> dst_tmp = dst;           
        int changes= 0;
        for (int i = l-1; i >= 0; i--)
        {        
            if(changes > k) return n;            
            if(dst_tmp[i] != x){            
                ans.push_back(i);
                if(i == 0){
                    changes++;
                } else{
                    changes++;
                    dst_tmp[i-1] += dst_tmp[i];
                }
            }
        }
        for (int i = l+1; i < n-1; i++)
        {        
            if(changes > k) return n;            
            if(dst_tmp[i] != x){
                ans.push_back(i);
                if(i == n-2){
                    changes++;
                } else{
                    changes++;
                    dst_tmp[i+1] += dst_tmp[i];
                }
            }
        }
        
        return changes;
    };

    int bst = n;    

    for (auto [x, l] : ml)
    {
        int s = solve(x, l);        
        if(s < bst){
            bst = s;                  
            curr = ans;            
            
        }
        ans.clear();
    }

        
    if(bst > k){
        cout << -1 << endl;
    } else{
        sort(curr.begin(), curr.end());
        cout << curr.size() << endl;
        for (auto a : curr)
        {
            cout << a+1 << " ";
        }
        cout << endl;
        
    }
    
}
