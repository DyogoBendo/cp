#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;

    scanf("%d %d", &n, &m);
    vector<pair<int, pair<int, int>>> libraries;

    for (size_t i = 0; i < n; i++)
    {
        int a, b;

        scanf("%d %d", &a, &b);

        libraries.push_back(make_pair(a, make_pair(b, i + 1)));
    }

    sort(libraries.begin(), libraries.end());

    int y = 0, i = 0;

    vector<int> answers;
    
    int currentValue = 0;
    int currentI = 0;

    while (i < n)
    {           
        if(libraries[i].first > y + 1){
            break;
        }
        while(libraries[i].first <= y + 1 && i < n){
            if(libraries[i].second.first > currentValue){
                currentValue = libraries[i].second.first;                
                currentI = libraries[i].second.second;                
            }
            i++;
        }                            
        if(currentValue > y){
            y = currentValue;                
            answers.push_back(currentI);                
        }         
    }
    
    if(y == m){
        printf("YES\n");
        printf("%ld\n", answers.size());
        for(int answer : answers){
            printf("%d ", answer);
        }
        printf("\n");
    } else{
        printf("NO\n");
    }
    
    
}
