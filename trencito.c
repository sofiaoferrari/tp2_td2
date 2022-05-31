#include "trencito.h"

char* strDuplicate(char* src) {

    // COMPLETAR

    return 0;
}

int strCompare(char* a, char* b) {

    // COMPLETAR

    return 0;
}

char* strConcatenate(char* src1, char* src2) {

    // COMPLETAR

    return 0;
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

    // COMPLETAR

    return 0;
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

    // COMPLETAR

    return 0;
}

int trainDanceAddToDance(struct trainDance* train, char* name1, char* name2, char* nameNew, int groupNew) {

    // COMPLETAR

    return 0;
}

int trainDanceImTired(struct trainDance* train, char* name) {

    // COMPLETAR

    return 0;
}

void trainDanceGotToMosh(struct trainDance** train, struct trainDance** trainMosh, struct trainDance** trainRemains, int groupMosh) {

    // COMPLETAR

}

void trainDanceDelete(struct trainDance* train) {
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
