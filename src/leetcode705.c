#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#define TABLELEN 1000000
typedef struct {
	int key[TABLELEN];
} MyHashSet;


MyHashSet* myHashSetCreate() {
	MyHashSet *a;
	a=malloc(sizeof(MyHashSet));
	memset(a->key,-1,sizeof(int)*TABLELEN);
	return a;
}

void myHashSetAdd(MyHashSet* obj, int key) {
	key=key%TABLELEN;
	obj->key[key]=1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
	key=key%TABLELEN;
	obj->key[key]=-1;
}

bool myHashSetContains(MyHashSet* obj, int key) {
	key=key%TABLELEN;
	if (obj->key[key]==-1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void myHashSetFree(MyHashSet* obj) {
	free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

int main(){
	MyHashSet* obj = myHashSetCreate();
	bool ans;
	ans=myHashSetContains(obj,0);
	printf("%d",ans);
}