#include "Monday.h"

using namespace virmar;

void doit() {
    string s; cin >> s;
    for (int i = 0; i < s.size() - 1; i++)
        if (s[i] == s[i + 1])
            return puts("1"), void();
    cout << s.size() << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}