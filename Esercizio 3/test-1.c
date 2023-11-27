#include <stdio.h>
#include <math.h>

int main() 
{
    int myNum;
    float pi = 3.14;

    printf("Inserisci il tuo numero: \n"); scanf("%d", &myNum);
    float semi = (myNum*3)/2;

    printf("L'area del quadrato e': %d\n", myNum*myNum);
    printf("L'area del cerchio e': %f\n", pi*(myNum*myNum));
    printf("L'area del triangolo e': %f\n", sqrt(semi*((semi-myNum)*3)));
    return 0;
}