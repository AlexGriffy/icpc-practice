#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * KATTIS
 * Name: Beehives
 * Difficulty: Easy 2.0
 * 
 *link
 * https://open.kattis.com/problems/mia
 */

bool inMap(int key, map<int, int> map){
    return map.find(key) != map.end();
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //2 players, 2 dice
    //score is not sum
    //12 or 21 is highest
    //next: doubles (11, 22, etc.) -- Ties
    // broken by value -- 66 highest
    // everything else - sort numbers high to low, 
    // becomes one number

    //OUTPUTS
    /**
     * Player 1 wins.
     * Player 2 wins.
     * Tie.
     */

    int s0; int s1;
    int r0; int r1;

    map<int, int> map = {{12,1}, {21,1}, {11,2},{22,2},{33,2},{44,2},{55,2},{66,2}};

    while(true){
        cin >> s0 >> s1 >> r0 >> r1;
        if (s0 == 0 && s1 == 0 && r0 == 0 && r1 == 0){
            break;
        }

        int roll1 = s0 * 10 + s1;
        int roll2 = r0 * 10 + r1;

        int sortedRoll1 = 0;
        int sortedRoll2 = 0;

        if (s0 > s1){
            sortedRoll1 = s0 * 10 + s1;
        }
        else{
            sortedRoll1 = s1 * 10 + s0;
        }

        if (r0 > r1){
            sortedRoll2 = r0 * 10 + r1;
        }
        else{
            sortedRoll2 = r1 * 10 + r0;
        }

        if (inMap(roll1, map) && inMap(roll2, map)){
            if (map[roll1] == 1 and map[roll2] == 1){
                cout << "Tie." << "\n";
                continue;
            }
            else if (map[roll1] == 1 && map[roll2] == 2){
                cout << "Player 1 wins."<<"\n";
                continue;
            }
            else if (map[roll1] == 2 && map[roll2] == 1){
                cout << "Player 2 wins."<<"\n";
                continue;
            }
            else if (map[roll1] == 2 && map[roll2] == 2){
                if (roll1 == roll2){
                    cout << "Tie." << "\n";
                    continue;
                }
                else if (roll1 > roll2){
                    cout << "Player 1 wins." << "\n";
                    continue;
                }
                else{
                    cout << "Player 2 wins." << "\n";
                    continue;
                }
            }
        }
        else if (inMap(roll1,map) && !inMap(roll2,map)){
            cout << "Player 1 wins." << "\n";
            continue;
        }
        else if (!inMap(roll1,map) && inMap(roll2,map)){
            cout << "Player 2 wins." << "\n";
            continue;
        }
        else{
            if(sortedRoll1 == sortedRoll2){
                cout << "Tie." << "\n";
                continue;
            }
            else if (sortedRoll1 > sortedRoll2){
                cout << "Player 1 wins." << "\n";
                continue;
            }
            else{
                cout << "Player 2 wins." << "\n";
                continue;
            }
        }

        cout << "Case not met" << "\n";

    }

    return 0;
}