#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    puts(n % 4 ? "Alice" : "Bob");
}

signed main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T --> 0) doit();
    return 0;
}

void init() {

}