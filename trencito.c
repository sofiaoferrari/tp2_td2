#include "trencito.h"
#include <string.h>



/*
    Funcion que dado un string cuenta la cantidad de caracteres del mismo (sin contar el caracter nulo)
*/
int len(char* string){
    int contador = 0;
    while (string[contador] != 0)
    {
        contador++;
    }

    return contador;
}

/*
    Funcion que pide memoria del largo de los dos strings recibidos sumados, mas uno para el caracter nulo. 
    Luego, recorre s1, copiando caracter a caracter(sin incluir el caracter nulo), y despues recorre s2 copiando 
    caracter a caracter, incluyendo el caracter nulo. Al final de la funcion libera ambos strings.
*/
char* strConcatenate(char* s1, char* s2){
    int len_s1 = len(s1);
    int len_s2 = len(s2);
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

/*
    Funcion que compara dos strings, a y b, caracter a caracter, y verifica el orden lexicografico.
    Para ello, seleccionamos el string mas corto como limite para recorrer ambos strings y asi los vamos recorriendo 
    caracter a caracter, nos fijamos si el caracter de b es mayor que el de a(ambos en la misma posicion i), si son 
    iguales el ciclo continua hasta terminar o que un caracter sea mayor que otro. Si un caracter de b es mayor que el 
    de a, devuelve -1, si es menor devuelve 1 y termina la funcion. Si al terminarse el ciclo todos los caracteres fueron 
    iguales, si el largo de a es mayor al largo de b, devuelve 1, caso contrario devuelve -1. En caso de no cumplirse 
    ninguna de esas dos, es decir, ambos strings son exactamente iguales, devuelve 0.
*/
int strCompare(char* a, char* b) {

    int l1 = len(a);
    int l2 = len(b);

    int min = l1;
    if ( l1 > l2) min = l2;


    for (int i = 0; i < min ; i++){
        int value = a[i] - b[i];
        if ( value > 0 )
            return 1;  
        else if (value < 0)
            return -1;
    }

    if ( l1 < l2) return -1;
    else if (l1 > l2) return 1;
    return 0;
}

/*
    Funcion que pide memoria igual al largo del string dado (+1 para el caracter nulo), y luego lo copia caracter a 
    caracter en ese bloque de memoria.
*/
char* strDuplicate(char* src){
    int largo = len(src);
    char *sdup = (char*)malloc( sizeof(char) * (largo + 1) );
    int i;
    for (i = 0; i <= largo; i++){
        sdup[i] = src[i]; 
    }

    return sdup;
}

/*
    Funcion que crea un tren dadas dos personas con sus respectivos nombres y grupos. 
    Para ello pide la memoria necesaria para crear los nodos y el trencito y los incializa con la data dada.
    Retorna el trencito creado.
*/
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

/*
    Funcion que recorre el tren, comprobando en cada nodo si el nombre del mismo coincide con el que se busca. 
    En caso de encontrarlo, devuelve su direccion de memoria, en caso de que no, devuelve NULL.
*/
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


/*
    Funcion que cuenta la cantidad de personas(nodos) que hay en el trencito del grupo dado y lo retorna.
*/
int trainDanceGroupCount(struct trainDance* train, int group) {
    if(!train || train->count == 0) return 0;
    struct node* n = train->first;
    int result = 0;
    do {
        if (n->group == group)
            result = result + 1;
        n = n->next;
    } while ( n != train->first );

    return result;
}


/*
    Funcion que recorre el tren por la cantidad de personas que contiene, empezando desde la primera.
    Por cada persona que encuentra, la concatena con las personas encontradas anteriormente y un separador.
    Para ello, en la primer iteracion inicializa "nombres" con el duplicado del nombre de la primer persona del 
    trencito y luego lo concatena con el separador. En los siguientes ciclos se concatena el string "nombres" con 
    el siguiente nombre y, a continuacion con el separador. Esto ocurre hasta el ultimo ciclo, en el cual no se 
    concatena con el separador.
    Retorna el string "nombres" con la concatenacion de todos los nombres separados por el separador dado.
*/
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

/*
    Funcion que agrega una persona a un trencito entre dos personas dadas.
    En el caso de que el tren no exista o este vacio, devuelve -1. De lo contrario, recorre el tren hasta encontrar a 
    name1 y name2 consecutivos(y en ese orden), y luego crea un nuevo nodo y lo agrega entre esas dos personas, sumando 
    uno al counter de personas del trencito.
    En caso de que los nombres dados no se encuentren consecutivos en ese orden, o alguno de ellos(o ambos) no se 
    encuentre en el trencito, devuelve -1.
*/
int trainDanceAddToDance(struct trainDance* train, char* name1, char* name2, char* nameNew, int groupNew) {
    if (!train || train->count == 0) return -1;
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


/*
    Funcion que quita a una persona(nodo) dada del trencito.
    En el caso de que el tren no exista o el tren tenga 2 o menos personas, es decir, esta vacio, devuelve -1. En 
    caso contrario, recorre el tren hasta encontrar el nombre "name" dado. Una vez que lo encuentra, toma el nodo anterior 
    y le asigna el siguiente nodo al nodo a borrar. Luego libera el nodo a eliminar y resta la cantidad de personas del tren.
    Retorna 0 si se pudo eliminar el nodo, y -1 si no se pudo.
*/
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

/*
    Funcion adicional creada para que recorra el tren hasta llegar al ultimo nodo del trencito(el cual apunta al primer 
    nodo del trencito) y retorna la direccion del mismo.
*/
struct node* ultimo_nodo(struct trainDance* train) {
   
    if (!train || train->count == 0) return NULL;
    struct node* current = train->first;
    int cant_personas = train->count;

    while (cant_personas > 1 && current->next != train->first)
        current = current->next;

    return current;
}

/*
    Procedimiento donde si el tren no existe, esta vacio, o tiene menos de dos personas para ir al mosh o remains devuelve 0 
    en ambos trenes, caso contrario, recorre el tren y crea los trencitos mosh o remains con dos personas, en el caso del 
    mosh con las primeras dos personas encontradas en el trencito que pertenezcan al grupo dado "groupMosh", y en el caso 
    de remains con las primeras dos personas encontradas que tengan distinto grupo al dado. Una vez que se crearon ambos 
    trenes va recorriendo el trencito y agregando a las demas personas a los mismos segun al grupo que pertenezcan. 
    Al finalizar el ciclo se elimina el tren original llamando a la funcion trainDanceDelete.
*/
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


/*
    Procedimiento que se encarga de eliminar nodo a nodo del tren dado a medida que lo va recorriendo.
    Una vez que el tren este vacio, se libera el tren.
*/
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


/*
    Procedimiento que imprime cada nodo pertenciente al tren dado.
    Para ello, recorre el tren e imprime tanto el nombre como el grupo de cada nodo.
*/
void trainDancePrint(struct trainDance* train) {
    struct node* n = train->first;
    printf("(%i)",train->count);
    do {
        printf("[%s,%i]",n->name,n->group);
        n = n->next;
    } while ( n != train->first );
}