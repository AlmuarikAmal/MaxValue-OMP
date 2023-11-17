#include<stdio.h>
#include<omp.h>
#include<stdlib.h>


int find_max(int A[], int j)
{
    int max_value = A[0];  // Initialize max_value with the first element
    
#pragma omp parallel for reduction(max:max_value)
    for (int i = 1; i < j; i++) {
        if (A[i] > max_value) {
            max_value = A[i];
        }
    }
    
    return max_value;
}
int main(int argc, char * argv []){

    int max_range ,max_indx;
        
    printf("Enter number of elements: ");
    scanf("%d", &max_range);
    printf("%d",max_range);

    int *rand_array_nums = (int *)malloc(max_range * sizeof(int));
    
    for (int i= 0 ; i< max_range - 1 ; i++){
        rand_array_nums[i]= rand(); /* generate integer random numbers on array */
    }

    max_indx = find_max(rand_array_nums, max_range);
    
    // print randomly assigned values
    for (int i = 0 ; i< max_range - 1; i++){
        printf("%d\t",rand_array_nums[i]);
        
    }
    // print the max value
    printf("\nThe maximum value is: %d", max_indx);

    return 0;
} /* end main */
