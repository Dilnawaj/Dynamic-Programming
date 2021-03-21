#include <iostream>

using namespace std;
//TOP DOWN
int minstep(int n,int dp[])
{
    if(n==1) return 0;
    if(dp[n]!=0) return dp[n];
    int op1,op2,op3;
op1=op2=op3=INT_MAX;
if(n%3==0) op1=minstep(n/3,dp)+1;
if(n%2==0) op2=minstep(n/2,dp)+1;
op3=minstep(n-1,dp)+1;
    int ans=min(op1,min(op2,op3));
    return dp[n]=ans;
}

//BOTTOM UP
int minsteps(int n){
int dp[n+1]={0};
dp[0]=0;
dp[1]=0;
for(int i=2;i<=n;i++)
{

if(i%3==0 && i%2==0 )  dp[i]=min(1+dp[i/2],min(1+dp[i/3],1+dp[i-1]));
else if(i%3!=0 && i%2==0 ) dp[i]=1+ min(dp[i/2],dp[i-1]);
   else if (i%3==0 && i%2!=0 ) dp[i]=1+min(dp[i/3],dp[i-1]);
else dp[i]=1+dp[i-1];


}
return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<"Min steps top down = "<<minsteps(n)<<endl;
    int dp[100]={0};
    cout<<"Min steps bottom up = "<<minstep(n,dp)<<endl;

    return 0;
}
