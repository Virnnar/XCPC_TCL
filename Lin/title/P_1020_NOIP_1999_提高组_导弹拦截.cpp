#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int MAXN=100010;
int a[MAXN],n;
int h[MAXN],k=1;
int s[MAXN]={50001},len;

void in(){
    while(cin>>a[++n]);n--;
}

void first(){
    for(int i=1;i<=n;i++){
        if(a[i]<=s[len])s[++len]=a[i];
        else {
            int *p=upper_bound(s,s+len+1,a[i],greater<int>());
            *p=a[i];
        }
    }
    cout<<len<<endl;
}

void second(){
    memset(s,0,sizeof(s)),len=1;
    s[1]=a[1];
    for(int i=2;i<=n;i++)
        if(s[len]<a[i])s[++len]=a[i];
        else {
            int *p=lower_bound(s+1,s+len+1,a[i]);
            *p=a[i];
        }
    cout<<len<<endl;
}

int main(){
    in();
    first();
    second();
    return 0;
}