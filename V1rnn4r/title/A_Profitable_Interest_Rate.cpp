#include "Monday.h"

using namespace virmar;



void doit() {
    int a, b; cin >> a >> b;
    if (a >= b) cout << a << endl;
    else cout << max(2 * a - b, 0) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}