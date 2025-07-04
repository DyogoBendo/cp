#include <bits/stdc++.h>
using namespace std;

#define darvem ios_base::sync_with_stdio(false);cin.tie(NULL)
#define endl '\n'
#define ll long long

int read(){
    string s;
    cin >> s;
    cin >> s;
    if(s == "GRANTED") return 0;

    cin >> s;        
    int curr = stoi(s.substr(1));
    cin >> s;

    return curr;
}

signed main(){    
    int base_time = 5;

    int curr = base_time;
    string s;
    int loop = 9; // if, !=, ++
    do
    {            
        if(curr == base_time){ // it means the size is wrong
            s.push_back('0');
        } else{ // the size is right, we need to check how many iterations it has done
            curr -= base_time + 5; // loop, i = 0, i < 
                
            int pos = curr / loop;
    
            if(s[pos] == '9') s[pos] = 'a';
            else if(s[pos] == 'z') s[pos] = 'A';
            else s[pos]++;            
        }
        cout << s << endl;
    } while (curr = read());
        
}