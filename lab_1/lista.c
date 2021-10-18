#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main(){
    struct doubly_linked_list_t *dll = dll_create();
    if (dll == NULL) {
        printf("Failed to allocate memory");
        return 8;
    }
    int input;
    printf("---- OPERACJE ----\n");
    printf("0.Zakończenie działania programu.\n");
    printf("1.Dodanie elementu na koniec listy.\n");
    printf("2.Usunięcie ostatniego elementu z listy.\n");
    printf("3.Dodanie elementu na początek listy.\n");
    printf("4.Usunięcie pierwszego elementu z listy.\n");
    printf("5.Dodanie elementu do listy na pozycji podanej przez użytkownika.\n");
    printf("6.Usunięcie elementu spod indeksu podanego przez użytkownika z listy.\n");
    printf("7.Wyświetlenie wartości ostatniego elementu listy.\n");
    printf("8.Wyświetlenie wartości pierwszego elementu listy.\n");
    printf("9.Sprawdzanie czy lista jest pusta.\n");
    printf("10.Wyświetlenie liczby elementów znajdujących się w liście.\n");
    printf("11.Usunięcie wszystkich elementów z listy.\n");
    printf("12.Wyświetlenie wartości elementu spod indeksu indeksu index listy.\n");
    printf("13.Wyświetlenie wartości wszystkich elementów znajdujących się w liście.\n");
    printf("14.Wyświetlenie od końca wartości wszystkich elementów znajdujących się w liście.\n");
    printf("---- OPERACJE ----\n");
    do {
        printf("Podaj operacje: ");
        if (scanf("%d", &input) != 1) {
            printf("Incorrect input");
            dll_clear(dll);
            free(dll);
            return 1;
        }
        if (input < 0 || input > 14) {
            printf("Incorrect input data\n");
            continue;
        }
        if (input == 1) {
            printf("Podaj liczbe: ");
            int value;
            if (scanf("%d", &value) != 1) {
                printf("Incorrect input");
                dll_clear(dll);
                free(dll);
                return 1;
            }
            int res = dll_push_back(dll, value);
            if (res == 2) {
                printf("Failed to allocate memory");
                dll_clear(dll);
                free(dll);
                return 8;
            }
        }
        if (input == 2) {
            int err;
            int value = dll_pop_back(dll, &err);
            if (err == 1) {
                printf("List is empty\n");
            } else {
                printf("%d\n", value);
            }
        }
        if (input == 3) {
            printf("Podaj liczbe: ");
            int value;
            if(scanf("%d", &value) != 1) {
                printf("Incorrect input");
                dll_clear(dll);
                free(dll);
                return 1;
            }
            int res = dll_push_front(dll, value);
            if (res == 2) {
                printf("Failed to allocate memory");
                dll_clear(dll);
                free(dll);
                return 8;
            }
        }
        if (input == 4) {
            int err;
            int value = dll_pop_front(dll, &err);
            if (err == 1) {
                printf("List is empty\n");
            } else {
                printf("%d\n", value);
            }
        }
        if (input == 5) {
            int value, index;
            printf("Podaj liczbe: ");
            if(scanf("%d", &value) != 1) {
                printf("Incorrect input");
                dll_clear(dll);
                free(dll);
                return 1;
            }
            printf("Podaj index : ");
            if(scanf("%d", &index) != 1) {
                printf("Incorrect input");
                dll_clear(dll);
                free(dll);
                return 1;
            }
            int res = dll_insert(dll, index, value);
            if (res == 2) {
                printf("Failed to allocate memory");
                dll_clear(dll);
                free(dll);
                return 8;
            } else if (res == 1) {
                printf("Index out of range\n");
            }
        }
        if (input == 6) {
            if (dll_is_empty(dll)) {
                printf("List is empty\n");
            } else {
                int index;
                printf("Podaj index: ");
                if (scanf("%d", &index) != 1) {
                    printf("Incorrect input");
                    dll_clear(dll);
                    free(dll);
                    return 1;
                }
                int err;
                int value = dll_remove(dll, index, &err);
                if (err == 1) {
                    printf("Index out of range\n");
                } else {
                    printf("%d\n", value);
                }
            }
        }
        if (input == 7) {
            int err;
            int value = dll_back(dll, &err);
            if (err == 1) {
                printf("List is empty\n");
            } else {
                printf("%d\n", value);
            }
        }
        if (input == 8) {
            int err;
            int value = dll_front(dll, &err);
            if (err == 1) {
                printf("List is empty\n");
            } else {
                printf("%d\n", value);
            }
        }
        if (input == 9) {
            printf("%d\n", dll_is_empty(dll));
        }
        if (input == 10) {
            printf("%d\n", dll_size(dll));
        }
        if (input == 11) {
            dll_clear(dll);
        }
        if (input == 12) {
            if (dll_is_empty(dll)) {
                printf("List is empty\n");
            } else {
                int err, index;
                printf("Podaj index: ");
                if (scanf("%d", &index) != 1) {
                    printf("Incorrect input");
                    dll_clear(dll);
                    free(dll);
                    return 1;
                }
                int value = dll_at(dll,index, &err);
                if (err == 1) {
                    printf("Index out of range\n");
                } else {
                    printf("%d\n", value);
                }
            }
        }
        if (input == 13) {
            if (dll_is_empty(dll)) {
                printf("List is empty\n");
            } else {
                dll_display(dll);
                printf("\n");
            }
        }
        if (input == 14) {
            if (dll_is_empty(dll)) {
                printf("List is empty\n");
            } else {
                dll_display_reverse(dll);
                printf("\n");
            }
        }
    } while (input != 0);
    dll_clear(dll);
    free(dll);
    return 0;
}
