#include "Monday.h"

using namespace virmar;

void init();

void doit() {
    int n; cin >> n;
    string s; cin >> s; s = '_' + s;
    vector<int> a(n);
    int max_val, min_val;
    max_val = min_val = a[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == '<') a[i] = min_val - 1;
        if (s[i] == '>') a[i] = max_val + 1;
        max_val = max(max_val, a[i]);
        min_val = min(min_val, a[i]);
    }

    for (auto i : a) cout << i - min_val + 1 << ' ';

    cout << endl;
    
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