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
    free(s1);
    free(s2);

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

int cantidad_string(struct trainDance* train, char* separator) {
    int tamano_string = 0;
    struct node* current = train->first;

    for (int i = 0; i < train->count; i++) {
        if (i != train->count -1)
            tamano_string += length(current->name) + length(separator); //sumo para contar el separador
        else
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
    char* nombres ;
    int cant_personas = train->count;
    struct node* current = train->first;

    for(int i = 1; i <= cant_personas; i++){
        
        if (i == 1)
            nombres = strDuplicate(current->name);
        else 
            nombres = strConcatenate(nombres, strDuplicate(current->name));
   
        if (i < cant_personas)
             nombres = strConcatenate(nombres, strDuplicate(separator));
    
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
            free(current->name);
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
    int cant_grupo = trainDanceGroupCount(*train, groupMosh);
    int cant_remains = cant_personas - cant_grupo;

    if (cant_personas < 4 || cant_grupo < 2 || cant_remains < 2) {
        *trainMosh = NULL;
        *trainRemains = NULL;
        return;
    }

    struct node*  prev = ultimo_nodo(*train);
    struct node* current = (*train)->first;

    for(int i = 0, j = 0, k = 0; i < cant_personas; i++){
        if (current->group == groupMosh && j < 2) {
            struct node* primero;
            struct node* segundo;

            if (j == 0) {
                primero = current;
            } else if (j == 1){
                segundo = current;
                char* nom1 = primero->name;
                char* nom2 = segundo->name;
                *trainMosh = trainDanceNew(nom1, groupMosh, nom2, groupMosh);
            } 
            j++;

        } else if (current->group == groupMosh){
            struct node* primero = (*trainMosh)->first;
            struct node* ultimo = ultimo_nodo(*trainMosh);

            char* nom1 = primero->name;
            char* nom2 = ultimo->name;
            char* nomNew = current->name;

            trainDanceAddToDance(*trainMosh, nom2, nom1, nomNew, groupMosh);
            j++;
        } else if ( k < 2) {
            struct node* primero;
            struct node* segundo;

            if (k == 0) {
                primero = current;
            } else if (k == 1){
                segundo = current;
                char* nom1 = primero->name;
                char* nom2 = segundo->name;
                int grupo1 = primero->group;
                int grupo2 = segundo->group;
                *trainRemains = trainDanceNew(nom1, grupo1, nom2, grupo2);
            } 
            k++;

        } else {
            struct node* primero = (*trainRemains)->first;
            struct node* ultimo = ultimo_nodo(*trainRemains);

            char* nom1 = primero->name;
            char* nom2 = ultimo->name;
            char* nomNew = current->name;
            int grupoNew = current->group;

            trainDanceAddToDance(*trainRemains, nom2, nom1, nomNew, grupoNew);
            k++;
        }
        prev = prev->next;
        current = current->next;
    }

   trainDanceDelete(*train);
   *train = NULL;
}

void trainDanceDelete(struct trainDance* train) {
    if (!train || train->count == 0) return;

    struct node* n = train->first;
    do {
        struct node* toDelete = n;
        n = n->next;
        free(toDelete->name);
        free(toDelete);
    } while ( n != train->first );
    free(train);
}

void trainDancePrint(struct trainDance* train) {
    struct node* n = train->first;
    printf("(%i)",train->count);
    do {
        printf("[%s,%i]",n->name,n->group);
        n = n->next;
    } while ( n != train->first );
}