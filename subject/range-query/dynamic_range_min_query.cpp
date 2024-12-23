#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int seg[4*N], n;
int vet[N];

const int INF = 1e9 + 1;

int build(int p = 1, int l = 0, int r = n - 1){
    if(l == r){
        return seg[p] = vet[l];
    }

    int mid = (r + l) / 2;

    return seg[p] = min(build(2*p, l, mid), build(2*p + 1, mid + 1, r));
}

int update(int k, int u, int p = 1, int l = 0, int r = n - 1){
    if(l == r){
        return seg[p] = u;
    }

    int mid = (l + r) / 2;

    int left = seg[2*p];
    int right = seg[2*p+1];

    if(k > mid){
        right = update(k, u, 2*p + 1, mid + 1, r);
    } else{
        left = update(k, u, 2*p, l, mid);
    }

    return seg[p] = min(left, right);
}

int query(int a, int b, int p = 1, int l = 0, int r = n - 1){        
    if(l > r) return INF;
    if(l > b) return INF;
    if(r < a) return INF;
    if(l >= a && r <= b){        
        return seg[p];
    }

    int mid = (l + r) / 2;
    
    int left = query(a, b, 2*p, l, mid);
    int right = query(a, b, 2*p + 1, mid + 1, r);    

    return min(left, right);
}


int main(){
    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        cin >> vet[i];
    }

    build();

    for (int i = 0; i < q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;


        if(t == 2){            
            a--;
            b--;
            cout << query(a, b) << endl;
        } else{
            a--;
            update(a, b);
        }
    }
    
    
}