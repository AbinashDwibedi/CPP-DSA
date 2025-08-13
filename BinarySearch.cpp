#include<iostream>
#include<vector>

int binary_search_tree(int arr[],int low,int high,int target);
int binary_search_tree(int arr[],int low,int high,int target){
    if(low > high){
        return -1;
    }
    int mid = low + (high - low)/2;
    if(arr[mid] == target){
        return mid;
    }
    else if(arr[mid] < target){
        return binary_search_tree(arr,mid+1,high,target);
    }
    else {
        return binary_search_tree(arr,low,mid+1,target);
    }
}

int main(){
    int arr[] = {1,2,34,53,63,654};
    int length = 6;
    int result = binary_search_tree(arr,0,length,53);
    std::cout << result << std::endl;
    return 0;
}