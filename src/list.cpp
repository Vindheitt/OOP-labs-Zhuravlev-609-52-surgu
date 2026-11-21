#include <list.h>

Item::Item(){
    this->next = nullptr;
    this->prev = nullptr;
    this->owner = nullptr;
}
Item::~Item(){
	if(owner)
		owner->Remove(this);
}
Item* Item::Next() const { return next; }
Item* Item::Prev() const { return prev; }

List::List(){
	this->head = nullptr;
	this->tail = nullptr;
}
List::~List(){ this->Clear(); }

Item* List::Head() const {	return head; }
Item* List::Tail() const {	return tail; }

void List::Add(Item* newItem){
    if (this->head == nullptr) {
        this->head = newItem;
        newItem->prev = nullptr;
    }
    else {
        this->tail->next = newItem;
        newItem->prev = this->tail;
    }
    newItem->next = nullptr;
    this->tail = newItem;
    newItem->owner = this;
}
void List::Delete(int index){
    Item* item = Remove(index);
    delete item;
}
Item* List::GetItem(int index){
    int i = 0;
    Item *current;

    if (index < 0)
        return nullptr;

    current = this->head;
    while (current != nullptr) {
        if (i == index)
            return current;
        current = current->next;
        i++;
    }
    return nullptr;
}
Item* List::Remove(int index){
	Item* item;

    item = GetItem(index);
    return Remove(item);
}
Item* List::Remove(Item* item){
    if(!item)
        return nullptr;

    if(!item->prev){
        this->head = item->next;
        if(item->next)
            item->next->prev = nullptr;
        else
            this->tail = nullptr;
    }
    else if(!item->next){
        this->tail = item->prev;
        item->prev->next = nullptr;
    }
    else{
        item->prev->next = item->next;
        item->next->prev = item->prev;
    }

    item->next = nullptr;
    item->prev = nullptr;
    item->owner = nullptr;
    return item;
}
void List::Insert(Item *newItem, int index){
    Item* item;
    if(!newItem)
        return;

    item = GetItem(index);
    if (!item){
        Add(newItem);
        return;
    }
    if(item->prev){
        newItem->next = item;
        newItem->prev = item->prev;
        item->prev->next = newItem;
        item->prev = newItem;
    }
    else{
        newItem->next = this->head;
        newItem->prev = nullptr;
        this->head->prev = newItem;
        this->head = newItem;
    }
    newItem->owner = this;
}
int List::Count(){
    int count;
    Item *current;

    for(current = this->head, count = 0;
        current != nullptr;
        count++, current = current->next);
    return count;
}
void List::Clear(){
    while(this->head)
        Delete(0);
    this->head = nullptr;
    this->tail = nullptr;
}
int List::GetIndex(const Item *item){
    int index;
    Item *current;

    if (!item)
        return -1;

    for(current = this->head, index = 0;
    	current != nullptr;
     	current = current->next, index++){
    if (current == item)
        return index;
    }
    return -1;
}
