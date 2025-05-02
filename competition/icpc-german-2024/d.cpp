#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int MAX = 2e5 + 10;
const int MOD = 1e9+7;

int n;
pair<int, int> seg[4*MAX], lazy[4*MAX];

pair<int, int> add(pair<int, int> x, pair<int, int> y){
    int k = x.second * y.second;
    int t = x.first *y.second + y.first * x.second;    
    return {t/gcd(k, t), k/(gcd(k, t))};
}

pair<int, int> mul(pair<int, int> x, pair<int, int> y){
    int a = x.first * y.first;
    int b = x.second * y.second;

    return {a/gcd(a, b), b/gcd(a, b)};
}

pair<int, int> build(int p=1, int l=0, int r=n-1) {
    lazy[p] = {0, 1};
    if (l == r) return seg[p] = {0, 1};
    int m = (l+r)/2;
    return seg[p] = add(build(2*p, l, m), build(2*p+1, m+1, r));
}
void prop(int p, int l, int r) {
    seg[p] = add(seg[p], mul(lazy[p],{r-l+1, 1})) ;
    if (l != r) lazy[2*p] = add(lazy[2*p], lazy[p]), lazy[2*p+1] = add(lazy[2*p+1], lazy[p]);
    lazy[p] = {0, 1};
}
pair<int, int> query(int a, int b, int p=1, int l=0, int r=n-1) {
    prop(p, l, r);
    if (a <= l and r <= b) return seg[p];
    if (b < l or r < a) return {0, 1};
    int m = (l+r)/2;
    return add(query(a, b, 2*p, l, m), query(a, b, 2*p+1, m+1, r));
}
pair<int, int> update(int a, int b, pair<int, int> x, int p=1, int l=0, int r=n-1) {
    prop(p, l, r);
    if (a <= l and r <= b) {
        lazy[p] = add(lazy[p], x);
        prop(p, l, r);
        return seg[p];
    }
    if (b < l or r < a) return seg[p];
    int m = (l+r)/2;
    return seg[p] = add(update(a, b, x, 2*p, l, m),
        update(a, b, x, 2*p+1, m+1, r));
}

int fast_expo(int a, int k){
    int curr = 1;
    int ans = 1;

    while(a){
        if(a % 2){
            ans = (ans * curr) % MOD;             
        }
        curr = curr * curr %MOD;

        a/= 2;
    }

    return ans;
}

int main(){
    int q;
    double p;
    cin >> n >> q >> p;

    int curr = p * 1e7;
    int g = gcd(curr, 10000000);
    auto b =  {curr/g, 10000000/g};

    build();

    while(q--){
        char c;
        cin >> c;

        if(c == '?'){
            int x;
            cin >> x;

            auto ans = query(x, x);

            int a = ans.first * fast_expo(ans.second, MOD - 2) %  MOD;
            cout << a << endl;
        }else{
            int x
        }

        if(c == '+'){

            update(x, x, );
        }
    }
}