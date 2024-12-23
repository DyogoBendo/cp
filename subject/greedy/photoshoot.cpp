#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    cin >> n >> s;

    int ans = 0;

    for (int i = n - 1; i > 0; i-= 2)
    {
        char a, b;
        a = s[i];
        b = s[i - 1];

        if(a == b) continue;
        if(b == 'G' && ans % 2 == 0){            
            ans ++;
        }
        else if(b == 'H' && ans % 2 == 1){            
            ans ++;
        }
    }
    
    cout << ans << endl;
}