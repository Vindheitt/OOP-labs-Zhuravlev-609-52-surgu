#include <iostream>
#include <format>

#include <list.h>
#include <utils.h>

using std::cout;
using std::format;

class DebugList: public List{
	public:
		void Menu(void) {
			int quantity = 0;
			quantity = this->Count();
			cout << format("Now there {} items.\n", quantity);
			cout << format("\t1 - Add item\n");
			cout << format("\t2 - Delete item\n");
			cout << format("\t3 - Insert item\n");
			cout << format("\t4 - Print items\n");
			cout << format("\t0 - Exit\n");
			cout << format("Choose action: ");
		}
		void printList(){
		    Item *p;
		    int i;

		    for(p = this->Head(), i = 0;
		        p != nullptr;
		        p = p->Next(), i++){
				cout << format("{}\t{}\t{}\t{}\n", i, \
		        	(void*)p, (void*)p->Prev(), (void*)p->Next());
		    }
		}
};
//-----------------------------------------
int main() {
    int userChoose;

    int index;

    Item *item;
    DebugList dl;
    //List list;
	do {
		dl.Menu();
		enterInt(userChoose);
		clearScreen();
		switch (userChoose) {
			case 1:
		   		item = new Item();
				dl.Add(item);
				break;
			case 2:
		    	dl.printList();
			    do{
					cout << format("Choose index num: ");
				}while(enterInt(index));
				dl.Delete(index);
				break;
			case 3:
				item = new Item();
				dl.printList();
				do{
					cout << format("Choose index num: ");
				}while(enterInt(index));
				dl.Insert(item, index);
				break;
			case 4:
				dl.printList();
				cout << "\n";
				break;
			case 0: break;
			default:break;
		}
	} while (userChoose);

	return 0;
}
