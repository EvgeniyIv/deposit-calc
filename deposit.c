#include<stdio.h>

int days, sum;

void DataInput(){
    printf("Enter days:");
    scanf("%d", &days);
    printf("Enter sum:");
    scanf("%d", &sum);
}
void InputCheck(){
  if( days < 30 || days > 365 ||
      sum < 1000){
    printf("Incorrect data input\n");
    printf("\n Enter again\n");
    DataInput();
    InputCheck();
  }
}
int Count(){
  if(days >= 30)
    sum = sum + (sum * 0.1);
  if(days >= 31)
    sum = sum + (sum * 0.02);
  if(days >= 120)
    sum = sum + (sum * 0.06);
  if(days == 360)
    sum = sum + (sum * 0.12);
  return sum;
}
  
int main(){
    DataInput();
    InputCheck();
    Count();

    printf("\nDeposit sum = %d\n",sum );

      return 0;
}
