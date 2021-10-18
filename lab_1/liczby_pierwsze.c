#include <stdio.h>

void n_primes(int amount) {
    int number = 2;
    int counter = 0;
    short is_prime;
    while (counter < amount) {
        is_prime = 1;
        for (int i = 2; i <= number/2; i++) {
            if (number % i == 0) {
                is_prime = 0;
                break;
            }
        }
        if (is_prime) {
            printf(" %d", number); counter++;
        }
        number++;
    }
}

int main() {
    printf("Podaj ilosc liczb pierwszych: ");
    int amount;
    if (scanf("%d", &amount) != 1) {
        printf("Incorrect input");
        return 1;
    } else if (amount <= 0) {
        printf("Incorrect input");
        return 1;
    } else {
        n_primes(amount);
    }
    return 0;
}

