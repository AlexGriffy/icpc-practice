#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    stack<int> stack1;
    stack<int> stack2;

    int n;
    int numMoves = 0;
    cin >> n;

    for (int i = 0; i < 2*n; i++){
        int m;
        cin >> m;
        stack2.push(m);
    }

    for (int i = 0; i < 2*n; i++){
        stack1.push(stack2.top());
        stack2.pop();
    }

    bool first = true;
    while (!(stack1.empty())){
        if (!first && !stack2.empty()){
            if (stack1.top() == stack2.top()){
                stack1.pop(); stack2.pop();
                numMoves++;
                continue;
        }
        }
        stack2.push(stack1.top());
        stack1.pop();
        numMoves++;
        first = false;
        
    }

    if (stack2.empty()){
        cout << numMoves << "\n";
    }
    else{
        cout << "impossible" << "\n";
    }

   //empty stack1 into stack2
   //empty stack 2 into stack1
   //if stack1 not empty, impossible. If it is, return # of moves


    return 0;
}