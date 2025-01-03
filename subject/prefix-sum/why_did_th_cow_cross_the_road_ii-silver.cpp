#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}


int main(){
	setIO("maxcross");
    int n, k, b;
    cin >> n >> k >> b;

    vector<int> v(n, 1);
    vector<int> psum(n + 1, 0);

    for (int i = 0; i < b; i++)
    {
        int x;
        cin >> x;    
        v[--x]--;
    }

    for (int i = 1; i <= n; i++)
    {
        psum[i] = psum[i - 1] + v[i - 1];
    }
    

    int ans = n;


    for (int i = k; i <= n; i++)
    {
        int x = psum[i] - psum[i - k];        
        ans = min(ans, k - x);
    }

    cout << ans << endl;
}