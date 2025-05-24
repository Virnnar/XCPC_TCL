#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    puts(n % 3 == 1 ? "YES" : "NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}