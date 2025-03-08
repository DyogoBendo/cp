#include <bits/stdc++.h>

#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'

using namespace std;
#define int long long

vector<int> primes;

void crivo(){
    int SZ = 1e5 + 10;
    vector<int> visited(SZ, 0);

    primes.push_back(2);
    for (int i = 2; i < SZ; i+=2)
    {
        visited[i] = 1;
    }
    
    for (int i = 3; i < SZ; i+=2)
    {
        if(!visited[i]){
            primes.push_back(i);
            for (int j = i; j < SZ; j+=i)
            {
                visited[j] = 1;
            }
            
        }
    }
    
}


void solve(){
    int n;
    cin >> n;

    int x = 1;
    for (auto p : primes)
    {
        if(n % p == 0){
            x = p;
            break;
        }
    }
    int total= 0;
    if(n % 2){
        total ++;
        n -= x;
    } 
    if(x == 1 || n == 0) cout << 1 << endl;
    else{
        total += n/2;
        cout << total << endl;
    }
    

}

signed main(){
    flash;
    crivo();
    int t = 1;    

    while(t--) solve();
}