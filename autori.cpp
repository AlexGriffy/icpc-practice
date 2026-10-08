#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    string abbrev;
    char letter;

    getline(cin, line);

    for (char &ch : line){
        if (isupper(ch)){
            abbrev += ch;
        }
    }

    cout << abbrev << "\n";

    return 0;
}