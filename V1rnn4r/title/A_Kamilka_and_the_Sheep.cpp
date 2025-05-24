#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    vector<int> a(n);
    for (int &i: a) cin >> i;
    cout << *max_element(all(a)) - *min_element(all(a))  << endl;
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