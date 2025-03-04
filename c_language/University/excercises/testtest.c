#include <stdio.h>


int recurse(int a[],int n){
   if(n-1 == 0){
	return 0;
   }
   int helper[n];
   for(int i = 0;i < n-1; i++){
	helper[i] = a[i]+a[i+1];
	printf("%d ",helper[i]);
	}
   printf("\n");
   return recurse(helper,n-1);
  

}

int main(){
	int arr[] = {10,15,20,30,35};
	int n = sizeof(arr)/sizeof(arr[0]);
	for(int i=0;i < n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
	recurse(arr,n);
	return 0;
} 
