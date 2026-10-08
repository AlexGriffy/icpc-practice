#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h; int m;

    cin >> h >> m;

    m = m - 45;
    if (m < 0){
        m+=60;
        if (h == 0){
            h = 23;
        }
        else{
            h--;
        }
    }

    cout << h << " " << m << "\n";
    return 0;
}