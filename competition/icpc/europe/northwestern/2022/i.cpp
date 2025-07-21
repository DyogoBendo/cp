#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    int c, d;
    cin >> c >> d;

    string s;
    int preva = 0, dista = 0, prevb = 0, distb = 0;
    for (int i = c; i <= d; i++)
    {
        cin >> s;

        if(s == "Fizz"){
            dista = i - preva;
            preva = i;
        }
        if(s == "Buzz"){
            distb = i - prevb;
            prevb = i;
        }
        if(s == "FizzBuzz"){
            dista = i - preva;
            preva = i;
            distb = i - prevb;
            prevb = i;
        }
    }

    if(dista == 0) dista = d + 1;
    if(distb == 0) distb = d+1;
    cout << dista << " " << distb << endl;
}