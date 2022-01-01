#include <iostream>
#include <math.h>
using namespace std;
int g;
int arr[100000];
long findXORSum(int arr[], int n) {
   long sum = 0;
   int unsetBits = 0, setBits = 0;
   for (int i = 0; i < 32; i++) {
      unsetBits = 0; setBits = 0;
      for (int j = 0; j < n; j++) {
         if (arr[j] % 2 == 0)
            unsetBits++;
         else
            setBits++;
         arr[j] /= 2;
      }
      sum += ( unsetBits*setBits* (pow(2,i)) );
   }
   return sum;
}
int main() {
   cin>>g;
   for(int i=0;i<g;i++)
   {
       cin>>arr[i];
   }
   int n = sizeof(arr) / sizeof(arr[0]);
   cout<<findXORSum(arr, n);
   return 0;
}
