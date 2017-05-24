#include <stdio.h>
#include "deposit.h"

int InputCheck(int days, int sum){
    if(days < 30 || days >= 365 ||
    sum < 1000) return 0;
    return 1;
}

int Count(int days, int sum){

    if (days >= 30){
        sum -= sum * 0.1;
    }
    if (days >= 120){
	sum += sum * 0.02;
    }
    if (days >= 240){
	sum += sum * 0.06;
    }
    if (days == 365){
	sum += sum * 0.12;
    }

    return sum;

}
