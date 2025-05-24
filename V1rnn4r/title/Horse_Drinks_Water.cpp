#include "Monday.h"

using namespace virmar;

void doit() {
    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1 = -x1;
    double d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    printf("%.11f\n", d);
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}