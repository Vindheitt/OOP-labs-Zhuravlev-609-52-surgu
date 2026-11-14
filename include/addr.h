#ifndef ADDR_H
#define ADDR_H

#include <utils.h>
#include <list.h>

#define STR_DISK_NAME 2
#define STR_PROTOCOL 8

// Элементы списка предназначены для хранения сетевого или локального адреса.
//
// Адрес ресурса в сети Интернет должен содержать ---
// протокол (HTTP, FTP и т.п.), имя узла, путь и имя файла;
//
// адрес в локальной сети ---
// имя компьютера, путь и имя файла;
//
// адрес локального ресурса ---
// диск (однобуквенное обозначение), путь и имя файла;
//
// адрес электронной почты ---
// имя узла и имя пользователя.
//
// Элемент любого типа сопровождается текстовым описанием.
//
// Необходимо обеспечить: сортировку
// адресов по имени узла; поиск адреса по ключевому слову в описании. При выводе
// всего списка отображать адреса в стандартном формате в соответствии с их типом.

// typedef enum protocol{
//     HTTP = 0,
//     HTTPS,
//     FTP,
// } protocol_t;

typedef enum addrType{
	NONE = 0,
    NETWORK_ADDR,
    LOCAL_NETWORK_ADDR,
    LOCAL_FILE_ADDR,
    EMAIL_ADDR,
} addrType_t;

typedef struct baseAddr{
    /*item */
    item_t *next;
    item_t *prev;

    /*baseAddr */
    addrType_t addrType;
    char name[STR_LEN]; //char* name;
    char descr[DES_LEN];//char* descr;
} baseAddr_t;

typedef struct file{
    /* file */
    char path[STR_LEN]; //char* path;
    char filename[STR_LEN]; //char* filename;
} file_t;

typedef struct netAddr{
    /* item */
    item_t *next;
    item_t *prev;

    /*baseAddr */
    addrType_t addrType;
    char name[STR_LEN]; //char* name;
    char descr[DES_LEN];//char* descr;

    /* file */
    char path[STR_LEN]; //char* path;
    char filename[STR_LEN]; //char* filename;

    /* netAddr */
    //protocol_t protocol;
    char protocol[STR_PROTOCOL];
} netAddr_t;

typedef struct localNetAddr{
    /* item */
    item_t *next;
    item_t *prev;

    /* baseAddr */
    addrType_t addrType;
    char name[STR_LEN]; //char* name;
    char descr[DES_LEN];//char* descr;

    /* file */
    char path[STR_LEN]; //char* path;
    char filename[STR_LEN]; //char* filename;

    /* localNetAddr */
} localNetAddr_t;

typedef struct localAddr{
    /* item */
    item_t *next;
    item_t *prev;

    /* baseAddr */
    addrType_t addrType;
    char name[STR_DISK_NAME]; //char* name;
    char descr[DES_LEN];//char* descr;

    /* file */
    char path[STR_LEN]; //char* path;
    char filename[STR_LEN]; //char* filename;

    /* localAddr */
} localAddr_t;

typedef struct emailAddr{
    /* item */
    item_t *next;
    item_t *prev;

    /* baseAddr */
    addrType_t addrType;
    char name[STR_LEN]; //char* name;
    char descr[DES_LEN];//char* descr;

    /* emailAddr */
    char userName[STR_LEN]; //char* userName;
} emailAddr_t;

/* type functions */
void typeList(void);

addrType_t typeChoose(void);

/* common functions */
void* Create(addrType_t type);

void Print(void* netAddr);

void Input(void* netAddr);

//void FreeAddr(void* netAddr);

/* list functions */
void Sort(list_t* list);

void Find(list_t* list, const char* pattern);

/* unique functions */
netAddr_t* CreateNetAddr(void);

localAddr_t* CreateLocalAddr(void);

localNetAddr_t* CreateLocalNetAddr(void);

emailAddr_t* CreateEmailAddr(void);
//-------------------
void PrintNetAddr(netAddr_t* netAddr);

void PrintLocalNetAddr(localNetAddr_t* localNetAddr);

void PrintLocalAddr(localAddr_t* localAddr);

void PrintEmailAddr(emailAddr_t* emailAddr);
//-------------------
void InputNetAddr(netAddr_t* netAddr);

void InputLocalNetAddr(localNetAddr_t* localNetAddr);

void InputLocalAddr(localAddr_t* localAddr);

void InputEmailAddr(emailAddr_t* emailAddr);
//-------------------

#endif
