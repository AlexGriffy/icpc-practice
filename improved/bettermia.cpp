#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * link:
 * https://open.kattis.com/problems/mia
 * 
 * CLAUDE'S suggested solution
 * 
 */

int score(int a, int b){
    if(min(a,b)==1 && max(a,b)==2) return 1000;   // Mia
    if(a==b)                        return 100+a;  // doubles: 11..66
    return 10*max(a,b)+min(a,b);                   // rest: sorted two-digit
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int s0,s1,r0,r1;
    while(cin >> s0 >> s1 >> r0 >> r1 && (s0||s1||r0||r1)){
        int p1 = score(s0,s1), p2 = score(r0,r1);
        if(p1==p2)      cout << "Tie.\n";
        else if(p1>p2)  cout << "Player 1 wins.\n";
        else            cout << "Player 2 wins.\n";
    }
    return 0;
}