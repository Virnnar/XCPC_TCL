#include<iostream>
#include<vector>
using namespace std;
bool check1(int x){//判断位数
    if(x>0&&x<10||x>100&&x<=999||x>10000&&x<=99999||x>1000000&&x<=9999999) return true;
    return false;
}
bool check2(int x){//判断回文
    vector<int> a(20);
    int l=0;
    while(x){
        a[l++]=x%10;
        x/=10;
    }
    for(int i=0;i<l;i++){
        // cout<<a[i]<<" "<<a[l-i-1]<<endl;
        if(a[i]!=a[l-i-1]) return false;
    }
    return true;
}
bool check3(int x){
    if(x==2) return true;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int a,b;
    cin>>a>>b;
    if(a%2==0) a++;
    for(int i=a;i<=b;i++){
        if(i==11) cout<<11<<endl;
        if(!check1(i)) continue;
        if(!check2(i)) continue;
        if(!check3(i)) continue;
        cout<<i<<endl; 
    }
    return 0;
}