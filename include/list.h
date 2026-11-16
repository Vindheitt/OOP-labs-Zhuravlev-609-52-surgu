#ifndef LIST_H
#define LIST_H

class Item;
class List;

class Item{
	friend class List;

	private:
		Item *next;
		Item *prev;
		List *owner;
	public:
		Item(void);

		~Item(void);

		Item* Next(void) const;

		Item* Prev(void) const;
};

class List{
	private:
		Item *head;
		Item *tail;

	public:
		List(void);

		~List(void);

		Item* Head(void) const;

		Item* Tail(void) const;

		void Add(Item *newItem);

		void Delete(int index);

		Item *GetItem(int index);

		Item* Remove(int index);

		Item* Remove(Item* item);

		void Insert(Item *newItem, int index);

		int Count(void);

		void Clear(void);

		int GetIndex(const Item *item);

		void Swap(Item* first, Item* second);
};
#endif
