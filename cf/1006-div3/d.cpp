#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int l = 0, r = 0, max_cnt = 0;
    for (int i = 0; i < n; i++)
    {
        int curr_max = 0;
        int cnt = 0;
        int lst = i;
        for (int j = i + 1; j < n; j++)
        {
            if(v[j] < v[i]){
                cnt ++;                
            } else if(v[j] > v[i]){
                cnt --;
            }
            if(cnt > curr_max){
                curr_max = cnt;
                lst = j;
            }
        }
        if(curr_max > max_cnt){
            max_cnt = curr_max;
            l = i;
            r = lst;
        }
    }
    
    cout << l + 1 << " " << r+1 << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}