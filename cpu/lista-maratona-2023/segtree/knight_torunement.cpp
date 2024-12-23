#include <bits/stdc++.h>

using namespace std;


#define N 300000

int knights[N];
int tree[4 * N];
int lazy[4 * N];

void update(int p, int lb, int rb, int l, int r, int w){
    if(lb > rb){
        return;
    }    

    if(lazy[p]){
        return;
    }    

    if(lb == l && rb  == r){
        lazy[p] = w;
        tree[p] = w;
        return;
    }
    int mid = (l + r) / 2;

    update(2 * p + 1, lb, min(rb, mid), l, mid, w);
    update(2 * p + 2, max(lb, mid + 1), rb, mid + 1, r, w);
}

void query(int p, int l, int r, int index){    
    if(l > index || r < index){
        return;
    }
    if(l > r){
        return;
    }
    if(lazy[p] && l < r){
        if(!lazy[2 * p + 1]){
            lazy[2 * p + 1] = lazy[p];
            tree[2 * p + 1] = lazy[p];
        }
        if(!lazy[2 * p + 2]){
            lazy[2 * p + 2] = lazy[p];
            tree[2 * p + 2] = lazy[p];
        }
        lazy[p] = 0;
    }
    if(l == r && l == index){
        knights[index] = tree[p];
        return;
    }
    int mid = (l + r) / 2;

    query(2 * p + 1, l, mid, index);
    query(2 * p + 2, mid + 1, r, index);
}

int main(){
    int n, m;

    cin >> n >> m;

    memset(knights, 0, sizeof(knights));
    memset(tree, 0, sizeof(knights));

    for (int i = 0; i < m; i++)
    {
        int lb, rb, w;
        cin >> lb >> rb >> w;
        lb --;
        rb --;
        w --;

        update(0, lb, w - 1, 0, n - 1, w + 1);        
        update(0, w + 1 , rb, 0, n - 1, w + 1);        
    }
    

    for (int i = 0; i < n; i++)
    {
        query(0, 0, n - 1, i);
    }

    for (int i = 0; i < n; i++)
    {
        cout << knights[i] << " ";
    }

    cout << endl;
    
    
    
}