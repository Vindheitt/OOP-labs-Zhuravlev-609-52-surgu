#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// Элементы списка предназначены для хранения сетевого или локального адреса.
// Адрес ресурса в сети Интернет должен содержать протокол (HTTP, FTP и т.п.), имя
// узла, путь и имя файла; адрес в локальной сети – имя компьютера, путь и имя
// файла; адрес локального ресурса – диск (однобуквенное обозначение), путь и имя
// файла; адрес электронной почты – имя узла и имя пользователя. Элемент любого
// типа сопровождается текстовым описанием. Необходимо обеспечить: сортировку
// адресов по имени узла; поиск адреса по ключевому слову в описании. При выводе
// всего списка отображать адреса в стандартном формате в соответствии с их типом.

void clearScreen();
int enterInt(int *n);
void createItem(item_t **item);
void createList(list_t **list);
void action(int userChoose, list_t *list);
void printActions();
void printList(list_t *list);
//-----------------------------------------

//-----------------------------------------
int main() {
    int userChoose;
    int quantity = 0;
    list_t *list;
    createList(&list);
	do {
	    quantity = Count(list);
		printf("Now there %d items.\n", quantity);
		printActions();
		printf("Choose action: ");
		enterInt(&userChoose);
		action(userChoose, list);
	} while (userChoose);
	Clear(list);
	free(list);
    return 0;
}
void printActions() {
	printf("\t1 - Add item\n");
	printf("\t2 - Delete item\n");
	printf("\t3 - Print items\n");
	//printf("\t3 - Insert item\n");
	printf("\t0 - Exit\n");
}
void clearScreen(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int enterInt(int *n) {
	if (n == NULL)
		return -1;
	char buf;
	if (scanf("%d%c", n, &buf) != 2) {
		printf("Something went wrong with enter int..\n");
		printf("Please try again: ");
		while (getchar() != '\n');
		return 1;
	}
	if (buf != '\n') {
		while (getchar() != '\n');
	}
	return 0;
}
void action(int userChoose, list_t *list) {
    item_t *item;
    int index;
	if (!list)
		return;
	clearScreen();
	switch (userChoose) {
		case 1:
		    createItem(&item);
			Add(list, item);
			break;
		case 2:
		    printList(list);
		    do{
				printf("Choose index num: ");
			}while(enterInt(&index));
		    Delete(list, index);
		    break;
		// case 3:
		//     //createItem(&item);
		//     //printItems(list);
		// 	do{
		// 		printf("Choose index num: ");
		// 	}while(enterInt(&index));
		// 	insert(list, item, index);
		//     break;
		case 3:
		    printList(list);
			printf("\n");
			//getchar();
		    break;
		case 0:

		    break;
		default:

		    break;

	}
}
void createItem(item_t **item){
    *item = malloc(sizeof(item_t));
    if(!(*item))
        return;
    (*item)->next = NULL;
    (*item)->prev = NULL;
}
void createList(list_t **list){
    *list = calloc(1, sizeof(list_t));
    if(!(*list))
        return;
    (*list)->head = NULL;
    (*list)->tail = NULL;
}
void printList(list_t *list){
    item_t *p;
    int i;
    if(!list)
        return;

    for(p = list->head, i = 0;
        p != NULL;
        p = p->next, i++){
        printf("%d\t%p\t%p\t%p\n", i, p, p->prev, p->next);
    }
}
//-----------------------------------------
