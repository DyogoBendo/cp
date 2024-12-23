#include <bits/stdc++.h>

using namespace std;

void solve(){
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a;
    vector<long long> b;
    long long a_smallest = 10000000001;
    long long a_biggest = -1;
    long long a_sum = 0;

    long long b_smallest = 10000000001;
    long long b_biggest = -1;
    long long b_sum = 0;


    for (long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        a.push_back(x);

        if(x > a_biggest) a_biggest = x;
        if(x < a_smallest) a_smallest = x;
        a_sum += x;
    }

    for (long long i = 0; i < m; i++)
    {
        long long x;
        cin >> x;
        b.push_back(x);

        if(x > b_biggest) b_biggest = x;
        if(x < b_smallest) b_smallest = x;
        b_sum += x;
    }

    int even = k % 2;

    long long result = a_sum;

    if(k == 1){
        if(a_smallest < b_biggest){
            result += (b_biggest - a_smallest);       
        }
        cout << result << endl;
        return;
    }
    if(!even){
        if(a_smallest < b_biggest){
            if(a_smallest < b_smallest){
                if(a_biggest > b_biggest){
                    result += b_biggest - a_biggest;
                }
            } else{
                result += b_smallest - a_smallest;
                if(a_biggest > b_biggest){
                    result += b_biggest - a_biggest;
                }
            }
        } else{
            result += b_smallest - a_biggest;
        }
        cout << result << endl;
        return;
    } else{
        if(a_smallest < b_biggest){
            result += b_biggest - a_smallest;
        } 

        cout << result << endl;
        return;
    }
    
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
}