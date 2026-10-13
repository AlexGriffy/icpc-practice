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

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n - 1; j++){
                string word1 = v[j].substr(0,2);
                string word2 = v[j+1].substr(0,2);
                if (word1 > word2){
                    string temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
                
            }
        }

        for (string s: v) cout << s << "\n";
    }


    return 0;
}