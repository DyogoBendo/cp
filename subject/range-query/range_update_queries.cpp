#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long
#define int long long

const int MAX = 2e5;

int seg[2 * MAX];
int n;

void build() {
	for (int i = n - 1; i; i--) seg[i] = seg[2*i] + seg[2*i+1];
}

int query(int a, int b) {
	int ret = 0;
	for(a += n, b += n; a <= b; ++a /= 2, --b /= 2) {
		if (a % 2 == 1) ret += seg[a];
		if (b % 2 == 0) ret += seg[b];
	}
	return ret;
}

void update(int p, int x) {
    if(p < n) seg[p += n] += x;
	while (p /= 2) seg[p] = seg[2*p] + seg[2*p+1];
}

signed main(){
    darvem;

    int q;
    cin >> n >> q;

    vector<int> v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];        
    }
    build();

    while(q--){
        int op;
        cin >> op;
        if(op == 1){
            int a, b, u;
            cin >> a >> b >> u;
            update(a-1, u);
            update(b, -u);
        } else{
            int k;
            cin >> k;
            k--;
            cout << query(0, k) + v[k] << endl;
        }
    }
}