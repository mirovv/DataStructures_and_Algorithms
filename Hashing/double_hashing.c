#include <stdio.h>
#include <stdlib.h>

#define OCC 0
#define EMP -1
#define DEL -2
#define m 12

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
    int h2 = i * (key % 7);
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
    insert(5);
    insert(9);
    insert(18);
    insert(17);
    insert(1);
    insert(8);
    insert(7);
    insert(92);
    insert(122);
    insert(33);
    insert(44);
    insert(12);
    printHashTable();

}