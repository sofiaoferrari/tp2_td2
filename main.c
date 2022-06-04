#include <stdio.h>
#include <stdlib.h>
#include "trencito.h"

int main() {

    printf("\nP R U E B A S\n");

    //-------------------------------strDuplicate-------------------------------
    printf("\n\n~ Prueba strDuplicate()\n");

    printf("\n  > Prueba de ejemplo:\n");
    char* dup = strDuplicate("hola");
    printf("\tstrDuplicate(\"hola\") -> \"%s\"\n", dup);
    free(dup);

    printf("\n  > Prueba string vacio:\n");
    dup = strDuplicate("");
    printf("\tstrDuplicate(\"\") -> \"%s\"\n", dup);
    free(dup);

    printf("\n  > Prueba string de un caracter:\n");
     dup = strDuplicate("$");
    printf("\tstrDuplicate(\"$\") -> \"%s\"\n", dup);
    free(dup);

    printf("\n  > Prueba string de todos los caracteres validos distintos de cero:\n");
    dup = strDuplicate(" !#$%&'\"()*+,-./\\123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~");
    printf("\tstrDuplicate(\" !#$%&'\"()*+,-./\\123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[]^_`abcdefghijklmnopqrstuvwxyz{|}~\") -> \"%s\"\n", dup);
    free(dup);


    //-------------------------------strCompare-------------------------------
    printf("\n\n~ Prueba strCompare()\n");

    printf("\n  > Prueba de ejemplo:\n");
    printf("\tstrCompare(\"abc\",\"abc\") -> %i\n", strCompare("abc","abc"));

    printf("\n  > Prueba con dos strings vacios:\n");
    printf("\tstrCompare(\"\",\"\") -> %i\n", strCompare("",""));

    printf("\n  > Prueba con dos strings de un caracter:\n");
    printf("\tstrCompare(\"s\",\"i\") -> %i\n", strCompare("s","i"));

    printf("\n  > Prueba con dos strings iguales hasta un caracter:\n");
    printf("\tstrCompare(\"abc\",\"abcd\") -> %i\n", strCompare("abc","abcd"));
    printf("\tstrCompare(\"abcd\",\"abc\") -> %i\n", strCompare("abcd","abc"));

    printf("\n  > Prueba con dos strings distintos:\n");
    printf("\tstrCompare(\"bbb\",\"ccc\") -> %i\n", strCompare("bbb","ccc"));
    printf("\tstrCompare(\"ccc\",\"bbb\") -> %i\n", strCompare("ccc","bbb"));


    //-------------------------------strConcatenate-------------------------------
    printf("\n\n~ Prueba strConcatenate()\n");

    printf("\n  > Prueba de ejemplo:\n");
    char* concat = strConcatenate(strDuplicate("123"),strDuplicate("456"));
    printf("\tstrConcatenate(\"123\",\"456\") -> \"%s\"\n", concat);
    free(concat);

    printf("\n  > Prueba con un string vacio y otro de 3 caracteres:\n");
    concat = strConcatenate(strDuplicate(""),strDuplicate("456"));
    printf("\tstrConcatenate(\"\",\"456\") -> \"%s\"\n", concat);
    free(concat);

    printf("\n  > Prueba con un string de 3 caracteres y otro vacio:\n");
    concat = strConcatenate(strDuplicate("123"),strDuplicate(""));
    printf("\tstrConcatenate(\"123\",\"\") -> \"%s\"\n", concat);
    free(concat);

    printf("\n  > Prueba con dos strings de un caracter:\n");
    concat = strConcatenate(strDuplicate("1"),strDuplicate("4"));
    printf("\tstrConcatenate(\"1\",\"4\") -> \"%s\"\n", concat);
    free(concat);

    printf("\n  > Prueba con dos strings de 5 caracteres:\n");
    concat = strConcatenate(strDuplicate("12345"),strDuplicate("23456"));
    printf("\tstrConcatenate(\"12345\",\"23456\") -> \"%s\"\n", concat);
    free(concat);

    //-------------------------------trainDanceNew-------------------------------
    printf("\n\n~ Prueba trainDanceNew()\n");

    printf("\n  > Prueba de ejemplo:\n");
    struct trainDance* td = trainDanceNew("Matias", 1, "Agatha", 2);
    printf("\ttrainDanceNew(\"Matias\",1,\"Agatha\",2) -> ");
    trainDancePrint(td);

    //creacion de los demas trenes para las pruebas

    struct trainDance* td3 = trainDanceNew("Matias", 1, "Agatha", 2);
    
    struct trainDance* tdt = trainDanceNew("Matias", 1, "Agatha", 2);
    
    struct trainDance* tdM1 = trainDanceNew("Matias", 1, "Agatha", 2);

    struct trainDance* tdM = trainDanceNew("Matias", 1, "Agatha", 2);

    printf("\n");

    //-------------------------------trainDanceGroupCount-------------------------------
    printf("\n\n~ Prueba trainDanceGroupCount()\n");

    printf("\n  > Prueba de ejemplo:\n");
    int result = trainDanceGroupCount(td, 1);
    printf("\ttrainDanceGroupCount(td, 1) -> %i\n", result);
    result = trainDanceGroupCount(td, 1);
    printf("\ttrainDanceGroupCount(td, 2) -> %i\n", result);
    

    //-------------------------------trainDanceAddToDance-------------------------------
    printf("\n\n~ Prueba trainDanceAddToDance()\n");

    printf("\n  > Prueba de ejemplo:\n");
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Carla", 2);
    printf("\ttrainDanceAddToDance(td, \"Matias\",\"Agatha\",\"Carla\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Pepo", 2);
    printf("\ttrainDanceAddToDance(td, \"Matias\",\"Agatha\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Agatha", "Matias", "Pepo", 2);
    printf("\ttrainDanceAddToDance(td, \"Agatha\",\"Matias\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n\n");
    
    printf("\n  > Agrego una persona al final del trencito:\n");
    result = trainDanceAddToDance(td3, "Matias", "Agatha", "Carla", 2);
    printf("\ttrainDanceAddToDance(td3, \"Matias\",\"Agatha\",\"Carla\",2) -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");
    printf("\n  > Agrego una persona al principio del trencito:\n");
    result = trainDanceAddToDance(td3, "Agatha", "Matias", "Pepo", 2);
    printf("\ttrainDanceAddToDance(td3, \"Agatha\",\"Matias\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");
    printf("\n  > Agrego una persona en cualquier parte del trencito:\n");
    result = trainDanceAddToDance(td3, "Agatha", "Pepo", "Luis", 1);
    printf("\ttrainDanceAddToDance(td3, \"Agatha\",\"Pepo\",\"Luis\",1) -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");

    //agrego una persona mas al tren de prueba tdM1
    result = trainDanceAddToDance(tdM1, "Matias", "Agatha", "Carla", 2);
    result = trainDanceAddToDance(tdM1, "Carla", "Agatha", "Carla", 3);
    printf("\n  > Agrego una persona entre dos personas con el mismo nombre:\n");
    result = trainDanceAddToDance(tdM1, "Carla", "Carla", "Pepe", 1);
    printf("\ttrainDanceAddToDance(tdM1, \"Carla\",\"Carla\",\"Pepe\",1) -> %i - ",result);
    trainDancePrint(tdM1);
    printf("\n");

    //agrego dos personas mas al tren de prueba tdM
    result = trainDanceAddToDance(tdM, "Matias", "Agatha", "Carla", 2);
    result = trainDanceAddToDance(tdM, "Agatha", "Matias", "Pepo", 1);

    //-------------------------------trainDanceGetNode-------------------------------
    printf("\n\n~ Prueba trainDanceGetNode()\n");

    printf("\n  > Prueba de ejemplo:\n");
    struct node* n = trainDanceGetNode(td, "Matias");
    printf("\ttrainDanceGetNode(td,\"Matias\") -> %s %i\n",n->name,n->group);
    n = trainDanceGetNode(td, "Agatha");
    printf("\ttrainDanceGetNode(td,\"Agatha\") -> %s %i\n",n->name,n->group);

    printf("\n  > Pruebo obtener el primer nodo del trencito:\n");
    n = trainDanceGetNode(td3, "Matias");
    printf("\ttrainDanceGetNode(td3,\"Matias\") -> %s %i\n",n->name,n->group);

    printf("\n  > Pruebo obtener el ultimo nodo del trencito:\n");
    n = trainDanceGetNode(td3, "Pepo");
    printf("\ttrainDanceGetNode(td3,\"Pepo\") -> %s %i\n",n->name,n->group);

    printf("\n  > Pruebo obtener un nodo que no se encuentra en el trencito:\n");
    n = trainDanceGetNode(td, "Marta");
    if (n == NULL) printf("\ttrainDanceGetNode(td,\"Marta\") -> 0\n");
    else printf("   trainDanceGetNode(td,\"Marta\") -> %s %i\n",n->name,n->group);


    //-------------------------------trainDanceImTired-------------------------------
    printf("\n\n~ Prueba trainDanceImTired()\n");

    printf("\n  > Prueba de ejemplo:\n");
    result = trainDanceImTired(td, "Agatha");
    printf("\ttrainDanceImTired(td, \"Agatha\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Ricardo");
    printf("\ttrainDanceImTired(td, \"Ricardo\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Matias");
    printf("\ttrainDanceImTired(td, \"Matias\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n\n");

    printf("\n  > Pruebo quitar a una persona de un trencito de dos:\n");
    result = trainDanceImTired(tdt, "Agatha");
    printf("\ttrainDanceImTired(tdt, \"Agatha\") -> %i - ",result);
    trainDancePrint(tdt);
    printf("\n\n");

    printf("\n  > Pruebo quitar al ultimo de un trencito de al menos 3 personas:\n");
    result = trainDanceImTired(td3, "Pepo");
    printf("\ttrainDanceImTired(td3, \"Pepo\") -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");
    printf("\n  > Pruebo quitar al primero de un trencito de al menos 3 personas:\n");
    result = trainDanceImTired(td3, "Matias");
    printf("\ttrainDanceImTired(td3, \"Matias\") -> %i - ",result);
    trainDancePrint(td3);
    printf("\n");

    //-------------------------------trainDanceGetNames-------------------------------
    printf("\n\n~ Prueba trainDanceGetNames()\n");
    
    printf("\n  > Prueba obtener los nombres de un trencito de 2 personas:\n");
    char* names = trainDanceGetNames(td, ",");
    printf("\ttrainDanceGetNames(td,\",\") -> %s\n",names);
    free(names);

    printf("\n  > Pruebo obtener los nombres de un trencito de 3 personas:\n");
    names = trainDanceGetNames(td3, "-");
    printf("\ttrainDanceGetNames(td3,\"-\") -> %s\n",names);
    free(names);

    printf("\n  > Pruebo obtener los nombres de un trencito de 4 personas:\n");
    names = trainDanceGetNames(tdM, "|");
    printf("\ttrainDanceGetNames(tdM,\"|\") -> %s\n",names);
    free(names);

    printf("\n  > Pruebo obtener los nombres con un separador de dos caracteres:\n");
    names = trainDanceGetNames(tdM1, "->");
    printf("\ttrainDanceGetNames(tdM1,\"->\") -> %s\n",names);
    free(names);

    
    //-------------------------------trainDanceGotToMosh-------------------------------
    printf("\n\n~ Prueba trainDanceGotToMosh()\n");

    struct trainDance* tdr;
    struct trainDance* tdm;

    printf("\n  > Prueba de ejemplo:\n");
    trainDanceGotToMosh(&td, &tdr, &tdm, 2);
    printf("\ttrainDanceGotToMosh(&td, &tdr, &tdm, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");

    trainDanceAddToDance(td, "Pepo", "Carla", "Diana", 1);
    trainDanceAddToDance(td, "Carla", "Pepo", "Marcos", 1);
    trainDanceGotToMosh(&td, &tdr, &tdm, 2);
    printf("\ttrainDanceGotToMosh(&td, &tdr, &tdm, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n\n");

    trainDanceDelete(tdr);
    trainDanceDelete(tdm);
    
    
    //2 remains, 1 pogo
    printf("\n  > Prueba con un trencito de 2 personas y solo uno para hacer pogo:\n");
    trainDanceGotToMosh(&td3, &tdr, &tdm, 1);
    printf("\ttrainDanceGotToMosh(&td3, &tdr, &tdm, 1) -> ");
    if(td3 != 0) trainDancePrint(td3); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n\n");
    
    //2 pogo, 1 remains
    printf("\n  > Prueba con un trencito de 3 personas y dos para hacer pogo:\n");
    trainDanceGotToMosh(&tdM1, &tdr, &tdm, 2);
    printf("\ttrainDanceGotToMosh(&td3, &tdr, &tdm, 2) -> ");
    if(tdM1 != 0) trainDancePrint(tdM1); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n\n");
    
    //2 pogo, 2 remains
    printf("\n  > Prueba con un trencito de 4 personas, dos para pogo y dos de resto:\n");
    trainDanceGotToMosh(&tdM, &tdr, &tdm, 2);
    printf("\ttrainDanceGotToMosh(&tdM, &tdr, &tdm, 2) -> ");
    if(tdM!= 0) trainDancePrint(tdM); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n\n");
    
    //-------------------------------trainDanceDelete-------------------------------
    trainDanceDelete(tdr);
    trainDanceDelete(tdm);

    trainDanceDelete(tdM1);
    trainDanceDelete(td3);
    trainDanceDelete(tdt);
}
