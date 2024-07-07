#include "Monday.h"

using namespace virmar;

void doit() {
    string s;
    getline(cin, s);
    cout << s;
}

int main() {
    virmar::READ_ARC = false;
    int T = 1; // cin >> T;
    while (T--) doit();
    return 0;
}