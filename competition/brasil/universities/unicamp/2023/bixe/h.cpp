#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a,b;
    cin >> a >> b;

    if(!(a%2) && b%2) cout << "S" << endl << "B" << endl;
    else if(a%2 && !(b%2)) cout << "S" << endl << "A" << endl;
    else if(a % 2 && b%2) cout << "S" << endl << "A B" << endl;
    else cout << "N" << endl;
}