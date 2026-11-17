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

void typeList(void);
addrType_t typeChoose(void);
BaseAddr* createAddr();

class AddrList: public List{
	public:
		void Sort(void);
		void PrintList(void);
		void Find(const std::string& pattern);
};

class BaseAddr: public Item{
	private:
		std::string name;
		std::string descr;
	public:
		std::string Name(void) const;
		std::string Descr(void) const;
		virtual void Print(void) = 0;
		virtual void Input(void) = 0;
		virtual addrType_t Type(void) const = 0;
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
		void Print(void) override;
		void Input(void) override;
		addrType_t Type(void) const override;
};

class LocalFileAddr: public BaseAddr, public File{
	public:
		void Print(void) override;
		void Input(void) override;
		addrType_t Type(void) const override;
};

class LocalNetworkAddr: public BaseAddr, public File{
	public:
		void Print(void) override;
		void Input(void) override;
		addrType_t Type(void) const override;
};

class EmailAddr: public BaseAddr{
	private:
		std::string userName;
	public:
		void Print(void) override;
		void Input(void) override;
		addrType_t Type(void) const override;
};

#endif
