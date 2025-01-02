#include <bits/stdc++.h>
using namespace std;


void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
    setIO("hps");
    int n;
    cin >> n;

    vector<vector<int>> psum(3, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        char c;
        cin >> c;
        int p;
        if(c == 'H') p = 0;
        else if (c == 'P') p = 1;
        else p = 2;
        psum[p][i] = 1;        
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            psum[i][j] += psum[i][j - 1];
        }
        
    }

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = 0;;
        for (int j = 0; j < 3; j++)
        {
            l = max(l, psum[j][i]);
            r = max(r, psum[j][n] - psum[j][i]);
        }
        ans = max(ans, l + r);
    }
    
    cout << ans << endl;
    
}
