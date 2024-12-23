#include <bits/stdc++.h>

using namespace std;
void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("feast");

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> v1(n + 1, 0);
    vector<int> v2(n + 1, 0);

    v1[0] = 1;

    for (int i = 0; i <= n; i++)
    {
        if(v1[i]){
            if(i + a <= n) v1[i + a] = 1;
            if(i + b <= n) v1[i + b] = 1;
            v2[i/2] = 1;            
        }
    }
    for (int i = 0; i <= n; i++)
    {
        if(v2[i]){
            if(i + a <= n) v2[i + a] = 1;
            if(i + b <= n) v2[i + b] = 1;                   
        }
    }

    int ans = 0;

    for (int i = 0; i <= n; i++)
    {
        if(v1[i] || v2[i]) ans = i;
    }
    
    cout << ans << endl;
}
