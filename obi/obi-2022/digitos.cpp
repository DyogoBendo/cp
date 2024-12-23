#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n;

// indica se o intervalo é composto apenas por 9, o que indica que precisamos aumentar o tamanho a ser analisado para o próximo, para verificar se ele é seu sucessor
int check_9(int i, int size){
    int count = 0;

    for (int j = i; j < i + size; j++)
    {
        if(v[j] == 9) count ++;
    }

    return count == size;
}

int find_9_sequence(int p, int size){
    int i = 0;
    while(v[p + size - 1 - i] == 9){
        i++;
    }
    return size - i - 1;
}

int check_range(int p, int size){
    int aumenta_digitos = check_9(p, size);
    int j = p + size;

    if(j + size + aumenta_digitos > n) return 0;
    if(aumenta_digitos){
        bool comeca1 = v[j] == 1;
        bool segue0 = true;
        for (int k = j + 1; k < j + size + 1; k++)
        {
            segue0 = min(segue0, v[k] == 0);
        }
        if(comeca1 && segue0) return size + 1;
        else return 0;
    }

    bool possible = true;
    int nine_sequence_end_position = find_9_sequence(p, size);
    for (int k = 0; k < size; k++)
    {
        if(k < nine_sequence_end_position){
            possible &= v[p + k] == v[j + k];
        }
        else if(k == nine_sequence_end_position){
            possible &= v[p + k] + 1 == v[j + k];
        } else{
            possible &= v[j + k] == 0;
        }
    }
    
    if(possible) return size;
    return 0;
}

int check(int size){
    int i = 0;
    while(1){
        if(i + size > n) return 0;
        if(i + size == n) return 1;
        int s = check_range(i, size);
        if(s == 0) return 0;
        i += size;
        size = s;
    }
}

int main(){
    int i;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    for (i = 1; i <= n; i++)
    {
        // verificar cada um dos tamanhos possíveis
        if(check(i)){
            break;
        }
    }
    

    for (int j = 0; j < i; j++)
    {
        cout << v[j];
    }
    cout << endl;
    
}