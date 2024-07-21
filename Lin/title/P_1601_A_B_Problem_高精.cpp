#include<iostream>
#include<cstdio>

using namespace std;

const int N = 500 + 6;

string a, b;
int numa[N], numb[N];
int lena, lenb;

int main() {
    cin >> a >> b
    lena = a.size(), lenb = b.size();
    for (int i = 0; i < lena; i++) numa[lena - i] = a[i] - '0';
    for (int i = 0; i < lenb; i++) numb[lenb - i] = b[i] - '0';

    int len = max(lena, lenb);

    for (int i = 1; i <= len; i++) numa[i] += numb[i];


    for (int i = 1; i <= max(lena, lenb); i++) {
        numa[i + 1] += numa[i] / 10;
        numa[i] %= 10;
    }

    if (a[len + 1] != 0) len++;

    // for (int i = len; i >= 1; i--) cout << (char)(a[i] + '0');

}

