#include "deposit.h"
#include <stdio.h>
int main()
{
    int days, sum;
    
    printf("Enter days:");
    scanf("%d", &days);
    printf("\nEnter sum:");
    scanf("%d", &sum);

    while(!InputCheck(days,sum)){
        printf("\nIncorrect data input\n");
        printf("\n Enter again\n");
        printf("Enter days:");
        scanf("%d", &days);
        printf("\nEnter sum:");
        scanf("%d", &sum);
    }
    
    sum = Count(days,sum);
    
    printf("\nDeposit sum = %d\n", sum);
    
    return 0;
}

