#include <bits/stdc++.h>

using namespace std;

void solve(){
    string l;
    string r;
    cin >> l >> r;

    long long result = 0;
    if(r.size() > l.size()){
        result = l.size() * 9;

        int different = 0;
        for (long long i = 1; i < r.size() - l.size(); i++)
        {
            if(int(r[i]) - 48 != 9) different = 1;
            result += 9;
        }

        result += r[0] - 48;

        
    } else{
        long long current = 0;
        for (long long i = 0; i < r.size(); i++)
        {
            current ++;
            if(r[i] != l[i]) break;
        }


        result = (l.size() - current) * 9; 
        result += (r[current - 1]) - l[current - 1]; 
        
    }

    cout << result << endl;
}

int main(){
    long long t;
    cin >> t;
    while(t--) solve();
}