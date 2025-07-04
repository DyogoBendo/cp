#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int n;
    cin >> n;

    vector<int> v(n);

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x >> v[i];
        v[i] += 180;
        v[i] *= 2;
    }

    vector<int> visited(720);

    for (int i = 1; i <= n; i++)
    {
        int prev = v[i-1], curr = v[i%n];
        if(prev > curr) swap(prev, curr);

        int d1 = prev + (720 - curr);
        int d2 = curr - prev;

        if(d1 < d2){
            for(int i = 0; i <= prev; i++) visited[i] = 1;
            for(int i = curr; i < 720; i++) visited[i] = 1;
        } else if(d2 < d1){
            for(int i = prev; i <= curr; i++) visited[i] = 1;
        } else{
            cout << "yes" << endl;
            return 0;
        }
    }
    
    for(int i = 0; i < 720; i++){
        if(!visited[i]){
            double ans = i/2.0 - 180;
            cout << setprecision(1) << fixed;
            cout << "no " << ans << endl;
            return 0;
        }
    }
    
    cout << "yes" << endl;
}