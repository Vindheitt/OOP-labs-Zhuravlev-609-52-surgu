#ifndef ADDR_H
#define ADDR_H

#include <list.h>
#include <string>
#include <utils.h>

class BaseAddr;

typedef enum addrType{
	NONE = 0,
    NETWORK_ADDR,
    LOCAL_NETWORK_ADDR,
    LOCAL_FILE_ADDR,
    EMAIL_ADDR,
} addrType_t;





class AddrList: public List{
	public:
		void Sort(void);

		void ChangeTwoItems(Item* first, Item* second);

		void Find(const std::string& pattern);

		void PrintList(void);

		void typeList(void);

		addrType_t typeChoose(void);
};

class BaseAddr: public Item{
	private:
		std::string name;
		std::string descr;
		addrType_t addrType;
	public:
		BaseAddr(void);
		~BaseAddr(void);
		explicit BaseAddr(addrType_t t);
		static BaseAddr* createAddr(addrType_t t);
		std::string Name(void) const;
		std::string Descr(void) const;
		addrType_t AddrType(void) const;
		void Print(void);
		void Input(void);
		void BaseInput(void);
};

class File{
	private:
		std::string path;
		std::string filename;
	public:
		std::string Path(void) const;
		std::string Filename(void) const;
		void Input(void);

};

class NetAddr: public BaseAddr, public File{
	private:
		std::string protocol;
	public:
		NetAddr(void);
		void Print(void);
		void Input(void);
};

class LocalFileAddr: public BaseAddr, public File{
	private:

	public:
		LocalFileAddr(void);
		void Print(void);
		void Input(void);
};

class LocalNetworkAddr: public BaseAddr, public File{
	public:
		LocalNetworkAddr(void);
		void Print(void);
		void Input(void);
};

class EmailAddr: public BaseAddr{
	private:
		std::string userName;
	public:
		EmailAddr(void);
		void Print(void);
		void Input(void);
};

#endif
