#include<stdio.h>

int days, sum;
void DataInput(){
    printf("Enter days:");
    scanf("%d", &days);
    printf("Enter sum:");
    scanf("%d", &sum);
}
void InputCheck(){
  if( days < 30 || days > 360 ||
      sum < 1000){
    printf("Incorrect data input\n");
    printf("\n Enter again");
    DataInput();
    InputCheck();
  }
}

int main(){
    DataInput();
    InputCheck();

    return 0;
}
