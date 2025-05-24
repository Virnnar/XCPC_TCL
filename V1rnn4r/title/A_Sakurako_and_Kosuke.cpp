#include "Monday.h"

using namespace virmar;

void doit() {
    int n; cin >> n;
    if (n % 2) puts("Kosuke");
    else puts("Sakurako");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}