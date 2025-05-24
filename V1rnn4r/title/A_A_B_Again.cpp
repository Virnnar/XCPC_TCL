#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    cout << (n % 10 + n / 10) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}