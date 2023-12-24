#include<iostream>
using namespace std;

int fun1(int arr[], int n, int key)
{

    int low=0;
    int high=n-1;
    int ans=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;

        if (arr[mid]==key)
        {
         ans=mid;
         high=mid-1;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int fun2(int arr[], int n, int key)
{

    int low=0;
    int high=n-1;
    int ans=0;
    while (low<=high)
    {
        int mid=low+(high-low)/2;

        if (arr[mid]==key)
        {
         ans=mid;
         low=mid+1;
        }
        else if (arr[mid]<key)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int count(int arr[], int n, int key) 
{
    int first_occurence=fun1(arr,n,key);   
    int second_occurence=fun2(arr,n,key);
	int occurence=(second_occurence-first_occurence)+1;
	
	if(first_occurence==0 && second_occurence==0)
	{
		return 0;
	}
	else
	{
		return occurence;
	}
}
int main()
{
    int n=10;
    int arr[10]={2,5,5,5,6,6,8,9,9,9};
    int key;
    cout<<"\nEnter key: ";
    cin>>key;
    int result=count(arr,n,key);
    if (result==0)
    {
        cout<<"\n "<<key<<" is not present";
    }
    else
    {
        cout<<key<<" occurs "<<result<<" times ";
    } 
}