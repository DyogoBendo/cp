#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int m[10][10];

int main(){
     setIO("cowtip");
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

        for (int j = 0; j < n; j++)
        {
            m[i][j] = s[j] - '0';
        }        
    }

    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if(m[i][j] == 1){
                ans ++;
                for (int a = 0; a <= i; a++)
                {
                    for (int b = 0; b <= j; b++)
                    {
                        m[a][b] ^= 1;
                    }                    
                }                
            }
        }        
    }
    
    cout << ans << endl;
}