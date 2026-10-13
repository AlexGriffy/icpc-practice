#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    
    bool first = true;

    while (cin >> n && (n != 0)){
        if (!first) cout << "\n";
        first = false;
        
        vector<string> v(n);
        string line;
        for (int i = 0; i < n; i++){
            cin >> line;
            v[i] = line;
        }

        stable_sort(v.begin(), v.end(), [](const string& a, const string& b) {
            return a.substr(0, 2) < b.substr(0, 2);
        });

        for (string s: v) cout << s << "\n";
    }


    return 0;
}