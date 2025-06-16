#include <bits/stdc++.h>

#define ll long long

using namespace std;

int const MAX = 1e5 + 2;
int const MOD = 9;

ll seg[4 * MAX][MOD];
ll lazy[4 * MAX];
ll ans[MOD];
int n;
int pao;

ll build(int p=1, int l = 0, int r = n - 1){    
    lazy[p] = 0;    
    if(l == r){        
        return seg[p][1] = 1;
    } 
    int m = (l + r) / 2;
    return seg[p][1] = build(2*p, l, m) + build(2 * p + 1, m + 1, r);
}

void build1(int n2){
    n = n2;
    build();
}

void prop(int p, int l, int r){       
    if(!lazy[p]) return;                
    vector<ll> tmp(MOD, 0);                            
    for (int i = 0; i < MOD; i++){
        int t = (i + lazy[p]) % MOD;                
        tmp[t] = seg[p][i];                 
    }
    for (int i = 0; i < MOD; i++)
    {
        seg[p][i] = tmp[i];
    }    
    
    if(l != r){
        lazy[2 * p] = (lazy[p] + lazy[2 * p]) % MOD;
        lazy[2*p + 1] = (lazy[p] + lazy[2*p + 1]) % MOD;
    }
    lazy[p] = 0;
}

void query(int a, int b, int p = 1, int l = 0, int r = n - 1){
    prop(p, l, r);
    if(a <= l and r <= b){
        if (a == l) {
            for (int i = 0; i < MOD; ++i) ans[i] = seg[p][i];
        }  else {
            for (int i = 0; i < MOD; ++i) ans[i] += seg[p][i];
        }
    }
    if(b < l or r < a) return;

    int m = (l + r) / 2;
    query(a, b, 2*p, l, m);
    query(a, b, 2* p + 1, m + 1, r);

}

void update(int a, int b, int x, int p = 1, int l = 0, int r = n - 1){    
    prop(p, l, r);
    if(a <= l and r <= b){
        lazy[p] = (lazy[p] + x) % MOD;
        prop(p, l, r);    
        return;    
    }

    if(b< l or r < a) return;
    int m = (l + r) / 2;

    update(a, b, x, 2*p, l, m);
    update(a, b, x, 2*p + 1, m + 1, r);
    
    for (int i = 0; i < MOD; i++){                
        seg[p][i] = seg[2*p][i] +  seg[2*p + 1][i];
    }        
}

int main(){
    int n, q, *v2;
    vector<ll> c;
    cin >> n >> q;
    
    build1(n);        

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        query(l, r);        

        int m = 0;
        int qtd = 0;
        for (int i = 0; i < MOD; i++){
            if(ans[i] >= qtd){
                m = i;
                qtd = ans[i];
            }
        }
        update(l, r, m);                
    }

    for (int i = 0; i < n; i++){
        query(i, i);

        int m = 0;
        int qtd = 0;
        for (int i = 0; i < MOD; i++){
            if(ans[i] >= qtd){
                m = i;
                qtd = ans[i];
            }
        }

        cout << m << endl;

    }
    
    
}