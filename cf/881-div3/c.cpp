#include <bits/stdc++.h>

using namespace std;

int main(){
    long long t, n;
    cin >> t;
    while(t){
        t --;
        cin  >> n;

        long long result = 0;
        long long i = n;
        while(i){            
            result += i;
            i /= 2;
        }
        cout << result << endl;
    }
}