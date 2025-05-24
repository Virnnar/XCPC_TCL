#include "Monday.h"

using namespace virmar;

void doit() {
    string s; cin >> s;
    cout << s.substr(0, s.size() - 2) + "i" << endl;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; cin >> T;
    while (T--) doit();
    return 0;
}