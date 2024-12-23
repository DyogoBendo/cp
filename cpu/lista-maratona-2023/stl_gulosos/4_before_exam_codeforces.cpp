#include <iostream>
#include <vector>

using namespace std;

int main(){
    int d, sumTime, minValue, maxValue, minSum, maxSum;
    vector<int> minValuesList;
    vector<int> maxValuesList;    

    cin >> d >> sumTime;

    for (size_t i = 0; i < d; i++)
    {
        cin >> minValue >> maxValue;

        minSum += minValue;
        maxSum += maxValue;
        minValuesList.push_back(minValue);
        maxValuesList.push_back(maxValue);
    }


    cin.clear();        
    bool isSmallerThanMinimum = sumTime < minSum;
    bool isBiggerThanMaximum = sumTime > maxSum;


    if ( isSmallerThanMinimum || isBiggerThanMaximum){
        cout << "NO" << endl;
    } else{        
        vector<int> answer = minValuesList;
        int currentSum = minSum;
        int currentPosition = 0;
        while(currentSum < sumTime){
            int sumDifference = sumTime - currentSum;
            int extremesDifference = maxValuesList[currentPosition] - minValuesList[currentPosition];
            int minimumDifference = min(extremesDifference, sumDifference);

            currentSum += minimumDifference;
            answer[currentPosition] += minimumDifference;
            currentPosition ++;            
        }

        cout << "YES" << endl;
        for (size_t i = 0; i < d; i++)
        {
            cout << answer[i];
            if(i < d - 1){
                cout << " ";
            } else{
                cout << endl;
            }
        }
       
    }
    
}