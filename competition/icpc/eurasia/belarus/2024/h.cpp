#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

signed main(){
    darvem;

    string s;
    getline(cin, s);

    cout << "What is the name of your team?" << endl;
    cout << "Our name is " + s <<"." << endl;
    cout << "My apologies, I did not understand. What is your team name?" << endl;
    cout << "We are team " + s <<"." << endl;
    cout << "I am really sorry. Could you please repeat it once again?" << endl;

    for (int i = 0; i < s.length(); i++)
    {
        s[i] = toupper(s[i]);
    }
    
    cout << "WE ARE TEAM " << s << "!!!" << endl;
    cout << "Oh, now I see. Here are your badges. Good luck!" << endl;
}