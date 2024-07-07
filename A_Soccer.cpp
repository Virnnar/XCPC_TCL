#include "Monday.h"

using namespace virmar;

void doit() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a > b) swap(a, b), swap(c, d);

    if(c <= d) puts("YES");
    else puts("NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}