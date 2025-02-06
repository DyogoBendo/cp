#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> top(n);
    vector<int> bot(n);

    for (int i = 0; i < n; i++)
    {
        cin >> top[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> bot[i];
    }

    vector<int> diff(n);

    for (int i = 0; i < n; i++)
    {
        diff[i] = top[i] - bot[i];
    }    
    
    int ans = 0;
    int ma = -(1e5 + 10);

    for (int i = 0; i < n; i++)
    {
        if(diff[i] >= 0){
            ans += top[i];
            ma = max(ma, bot[i]);
        } else{
            ans += bot[i];
            ma = max(ma, top[i]);
        }
    }
    
    cout << ans + ma << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}