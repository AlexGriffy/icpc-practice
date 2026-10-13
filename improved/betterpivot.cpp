#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //build arrays prefix max and suffix min based on array A
    //each prefMax[i] corresponds to the largest value to the left of A[i]

    

    int n;
    cin >> n;

    //initialize array
    vector<int> A(n);
    for (int i = 0; i < n; i++){
        int m;
        cin >> m;
        A[i] = m;
    }

    //build prefMax array
    vector<int> prefMax(n);
    prefMax[0] = A[0];
    for (int i = 1; i<n; i++) prefMax[i] = max(prefMax[i-1], A[i]);

    //build sufMin array
    vector<int> sufMin(n);
    sufMin[n-1] = A[n-1];
    for (int i = n-2; i >= 0; i--) sufMin[i] = min(sufMin[i+1], A[i]);

    vector<int> pivots;
    for (int i = 0; i < n; i++){
        if (prefMax[i] == sufMin[i]){
            pivots.push_back(A[i]);
        }
    }

    cout << pivots.size() << "\n";

    return 0;
}