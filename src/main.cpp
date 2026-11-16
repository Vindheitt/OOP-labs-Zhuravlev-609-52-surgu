#include <iostream>
#include <format>

#include <addr.h>
#include <list.h>
#include <string>
#include <utils.h>

using std::cout;
using std::format;

class DebugList: public AddrList{
	public:
		void Menu(void) {
			int quantity = 0;
			quantity = this->Count();
			cout << format("Now there {} items.\n", quantity);
			cout << format("\t1 - Add item\n");
			cout << format("\t2 - Delete item\n");
			cout << format("\t3 - Insert item\n");
			cout << format("\t4 - Print items\n");
			cout << format("\t5 - Print one item\n");
			cout << format("\t6 - Sort\n");
			cout << format("\t7 - Find in description\n");
			cout << format("\t0 - Exit\n");
			cout << format("Choose action: ");
		}
};
//-----------------------------------------
int main() {
    int userChoose;

    int index;
    addrType_t t;
    BaseAddr *item;
    DebugList dl;
    std::string pattern;
    //AddrList dl;
    //List list;
	do {
		dl.Menu();
		enterInt(userChoose);
		clearScreen();
		switch (userChoose) {
			case 1:
				t = typeChoose();
				item = createAddr(t);
            	if (!item)
             		break;
             	item->Input();
				dl.Add(item);
				break;
			case 2:
				dl.PrintList();
			    do{
					cout << format("Choose index num: ");
				}while(enterInt(index));
				dl.Delete(index);
				break;
			case 3:
				t = typeChoose();
				item = createAddr(t);
				if (!item)
             		break;
				item->Input();
				dl.PrintList();
				do{
					cout << format("Choose index num: ");
				}while(enterInt(index));
				dl.Insert(item, index);
				break;
			case 4:
				dl.PrintList();
				cout << "\n";
				break;
			case 5:
				do{
					cout << format("Choose index num: ");
				}while(enterInt(index));
				item = (BaseAddr*)dl.GetItem(index);
				if(item)
					item->Print();
				break;
			case 6:
				dl.Sort();
				break;
			case 7:
				clearScreen();
				cout << format("Enter pattern: ");
				std::cin >> pattern;
				clearScreen();
				dl.Find(pattern);
				cout << format("\n");
				break;
			case 0: break;
			default:break;
		}
	} while (userChoose);

	return 0;
}
