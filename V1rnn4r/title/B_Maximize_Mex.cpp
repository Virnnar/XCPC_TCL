#include "Monday.h"

using namespace virmar;

void doit() {
    int n, x; cin >> n >> x;
    map<int, int> H;
    for (int i = 0; i < n; i++) {
        int t; cin >> t;
        H[t]++;
    }
    int now = 0;
    while (true) {
        if (H[now])
            H[now + x] += H[now] - 1;
        if (!H[now]) break;
        now++;
    }
    cout << now << endl;

}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}