/*

d) Given an array of integers representing the elevation of a roof structure at various positions, each position is separated by a unit length, Write a program
to determine the amount of water that will be trapped on the roof after heavy rainfall
Example:

input: [2 1 3 0 1 2 3]

Ans: 7 units of water will be trapped

The next phase is that the values are now not discrete but analog Eg. I give an equation of function

that is bounded, can you predict how many units of water gets trapped.

*/


#include <bits/stdc++.h>
#define pi 3.1415926535

using namespace std;

double trappedwater(){
    // Taking given function as cos(x)
    
    double l=0,r=6*pi; // Taking interval as 0 and 6*pi
    double n=1000000; // Taking 1000000 blocks
    double h=(r-l)/n,ans=0;
    vector<double> block(1e6),leftm(1e6,-1),rightm(1e6,-1);
    for(int i=0;i<n;i++){
        block[i]=cos(i*h+h/2);
    }
    for(int i=1;i<n;i++){
        leftm[i]=max(leftm[i-1],block[i]);
    }
    for(int i=n-2;i>=0;i--){
        rightm[i]=max(rightm[i+1],block[i]);
    }
    for(int i=0;i<n;i++){
        ans+=(min(leftm[i],rightm[i])-block[i])*h;
    }
    return ans;
}

int main()
{
    cout<<trappedwater()<<endl;
    return 0;
}
