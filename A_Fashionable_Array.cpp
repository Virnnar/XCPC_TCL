#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    int odd[2] = {n, 0}, eve[2] = {n, 0};
    for (int i = 0; i < n; i++)
        if (a[i] & 1) {
            odd[0] = min(odd[0], i);
            odd[1] = max(odd[1], i);
        } else {
            eve[0] = min(eve[0], i);
            eve[1] = max(eve[1], i);
        }
    cout << min(odd[0] + n - 1 - odd[1], eve[0] + n - 1 - eve[1]) << endl;
}
// 1 1 2 3 4 5 9

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}