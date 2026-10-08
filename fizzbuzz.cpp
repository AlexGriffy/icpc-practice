#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    int y;
    int n;
    cin >> x >> y >> n;

    for (int i=1; i<=n; i++){
        
        if ((i % x == 0) && (i % y == 0)){
            cout << "FizzBuzz" << "\n";
            continue;
        }
        if (i % x == 0){
            cout << "Fizz" << "\n";
            continue;
        }
        if (i % y == 0){
            cout << "Buzz" << "\n";
            continue;
        }
        else{
            cout << i << "\n";
            continue;
        }
    }

    return 0;
}