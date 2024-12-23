#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int x1, y1, x2, y2, n;
    cin >> x1 >> y1 >> x2 >> y2 >> n;
    string s;
    cin >> s;

    vector<int> prefix_x(n + 1, 0);
    vector<int> prefix_y(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        int y = 0;
        if(s[i] == 'U') y = 1;
        if(s[i] == 'D') y = -1;
        if(s[i] == 'R') x = 1;
        if(s[i] == 'L') x = -1;

        prefix_x[i + 1] = prefix_x[i] + x;
        prefix_y[i + 1] = prefix_y[i] + y;
    }

    int lo = 0;
    int hi = 10e14;

    auto check = [&](int days){        
        int current_x = prefix_x[n] * (days /n) + prefix_x[days %n];
        int current_y = prefix_y[n] * (days /n) + prefix_y[days %n];

        int diff = abs(x1 + current_x - x2) + abs( y1 + current_y - y2);
        return diff <= days;
    };

    int ans=  -1;

    while(lo < hi){
        int mid = lo + (hi - lo) / 2;        
        if(check(mid)){
            ans = mid;
            hi = mid;
        } else{
            lo = mid + 1;
        }
    }
    
    cout << ans << endl;
}