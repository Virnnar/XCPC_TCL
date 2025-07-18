#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
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