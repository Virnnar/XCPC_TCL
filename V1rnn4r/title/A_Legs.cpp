#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    n /= 2;
    cout << (n + 1)/ 2 << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}