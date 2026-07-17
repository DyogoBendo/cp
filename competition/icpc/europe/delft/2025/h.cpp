#include <bits/stdc++.h>
using namespace std;

#define ld long double
#define int long long
#define fastio cin.tie(0)->sync_with_stdio(0)

signed main(){
    fastio;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    queue<char> q2, q3;

    for(int i = 0; i < s2.size(); i++) q2.push(s2[i]);
    for(int i = 0; i < s3.size(); i++) q3.push(s3[i]);

    for(int i = 0; i < s1.size(); i++){
        char curr = s1[i];

        if(curr == '2'){
            while(q3.front() != '2'){
                cout << "1";
                q2.pop();
                q3.pop();
            }
            q3.pop();
        } else{
            while(q2.front() != '3'){
                cout << "1";
                q2.pop(); q3.pop();
            }
            q2.pop();
        }

        cout << curr;
    }
    while(!q2.empty()){
        cout << q2.front();
        q2.pop();
    }
    cout << endl;
}