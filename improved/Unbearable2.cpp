#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //each iteration:
    //create a hashmap
    // loop n times: take string, get last word, add to hashmap
    //print list
    
    int n;
    int listNum = 1;

    while (cin >> n && !(n==0)){
        map<string,int> animalMap;
        cin.ignore();

        for (int i = 0; i < n; i++){
            string line;
            getline(cin,line);
            string last = line.substr(line.find_last_of(' ') + 1);
            for (char &ch : last) ch = tolower(ch);
            animalMap[last]++;
        }

        cout << "List "<< listNum << ":" << "\n";
        for (auto [key, val]: animalMap){
            cout << key << " | " << val << "\n";
        }

        listNum++;
    }

    return 0;
}