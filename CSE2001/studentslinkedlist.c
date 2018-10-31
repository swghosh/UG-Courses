/* 
 * WAP to create a circular
 * linked list of students
 * that'll contain in each node
 * the name and age of the respective
 * student. Also, count the number
 * of nodes present.
 */

#include <stdio.h>
#include <stdlib.h>

struct studentNode {
    char *name;
    int age;
    struct studentNode *next;
};
#define NODE struct studentNode

struct studentsList {
    NODE *start;  
};
#define LIST struct studentsList

void init(LIST *list);
void insert(LIST *list, char *name, int age);
void traversePrint(LIST *list);
int count(LIST *list);

void init(LIST *list) {
    list->start = NULL;
}

void traversePrint(LIST *list) {
    NODE *iter;
    iter = list->start;

    if(iter == NULL) {
        printf("Empty List.\n");
        return;
    }

    do {
        printf("Student Name: %s, Student Age: %d.\n", iter->name, iter->age);
        iter = iter->next;
    }
    while(iter != list->start);
}

int count(LIST *list) {
    NODE *iter; int counter = 0;
    iter = list->start;

    if(iter == NULL) {
        return 0;
    }

    do {
        iter = iter->next;
        counter++;
    }
    while(iter != list->start);

    return counter;
}

// insert end
void insert(LIST *list, char *name, int age) {
    NODE *new, *iter;

    if(list->start == NULL) {
        new = (NODE*) malloc(sizeof(NODE));
        new->name = name;
        new->age = age;

        // circular
        list->start = new;
        new->next = list->start;
    }
    else {
        new = (NODE*) malloc(sizeof(NODE));
        new->name = name;
        new->age = age;

        iter = list->start;
        do {
            iter = iter->next;
        }
        while(iter->next != list->start);
        iter->next = new;
        new->next = list->start;
    }
}

int main() {
    LIST students;
    char name1[10] = "John", name2[10] = "Smith", name3[10] = "Jenny";
    int age1 = 10, age2 = 11, age3 = 12;
    
    init(&students);

    printf("\nTraverse Operation\n");
    traversePrint(&students);
    printf("Count: %d.\n", count(&students));
    
    insert(&students, name1, age1);
    insert(&students, name2, age2);
    insert(&students, name3, age3);

    printf("\nTraverse Operation\n");
    traversePrint(&students);
    printf("Count: %d.\n", count(&students));

    return 0;
}