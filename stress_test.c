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

void stress_test(int n,int m){
    srand(time(NULL)); // randomize seed
    int a[n];
    char str[LEN];
    static char nums[11]="0123456789";
    //printf("%d,%d\n",n,m);
    while (1){
        for (int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                str[i] = nums[rand()%10];
                while (str[0]-'0'==0){
                    str[0] = nums[rand()%10];
                }
                //printf("%c ",str[i]);
            }
            //printf("%s ",str);
            a[j]=atoi(str);
        }
        print_array(a,n);
        heap_permutation(a, n, n); 
        naive(a,n);
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
void simple_test(int n, int m){
    srand(time(NULL)); // randomize seed
    int a[n];
    char str[LEN];
    static char nums[11]="0123456789";
    for (int j=0;j<n;j++){
            for(int i=0;i<m;i++){
                str[i] = nums[rand()%10];
                while (str[0]-'0'==0){
                    str[0] = nums[rand()%10];
                }
                //printf("%c ",str[i]);
            }
            //printf("%s ",str);
            a[j]=atoi(str);
    }
    print_array(a,n);
    heap_permutation(a, n, n); 
    naive(a,n);
    double max=combine_max(a,n);
    printf("naive: %f\nheap: %f\n",max,h_max);
}

int main(int argc, char **argv) {
  if (argc<4||atoi(argv[3])<0||atoi(argv[3])>1){
    printf("test <N> <M> <mode>\nN=# of elements in array, M=# of digits in each integer\nmode=0 is stress test, 1 is simple test\n");
    exit(1);
  } else if (atoi(argv[2])>6||atoi(argv[2])<=0||atoi(argv[1])<=0||atoi(argv[1])*atoi(argv[2])>30){
    printf("N= positive integer, M= positive integer <= 6\nN*M can't be bigger than 30 (arbitrary max digits of float)");
    exit(1);
  }
  int n=atoi(argv[1]), m=atoi(argv[2]);
  if (atoi(argv[3])==0){
        stress_test(n,m);
  } else{
        simple_test(n,m);
    }
  
  
    //int a[] = {798,1328491,0,213}; //798 132849 0 213
    //int n = sizeof a/sizeof a[0]; 
    
    return 0; 
} 
