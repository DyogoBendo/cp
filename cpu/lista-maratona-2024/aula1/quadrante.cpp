#include <bits/stdc++.h>

using namespace std;

int main(){
    int x, y;
    cin >> x >> y;
    if(x * y == 0){
        cout << "eixos" << endl;
        return 0;
    }
    cout << 'Q';
    if(x * y > 0){
        if(x > 0) cout << 1;
        else cout << 3;
    } else{
        if(x > 0) cout << 4;
        else cout << 2;
    }
    cout << endl;
}