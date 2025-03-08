#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> students(n);    
    for(int &x: students) cin >> x;    

    sort(students.begin(), students.end());
    
    int l = 0, r = 0, ans = 1e6, diff = 0;
    vector<int> cnt(m + 1, 0);    
    while(l < n){
        while(r < n && diff != m){            
            for(int x = 1; x <= m && x*x <= students[r]; x++){
                if(students[r] % x == 0){
                    cnt[x]++;
                    if(cnt[x] == 1) diff++;
                    int d = students[r]/x;
                    if(d <= m && d != x){
                        cnt[d]++;
                        if(cnt[d] == 1) diff++;
                    }                    
                }
            }
            r++;
        }
        if(diff == m){                        
            ans = min(ans, students[r-1] - students[l]);
        } 
        for(int x = 1; x <= m && x*x <= students[l]; x++){
            if(students[l] % x == 0){
                cnt[x]--;
                if(cnt[x] == 0){                    
                    diff--;
                } 
                int d = students[l]/x;
                if(d <= m && d!= x){
                    cnt[d]--;
                    if(cnt[d] == 0){                        
                        diff--;
                    } 
                }
            }
        }        
        l++;
    }

    if(ans == 1e6) cout << -1 << endl;
    else cout << ans << endl;
}

signed main(){
    flash;
    int t = 1;    
    cin >> t;

    while(t--) solve();
}