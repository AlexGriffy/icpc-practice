#include <bits/stdc++.h>
using namespace std;

bool inPeople(map<string,bool> m, string name){
    return (m.find(name) != m.end());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string,bool> people;
    int n;

    string line;
    string entry;
    string name;

    cin >> n;
    cin.ignore();

    for (int i = 0; i < n; i++){
        getline(cin,line);
        if (line.substr(0,5) == "entry"){
            entry = line.substr(0,5);
            name = line.substr(6);
        }
        else{
            entry = line.substr(0,4);
            name = line.substr(5);
        }

        if (inPeople(people, name)){
            if (entry == "exit" && !(people[name])){
                cout << name << " exited (ANOMALY)" << "\n";
                people[name] = false;
                continue;
            }
            else if (entry == "entry" && people[name]){
                cout << name << " entered (ANOMALY)" << "\n";
                people[name] = true;
                continue;
            }
            else{
                if (entry == "entry"){
                    cout << name << " entered" << "\n";
                    people[name] = true;
                }
                else{
                    cout << name << " exited" << "\n";
                    people[name] = false;
                }
            }
        }
        else{
            if (entry == "entry"){
                    cout << name << " entered" << "\n";
                    people[name] = true;
            }
            else{
                cout << name << " exited (ANOMALY)" << "\n";
                    people[name] = false;
            }
        }

    }

    return 0;
}

