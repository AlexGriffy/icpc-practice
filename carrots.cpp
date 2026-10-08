#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; int p;
    cin >> n >> p;

    string line;
    for (int i = 0; i < n; i++){
        getline(cin, line);
    }

    cout << p << "\n";

    return 0;
}