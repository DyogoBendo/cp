#include <bits/stdc++.h>

using namespace std;

#define N 1000000
int tree[4 * N];
int treeL[4 * N];
int treeR[4 * N];

int leftT;
int rightT;
int totalN;

string sequence;

void build(int p, int l, int r){
    if(l > r){
        return;
    }
    if(l == r){
        tree[p] = 0;
        if(sequence[l] == '('){
            treeL[p] = 1;
            treeR[p] = 0;
        } else{
            treeR[p] = 1;
            treeL[p] = 0;
        }        
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p + 1, l, mid);
    build(2 * p + 2, mid + 1, r);

    int nc = min(treeL[2 * p + 1], treeR[2 * p + 2]);
    tree[p] = tree[2 * p + 1] + tree[2 * p + 2] + (2 * nc);
    treeL[p] = treeL[2 * p + 1] - nc + treeL[2 * p + 2];
    treeR[p] = treeR[2 * p + 2] - nc + treeR[2 * p + 1];

}

int query(int p, int l, int r, int lb, int rb, int olb, int orb){
    if(lb > rb){
        return 0;
    }

    if(l == lb && r == rb){
        totalN += 2 * min(treeR[p], leftT);        
        leftT -= min(treeR[p], leftT);
        leftT += treeL[p];            
        return tree[p];
    }

    int mid = (l + r) / 2;

    int q1 = query(2 * p + 1, l, mid, lb, min(rb, mid), olb, orb);
    int q2 = query(2 * p + 2, mid + 1, r, max(lb, mid + 1), rb, olb, orb);
    return q1 + q2;
}


int main(){    
    cin >> sequence;

    build(0, 0, sequence.length() - 1);
    int m;
    cin >> m;    
    

    for (int i = 0; i < m; i++)
    {
        leftT= 0;
        rightT = 0;
        totalN = 0;
        int l, r;
        cin >> l >> r;
        l --;
        r --;
        cout <<  query(0, 0, sequence.length() - 1, l, r, l, r) + totalN << endl;                

    }
    
}