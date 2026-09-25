//benjamin PAILHES
//gcc -Wall -pedantic -fsanitize=address -g -o maximum_local maximum_local.c

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

/** t : tableau
 * n : sa taille
 * i : un indice */
bool maximum_local(int *t, int n, int i){
    if (i >= n || i < 0){
        return false;
    }
    
    if (i == 0){
        return t[i] > t[i+1];
    }
    if (i == n-1){
        return t[i-1] < t[i];
    }
    
    return t[i-1] < t[i] && t[i] > t[i+1];
}

/** t : tableau
* n : sa taille
* i : un indice */
//Ã  dÃ©commenter pour la question 2
bool valeur_inferieur_a_droite(int *t, int n, int i){
    for (int j = i; j < n-1; j++){
        if (t[j] != t[i]){
            break;
        }
        if (t[j] > t[j+1]){
            return true;
        }
    }
    return false;
}

bool valeur_inferieur_a_gauche(int *t, int i){
    for (int j = i; j > 0; j -= 1){
        if (t[j] != t[i]){
            break;
        }
        if (t[j] > t[j-1]){
            return true;
        }
    }
    return false;
}

bool vrai_maximum_local(int *t, int n, int i){
    if (i >= n-1 || i < 1){
        return false;
    }
    
    return valeur_inferieur_a_droite(t, n, i) && valeur_inferieur_a_gauche(t, i);
}


int main(void){
    int t[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2};
    int t2[] = {1, 2, 3, 2, 1, -1, -2, -1, -3, 5, 5, 2, 3, 3, 3, 3, 1, 4, 4, 4};

    assert(! maximum_local(t, 12, 0));
    assert(maximum_local(t, 12, 2));
    assert(maximum_local(t, 12, 7));
    assert(! maximum_local(t, 12, 9));
    assert(! maximum_local(t, 12, 12));

    //Ã  dÃ©commenter pour la question 2
    assert(! vrai_maximum_local(t2, 20, 0));
    assert(vrai_maximum_local(t2, 20, 2));
    assert(vrai_maximum_local(t2, 20, 7));
    assert(vrai_maximum_local(t2, 20, 9));
    assert(vrai_maximum_local(t2, 20, 12));
    assert(vrai_maximum_local(t2, 20, 13));
    assert(vrai_maximum_local(t2, 20, 14));
    assert(vrai_maximum_local(t2, 20, 15));
    assert(! vrai_maximum_local(t2, 20, 16));
    assert(! vrai_maximum_local(t2, 20, 18));
    assert(! vrai_maximum_local(t2, 20, 19));

    return 0;
}
