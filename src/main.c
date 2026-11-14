#include <addr.h>
#include <stdio.h>
#include <stdlib.h>

#include <list.h>
#include <utils.h>

int createList(list_t **list);
void action(int userChoose, list_t *list);
void printActions(void);
void printList(list_t *list);
void printOneItem(list_t* list, int index);
//-----------------------------------------
int main(void) {
    int userChoose;
    int quantity = 0;
    list_t *list;

    if(createList(&list))
    	return -1;

    clearScreen();
	do {
	    quantity = Count(list);
		printf("Now there %d items.\n", quantity);
		printActions();
		do{
			printf("Choose action: ");
		}while(enterInt(&userChoose));
		action(userChoose, list);
	} while (userChoose);
	Clear(list);
	free(list);
    return 0;
}
void printActions(void) {
	printf("\t1 - Add item\n");
	printf("\t2 - Delete item\n");
	printf("\t3 - Insert item\n");
	printf("\t4 - Print items\n");
	printf("\t5 - Print one item\n");
	printf("\t6 - Sort\n");
	printf("\t7 - Find in description\n");
	printf("\t0 - Exit\n");
}

void action(int userChoose, list_t *list) {
    void *item;
    int index;
    addrType_t type;
    char pattern[STR_LEN];

	if (!list)
		return;
	clearScreen();
	switch (userChoose) {
		case 1:
			type = typeChoose();
			item = Create(type);
			Add(list, (item_t*)item);
			break;
		case 2:
		    printList(list);
		    do{
				printf("Choose index num: ");
			}while(enterInt(&index));
		    Delete(list, index);
		    break;
		case 3:
			type = typeChoose();
			item = Create(type);
		    printList(list);
			do{
				printf("Choose index num: ");
			}while(enterInt(&index));
			Insert(list, item, index);
		    break;
		case 4:
		    printList(list);
			printf("\n");
		    break;
		case 5:
			do{
				printf("Choose index num: ");
			}while(enterInt(&index));
			printOneItem(list, index);
		case 6:
			Sort(list);
			break;
		case 7:
			clearScreen();
			printf("Enter pattern: ");
			enterString(pattern, STR_LEN);
			clearScreen();
			Find(list, pattern);
			printf("\n");
			break;
		case 0:

		    break;
		default:

		    break;
	}
}

int createList(list_t **list){
	if(!list)
		return -1;
    *list = calloc(1, sizeof(list_t));
    if(!(*list))
        return -1;
    return 0;
}

void printList(list_t *list){
    item_t *p;
    int i;
    if(!list)
        return;

    for(p = list->head, i = 0;
        p != NULL;
        p = p->next, i++){
        	printf("%d)", i);
        	Print((void*)p);
    }
}
void printOneItem(list_t* list, int index){
	baseAddr_t* ptr = (baseAddr_t*)GetItem(list, index);
	Print(ptr);
	printf("%s\n", ptr->descr);
}
//-----------------------------------------
