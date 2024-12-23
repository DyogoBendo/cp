#include <bits/stdc++.h>

using namespace std;

#define N 200000

int treeLeft[2 * N];
int treeRight[2 * N];
pair<int, int> values[N];

int maxLeft;
int minRight;

void build(int p, int l, int r){    
    if(l > r){
        return;
    }    

    if(l == r){
        treeLeft[p] = values[l].first;
        treeRight[p] = values[l].second;
        return;
    }

    int mid = (l + r) / 2;

    build(p + 1, l, mid);
    build(p + 2 * (mid - l + 1), mid  + 1, r);

    treeLeft[p] = max(treeLeft[p + 1], treeLeft[p + 2 * (mid - l + 1)]);
    treeRight[p] = min(treeRight[p + 1], treeRight[p + 2 * (mid - l + 1)]);
}

void update(int p, int l, int r, int i){
    if(l > r){
        return;
    }        

    if(l == r == i){
        treeLeft[p] = maxLeft;
        treeRight[p] = minRight;
        return;
    }

    int mid = (l + r) / 2;
    if(i <= mid){
        update(p + 1, l, mid, i);
    } else{
        update(p + 2 * (mid - l + 1), mid + 1, r, i);
    }
    treeLeft[p] = max(treeLeft[p + 1], treeLeft[p + 2 * (mid - l + 1)]);
    treeRight[p] = min(treeRight[p + 1], treeRight[p + 2 * (mid - l + 1)]);
    return;
}

void query(int p, int lb, int rb, int l, int r){    
    if( l > r){
        return;
    }
    if(lb > rb){
        return;
    }

    if(l == lb && r == rb){
        if(treeLeft[p] > maxLeft){
            maxLeft = treeLeft[p];
        }
        if(treeRight[p] < minRight){
            minRight = treeRight[p];
        }
        return;
    }

    int mid = (l + r) / 2;

    query(p + 1, lb, min(rb, mid), l, mid);
    query(p + 2 * (mid - l + 1), max(lb, mid + 1), rb, mid + 1, r);
}

int main(){
    int n, q, a, b;
    char c;

    scanf("%d %d", &n, &q);

    for (int i = 0; i < n; i++)
    {        
        scanf("%d %d", &a, &b);        

        values[i] = make_pair(a, b);
    }

    build(0, 0, n - 1);    
    
    int ai, bi, x;
    for (int j = 0; j < q; j++)
    {               
        scanf(" %c %d %d", &c, &ai, &bi);        
        ai --;
        if(c == 'C'){
            scanf("%d", &x);       
            maxLeft = bi;
            minRight = x;            
            update(0, 0, n - 1, ai);
        } else{            
            bi --;
            minRight = INT_MAX;
            maxLeft = INT_MIN;            
            query(0, ai, bi, 0, n - 1);            
            if(minRight < maxLeft){
                printf("0\n");
            } else{
                printf("%d\n", minRight - maxLeft + 1);                
            }
        }

    }
    
}