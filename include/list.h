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
		Item();

		~Item();

		Item* Next() const;

		Item* Prev() const;
};

class List{
	private:
		Item *head;
		Item *tail;

	public:
		List();

		~List();

		Item* Head() const;

		Item* Tail() const;

		void Add(Item *newItem);

		void Delete(int index);

		Item *GetItem(int index);

		Item* Remove(int index);

		Item* Remove(Item* item);

		void Insert(Item *newItem, int index);

		int Count();

		void Clear();

		int GetIndex(const Item *item);
};
#endif
