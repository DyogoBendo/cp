#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

void solve(){
    int n, m;
    cin >> n >> m;

    vector<int> workers_cnt(n);
    vector<int> tasks(m);

    for (int i = 0; i < m; i++)
    {
        cin >> tasks[i];
        tasks[i]--;
        workers_cnt[tasks[i]] ++;
    }            

    int l = 0, h = 3*m;

    auto check = [&](int x){
        ll needed = 0;
        ll av = 0;

        for (int i = 0; i < n; i++)
        {
            ll curr_prof = workers_cnt[i] - min(workers_cnt[i], x);
            ll time_left = x - min(workers_cnt[i], x);
            needed += curr_prof;

            ll extra=  (time_left) / 2;
            av += extra;
        }
        return av < needed;
        
    };

    while(l < h){
        int mid = (h - l) / 2 + l;

        if(check(mid)){
            l = mid + 1;
        } else{
            h = mid;
        }
    }

    cout << h << endl;
}

signed main(){
    darvem;
    int t = 1;
    cin >> t;

    while(t--) solve();
}