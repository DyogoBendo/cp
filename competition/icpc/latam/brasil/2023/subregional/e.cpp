#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXV = 1e6 + 10;

int cnt[MAXV];

int calc(int x){
    int ans = 0;
    while(x){
        ans += x%10;
        x/= 10;
    }
    return ans;
}

signed main(){
    darvem;

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    
    int visited = 0;

    int ans = 0;
    for (int curr = MAXV - 1; curr >= 0; curr--)
    {
        int x = calc(curr);
        if(visited + cnt[curr] >= k){
            ans = x;
            break;
        }
        visited += cnt[curr];
        cnt[curr - x] += cnt[curr];
    }
    
    cout << ans << endl;

}