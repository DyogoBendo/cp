#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

const int MAX = 1e9 + 10;

void calc(){
    int MID = 1e5;

    vector<int> visited(MID);
    for (int i = 2; i < MID ; i+=2)
    {
        visited[i] = 1;
    }

    for (int i = 3; i < MID; i+=2)
    {
        if(!visited[i]){
            primes.push_back(i);
            for (int k = i + i; k < MID; k+= i)
            {
                visited[k] = 1;
            }
            
        }
    }
    
}

void solve(){
    int n;
    cin >> n;

    int cn = n;

    if(n == 1){
        cout << "FastestFinger" << endl;
        return;
    }

    int two = 0;
    int odd_factors = 0;


    while(n % 2 == 0){
        two ++;
        n /= 2;
    }

    for (auto p : primes)
    {
        while(n % p == 0){
            odd_factors ++;
            n /= p;
        }
        if(n == 1) break;
    }
    if(n > 1) odd_factors ++;
    
    if(two > 1 && !odd_factors){
        cout << "FastestFinger" << endl;
        return;
    }

    if(two == 1 && odd_factors == 1){
        cout << "FastestFinger" << endl;
        return;
    }

    cout << "Ashishgup" << endl;

}

signed main(){
    calc();
    int t;
    cin >> t;

    while(t--) solve();
}