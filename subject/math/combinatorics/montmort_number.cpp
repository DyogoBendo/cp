#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
int MOD;

int add(int x, int y){
    return (x + y) % MOD;
}

int mul(int x, int y){
    return 1LL*x * y % MOD;
}

signed main(){
    darvem;

    int n;
    cin >> n >> MOD;
    int p1 = 0, p2 = 1;
    cout << p1 << " " << p2;
    for (int i = 3; i <= n; i++)
    {
        int curr = mul(add(p1, p2), i-1);
        cout << " " << curr;
        p1 = p2;
        p2 = curr;
    }
    cout << endl;
    
}