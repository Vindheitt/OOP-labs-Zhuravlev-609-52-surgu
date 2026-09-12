#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

// Элементы списка предназначены для хранения сетевого или локального адреса.
// Адрес ресурса в сети Интернет должен содержать протокол (HTTP, FTP и т.п.), имя
// узла, путь и имя файла; адрес в локальной сети – имя компьютера, путь и имя
// файла; адрес локального ресурса – диск (однобуквенное обозначение), путь и имя
// файла; адрес электронной почты – имя узла и имя пользователя. Элемент любого
// типа сопровождается текстовым описанием. Необходимо обеспечить: сортировку
// адресов по имени узла; поиск адреса по ключевому слову в описании. При выводе
// всего списка отображать адреса в стандартном формате в соответствии с их типом.

typedef struct item item_t;

typedef struct item{
    item_t *next;
    item_t *prev;
} item_t;

typedef struct list{
    item_t *head;
    item_t *tail;
} list_t;

void clearScreen();
int enterInt(int *n);
void createItem(item_t **item);
void createList(list_t **list);
void action(int userChoose, list_t *list);
void printActions();
void printItems(list_t *list);
//-----------------------------------------
void Add(list_t *list, item_t *newItem);
void Delete(list_t *list, int index);
item_t *getItem(const list_t *list, int index);

item_t *removeItem(list_t *list, int index);
void insert(list_t *list, item_t *newItem, int index);
int count(const list_t *list);
void clear(list_t *list);
int getIndex(const list_t *list, const item_t *item);
//-----------------------------------------
int main() {
    int userChoose;
    int quantity = 0;
    list_t *list;
    createList(&list);
	do {
	    quantity = count(list);
		printf("Now there %d items.\n", quantity);
		printActions();
		printf("Choose action: ");
		enterInt(&userChoose);
		action(userChoose, list);
	} while (userChoose);
	clear(list);
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
	while (scanf("%d%c", n, &buf) != 2) {
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
		    printItems(list);
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
		    printItems(list);
			getchar();
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
    printf("Enter text: ");
    // (*item)->text = malloc(sizeof(char)*128);
    // if(!(*item)->text)
    //     return;
    // fgets((*item)->text, 128, stdin);
}
void createList(list_t **list){
    *list = malloc(sizeof(list_t));
    if(!(*list))
        return;
    (*list)->head = NULL;
    (*list)->tail = NULL;
}
void printItems(list_t *list){
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
void Add(list_t *list, item_t *newItem){
    if (!list || !newItem)
        return;
    if (list->head == NULL) {
        list->head = newItem;
        newItem->prev = NULL;
    }
    else {
        list->tail->next = newItem;
        newItem->prev = list->tail;
    }

    newItem->next = NULL;
    list->tail = newItem;
}
void Delete(list_t *list, int index){
    item_t* item = removeItem(list, index);
    free(item);
}
item_t *getItem(const list_t *list, int index){
    int i = 0;
    item_t *current;
    if (!list || index < 0)
        return NULL;
    current = list->head;
    while (current != NULL) {
        if (i == index)
            return current;
        current = current->next;
        i++;
    }
    return NULL;
}
item_t *removeItem(list_t *list, int index){
    item_t* item;
    if (!list)
        return NULL;
    item = getItem(list, index);
    if(!item)
        return NULL;

    if(!item->prev){
        list->head = item->next;
        if(item->next)
            item->next->prev = NULL;
    }
    else if (!item->next){
        list->tail = item->prev;
        if(!item->prev)
            item->prev->next = NULL;
    }
    else{
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    item->next = NULL;
    item->prev = NULL;
    return item;
}
void insert(list_t *list, item_t *newItem, int index){
    item_t* item;
    if(!list && !newItem)
        return;

    item = getItem(list, index);
    if (!item){
        Add(list, newItem);
        return;
    }

    if(!list->head){
        Add(list, newItem);
        return;
    }

    if(item->prev){
        newItem->next = item;
        newItem->prev = item->prev;
        item->prev->next = newItem;
        item->prev = newItem;
        return;
    }
    else{
        newItem->next = list->head;
        newItem->prev = NULL;
        list->head->prev = newItem;
        list->head = newItem;
    }
}
int count(const list_t *list){
    int count;
    item_t *current;
    if (!list)
        return 0;

    for(current = list->head, count = 0;
        current != NULL;
        count++, current = current->next);
    return count;
}
void clear(list_t *list){
    //int i = 0;
    if (!list)
        return;

    while(list->head) {
        Delete(list, 0);
        //printf("%d", i++);
    }
    list->head = NULL;
    list->tail = NULL;
}
int getIndex(const list_t *list, const item_t *item){
    int index;
    item_t *current;

    if (!item || !list)
        return -1;

    for(current = list->head, index = 0;
        current != NULL;
        current = current->next,index++){
            if (current == item)
                return index;
        }
    return -1;
}
