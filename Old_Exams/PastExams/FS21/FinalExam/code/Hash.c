#include<stdio.h>


struct elem {
int key;
int status; /* 0: OCCUPIED, -1: EMPTY*/
};

int m=10;
struct elem HT[10];

void HInit(){
	int i=0;
	for(i=0;i<m;i++){
		HT[i].status = -1;
		HT[i].key = -1;
	}
}

int hash(int k, int i){
	return (k%m + i)%m;
}

int HTInsert(int k){
	int i=0;
	int probe = hash(k,i);
	while(i<m && HT[probe].status ==0){
		i++;
		probe = hash(k,i);
	}
	if(i>=m) return -1;
	HT[probe].key=k;
	HT[probe].status=0;
	return probe;
}



int HTDelete(int k){
	int i=0;
	int probe = hash(k,i);
	int actualHashIdx= probe;
	while(i<m && HT[probe].status == 0 && HT[probe].key!=k){
		i++;
		probe = hash(k,i);		
	}
	if(i>=m || HT[probe].status==-1) return -1;
	HT[probe].status = -1;
	HT[probe].key = -1;
	int j=(probe+1)%m;
	while(j!=actualHashIdx && HT[j].status!=-1){
		if(hash(HT[j].key,0)!=j){
			int tmpKey = HT[j].key;
			HT[j].key = -1;
			HT[j].status = -1;
			HTInsert(tmpKey);
		}
		j = (j+1)%m;
	}
	return probe;
}

void printHash(){
	int i=0;
	for(i=0;i<m;i++){
		printf("%d, %d \n",HT[i].status,HT[i].key);
	}
}

int main(){
	HInit();
	//HTInsert(3);
	HTInsert(14);
	HTInsert(25);
	HTInsert(23);
	HTInsert(34);
	HTInsert(47);
	HTInsert(53);
	printf("\n Print Hash: \n");
	printHash();
	printf("Delete 3: %d\n",HTDelete(3));
	printf("\n Print Hash: \n");
	printHash();
}
