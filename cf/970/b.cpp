#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int k = 0;
    
    for (int i = 1; i <= n / 2; i++)
    {        
        int tmp = i * i;        
        if(tmp == n ){
            k = i;
            break;
        }
        if(tmp > n) break;        
    }
    


    if(k == 0){
        cout << "No" << endl;
        return;
    }
    

    int l1 = 1;
    int l2 = 1;
    int c1 = 1;
    int c2 = 1;
    int inner = 1;


    for (int i = 0; i < k; i++)
    {
        if(s[i] != '1') l1 = 0;
        if(s[k * (k - 1) + i] != '1') l2 = 0;
        if(s[k * i] != '1') c1 = 0;
        if(s[k * (i + 1) - 1] != '1') c2 = 0;
    }    

    for (int i = 1; i < k - 1; i++)
    {
        for (int j = 1; j < k - 1; j++)
        {
            if(s[i * k + j] != '0') inner = 0;
        }
        
    }    
    

    if(l1 + l2 + c1 + c2 + inner != 5){
        cout << "No" << endl;
    } else{
        cout << "Yes" << endl;
    }

}

signed main(){
    int t;
    cin >> t;
    while(t--)solve();
}