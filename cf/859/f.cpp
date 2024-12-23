#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, m, i1, j1, i2, j2;
    string d;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;

    int current_y = d[0] == 'D' ? 1 : -1;
    int current_x = d[1] == 'R' ? 1 : -1;    

    vector<vector<vector<int>>> visited(n, vector<vector<int>> (m, vector<int> (4, 0)));

    int found = 0;
    int possible = 0;
    while(1){           
        int c = -1;
        if(current_y == 1){
            if(current_x == 1){
                c = 0;
            } else{
                c = 1;
            }
        } else{
            if(current_x == 1){
                c = 2;
            } else{
                c = 3;
            }
        }

        if(visited[i1 - 1][j1 - 1][c]){
            break;
        } else{
            visited[i1 - 1][j1 - 1][c] = 1;
        }

        if(i1 == i2 && j1 == j2){ 
            possible = 1;           
            break;
        }
        i1 += current_y;
        j1 += current_x;

        int change_i = 0;
        int change_j = 0;
        if(i1 > n){
            i1 = n; 
            current_y = -1;
            change_i = 1;
        }
        if(i1 < 1){
            i1 = 1;
            current_y = 1;
            change_i = 1;
        }

        if(j1 > m){
            j1 --;
            current_x = - 1;
            change_j = 1;
        }
        if(j1 < 1){
            j1 ++;
            current_x = 1;
            change_j = 1;
        }

        if(change_i) {
            j1 -= current_x;
            found ++;
        }
        if(change_j){
            i1 -= current_y;
            found ++;
        }

        if(change_j && change_i){
            j1 += current_x;
            i1 += current_y;
            found --;
        }
    }

    if(!possible) found = -1;
    cout << found << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}