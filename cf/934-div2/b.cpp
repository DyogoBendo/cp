#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k;
    cin >> n >> k;

    vector<int> left(n);
    vector<int> right(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> left[i];        
    }
    for (int i = 0; i < n; i++)
    {
        cin >> right[i];        
    }

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());

    vector<int> position (n, 0);

    for (int i = 1; i < n; i++)
    {
        if(left[i] == left[i - 1]){
            position[left[i] - 1] = 1; // 1 significa que os dois estão do mesmo lado, esquerdo

        }
    }
    
    for (int i = 1; i < n; i++)
    {
        if(right[i] == right[i - 1]){
            position[right[i] - 1] = 2; // 1 significa que os dois estão do mesmo lado, direito
        }
    }


    vector<int> left_ans;
    vector<int> right_ans;

    int count_left = 0;
    int count_right = 0;
    int total = 2 * k;
    for (int i = 0; i < n; i++)
    {
        if(count_left == total && count_right == total) break;
        if(position[i] == 1){
            if(count_left < total - 1){
                count_left += 2;
                left_ans.push_back(i + 1);
                left_ans.push_back(i + 1);
            }
        } else if(position[i] == 2){
            if(count_right < total - 1){
                count_right += 2;
                right_ans.push_back(i + 1);
                right_ans.push_back(i + 1);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if(count_left == total && count_right == total) break;
        if(position[i] == 0){
            left_ans.push_back(i + 1);
            right_ans.push_back(i + 1);
            count_left ++;
            count_right ++;
        }
    }

    for (int i = 0; i < total; i++)
    {
        cout << left_ans[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < total; i++)
    {
        cout << right_ans[i] << " ";
    }
    cout << endl;
    
    
}

int main(){
    int t;
    cin >> t;
    while(t -- ){
        solve();
    }
}