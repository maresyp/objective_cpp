#include <stdio.h>

int silnia(int n) {
    if(n <= 0) return 1;
    else return n * silnia(n - 1);
}
int main () {
    printf("Podaj liczbe do obliczenia silni: ");
    int number;
    if (scanf("%d", &number) != 1) {
        printf("Incorrect input !");
        return 1;
    } else if (number < 1){
        printf("Incorrect input !");
        return 1;
    } else {
        printf("Wynik -> %d", silnia(number));
    }
    return 0;
}