#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int ax, bx, cx, ay, by, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;    

    int area = ((ax*by) + (ay*cx) + (bx*cy)) - ((ay * bx) + (ax * cy) + (by*cx));

    if(area < 0) cout << "RIGHT" << endl;
    else if(area > 0) cout << "LEFT" << endl;
    else cout << "TOWARDS" << endl;
}