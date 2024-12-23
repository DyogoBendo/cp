#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("gymnastics");

    int n, k;
    cin >> k >> n;

    vector<vector<int>> cows (k, vector<int>(n));

    for (auto &x : cows)
    {
        for (auto &y : x)
        {
            cin >> y;
        }
        
    }
    
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            int menori = -1;
            int possible = 1;
            for (auto x : cows)
            {

                int pi = 0;
                int pj = 0;

                for (int y = 0; y < n; y++)
                {
                    if(x[y] == i) pi = y; 
                    if(x[y] == j) pj = y;
                }
                if(menori == -1){
                    menori = pi < pj;
                } else{
                    if(menori && pj < pi) possible = 0;
                    else if(!menori && pi < pj) possible = 0;
                }
            }
            if(possible) ans ++;
        }
        
    }

    cout << ans << endl;
    
 
}