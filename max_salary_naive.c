#include "max_salary.h"

int * best_arr;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int is_better(const void *a,const void *b){
  const int *ia=(const int *)a;
  const int *ib=(const int *)b;
  char str1[LEN],str2[LEN],temp[LEN];
  sprintf(str1, "%d", *ia);
  sprintf(temp, "%d", *ib);
  strcpy(str2,temp);
  strcat(str2,str1);//str2 in front
  strcat(str1,temp);//str1 in front
  //printf("STR: %s %s\n",str1,str2);
  return (atof(str2)>atof(str1))?(1):(0);//str2 vs str1
  //printf("atoi: %d\n",a[0]);
}
double h_max=0;
void naive(int *a,int n){
        qsort(a, n, sizeof(int), is_better);
}

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
  

