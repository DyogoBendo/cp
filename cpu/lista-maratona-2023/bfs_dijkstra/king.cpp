#include "bits/stdc++.h"

using namespace std;

int main(){
    char t[3];
    char s[3];

    cin >> s >> t;
    int sx = s[0];
    int sy = s[1];

    int tx = t[0];
    int ty = t[1];    

    int total = max(abs(sx - tx), abs(sy - ty));
    cout << total << endl;    
    while(sx != tx || sy != ty){        
        if(sx > tx){
            sx --;            
            cout << "L";
        } else if(sx < tx){
            sx ++;      
            cout << "R";      
        }
        if(sy > ty){
            sy --;    
            cout << "D";        
        } else if(sy < ty){
            sy ++;      
            cout << "U";      
        }
        cout << endl;
    }

}