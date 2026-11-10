#ifndef LIST_H
#define LIST_H

class Item{
	public:
		Item *next;
		Item *prev;
};

class List{
	public:
		Item *head;
		Item *tail;
	List();

	void Add(List *list, Item *newItem);

	void Delete(List *list, int index);

	Item *GetItem(const List *list, int index);

	Item *Remove(List *list, int index);

	void Insert(List *list, Item *newItem, int index);

	int Count(const List *list);

	void Clear(List *list);

	int GetIndex(const List *list, const Item *item);
};
#endif
