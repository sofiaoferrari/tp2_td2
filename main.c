#include <stdio.h>
#include <stdlib.h>
#include "trencito.h"

int main() {

    // COMPLETAR

    // A Continuacion dejamos algunos ejemplos de como
    // llama a las funciones pedidas. Este codigo debe
    // ser borrado / modificado.

    // strDuplicate
    char* dup = strDuplicate("hola");
    printf("strDuplicate(\"hola\") -> \"%s\"\n", dup);
    free(dup);

    // strCompare
    printf("strCompare(\"abc\",\"abc\") -> %i\n", strCompare("abc","abc"));
    printf("strCompare(\"abcd\",\"abc\") -> %i\n", strCompare("abcd","abc"));
    printf("strCompare(\"abc\",\"abcd\") -> %i\n", strCompare("abc","abcd"));

    // strConcatenate
    char* concat = strConcatenate(strDuplicate("123"),strDuplicate("456"));
    printf("strConcatenate(\"123\",\"456\") -> \"%s\"\n", concat);
    free(concat);

    // trainDanceNew
    struct trainDance* td = trainDanceNew("Matias", 1, "Agatha", 2);
    printf("trainDanceNew(\"Matias\",1,\"Agatha\",2) -> ");
    trainDancePrint(td);
    printf("\n");

    // trainDanceGetNode
    struct node* n = trainDanceGetNode(td, "Matias");
    printf("trainDanceGetNode(td,\"Matias\") -> %s %i\n",n->name,n->group);
    n = trainDanceGetNode(td, "Agatha");
    printf("trainDanceGetNode(td,\"Agatha\") -> %s %i\n",n->name,n->group);

    // trainDanceGroupCount
    int result = trainDanceGroupCount(td, 1);
    printf("trainDanceGroupCount(td, 1) -> %i\n", result);
    result = trainDanceGroupCount(td, 1);
    printf("trainDanceGroupCount(td, 2) -> %i\n", result);

    // trainDanceGetNames
    char* names = trainDanceGetNames(td, ",");
    printf("trainDanceGetNames(td,\",\") -> %s\n",names);
    free(names);

    // trainDanceAddToDance
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Carla", 2);
    printf("trainDanceAddToDance(\"Matias\",\"Agatha\",\"Carla\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Matias", "Agatha", "Pepo", 2);
    printf("trainDanceAddToDance(\"Matias\",\"Agatha\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceAddToDance(td, "Agatha", "Matias", "Pepo", 2);
    printf("trainDanceAddToDance(\"Agatha\",\"Matias\",\"Pepo\",2) -> %i - ",result);
    trainDancePrint(td);
    printf("\n");

    // trainDanceImTire
    result = trainDanceImTired(td, "Agatha");
    printf("trainDanceImTired(td, \"Agatha\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Ricardo");
    printf("trainDanceImTired(td, \"Ricardo\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");
    result = trainDanceImTired(td, "Matias");
    printf("trainDanceImTired(td, \"Matias\") -> %i - ",result);
    trainDancePrint(td);
    printf("\n");

    // trainDanceGotToMosh
    struct trainDance* tdr;
    struct trainDance* tdm;
    trainDanceGotToMosh(&td, &tdr, &tdm, 2);
    printf("trainDanceGotToMosh(td, &tdr, &tdm, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");
    trainDanceAddToDance(td, "Pepo", "Carla", "Diana", 1);
    trainDanceAddToDance(td, "Carla", "Pepo", "Marcos", 1);
    trainDanceGotToMosh(&td, &tdr, &tdm, 2);
    printf("trainDanceGotToMosh(td, &tdr, &tdm, 2) -> ");
    if(td != 0) trainDancePrint(td); else printf("0");
    printf(" - ");
    if(tdr != 0) trainDancePrint(tdr); else printf("0");
    printf(" - ");
    if(tdm != 0) trainDancePrint(tdm); else printf("0");
    printf("\n");

    // trainDanceDelete
    trainDanceDelete(tdr);
    trainDanceDelete(tdm);

}
