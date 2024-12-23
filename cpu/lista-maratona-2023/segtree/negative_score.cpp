#include <bits/stdc++.h>

using namespace std;

#define N 100000

int segtree[4 *N];
int values[N];

void build(int left, int right, int position){
    if(left == right){
        segtree[position] = values[left];
        return;
    }
    if(left > right){
        return;
    }

    int middle = (left + right) / 2;

    build(left, middle, 2 * position + 1);
    build(middle + 1, right, 2 * position + 2);

    segtree[position] = min(segtree[2 * position + 1], segtree[2 * position + 2]);
}

int query(int left, int right, int position, int left_bound, int right_bound){
    if(left_bound > right_bound){
        return numeric_limits<int>::max();
    }
    if(left == left_bound && right == right_bound){
        return segtree[position];
    }

    int middle = (left + right) / 2;    
    return min(
            query(
                left, middle, 2 * position + 1, left_bound, min(right_bound, middle)
            ), 
            query(
                middle + 1, right, 2 * position + 2, max(middle + 1, left_bound), right_bound
            ));
}

int main(){
    int t, num = 1;
    scanf("%d", &t);   

    while(t){
        int n, q;
        scanf("%d %d", &n, &q);
        for(int i = 0; i < n; i ++)  scanf("%d", &values[i]);

        printf("Scenario #%d:\n", num);        
        build(0, n - 1, 0);

        for (int i = 0; i < q; i++)
        {
            int start, end;
            scanf("%d %d", &start, &end);            
            start --;
            end --;
            int result = query(0, n - 1, 0, start, end);
            printf("%d\n", result);            
        }
        
        t --;
        num ++;
    }
}