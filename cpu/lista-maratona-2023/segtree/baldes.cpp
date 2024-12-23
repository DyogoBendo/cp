#include <bits/stdc++.h>

using namespace std;

#define N 100000
#define LIMIT 1000001

int baldes[N];
int treeMin[4 * N];
int treeMax[4 * N];
int treeMinWho[4 * N];
int treeMaxWho[4 * N];

int maxValue;
int maxWho;
int smallerValue;
int smallWho;

void build(int p, int l, int r){
    if(l > r){
        return;
    }

    if(l == r){        
        treeMax[p] = baldes[l];
        treeMin[p] = baldes[l];        
        treeMinWho[p] = l;
        treeMaxWho[p] = l;
        return;
    }

    int mid = (l + r) / 2;

    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid + 1, r);

    if(treeMax[2 * p + 1] > treeMax[2 * p + 2]){
        treeMax[p] = treeMax[2 * p + 1];
        treeMaxWho[p] = treeMaxWho[2 * p + 1];
    } else{
        treeMax[p] = treeMax[2 * p + 2];
        treeMaxWho[p] = treeMaxWho[2 * p + 2];
    }

    if(treeMin[2 * p + 1] < treeMin[2 * p + 2] && treeMin[2 * p + 1]){
        treeMin[p] = treeMin[2 * p + 1];
        treeMinWho[p] = treeMinWho[2 * p + 1];
    } else{
        treeMin[p] = treeMin[2 * p + 2];
        treeMinWho[p] = treeMinWho[2 * p + 2];
    }
}

void update (int p, int l, int r, int i, int v){    
    if(l > r){
        return;
    }
    if(l == r && l == i){                
        treeMax[p] = max(v, treeMax[p]);
        treeMin[p] = min(v, treeMin[p]);
        return;
    }
    
    int mid = (l + r) / 2;

    if(i <= mid){
        update(2 * p + 1, l, mid, i, v);
    } else{
        update(2 * p + 2, mid + 1, r, i, v);
    }

    if(treeMax[2 * p + 1] > treeMax[2 * p + 2]){
        treeMax[p] = treeMax[2 * p + 1];
        treeMaxWho[p] = treeMaxWho[2 * p + 1];
    } else{
        treeMax[p] = treeMax[2 * p + 2];
        treeMaxWho[p] = treeMaxWho[2 * p + 2];
    }

    if(treeMin[2 * p + 1] < treeMin[2 * p + 2] && treeMin[2 * p + 1]){
        treeMin[p] = treeMin[2 * p + 1];
        treeMinWho[p] = treeMinWho[2 * p + 1];
    } else{
        treeMin[p] = treeMin[2 * p + 2];
        treeMinWho[p] = treeMinWho[2 * p + 2];
    }
}

void query(int p, int l, int r, int lb, int rb){    
    if(lb > rb){
        return;
    }
    if(l == lb && r == rb){
        int ma = treeMax[p];
        int mi = treeMin[p];
        if(ma > maxValue){
            maxValue = ma;
            maxWho = treeMaxWho[p];
        }
        if(mi < smallerValue){
            smallerValue = mi;
            smallWho = treeMinWho[p];
        }
        return;
    }

    int mid = (l + r) / 2;

    query(2 * p + 1, l, mid, lb, min(rb, mid));
    query(2 * p + 2, mid + 1, r, max(lb, mid + 1), rb);
}

int main(){
    int n, m;

    cin >> n >> m;

    for(int i = 0; i < n; i ++){
        cin >> baldes[i];
    }
    build(0, 0, n - 1);
    for (int i = 0; i < m; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if(t == 1){
            b --;
            update(0, 0, n - 1, b, a);
        } else{
            a --;
            b --;
            maxValue = -INT_MAX;
            smallerValue = INT_MAX;            
            query(0, 0, n - 1, a, b);            
            if(smallWho == maxWho){
                int r = 0;
                int oldSmaller = smallerValue;
                int oldBigger = maxValue;
                int index = smallWho;
                if(smallWho > a){
                    maxValue = -INT_MAX;
                    smallerValue = INT_MAX;
                    query(0, 0, n - 1, a, index - 1);                    
                    r = max(r, oldBigger - smallerValue);
                    r = max(r, maxValue - oldSmaller);
                }
                if(smallWho < b){
                    maxValue = -INT_MAX;
                    smallerValue = INT_MAX;
                    query(0, 0, n - 1, index + 1, b);                    
                    r = max(r, oldBigger - smallerValue);
                    r = max(r, maxValue - oldSmaller);
                }
                cout << r << endl;
            } else{
                cout << maxValue - smallerValue << endl;
            }

        }
    }
    
}