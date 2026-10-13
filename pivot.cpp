#include <bits/stdc++.h>
using namespace std;



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // take input of list of nums
    //Loop through the list of nums
    // First check the first entry:
    //    then only check if elements, on right are greater than, if so add to pivot list
    // Second, check all elements in between first and last,
        //for each element, check if the left side is all less than or equal to, and if right side
        //is all greater than. if so, add to our pivot list
    //Lastly, check the last element of the list
        //if everything to the left is less than or equal to element, add element to the pivot list
    //print the length of the pivot list to console


    int n;
    cin >> n;
    vector<int> numList(n);
    vector<int> pivotList;

    for (int i = 0; i<n; i++){
        int m;
        cin >> m;
        numList[i] = m;
    }


    //check everything to the right of first number
    int firstNum = numList.front();
    

    for (int i = 1; i<n; i++){
        if (numList[i] <= firstNum){
            break;
        }
        if (i == n-1){
                pivotList.push_back(firstNum);
        }
    }

    //check all numbers between first and last number
    bool maybePivot;
    for (int i = 1; i< n-1; i++){
        maybePivot = true;
        for (int j = 0; j < i; j++){
            if (numList[j] > numList[i]){
                maybePivot = false;
                break;
            }
        }
        if (maybePivot){
            for (int j=i+1; j < n; j++){
                if (numList[j] <= numList[i]){
                    maybePivot = false;
                    break;
                }
            }
        }
        if (maybePivot){
            pivotList.push_back(numList[i]);
        }
    }

    int lastNum = numList.back();
    
    for (int i = 0; i<n-1; i++){
        if (numList[i] > lastNum){
            break;
        }
        if (i == n - 2){
                pivotList.push_back(lastNum);
        }
    }

    cout << pivotList.size() << "\n";
    

    return 0;
}