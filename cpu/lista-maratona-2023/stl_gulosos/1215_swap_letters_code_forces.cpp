#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s, t;

    int ab = -1;
    int ba = -1;
      
    int pending = 0;
    vector<pair<int, int>> answers;

    scanf("%d", &n);
    cin >> s;
    cin >> t;

    for (size_t i = 0; i < n; i++)
    {
        char current_s = s[i];
        char current_t = t[i];

        if(current_s != current_t){
            if(current_s == 'a'){
                if(ab == -1){
                    ab = i;
                    pending ++;
                } else{
                    answers.push_back(make_pair(ab, i));
                    ab = -1;
                    pending --;
                }
            } else{
                if(ba == -1){
                    ba = i;
                    pending ++;
                } else{
                    answers.push_back(make_pair(ba, i));
                    ba = -1;
                    pending --;
                }
            }
        }
    }

    if (pending == 1){
        printf("%d\n", -1);
    } else{
        if(pending == 2){
            answers.push_back(make_pair(ab, ab));
            answers.push_back(make_pair(ab, ba));
        }

        printf("%d\n", answers.size());

        for (auto answer : answers)
        {
            printf("%d %d\n", answer.first + 1, answer.second + 1);
        }
        
    }
}