#include <bits/stdc++.h>

using namespace std;

long long findMDC(long long a, long long b){
    while (a % b != 0)
    {
        long long res;
        res = a % b;        
        a = b;
        b = res;
    }

    return b;
    
}

int main(){
    int t;
    cin >> t;

    for (size_t i = 0; i < t; i++)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        long long xDifference = abs(a - c);
        long long yDifference = abs(b - d);
        long long result;
        if(!xDifference){
            result = yDifference + 1;
        } else{
            auto m = div(yDifference, xDifference);
            if(m.rem == 0){
                result = xDifference + 1;
            } else{
                long long mdc = findMDC(yDifference, xDifference);                

                result = mdc + 1;
            }
        }

        cout << result << endl;
    }
    
}