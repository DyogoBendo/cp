#include <bits/stdc++.h>

using namespace std;

#define int long long

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

signed main(){
    setIO("herding");

    int n;
    cin >> n;
    vector<int> v(n);
    for(int &x: v) cin >> x;

    sort(v.begin(), v.end());    

    int max_move = max(v[n-1] - v[1] + 1 - (n-1), v[n-2] - v[0] + 1 - (n - 1));
    int min_move = max_move;

    int l = 0, r = 0;
    while(l < n){
        for(; r < n && v[r] < v[l] + n; r++);        
        if(r - l == n -1 && v[l] + n-2 == v[r-1] && r == n);
        else if(l > 0 || v[r - 1] == v[l] + n) min_move = min(min_move, n - (r - l));
        l++;
    }        
    
    cout << min_move << endl << max_move << endl;
}