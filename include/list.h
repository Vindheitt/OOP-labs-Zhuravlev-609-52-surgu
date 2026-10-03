#ifndef LIST_H
#define LIST_H

typedef struct item item_t;

typedef struct item{
    item_t *next;
    item_t *prev;
} item_t;

typedef struct list{
    item_t *head;
    item_t *tail;
} list_t;

void Add(list_t *list, item_t *newItem);

void Delete(list_t *list, int index);

item_t *GetItem(const list_t *list, int index);

item_t *Remove(list_t *list, int index);

void Insert(list_t *list, item_t *newItem, int index);

int Count(const list_t *list);

void Clear(list_t *list);

int GetIndex(const list_t *list, const item_t *item);

#endif
