#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;

    int curr = 0;
    bool possible = true;
    while(n--){
        int d;
        string s;
        cin >> d >> s;

        if(curr == 0 && s != "South"){            
            possible = false;
        }
        else if(curr == 20000 && s != "North"){            
            possible = false;
        } else if(s == "South"){
            curr += d;
        } else if(s == "North"){
            curr -= d;
        }

        if(curr < 0 || curr > 20000){            
            possible = false;
        } 
    }

    if(!possible || curr != 0){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
}