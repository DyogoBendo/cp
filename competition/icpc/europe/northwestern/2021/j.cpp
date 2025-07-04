#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(0)->sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) ((int)(a).size())

vector<int> visited (1000);

void solve(){
    int n=1;
    cin >> n;
    vector<int> arr (n);    
    int trash;
    for (auto &a: arr) cin >> trash >> a;
    arr.push_back(arr[0]);

    int last=(arr[0] + 180);
    bool found = false;

    for (int i=1; i<n+1; i++){
        int lon = (arr[i] + 180);        
        
        int mn = 2*min(last, lon), mx = 2*max(last, lon);
        
        int d = 360 + (mn - mx);                

        if(d < 0){
            for (int j = 0; j <= mn; j++)visited[j] = 1;
            for (int j = mx; j < 720; j++)visited[j] = 1;            
        }else if(d > 0)for(int j = mn; j<= mx; j++) visited[j] = 1;
        else found = true;        
                
        last = lon;
    }
    int cant=-1;
    
    for (int i=0; i<720; i++){
        if (!visited[i]){
            cant = i;            
        } 
    } 
        
    if (cant == -1 or found){        
        cout << "yes";
    } 
    else{            
        double ans = cant / 2.0 - 180;        
        cout << setprecision(1) << fixed;
        cout << "no " << ans;
    } 
    cout << '\n';
}

signed main(){
    fastio;
    int t=1;
    //cin >> t;
    for (int i=0; i<t; i++) solve();
}