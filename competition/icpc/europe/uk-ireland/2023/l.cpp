#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int h1, d1, t1, h2, d2, t2;
    cin >> h1 >> d1 >> t1;
    cin >> h2 >> d2 >> t2;

    int p1 = ((h2 / d1) + (h2 %d1 > 0) - 1) * (t1);
    int p2 = ((h1 / d2) + (h1 % d2 > 0) - 1) * (t2);    

    if(p1 < p2){
        cout << "player one" << endl;
    } else if(p1 == p2){
        cout << "draw" << endl;
    } else{
        cout << "player two" << endl;
    }
    

}