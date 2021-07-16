#include <iostream>

using namespace std;
//TOP DOWN
int fib(int n,int dp[])
{ if(n==0 || n==1) return n;
    int ans;
    if(dp[n]!=0) return dp[n];
    ans=fib(n-1,dp)+fib(n-2,dp);
    return dp[n]=ans;

}

//BOTTOM UP
int fibb(int n)
{
    if(n==0 || n==1) return n;
    int a=0; int b=1; int c;
    for(int i=2;i<=n;i++)
    {
        c=a+b;
        a=b;
        b=c;

    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int *dp = new int[n];
    //Creating dynamic array is better than giving size of 100 :)
    //int dp[100]={0};
    cout<<"Top down "<<fib(n,dp)<<endl;
    cout<<"Bottom up "<<fibb(n)<<endl;
    return 0;
}
