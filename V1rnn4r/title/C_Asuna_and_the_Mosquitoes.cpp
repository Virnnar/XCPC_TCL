#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    ll sum = 0, k = 0;
    for (int &i: a) cin >> i, sum += i, k += i & 1;

    bool jud = true;

    for (int i = 1; i < n; i++)
        if ((a[i] + a[i - 1]) & 1) jud = false;

    if (jud) return cout << *max_element(all(a)) << endl, void();

    cout << sum - k + 1 << endl;


}

int main() {
    virmar::READ_ARC = false;
    init();
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}

void init() {

}


