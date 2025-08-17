#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
const int MAXN = 1e6+10;
const int MOD = 1e9+7;

int fat[MAXN], ifat[MAXN];

int mul(int x, int y){
    return 1LL * x * y % MOD;
}
int fast_expo(int x, int k){
    int ans = 1;
    while(k){
        if(k&1){
            ans = mul(ans, x);
        }
        x = mul(x, x);
        k/= 2;
    }
    return ans;
}


int inv(int x){
    return fast_expo(x, MOD-2);
}

void init(){
    fat[0] = 1;
    for(int i = 1; i < MAXN; i++) fat[i] = mul(fat[i-1], i);
    ifat[MAXN-1] = inv(fat[MAXN-1]);

    for(int i = MAXN-2; i>= 0; i--) ifat[i] = mul(i+1, ifat[i+1]);
}

int comb(int a, int b){
    return mul(fat[a], mul(ifat[a-b], ifat[b]));
}

signed main(){
    darvem;
    init();

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        cout << comb(a, b) << endl;
    }
}