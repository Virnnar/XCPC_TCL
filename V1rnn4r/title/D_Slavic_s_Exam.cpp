#include "Monday.h"

using namespace virmar;

void doit() {
    string a, b, c; cin >> a >> b;
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '?') {
            if (idx < b.size())
                c += b[idx++];
            else
                c += 'a';
        } else {
            c += a[i];
            if (idx < b.size() and a[i] == b[idx]) idx++;
        }
    if (idx == b.size()) {
        puts("YES");
        cout << c << endl;
    } else puts("NO");
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}