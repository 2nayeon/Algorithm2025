#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct anode* apointer;
struct anode {
	char animal[10];
	int num;
	apointer next;
};

apointer animal_list(); 
void buildone(apointer ptr, apointer inode);
void print_list(apointer ptr);

int main() {
	apointer ptr, inode;

	ptr = animal_list();
	inode = (apointer)malloc(sizeof(struct anode));
	strcpy(inode->animal, "rabbit");
	inode->num = 12;
	buildone(ptr, inode);
	print_list(ptr);

	return 0;
}

apointer animal_list() {
	apointer inode1, inode2;
	inode1 = (apointer)malloc(sizeof(struct anode));
	inode2 = (apointer)malloc(sizeof(struct anode));

	strcpy(inode1->animal, "pig");
	inode1->num = 10;
	inode1->next = inode2;
	
	strcpy(inode2->animal, "dog");
	inode2->num = 5;
	inode2->next = NULL;

	return inode1;
}

void buildone(apointer ptr, apointer inode) {
	while (ptr->next != NULL){
		ptr = ptr->next;
	}
	ptr->next = inode;
}

void print_list(apointer ptr) {
	printf("=== Animal List ===\n");
	while (ptr != NULL) {
		printf("%s: %d\n", ptr->animal, ptr->num);
		ptr = ptr->next;
	}
}

