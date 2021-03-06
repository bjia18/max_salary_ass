#include "max_salary.h"

double combine_max(int *c, int n){//find bigger value of heap's permutation
  char str[LEN*n];
  sprintf(str, "%d", c[0]);
  for (int i=1; i<n; i++){
    sprintf(str+strlen(str), "%d", c[i]);
  }
  //printf("STR: %s\n",str);
  double max=atof(str);
  return max;
}

void fast(int *a,int n){
        qsort(a, n, sizeof(int), is_better);
        print_array(a,n);
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

void stress_test(int n,int m){
    srand(time(NULL)); // randomize seed
    int a[n];
    //printf("%d,%d\n",n,m);
    double temp=m;
    while (1){
        for (int j=0;j<n;j++){
            a[j]=rand()%(int)pow(10,temp);
        }
        print_array(a,n);
        heap_permutation(a, n, n); 
        fast(a,n);
        double max=combine_max(a,n);//to compare max & h_max as 2 doubles
        if (h_max!=max){//strcmp requires turning h_max back to string & has the same O(n) as array comparison and combine_max
            printf("WRONG: h_max: %f, max: %f",h_max,max);//I could have returned strings for h_max and array a but it doesn't increase the limit of double; 
            exit(1);//double comparison for h_max is better than comparing 2 strings digit by digit
        } else{//if i didn't need h_max for heap's permutation (or compare naive to it) i would just print array a
            printf("OK\n");
            h_max=0;
        }
    }
    //printf("H_MAX: %f\n",h_max);
}
void simple_test(int *a, int n){
    print_array(a,n);
    heap_permutation(a, n, n); 
    fast(a,n);
    double max=combine_max(a,n);
    printf("fast: %f\nheap: %f\n",max,h_max);
}

int main(int argc, char **argv) {
  if (argc<4||atoi(argv[3])<0||atoi(argv[3])>1||(atoi(argv[3])==1 && argc<5)){
    printf("stress test: test <N> <M> <mode>\nsimple test: test <N> <M> <mode> <array>\nN=# of elements in array, M=maximum # of digits in each integer\nmode=0 is stress test, 1 is simple test\n");
    exit(1);
  } else if (atoi(argv[2])>6||atoi(argv[2])<=0||atoi(argv[1])<=0||atoi(argv[1])*atoi(argv[2])>50||argc>5){
    printf("N= positive integer, M= positive integer <= 6\nN*M can't be bigger than 50 (arbitrary max digits of float)\narray: 1,2,34,5 shouldn't be separated by space\n");
    exit(1);
  }
  int n=atoi(argv[1]), m=atoi(argv[2]);
  if (atoi(argv[3])==0){
        stress_test(n,m);
  } else{
        int a[n];
        int i=0;
        char* token = strtok(argv[4], ","); 

        while (token != NULL) { 
          a[i]=atoi(token); 
          i++;
          token = strtok(NULL, ","); 
        } 
        simple_test(a,n);
    }
  
  
    //int a[] = {798,1328491,0,213}; //798 132849 0 213
    //int n = sizeof a/sizeof a[0]; 
    
    return 0; 
} 
