#include "trencito.h"
#include <string.h>

int length(char* string){
    int counter = 0;
    while (string[counter] != 0)
    {
        counter++;
    }

    return counter;
}

char* strConcatenate(char* s1, char* s2){
    int len_s1 = length(s1);
    int len_s2 = length(s2);
    int len_snew = len_s1 + len_s2;
    char* snew = malloc((sizeof(char))*(len_snew +1));
    int i=0;
    for(i; i < len_s1; i++){
        snew[i] = s1[i];
    }
    int t = 0;
    for(i; i <= len_snew ; i++){
        snew[i] = s2[t];
        t++;
    }
 
  return snew;
}

int strCompare(char* a, char* b) {

    int l1 = length(a);
    int l2 = length(b);

    int min;

    // voy a usar una variable auxiliar, va a valer 1 si l1 es el mayor, 2 si l2 es el mayor, 3 si son iguales
    int auxi;
    if ( l1 == l2){
        min = l2;
        auxi = 3;
    } else if ( l1 > l2) {
        min = l2;
        auxi = 1;
    } else {
        min = l1;
        auxi = 2;
    }

    int i;
    for (i = 0; i < min ; i++){
        int value = a[i] - b[i];
        if ( value != 0){
            if ( value > 0 ){
                return 1;
            }
            return -1;
        }
    }

    if ( auxi == 1)
        return 1;
    if (auxi == 2)
        return -1;
    return 0;
}


char* strDuplicate(char* src){
    int len = length(src);
    char *sdup = (char*)malloc( sizeof(char) * (len + 1) );
    int i;
    for (i = 0; i <= len; i++){
        sdup[i] = src[i]; 
    }

    return sdup;
}


struct trainDance* trainDanceNew(char* name0, int group0, char* name1, int group1) {
    struct node* n0 = (struct node*)malloc(sizeof(struct node));
    struct node* n1 = (struct node*)malloc(sizeof(struct node));
    n0->name = strDuplicate(name0);
    n0->group = group0;
    n0->next = n1;
    n1->name = strDuplicate(name1);
    n1->group = group1;
    n1->next = n0;
    struct trainDance* td = (struct trainDance*)malloc(sizeof(struct trainDance));
    td->first = n0;
    td->count = 2;
    return td;
}

struct node* trainDanceGetNode(struct trainDance* train, char* name) {

    if (!train || train->count == 0) return NULL;
    struct node* current = train->first;
    
    for (int i = 0; i < train->count; i++) {
        if (!strCompare(current->name, name)) {
            return current;
        } else current = current->next;
    }

    return NULL;
}

int cantidad_string(struct trainDance* train) {
    int tamano_string = 0;
    struct node* current = train->first;

    for (int i = 0; i < train->count; i++) {
        tamano_string += length(current->name) + 1; //sumo 1 para contar el caracter nulo

        current = current->next;
    }

    return tamano_string;
}

int trainDanceGroupCount(struct trainDance* train, int group) {
    struct node* n = train->first;
    int result = 0;
    do {
        if (n->group == group)
            result = result + 1;
        n = n->next;
    } while ( n != train->first );

    return result;
}

char* trainDanceGetNames(struct trainDance* train, char* separator) {
    int cantidad_caracteres = cantidad_string(train);
    char* nombres = (char*)malloc((sizeof(char))*cantidad_caracteres);
    int cant_personas = train->count;
    struct node* current = train->first;

    for(int i = 1; i <= cant_personas; i++){
        nombres = strConcatenate(nombres, current->name);
        if (i < cant_personas)
        nombres = strConcatenate(nombres, separator);

        current = current->next;
    }

    return nombres;
}

int trainDanceAddToDance(struct trainDance* train, char* name1, char* name2, char* nameNew, int groupNew) {
    if (!train) return -1;
    int cant_personas = train->count;
    struct node* prev = train->first;
    struct node* current = prev->next;    

    for(int i = 0; i <= cant_personas; i++){
        char* nom1 = prev->name;
        char* nom2 = current->name;
    
        if (!strCompare(nom1, name1) && !strCompare(nom2, name2)) {
            struct node* nuevo = (struct node*)malloc(sizeof(struct node));
            nuevo->name = strDuplicate(nameNew);
            nuevo->group = groupNew;
            nuevo->next = current;
            prev->next = nuevo;
            train->count++;
            return 0; //pudo meterse
        } else {
            prev = prev->next;
            current = current->next;
        }
    }

    return -1; //devuelve -1 cuando no se pudo meter
}

int trainDanceImTired(struct trainDance* train, char* name) {
    if (!train || train->count <= 2) return -1;
    int cant_personas = train->count;
    struct node* prev = train->first;
    struct node* current = prev->next;

    for(int i = 0; i <= cant_personas; i++){
        char* nombre = current->name;

        if (!strCompare(nombre, name)){
            prev->next = current->next;
            if(current == train->first)
                train->first = current->next;
            free(current);
            train->count --;
            return 0;
        } else {
            prev = prev->next;
            current = current->next;
        }
    }

    return -1;
}

struct node* ultimo_nodo(struct trainDance* train) {
    if (!train || train->count == 0) return NULL;
    struct node* current = train->first;
    int cant_personas = train->count;

    while (cant_personas > 1 && current->next != train->first)
        current = current->next;

    return current;
}

void trainDanceGotToMosh(struct trainDance** train, struct trainDance** trainMosh, struct trainDance** trainRemains, int groupMosh) {
    if (!train ) return;
    int cant_personas = (*train)->count;
    int cant_max_pogo = cant_personas - 2;
    int cant_grupo = trainDanceGroupCount(*train, groupMosh);

   // printf("\nPersonas: %d\nMax pogo:%d\n#Grupo%i: %d", cant_personas,cant_max_pogo,groupMosh,cant_grupo);

    if (cant_personas < 4 || cant_grupo < 2 || cant_grupo > cant_max_pogo) {
        *trainMosh = NULL;
        *trainRemains = NULL;
        return;
    }

    struct node*  prev = ultimo_nodo(*train);
    struct node* current = (*train)->first;
    struct node* prox = prev->next;

    for(int i = 0, j = 0; i < cant_personas, j < cant_grupo; i++){
        prev->next = current->next;
        if (current->group == groupMosh) {
            if (j = 0) {
                current->next = NULL;
                (*trainMosh)->first = current;
            }
            // else if (j = 1) {
            //     (*trainMosh)->first->next = current;
            // }
            else {
                current->next = (*trainMosh)->first;
                struct node* ultimo = ultimo_nodo(*trainMosh);
                ultimo->next = current;
            }
            if (i = 0)
                (*train)->first = prev->next; //current->next
            j++;
            (*trainMosh)->count ++;

        } else {
            if ((*trainRemains)->count = 0){
                current->next = NULL;
                (*trainRemains)->first = current;
            } else {
                current->next = (*trainRemains)->first;
                struct node* ultimo = ultimo_nodo(*trainRemains);
                ultimo->next = current;
            }
            //prev->next = current->next;
            (*trainRemains)->count ++;
        }
        prev = prev->next;
        current = current->next;
        (*train)->count --;
    }
}

void trainDanceDelete(struct trainDance* train) {

    // COMPLETAR

}

void trainDancePrint(struct trainDance* train) {
    struct node* n = train->first;
    printf("(%i)",train->count);
    do {
        printf("[%s,%i]",n->name,n->group);
        n = n->next;
    } while ( n != train->first );
}
