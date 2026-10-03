#include "list.h"

#include <stdlib.h>

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
    item_t* item = Remove(list, index);
    free(item);
}
item_t *GetItem(const list_t *list, int index){
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
item_t *Remove(list_t *list, int index){
    item_t* item;
    if (!list)
        return NULL;
    item = GetItem(list, index);
    if(!item)
        return NULL;

    if(!item->prev){
        list->head = item->next;
        if(item->next)
            item->next->prev = NULL;
        else
            list->tail = NULL;
    }
    else if (!item->next){
        list->tail = item->prev;
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
void Insert(list_t *list, item_t *newItem, int index){
    item_t* item;
    if(!list || !newItem)
        return;

    item = GetItem(list, index);
    if (!item){
        Add(list, newItem);
        return;
    }
    if(item->prev){
        newItem->next = item;
        newItem->prev = item->prev;
        item->prev->next = newItem;
        item->prev = newItem;
    }
    else{
        newItem->next = list->head;
        newItem->prev = NULL;
        list->head->prev = newItem;
        list->head = newItem;
    }
}
int Count(const list_t *list){
    int count;
    item_t *current;
    if (!list)
        return 0;

    for(current = list->head, count = 0;
        current != NULL;
        count++, current = current->next);
    return count;
}
void Clear(list_t *list){
    if (!list)
        return;

    while(list->head)
        Delete(list, 0);
    list->head = NULL;
    list->tail = NULL;
}
int GetIndex(const list_t *list, const item_t *item){
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
