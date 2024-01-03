#include <iostream>
#include <stack>
using namespace std;

struct Move {
    int disks;
    char source, target, auxiliary;

    Move(int d, char src, char tgt, char aux) : disks(d), source(src), target(tgt), auxiliary(aux) {}
};

void iterativeTowerOfHanoi(int n, char source, char target, char auxiliary) {
    stack<Move> moves;
    moves.push(Move(n, source, target, auxiliary));

    while (!moves.empty()) {
        Move currentMove = moves.top();
        moves.pop();

        n = currentMove.disks;
        source = currentMove.source;
        target = currentMove.target;
        auxiliary = currentMove.auxiliary;

        if (n > 0) {
            moves.push(Move(n - 1, auxiliary, target, source));
            cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl;
            moves.push(Move(n - 1, source, auxiliary, target));
        }
    }
}

int main() {
    int N = 3;
    char source = 'A', target = 'C', auxiliary = 'B';

    iterativeTowerOfHanoi(N, source, target, auxiliary);

    return 0;
}


