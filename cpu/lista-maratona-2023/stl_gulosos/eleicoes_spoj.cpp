#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int n;
    map<int, int> votos;

    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int voto;
        cin >> voto;

        if(votos.find(voto) == votos.end()){
            votos[voto] = 1;
        } else{
            votos[voto] ++;
        }        
    }



    const int * maior_valor = &votos.begin()->second, * vencedor = &votos.begin()->first;
    for(const auto& elem: votos){
        if (elem.second > *maior_valor){
            maior_valor = &elem.second;
            vencedor = &elem.first;
        }
    }
    
    cout << *vencedor << endl;
}