#include <bits/stdc++.h>

using namespace std;

void solve(){
    string a, b;
    cin >> a >> b;

    int x = 0;

    for (int i = 0; i < b.size(); i++)
    {
        int p = i;

        int total = 0;

        for (int j = 0; j < a.size(); j++)
        {
            if(a[j] == b[p]){
                total ++;
                p ++;
            }
        }

        x = max(x, total);
        
    }

    cout << a.size() + b.size() - x << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}