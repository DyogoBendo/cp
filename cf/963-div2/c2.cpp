#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());        
        
        int lst = v.back();        
        
        int l = lst;
        int r = lst + k;        
                
        for(int i = 0; i < n-1; i++){            
            int y = (lst - v[i]) / (2*k);
            int li = 2*k*y + v[i];
            int ri = li + k;                      
                    
            if(ri < lst){
                li += 2*k;
                ri += 2*k;
            }            

            l = max(l, li);
            r = min(r, ri);
        }
        
        if(l >= r) cout << -1 << endl;
        else cout << l << endl;
    }
}