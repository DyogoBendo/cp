#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<char, int>> v(n);

    int si = 0, mp = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;

        if(v[i].first == '+' && v[i].second % 2) si ++;

        if(v[i].first == '*' && v[i].second % 2 == 0) mp ++;
    }
    
    int x;
    cin >> x;

    if(mp == 0){
        if(x % 2 == 0 && si % 2){
            cout << "me" << endl;
            cout.flush();
        } else if(x % 2 && si % 2 == 0){
            cout << "me" << endl;
            cout.flush();
        } else{
            cout << "you" << endl;
            cout.flush();
        }
    } else{
        if(x%2 == 0 && si %2 == 0){
            cout << "you" << endl;
            cout.flush();
        } else if(x % 2 == 0 && si % 2 == 1){
            if(mp % 2 == 0){
                cout << "you" << endl;
                cout.flush();
            } else{
                cout << "me" << endl;
                cout.flush();
            }
        }

    }

}