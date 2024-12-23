#include <bits/stdc++.h>

using namespace std;

void setIO(string s) {
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

int main(){
    setIO("lostcow");

    int x, y;
    cin >> x >> y;

    int factor = 1;    
    int result = 0;
    if(x < y){
        int position = x;
        int next_position;
        while(position < y){                      
            next_position = x + factor;
            result += abs(next_position - position);            
            position = next_position;   
            factor *= -2;                     
        }
        result -= (position - y);
    } else{
        int position = x;
        int next_position;
        while(position > y){            
            next_position = x + factor;            
            result += abs(next_position - position);
            position =next_position;
            factor *= -2 ;                           
        }
        result -= (y - position);
    }

    cout << result << endl;

}