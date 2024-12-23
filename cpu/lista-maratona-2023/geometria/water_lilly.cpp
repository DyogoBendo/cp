#include <bits/stdc++.h>

using namespace std;

int main(){
    long double h, l;
    cin >> h >> l;

    long double result = ((l + h) * (l - h) )/ (2 * h);
    cout << setprecision(7) << result << endl;
}