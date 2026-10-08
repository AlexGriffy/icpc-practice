#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int a; int b;

    cin >> a >> b;

    if (a > 0 && b > 0){
        cout << "1" << "\n";
    }

    if (a < 0 && b > 0){
        cout << "2" << "\n";
    }


    if (a < 0 && b < 0){
        cout << "3" << "\n";
    }

    if (a > 0 && b < 0){
        cout << "4" << "\n";
    }

    return 0;
}