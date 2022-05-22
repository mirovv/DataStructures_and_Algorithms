#include <stdio.h>
#include <stdlib.h>

#define OCC 0
#define EMP -1
#define DEL -2
#define m 9

typedef struct Element{
    int value;
    int status;
}Element;
Element HT[m];

void init(){
    for (int i = 0; i<m; i++){
        HT[i].status = EMP;
        HT[i].value = 0;
    }
}

int hash(int key, int i){
    int h1 = key % m;
    int h2 = i * (1 + (key % 7));
    return (h1 + h2) % m;
}

void insert(int key){
    int i = 0;
    int hK = hash(key, i);

    while(HT[hK].status == OCC){
        printf("COLLISION\n");
        i++;
        hK = hash(key, i);
    }
    if(HT[hK].status != OCC){
        HT[hK].value = key;
        HT[hK].status = OCC;
        return;
    }

}

void delete(int key){
    int i = 0;
    int hK = hash(key, i);

    while(HT[hK].value != key && HT[hK].status == OCC && i < m){
        i++;
        hK = hash(key, i);
    }
    if (HT[hK].value == key){
        HT[hK].status = DEL;
        HT[hK].value = EMP;
    }else{
        printf("Value does not exist in HT\n");
        return;
    }
}
int search(int key){
    int i = 0;
    int hKey = hash(key, i);
    while (HT[hKey].value != key && HT[hKey].status == OCC){
        i++;
        hKey = hash(key, i);
    }
    if (HT[hKey].value == key){
        printf("You searched for %d and it was found at index %d in the Hashtable\n", key, hKey);
        return hKey;
    }
    printf("The Value %d that you're looking for is not in HT\n", key);
    return -1;
}

void printHashTable() {
    printf("\n------------- Start -------------\n");
    int i;
    printf("Table size: %d\n\n", m); 
    for (i = 0; i < m; i++){
        if (HT[i].status == OCC) {
            printf("i: %d\tkey: %d\n", i, HT[i].value);
        }else if(HT[i].status == DEL && HT[i].value == EMP){
            printf("i: %d\tkey: DELETED --> %d\n", i, HT[i].value);
        }else{
            printf("i: %d\tkey: EMPTY\n", i);
        }
    }
    printf("\n------------- End -------------\n\n");
}

int main(){

    init();
    insert(31);
    insert(45);
    insert(15);
    insert(99);
    insert(9084);
    insert(45);
    insert(6);
    search(15);
    insert(28);
    printHashTable();

}