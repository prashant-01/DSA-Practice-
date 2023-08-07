#include<bits/stdc++.h>
using namespace std;
double division(int dividend , int divisor){
    int l=0,r=dividend,mid;
    double ans;
    //calc integer part
    while(l<=r){
        mid=l+(r-l)/2;
        if(mid*divisor==dividend)return mid;
        else if(mid*divisor<dividend){
            ans=mid;
            l=mid+1;
        }else r=mid-1;
    }

    //calc decimal part
    double step=0.1;
    for(int i=0;i<4;i++){
        for(double j=ans; j*divisor <= dividend ; j=j+step){
            ans=j;
        }
        step/=10;
    }
    return ans;
}
int main(){
    int divisor , dividend;
    cin >> dividend;
    cin >> divisor;
    cout << division(dividend,divisor);
}