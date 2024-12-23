#include <bits/stdc++.h>

using namespace std;

int solve(int n, int x, int y){
    int x_dist =  min(x - 1, n - x);
    int y_dist = min(y - 1, n - y);

    return min(x_dist,  y_dist);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x1, y1, x2, y2;
        cin >> n >> x1 >> y1 >> x2 >> y2;

        cout << abs(solve(n, x1, y1) - solve(n, x2, y2)) << endl;
    }
}