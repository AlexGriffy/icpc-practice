#include <bits/stdc++.h>
using namespace std;


/**
 * 
 * Claude's approach to "Secure Doors" problem
 * https://open.kattis.com/problems/securedoors
 */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<string, bool> inside;   // missing key -> false (outside)

    while (n--) {
        string action, name;
        cin >> action >> name;
        bool entering = (action == "entry");

        cout << name << (entering ? " entered" : " exited");
        if (inside[name] == entering) cout << " (ANOMALY)";   // already in state we're moving to
        cout << "\n";

        inside[name] = entering;
    }
    return 0;
}