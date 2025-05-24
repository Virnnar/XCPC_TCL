#include "Monday.h"

using namespace virmar;

void doit() {
    int x, y; cin >> x >> y;
    if (y == x + 1) return puts("Yes"), void();
    if (x > y and (x - y + 1) % 9 == 0) return puts("Yes"), void();
    puts("No");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}



