#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;

    scanf("%d", &n);

    vector<pair<int, int>> horarios;

    for (size_t i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        horarios.push_back(make_pair(b, a));
    }
    
    sort(horarios.begin(), horarios.end());
    int total = 1;
    int atual = 0;
    for (size_t i = 1; i < n; i++)
    {
        if(horarios[atual].first <= horarios[i].second){
            total ++;
            atual = i;
        }
    }

    printf("%d\n", total);
    
}