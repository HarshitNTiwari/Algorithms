#include <iostream>
#include <math.h>
using namespace std;

int main(){
    long long int n,k; cin>>n; cin>>k;
    long long int b= (2*n) +3;
    long long int c= ((n*n)+n-2*k);

    long long int y= (b- pow((b*b -4*c),0.5))/2;
    cout<<y<<endl;
}