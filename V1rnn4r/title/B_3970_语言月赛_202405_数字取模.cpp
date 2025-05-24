#include "Monday.h"

using namespace virmar;

void doit() {
    while (b) {
        if (b % 2) ans *= a;
        a *= a;
        b /= 2;
        
    }
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}