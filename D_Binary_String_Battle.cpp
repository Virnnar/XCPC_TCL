#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    int cnt = count(all(s), '1');
    puts(cnt <= k or n < 2 * k ? "Alice" : "Bob");
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