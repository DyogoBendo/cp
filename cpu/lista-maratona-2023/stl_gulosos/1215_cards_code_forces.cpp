#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a1, a2, k1, k2, n;

    cin >> a1;
    cin >> a2;
    cin >> k1;
    cin >> k2;
    cin >> n;

    // calcular valor minimo

    int min_value;

    int value = ((k1 - 1) * a1) + ((k2 - 1) * a2);    
    min_value = max(n - value, 0);

    // calcular o maior valor de cartões vermelhos

    int max_value;
    
    if (k1 < k2){
        int result = min(n / k1, a1);
        max_value = result;
        n -= result * k1;        
        max_value += min(n / k2, a2);
    } else{
        int result = min(n / k2, a2);
        max_value = result;
        n -= result * k2;        
        max_value += min(n / k1, a1);
    }

    
    cout << min_value << " " << max_value << endl;
}