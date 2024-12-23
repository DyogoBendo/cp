#include <bits/stdc++.h>

using namespace std;

#define N 100000

int sequence[N];
int segtree[4 * N];

void build(int position, int left, int right){
    if(left > right){
        return;
    }
    if(left == right){
        segtree[position] = sequence[left];
        return;
    }

    int middle = (left + right) / 2;

    build(2 * position + 1, left, middle);
    build(2 * position + 2, middle + 1, right);

    segtree[position] = segtree[2 * position + 1] * segtree[2 * position + 2];

}

void change(int position, int left, int right, int new_value, int update_index){
    if(left > right){
        return;
    }
    if(left == right && left == update_index){
        segtree[position] = new_value;
        return;
    }

    int middle = (left + right) / 2;

    if(update_index  <= middle){
        change(2 * position + 1, left, middle, new_value, update_index);
    } else{
        change(2 * position + 2, middle + 1, right, new_value, update_index);
    }
    segtree[position] = segtree[2 * position + 1] * segtree[2 * position + 2];
}

int product(int position, int left, int right, int left_bound, int right_bound){
    if(left_bound > right_bound){
        return 1;
    }
    if(left_bound == left && right_bound == right){
        return segtree[position];
    }

    int middle = (left + right ) / 2;

    return product(2 * position + 1, left, middle, left_bound, min(right_bound, middle)) * product(2 * position +2, middle + 1, right, max(left_bound, middle + 1), right_bound);
}


int main(){
    int n, k;
    

    while(cin >> n >> k){
        for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;
        if(v < 0 ){
            sequence[i] = -1;
        } else if(v > 0){
            sequence[i] = 1;
        } else{
            sequence[i] = 0;
        }
    }

    build(0, 0, n - 1);

    vector<char> answer;
    for (int i = 0; i < k; i++)
    {
        char c;
        int a, b;

        cin >> c >> a >> b;

        if(c == 'C'){
            a --;
            if(b > 0 ){
                b = 1;
            } else if(b < 0 ){
                b = -1;
            }
            change(0, 0, n -1, b, a);
        } else{
            a --;
            b --;
            int result = product(0, 0, n - 1, a, b);

            if(result == 1){
                cout << '+';
            } else if(result == - 1){
                cout << '-';
            } else{
                cout << '0';
            }
        }
    }
    cout << endl;
    }
    
}