#include <addr.h>
#include <format>
#include <iostream>
#include <list.h>
#include <string>
#include <utils.h>

using std::cout;
using std::cin;
using std::format;

void AddrList::PrintList(){
	Item *p;
	int i;
    for(p = this->Head(), i = 0;
        p != nullptr;
        p = p->Next(), i++){
        cout << i << " ";
		((BaseAddr*)p)->Print();
    }
}
void AddrList::Sort(){
	int i, j;
	int quanity;
	BaseAddr* p1;
	BaseAddr* p2;


	quanity = Count();
	for(i = 0; i < quanity - 1; i++){
		p1 = (BaseAddr*)GetItem(i);
		for(j = i + 1; j < quanity; j++){
			p2 = (BaseAddr*)GetItem(j);
			if(p1->Name() > p2->Name())
				p1 = p2;
		}
		Insert(Remove(p1), i);
	}
}
void AddrList::Find(const std::string& pattern){
	BaseAddr* ptr;
	int i;
	std::size_t pos;

	for(ptr = (BaseAddr*)this->Head(), i = 0;
		ptr != nullptr;
		ptr = (BaseAddr*)ptr->Next(), i++)
	{
		pos = ptr->Descr().find(pattern);
		if (pos == std::string::npos)
			continue;
    	cout << format("{})", i);
     	ptr->Print();
	}
}
//-------------
std::string BaseAddr::Name() const { return this->name; }
std::string BaseAddr::Descr() const { return this->descr; }
addrType_t BaseAddr::AddrType() const { return this->addrType; }

std::string File::Path() const { return this->path; }
std::string File::Filename() const { return this->filename; }
BaseAddr* createAddr(addrType_t t) {
    switch (t) {
        case NETWORK_ADDR:       return new NetAddr();
        case LOCAL_FILE_ADDR:    return new LocalFileAddr();
        case LOCAL_NETWORK_ADDR: return new LocalNetworkAddr();
        case EMAIL_ADDR:         return new EmailAddr();
        case NONE:
        default:                 return nullptr;
    }
}

void typeList(void) {
	cout << "\t1 - Network Addreas\n";
	cout << "\t2 - Local Addreas\n" ;
	cout << "\t3 - Local Network Addreas\n";
	cout << "\t4 - Email Addreas\n" ;
}

addrType_t typeChoose(void){
	int numType = -1;
	addrType_t type = NONE;
	while(!type){
		clearScreen();
		typeList();
		cout << "Choose type: ";
		while(enterInt(numType));
		switch (numType) {
			case 1:
				type = NETWORK_ADDR;
				break;
			case 2:
				type = LOCAL_FILE_ADDR;
				break;
			case 3:
				type = LOCAL_NETWORK_ADDR;
				break;
			case 4:
				type = EMAIL_ADDR;
				break;
		}
	}
	clearScreen();
	return type;
}

BaseAddr::BaseAddr(addrType_t t) : addrType(t) {}
NetAddr::NetAddr()                   : BaseAddr(NETWORK_ADDR)       {}
LocalFileAddr::LocalFileAddr()       : BaseAddr(LOCAL_FILE_ADDR)    {}
LocalNetworkAddr::LocalNetworkAddr() : BaseAddr(LOCAL_NETWORK_ADDR) {}
EmailAddr::EmailAddr()               : BaseAddr(EMAIL_ADDR)         {}
//-------------------
void BaseAddr::Print(void){
	addrType_t type;
    type = this->addrType;
    switch(type){
        case NETWORK_ADDR:
            ((NetAddr*)this)->Print();
            break;
        case LOCAL_NETWORK_ADDR:
            ((LocalNetworkAddr*)this)->Print();
            break;
        case LOCAL_FILE_ADDR:
            ((LocalFileAddr*)this)->Print();
            break;
        case EMAIL_ADDR:
            ((EmailAddr*)this)->Print();
            break;
        case NONE: break;
    }
}
void NetAddr::Print(void){
	cout << format("{}://{}/{}/{}\n", this->protocol,this->Name(), this->Path(), this->Filename());
	cout << format("\t{}\n", this->Descr());
}
void LocalNetworkAddr::Print(void){
	cout << format("{}\\{}\\{}\n", this->Name(), this->Path(), this->Filename());
	cout << format("\t{}\n", this->Descr());
}
void LocalFileAddr::Print(void){
	cout << format("{}\\{}\\{}\n", this->Name(), this->Path(), this->Filename());
	cout << format("\t{}\n", this->Descr());
}
void EmailAddr::Print(void){
	cout << format("{}@{}\n", this->userName, this->Name());
	cout << format("\t{}\n", this->Descr());
}
//-------------------
void File::Input(void){
	cout << "Please enter file path: ";
	cin >> this->path;

    cout << "Please enter filename: ";
    cin >> this->filename;
}
void BaseAddr::Input(void){
    switch(addrType){
        case NETWORK_ADDR:
            ((NetAddr*)this)->Input();
            break;
        case LOCAL_NETWORK_ADDR:
            ((LocalNetworkAddr*)this)->Input();
            break;
        case LOCAL_FILE_ADDR:
            ((LocalFileAddr*)this)->Input();
            break;
        case EMAIL_ADDR:
            ((EmailAddr*)this)->Input();
            break;
        case NONE: break;
    }
}
void BaseAddr::BaseInput(void){
	do {
		switch (addrType) {
			case NETWORK_ADDR:
			case LOCAL_NETWORK_ADDR:
				cout << "Please enter local node's name: ";
				break;
			case LOCAL_FILE_ADDR:
	  			cout << "Please enter disk's name: ";
	   		break;
			case EMAIL_ADDR:
	   			cout << "Please enter email's node: ";
	      		break;
			default: break;
		}
    	cin >> name;
	} while(addrType == LOCAL_FILE_ADDR && name.size() != 1);

    cout << "Please enter descriprion: ";
    std::getline(std::cin >> std::ws, descr);
}
void NetAddr::Input(void){
	((BaseAddr*)this)->BaseInput();
    ((File*)this)->Input();

    cout << "Please enter protocol: ";
    cin >> protocol;
}
void LocalNetworkAddr::Input(void){
	((BaseAddr*)this)->BaseInput();
    ((File*)this)->Input();
}
void LocalFileAddr::Input(void){
	((BaseAddr*)this)->BaseInput();
    ((File*)this)->Input();
}
void EmailAddr::Input(void){
	((BaseAddr*)this)->BaseInput();
	cout << "Please enter username: ";
    cin >> this->userName;
}
//-------------------
