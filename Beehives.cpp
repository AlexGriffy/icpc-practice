#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * KATTIS
 * Name: Beehives
 * Difficulty: Easy 1.8
 * 
 *link
 * https://open.kattis.com/problems/beehives
 */
struct P {double x, y;};
double dist(P a, P b) { double dx=a.x-b.x, dy=a.y-b.y; return dx*dx + dy*dy; }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    //STEPS
    //take input for d (distance) and N (number of hives)
    //break if entered: 0.0 0
    //take input for each point - put into a point struct
    //create list of the point structs
    //create separate list of true/false if hives have fought

    //check every possible pair, update true/false list accordingly
    //output # true (sour) and # false (sweet)

    double d;
    int N;

    while(true){
        cin >> d >> N;
        if (d == 0.0 and N == 0){
            break;
        }

        vector<P> pts(N);
        vector<bool> fought(N);

        for (int i = 0; i < N; i++){
            cin >> pts[i].x >> pts[i].y;
        }

        for (int i = 0; i < N; i++){
            for (int j=i+1; j < N; j++){
                double distance = dist(pts[i],pts[j]);
                if (distance <= d*d){
                    fought[i] = true;
                    fought[j] = true;
                }

            }
        }

        int sour = 0;
        int sweet = 0;

        for (int i = 0; i < fought.size(); i++){
            if (fought[i]){
                sour++;
            }
            else{
                sweet++;
            }
        }

        cout << sour << " sour, " << sweet << " sweet" << "\n";

    }
    return 0;
}