#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    int c1 = a % 3;
    int c2 = b % 3;
    if( c2 == c1) c2 = (c2 + 1) % 3;

    for (int i = 0; i < 3; i++)
    {
        if(c1 == i || c2 == i) continue;
        cout << i << endl;
        break;
    }
    
}