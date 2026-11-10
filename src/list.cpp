#include <list.h>

#include <stdlib.h>

List::List(){
	this->head = nullptr;
	this->tail = nullptr;
}
void List::Add(List *list, Item* newItem){
    if (list->head == nullptr) {
        list->head = newItem;
        newItem->prev = nullptr;
    }
    else {
        list->tail->next = newItem;
        newItem->prev = list->tail;
    }

	    newItem->next = nullptr;
	    list->tail = newItem;
	}
void List::Delete(List* list, int index){
    Item* item = Remove(list, index);
    delete item;
}
Item* List::GetItem(const List *list, int index){
    int i = 0;
    Item *current;
    if (!list || index < 0)
        return nullptr;
    current = list->head;
    while (current != nullptr) {
        if (i == index)
            return current;
        current = current->next;
        i++;
    }
    return nullptr;
}
Item* List::Remove(List *list, int index){
	Item* item;
	if (!list)
        return nullptr;
    item = GetItem(list, index);
    if(!item)
        return nullptr;

    if(!item->prev){
        list->head = item->next;
        if(item->next)
            item->next->prev = nullptr;
        else
            list->tail = nullptr;
    }
    else if (!item->next){
        list->tail = item->prev;
        item->prev->next = nullptr;
    }
    else{
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    item->next = nullptr;
    item->prev = nullptr;
    return item;
}
void List::Insert(List *list, Item *newItem, int index){
    Item* item;
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
        newItem->prev = nullptr;
        list->head->prev = newItem;
        list->head = newItem;
    }
}
int List::Count(const List *list){
    int count;
    Item *current;
    if (!list)
        return 0;

    for(current = list->head, count = 0;
        current != nullptr;
        count++, current = current->next);
    return count;
}
void List::Clear(List *list){
    if (!list)
        return;

    while(list->head)
        Delete(list, 0);
    list->head = nullptr;
    list->tail = nullptr;
}
int List::GetIndex(const List *list, const Item *item){
    int index;
    Item *current;

    if (!item || !list)
        return -1;

    for(current = list->head, index = 0;
    current != nullptr;
    current = current->next,index++){
    if (current == item)
        return index;
    }
    return -1;
}
