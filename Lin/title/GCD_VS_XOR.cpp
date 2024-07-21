#include "Monday.h"

using namespace virmar;

ll x;

void doit() {
    cin >> x;
    if ((x ^ 1) == 1) return puts("1"), void();
    
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}