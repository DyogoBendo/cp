#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t --){
        int n;
        cin >> n;

        int number_of_even = 0, smaller = 1000000001;
        int possible = 0;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x % 2 == 0){
                number_of_even ++;
            }
            if(x < smaller){
                smaller = x;
            }
        }        
        if(smaller % 2 == 0){
            if(number_of_even == n) possible = 1;
        } else{
            possible = 1;
        }
        if(possible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}