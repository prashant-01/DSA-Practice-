 #include<bits/stdc++.h>
 using namespace std;
long merge(vector<int> &temp , vector<int>&v , int s , int mid , int e){
    int i=s , j=mid+1 , k=s;
    long c=0;
    while(i<=mid && j<=e){
        if(v[i] <= v[j]){
            temp[k++]=v[i++];
        }
        else{
            temp[k++]=v[j++];
            c+=mid-i+1;
        }
    }
    while(i<=mid)temp[k++]=v[i++];
    while(j<=e)temp[k++]=v[j++];

    while(s <= e){
        v[s] = temp[s];
        s++;
    }

    return c;
}

long mergeSort(vector<int>&v , int s , int e , vector<int> &temp){
    if(s >= e)return 0;
    long c=0;
    int mid=s+(e-s)/2;
    c+=mergeSort(v , s , mid , temp);
    c+=mergeSort(v , mid+1 , e , temp);
    c+=merge(temp , v , s , mid , e);
    return c;
}

 int main(){
    vector<int>v={8,4,2,1};
    vector<int>temp={0,0,0,0};
    int count = mergeSort(v,0,v.size()-1 , temp);
    for(int i=0;i<4;i++)cout << v[i] << " ";
    cout << "Inversion " << count ;
 }