#include<bits/stdc++.h>
using namespace std;
double sqRoot(int num){
    //calc integer part
    int l=0,r=num,mid;
    double ans;
    while(l<=r){
        mid=l+(r-l)/2;
        if(mid*mid == num)return mid;
        else if(mid*mid < num){
            ans=mid;
            l=mid+1;
        }
        else r=mid-1;
    }

    //calc decimal part
    double step=0.1;
    for(int i=0;i<5;i++){
        for(double j=ans;j*j<=num;j=j+step){
            ans=j;
        }
        step=step/10;
    }
    return ans;
}
int main(){
    int num;cin>>num;
    cout << sqRoot(num);
}