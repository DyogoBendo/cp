#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string s;
    getline(cin, s);

    if(s == "Vamos la, Torterra!"){
        cout << "Staraptor, eu escolho voce!" << endl;
    } else if(s == "Vamos la, Luxray!"){
        cout << "Torterra, eu escolho voce!" << endl;
    } else{
        cout << "Luxray, eu escolho voce!" << endl;
    }
}