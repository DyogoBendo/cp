#include <bits/stdc++.h>

using namespace std;

#define N 100000

long long tree[4 * N];
long long lazy[4 * N];

void update(long long position, long long lb, long long rb, long long l, long long r, long long value){

    if(lazy[position]){
        tree[position] += (r - l + 1) * lazy[position];
        if(l < r ){
            lazy[2 * position + 1] += lazy[position];
            lazy[2 * position + 2] += lazy[position];
        }
        lazy[position] = 0;
    }
    if(lb > rb){
        return;
    }


    if(l == lb && r == rb){        
        tree[position] += (r - l + 1) * value;
        if(l < r){
            lazy[2 * position + 1] += value;
            lazy[2 * position + 2] += value;
        }
    } else{        
        long long m = (l + r) / 2;        
        update(2 * position + 1, lb, min(rb, m), l, m, value);
        update(2 * position + 2, max(lb, m + 1), rb, m + 1, r, value);
        tree[position] = tree[2 * position + 1] + tree[2 * position + 2];
    }
}

long long query(long long position, long long lb, long long rb, long long l, long long r){
    if(lb > rb){
        return 0;
    }

    if(lazy[position]){
        tree[position] += (r - l + 1) * lazy[position];
        if(l < r){
            lazy[2 * position + 1] += lazy[position];
            lazy[2 * position + 2] += lazy[position];
        }
        lazy[position] = 0;
    }


    if(l == lb && r == rb){
        return tree[position];
    }
    
    long long mid = (l + r ) / 2;
    return query(2 * position + 1, lb, min(mid, rb), l, mid) + query(2 * position + 2, max(lb, mid + 1), rb, mid + 1, r);
}

int main(){
    long long t;
    cin >> t;

    while(t){
        t --;
        long long n, c;
        cin >> n >> c;    
        memset(lazy, 0, sizeof(lazy));  
        memset(tree, 0, sizeof(tree));              

        for (long long i = 0; i < c; i++)
        {
            long long command, p, q;
            long long v;

            cin >> command >> p >> q;
            p --;
            q --;
            if(!command){
                cin >> v;                
                update(0, p, q, 0, n - 1, v);
            } else{
                cout << query(0, p, q, 0, n - 1)  << endl;
            }
        }

                     
    }
}