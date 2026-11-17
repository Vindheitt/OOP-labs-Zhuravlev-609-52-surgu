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
	for(p = Head(), i = 0;
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

std::string File::Path() const { return this->path; }
std::string File::Filename() const { return this->filename; }
//-------------
BaseAddr* BaseAddr::createAddr(addrType_t t) {

	switch (t) {
		case NETWORK_ADDR:	   return new NetAddr();
		case LOCAL_FILE_ADDR:	return new LocalFileAddr();
		case LOCAL_NETWORK_ADDR: return new LocalNetworkAddr();
		case EMAIL_ADDR:		 return new EmailAddr();
		case NONE:
		default:				 return nullptr;
	}
}
void AddrList::typeList(void) {
	cout << "\t1 - Network Addreas\n";
	cout << "\t2 - Local Addreas\n" ;
	cout << "\t3 - Local Network Addreas\n";
	cout << "\t4 - Email Addreas\n" ;
}
addrType_t AddrList::typeChoose(void){
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
//-------------------
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
void BaseAddr::Input(void){
	cin >> name;

	cout << "Please enter descriprion: ";
	std::getline(std::cin >> std::ws, descr);
}
void File::Input(void){
	cout << "Please enter file path: ";
	cin >> this->path;

	cout << "Please enter filename: ";
	cin >> this->filename;
}
void NetAddr::Input(void){
	cout << "Please enter node's name: ";
	BaseAddr::Input();
	File::Input();

	cout << "Please enter protocol: ";
	cin >> protocol;
}
void LocalNetworkAddr::Input(void){
	cout << "Please enter local node's name: ";
	BaseAddr::Input();
	File::Input();

}
void LocalFileAddr::Input(void){
	cout << "Please enter disk's name: ";
	BaseAddr::Input();
	File::Input();
}
void EmailAddr::Input(void){
	cout << "Please enter email's node: ";
	BaseAddr::Input();
	cout << "Please enter username: ";
	cin >> this->userName;
}
//-------------------
addrType_t NetAddr::Type(void) const { return NETWORK_ADDR; }
addrType_t LocalFileAddr::Type(void) const { return LOCAL_FILE_ADDR; }
addrType_t LocalNetworkAddr::Type(void) const { return LOCAL_NETWORK_ADDR; }
addrType_t EmailAddr::Type(void) const { return EMAIL_ADDR; }
