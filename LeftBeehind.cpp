#include <bits/stdc++.h>
using namespace std;

/**
 * KATTIS PROBLEM
 * Name: "Left Beehind"
 * Difficult: easy (1.5)
 * 
 * link:
 * https://open.kattis.com/problems/leftbeehind
 * 
 */

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    /**
     * Conditions:
     * sweet < sour -> "Left beehind."
     * sweet > sour -> "To the convention."
     * sweet = sour -> "Undecided."
     * sweet + sour -> "Never speak again."
     * 
     * inputs:
     * x,y (sweet, sour)
     * terminated by a line containing two zeroes
     * 
     */

    int sweet, sour;
    while (cin >> sweet >> sour){
        if (sweet==0 and sour==0){ break;}

        if (sour + sweet == 13){
            cout << "Never speak again." << "\n";
            continue;
        }
        else if (sweet < sour){
            cout << "Left beehind." << "\n";
        }
        else if (sweet > sour){
            cout << "To the convention." << "\n"; 
        }
        else{
            cout << "Undecided." << "\n"; 
        }
    }



    return 0;
}