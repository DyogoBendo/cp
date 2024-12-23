#include <bits/stdc++.h>

using namespace std;

#define N 200000

int p[N];
int segtree[4*N];


void build(int left, int right, int position){    
    if(left == right){
        segtree[position] = p[left];
        return;
    }
    if(left > right) return;

    int middle = (left + right ) / 2;
    build(left, middle, 2 * position + 1);
    build(middle + 1, right, 2 * position + 2);

    segtree[position] = segtree[2 * position + 1] + segtree[2 * position + 2];
}   

int show(int left_bound, int right_bound, int current_left, int current_right, int position){
    if(left_bound > right_bound){
        return 0;
    }

    if(current_left == left_bound && current_right == right_bound){
        return segtree[position];
    }

    int middle = (current_left + current_right) / 2;
    return show(left_bound, min(right_bound, middle), current_left, middle, 2 * position + 1) + show(max(middle + 1, left_bound), right_bound,  middle + 1, current_right, 2 * position + 2);
}

void update(int left, int right, int position, int update_index, int new_value){    
    if(left == right){        
        segtree[position] = new_value;
        return;
    }
    if(left > right) return;
    int middle = (left + right) / 2;
    if(update_index <= middle){
        update(left, middle, 2 * position + 1, update_index, new_value);
    } else{
        update(middle + 1, right, 2 * position + 2, update_index, new_value);
    }

    segtree[position] = segtree[2 *position + 1] + segtree[2 * position + 2];      
}

int main(){
    int n, test = 1;
    cin >> n;

    while(n){

        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
        }

        build(0, n - 1, 0);
        cout << "Case " << test << ":" << endl; 
        
        string operation;
        int a, b;
        cin >> operation;
        while(operation != "END"){
            cin >> a >> b;

            if(operation == "M"){
                a --;
                b --;
                int result = show(a, b, 0, n - 1, 0);
                cout << result << endl;
            } else{
                a --;
                update(0, n - 1, 0, a, b);
            }

            cin >> operation;
        }

        cout << endl;
        test ++;
        cin >> n;
    }
}