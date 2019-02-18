#include "max_salary.h"

//int * best_arr;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

double h_max=0;

// Generating permutation using Heap Algorithm 
void heap_permutation(int a[], int size, int n) 
{ 
    // if size becomes 1 then do something with the obtained permutation   
    if (size == 1) 
    { 
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        double temp=combine_max(a,n);
        if (temp>h_max)
          h_max=temp;
          //memcpy(best_arr, a, sizeof(best_arr));
        return; 
    } 
  
    for (int i=0; i<size; i++) 
    { 
        heap_permutation(a,size-1,n); 
  
        // if size is odd, swap first and last element 
        if (size%2==1) {
            SWAP(a[0], a[size-1]); 
		    }
        // If size is even, swap ith and last element 
        else{
            SWAP(a[i], a[size-1]);
		    }			
    } 
} 
  

