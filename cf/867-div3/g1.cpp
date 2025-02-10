#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        set<long long> ms;
        set<long long> s;
        long long biggest = 0;

        for (int i = 0; i < n; i++)
        {   
            long long x;
            cin >> x;   
            if(x > biggest) biggest = x;
            ms.insert(x);
            s.insert(x);
        }
        
        long long total = 0;        
        auto it = s.begin();
        while(it != s.end()){
            long long x = *it;
            long long appearences = ms.count(x);
            total = total + (appearences * (appearences - 1) * (appearences - 2));            
            
            long long b_limit = ceil(sqrt(ceil(biggest / x)));
            for (long long i = 2; i <= b_limit; i++)
            {
                long long a1 = ms.count(x * i);
                long long a2 = ms.count(x * i * i);
                total = total + (appearences * a1 * a2);
            }
            it ++;
        }

        cout << total << endl;
    }
}