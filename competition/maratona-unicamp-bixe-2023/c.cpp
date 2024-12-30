#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll x,y,z;

ll isPossible(){
    if(x < 0 && y < 0) {
        x *= -1;
        y *= -1;
        z *= -1;
    }
    if(x > 0 && y > 0){
        if(x < y) {
            return x;
        }
        if(z > y) {
            return -1;
        } 
        if(z > 0){
            return x;
        }
        return x - (z*2);
    
    } else {
        return abs(x);
    }
}

int main(){
    cin >> x >> y >> z;
 
    cout << isPossible() << endl;
}