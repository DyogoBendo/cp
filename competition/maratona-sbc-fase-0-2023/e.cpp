#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int negative = -1, positive = -1;
    int oldNegative = -1, oldPositive = -1;
    int found = 0;
    cin >> n;

    int palpites[10000];
    int erros[10000];
    for (int i = 0; i < n; i++)
    {
        cin >> palpites[i];
    }

    for (int i = 0; i < n; i++)
    {        
        cin >> erros[i];   
    }

    int number1 = palpites[0];
    for (int i = 0; i < n; i++)
    {
        int possibleA = abs(number1 - erros[i]);
        int possibleB = number1 + erros[i];

        
    }
        

    if(found){
        cout << found << endl;
    } else{
        cout << negative << endl;
        cout << positive << endl;
    }
    
    
}