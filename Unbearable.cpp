#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * KATTIS
 * Name: Un-bear-able Zoo
 * Difficulty: Easy 1.7
 * 
 *link
 * https://open.kattis.com/problems/zoo
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    int listNum = 1;
    while (true){
        cin >> n;
        if (n == 0){
            break;
        }
        cin.ignore();

        map<string,int> list;
        string line;

        for (int i = 0; i < n; i++){
            getline(cin,line);
            string last = line.substr(line.find_last_of(' ') + 1);
            for (char &ch : last) ch = tolower(ch);
            list[last]++;
        }

        cout << "List " << listNum << ":\n";
        for (auto [key, val] : list){
            cout << key << " | " << val << "\n";
        }       
        listNum++;
    }
    return 0;
}