#include "max_salary.h"

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
        double max=naive(a,n);
        heap_permutation(a, n, n); 
        if (h_max!=max){
            printf("h_max: %f, max: %f",h_max,max);
            //print_array(a,n);
            exit(1);
        } else{
            printf("OK\n");
            h_max=0;
            //printf("h_max: %f, max: %f",h_max,max);
        }
    }
    //printf("H_MAX: %f\n",h_max);
}

// Code to test permutations
int main(int argc, char **argv) {
  if (argc<3){
    printf("test <N> <M>\nN=# of elements in array, M=# of digits in each integer\n");
    exit(1);
  } else if (atoi(argv[2])>6||atoi(argv[2])<=0||atoi(argv[1])<=0||atoi(argv[1])*atoi(argv[2])>30){
    printf("N= positive integer, M= positive integer <= 6\nN*M can't be bigger than 30 (arbitrary max digits of float)");
    exit(1);
  }
  int n=atoi(argv[1]), m=atoi(argv[2]);
  stress_test(n,m);
    //int a[] = {798,1328491,0,213}; //798 132849 0 213
    //int n = sizeof a/sizeof a[0]; 
    
    return 0; 
} 