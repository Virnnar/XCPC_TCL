#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=25;
void slove(){
    int n;
    string str,str1;
    cin>>n;
    cin>>str;
    str1=str;
    sort(str.begin(),str.end());
    if(str==str1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        slove();
    }
    return 0;
}