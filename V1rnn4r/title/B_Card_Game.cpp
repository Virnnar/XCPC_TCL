#include "Monday.h"

using namespace virmar;

void doit() {
    int a[3], b[3];
    cin >> a[1] >> a[2] >> b[1] >> b[2];
    int ans = 0;
    if ((a[1] > b[1] and a[2] >= b[2]) or (a[1] >= b[1] and a[2] > b[2])) ans++;
    swap(b[1], b[2]);
    if ((a[1] > b[1] and a[2] >= b[2]) or (a[1] >= b[1] and a[2] > b[2])) ans++;
    cout << ans * 2 << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}