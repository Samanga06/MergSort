#include <iostream>

using namespace std;

void merge(int arr[],int l,int m, int r){
    int n1 = m-l+1;
    int n2 = r-m;
    
    int l1[n1];
    int l2[n2];
    
    for(int i =0 ;i<n1;i++)l1[i] = arr[l+i];
    for(int i=0;i<n2;i++)l2[i] = arr[m+1+i];
    
    int i = 0;
    int j = 0;
    int k = l;
    while(j<n2 && i<n1){
        if(l1[i]>=l2[j]){
            arr[k] = l2[j];
            k++;
            j++;
        }else{
            arr[k] = l1[i];
            k++;
            i++;
        }
    }
    
    while (i < n1) arr[k++] = l1[i++];
    while (j < n2) arr[k++] = l2[j++];
    
}

void mergesort(int arr[],int l, int r){
    if(l<r){
        int m = l + (r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        
        merge(arr,l,m,r);
    }
}

int main(){
    
    int arr[7] = {24,8,7,51,27,35,88};
    
    mergesort(arr,0,6);
    
    for(int x:arr){
        cout<<x<<"\t";
    }
    
    return 0;
}
