#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int w, h, a, b; cin >> w >> h >> a >> b;
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2)
        return puts(abs(y1 - y2) % b == 0 ? "Yes" : "No"), void();
    if (y1 == y2)
        return puts(abs(x1 - x2) % a == 0 ? "Yes" : "No"), void();

    if ((x1 - x2) % a == 0 or (y1 - y2) % b == 0) return puts("Yes"), void();

    puts("No");


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