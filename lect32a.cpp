#include<iostream>
using namespace std;
void saydigit(string arr[],int n)
{
    if(n==0)
    return ;
    int digit=n%10;
    saydigit(arr,n/10);
    cout<<arr[digit]<<endl;
}
int main()
{
    int n;
    cin>>n;
    string arr[10]={"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    saydigit(arr,n);
    return 0;
}