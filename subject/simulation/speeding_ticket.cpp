#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("speeding");

    int n, m;
    cin >> n >> m;

    int road[100]{};
    int cow[100]{};
    

    int a, b;
    int current = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;        
        for (int i = current; i < a + current; i++)
        {            
            road[i] = b;
        }
        current += a;
    }

    current = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        for (int i = current; i < a + current; i++)
        {
            cow[i] = b;
        }
        current += a;
    }
    
    int ans = 0;
    for (int i = 0; i < 100; i++)
    {
        ans = max(ans, cow[i] - road[i]);
    }
    cout << ans << endl;
    
}