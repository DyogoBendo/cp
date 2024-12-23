#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    long long values[3] = {1, 1, 5};
    cin >> n;

    for (int i = 3; i <= n ; i++)
    {        
        long long new_value = (values[(i - 1) % 3] +  ((4 * values[(i - 2) % 3]) % 1000000007) + ((2 * values[(i - 3) % 3]) % 1000000007)) % 1000000007;
        values[i % 3] = new_value;
    }

    cout << values[n % 3] << endl;

}