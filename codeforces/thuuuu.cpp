#include<bits/stdc++.h>
using namespace std;
void Nhap(int A[],int n){
   for (int i=0;i<n;i++){
      scanf("%d",&A[i]);
   }
}
int SumSubArray(int A[], int n) {
   int Count = 0, Count1 = 0;
   int Temp = 0, Temp1 = 0;
   for(int i = 0; i<n; i++)
   if(A[i]>=0) {
      Count++;
      Temp+=A[i];
   }
   else {
      if(Count>Count1) {
         Temp1 = Temp;
         Count1 = Count;
      }
      if(Count == Count1 && Temp1<Temp)
         Temp1 = Temp;
      Temp = 0;
      Count = 0;
   }
   if(Count>Count1 ||(Count == Count1 && Temp1<Temp))
      Temp1 = Temp;
   return Temp1;
}
int main(){
   int A[50], n;
   scanf("%d",&n);
   Nhap(A,n);
   cout << SumSubArray(A,n)+1;

}
