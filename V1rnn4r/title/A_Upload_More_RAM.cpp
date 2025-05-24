#include "Monday.h"

using namespace virmar;

int n, k;

void doit() {
    cin >> n >> k;
    // if (k == 1) cout << n << endl;
    cout << n * k - (k - 1) << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}