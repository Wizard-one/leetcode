#include <stdlib.h>
#include <string.h>
#define TABLELEN 1000001
typedef struct {
	int key[TABLELEN];
} MyHashMap;


MyHashMap* myHashMapCreate() {
	MyHashMap *a;
	a=malloc(sizeof(MyHashMap));
	memset(a->key,-1,sizeof(int)*TABLELEN);
	return a;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
	key=key%TABLELEN;
	obj->key[key]=value;
}

int myHashMapGet(MyHashMap* obj, int key) {
	key=key%TABLELEN;
	return obj->key[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
	key=key%TABLELEN;
	obj->key[key]=-1;
}

void myHashMapFree(MyHashMap* obj) {
	free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/