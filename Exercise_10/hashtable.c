#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define m 7
#define OCCUPIED 0
#define EMPTY -1
#define DELETED -2

struct HTElement{
    int status;
    int value;
};

void init(struct HTElement A[]){
    for (int i = 0; i < m; i++){
        A[i].status = EMPTY;
        A[i].value = 0;
    }
}

int hash(int k, int i){
    int h1 = (k % m) + 1;
    int h2 = i * ((m-1) - (k % (m-1)));
    return (int) (h1 + h2) % m;
}

void insert(struct HTElement A[], int key){
    int i = 0;
    int hKey = hash(key, i);
    while (i < m && A[hKey].status == OCCUPIED){
        i++;
        hKey = hash(key, i);
        
    }
    if (i == m){
        return;
    }
    A[hKey].status = OCCUPIED;
    A[hKey].value = key;
}

void delete(struct HTElement A[], int key){
    int i = 0;
    int hKey = hash(key, i);
    while (i < m && A[hKey].value != key && A[hKey].status == OCCUPIED){
        i++;
        hKey = hash(key, i);
    }
    if (A[hKey].value == key){
        int temp = A[hKey].value;
        A[hKey].status = DELETED;
        A[hKey].value = EMPTY;
        printf("Deleted Key %d with value %d \n", hKey, temp);
        return;
    }else{
        printf("Value %d does not exist in HT\n", key);
        return;
    }
}

int search(struct HTElement A[], int key){
    int i = 0;
    int hKey = hash(key, i);
    while (A[hKey].value != key && A[hKey].status == OCCUPIED && i < m){
        i++;
        hKey = hash(key, i);
    }
    if (A[hKey].value == key){
        printf("You searched for %d and it was found at index %d in the Hashtable\n", key, hKey);
        return hKey;
    }
    printf("The Value %d that you're looking for is not in HT\n", key);
    return -1;
}

void printHashTable(struct HTElement A[]) {
    printf("------------- Start -------------\n");
    int i;
    printf("Table size: %d\n\n", m); 
    for (i = 0; i < m; i++){
        if (A[i].status == OCCUPIED) {
            printf("i: %d\tkey: %d\n", i, A[i].value);
        }else if(A[i].status == DELETED && A[i].value == EMPTY){
            printf("i: %d\tkey: DELETED --> %d\n", i, A[i].value);
        }else{
            printf("i: %d\tkey: EMPTY\n", i);
        }
    }
    printf("\n------------- End -------------\n");
}

int main(){
    struct HTElement HT[m];
    init(HT);
    insert(HT, 1313);
    insert(HT, 1314);
    insert(HT, 1315);
    insert(HT, 2000);
    insert(HT, 2001);
    insert(HT, 2002);
    printHashTable(HT);
    delete(HT, 2002);
    printHashTable(HT);
    delete(HT, 9999);
    printHashTable(HT);
    int x = search(HT, 1313);
    int y = search(HT, 7777);





    return 1;
}