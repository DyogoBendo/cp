#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;

    string s;
    for (int i = 0; i < m; i++)
    {
        s.append("B");
    }

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(x - 1 < m - x && s[x - 1] != 'A'){
            s[x - 1] = 'A';
        } else if (s[m - x] != 'A'){
            s[m - x]= 'A';
        } else{
            s[x - 1] = 'A';
        }
    }
    
    cout << s << endl;
    
}

int main(){
    int t;
    cin >> t;
    while (t--)solve();
    
}