#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve(){
    int n;
    cin >> n;

    int even = 0;
    int odd = 0;


    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        if(i % 2 == 0) even += x;
        else odd += x;
    }

    int qtd = n / 2;
    int qtd_even = qtd + (n % 2);

    int m1 = even % qtd_even;
    int m2 = odd % qtd;

    int r1 = even / qtd_even;
    int r2 = odd / qtd;

    if(m1 != 0 || m2 != 0 || r1 != r2){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
    
}

signed main(){
    int t;
    cin >> t;
    while(t--) solve();
}