// contains binary search and bubble sorting
//  main.cpp
//  Assignment1
//
//  Created by Aaish Sindwani on 19/01/17.
//  Copyright © 2017 Aaish Sindwani. All rights reserved.
//
using namespace std;
#include <iostream>

void bubble(int *a){
    int k;
    for(int i=4;i>=0;i--){
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                k=a[j];
                a[j]=a[j+1];
                a[j+1]=k;
            }
        }
    }
}
int itbst(int *a,int ele){
    int start=0,end=4,mid;
    while(start<=end){
        mid=(start+end)/2;
        if(a[start]==ele){
            return start;
        }
        else if(a[end]==ele){
            return end;
        }
        else if(a[mid]>ele){
            end=mid;
        }
        else if(a[mid]<ele){
            start=mid+1;
        }
        else
            return mid;
    }
    return -1;
}

int bst(int *a,int ele,int start,int end){
    int mid=(start+end)/2;
    if(a[mid]==ele){
	return mid;
    }
    else if(a[start]==ele){
	return start;
    }
    else if(a[end]==ele){
	return end;
    }
    else if((end-start)<2){
        return -1;
    }
    else if(a[mid]>ele){
        end=mid;
        return bst(a,ele,start,end);
    }
    else if(a[mid]<ele){
        start=mid;
        return bst(a,ele,start,end);
    }
    else{
	return -1;
	}
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[5];
    cout<<"Enter array"<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
    bubble(arr);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    int ele,ind;
    cout<<"Enter element to search"<<endl;
    cin>>ele;
    ind=itbst(arr,ele);
    cout<<"Found at "<<ind<<endl;
    return 0;
}
