//benjamin PAILHES
//gcc -Wall -pedantic -fsanitize=address -g -o periodique periodique.c

#include <assert.h>

/** t : tableau
 * n : taille de t
 * p : un entier */
bool periodique(int *t, int n, int p){
    for (int i = 0; i < n-p; i++){
        if (t[i] != t[i+p]){
            return false;
        }
    }
    return true;
}

int main(void){
    int t[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2};
    int t2[] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 1};

    assert(periodique(t, 11, 3));
    assert(! periodique(t, 11, 2));
    assert(! periodique(t2, 11, 3));


    return 0;
}