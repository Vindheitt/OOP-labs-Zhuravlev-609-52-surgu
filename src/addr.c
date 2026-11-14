#include <utils.h>
#include <list.h>
#include <addr.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void typeList(void) {
	printf("\t1 - Network Addreas\n");
	printf("\t2 - Local Addreas\n");
	printf("\t3 - Local Network Addreas\n");
	printf("\t4 - Email Addreas\n");
}

addrType_t typeChoose(void){
	int numType;
	addrType_t type = NONE;

	while(!type){
		clearScreen();
		typeList();
		printf("Choose type: ");
		while(enterInt(&numType));
		switch (numType) {
			case(1):
				type = NETWORK_ADDR;
				break;
			case(2):
				type = LOCAL_FILE_ADDR;
				break;
			case(3):
				type = LOCAL_NETWORK_ADDR;
				break;
			case(4):
				type = EMAIL_ADDR;
				break;
		}
	}
	clearScreen();
	return type;
}
//-------------------
void* Create(addrType_t type){
    void* addr;
    switch(type){
        case NETWORK_ADDR:
            addr = CreateNetAddr();
            break;
        case LOCAL_NETWORK_ADDR:
            addr = CreateLocalNetAddr();
            break;
        case LOCAL_FILE_ADDR:
            addr = CreateLocalAddr();
            break;
        case EMAIL_ADDR:
            addr = CreateEmailAddr();
            break;
        case NONE:
        	addr = NULL;
        	break;
    }
    Input(addr);
    return addr;
}

netAddr_t* CreateNetAddr(void){
    netAddr_t* netAddr;
    netAddr = malloc(sizeof(netAddr_t));
    if(!netAddr)
        return NULL;

    /* item */
    netAddr->next = NULL;
    netAddr->prev = NULL;

    /*baseAddr */
    netAddr->addrType = NETWORK_ADDR;
    //netAddr->name = malloc(sizeof(char) * STR_LEN);

    /* file */
    //netAddr->path = malloc(sizeof(char) * STR_LEN);
    //netAddr->filename = malloc(sizeof(char) * STR_LEN);

    // if(!netAddr->path ||!netAddr->filename || !netAddr->name){
    //     free(netAddr->path);
    //     free(netAddr->filename);
    //     free(netAddr->name);
    //     free(netAddr);
    //     return NULL;
    // }


    /* netAddr */


    //Input(newNetAddr);
    return netAddr;
}

localNetAddr_t* CreateLocalNetAddr(void){
    localNetAddr_t* localNetAddr;

    localNetAddr = malloc(sizeof(localNetAddr_t));
    if(!localNetAddr)
        return NULL;

    /* item */
    localNetAddr->next = NULL;
    localNetAddr->prev = NULL;

    /* baseAddr */
    localNetAddr->addrType = LOCAL_NETWORK_ADDR;
    //localNetAddr->name = malloc(sizeof(char) * STR_LEN);

    /* file */
    //localNetAddr->path = malloc(sizeof(char) * STR_LEN);
    //localNetAddr->filename = malloc(sizeof(char) * STR_LEN);


    // if(!localNetAddr->path ||!localNetAddr->filename || !localNetAddr->name){
    //     free(localNetAddr->path);
    //     free(localNetAddr->filename);
    //     free(localNetAddr->name);
    //     free(localNetAddr);
    //     return NULL;
    // }

    /* localNetAddr */
    return localNetAddr;
}

localAddr_t* CreateLocalAddr(void){
    localAddr_t* localAddr;

    localAddr = malloc(sizeof(localAddr_t));
    if(!localAddr)
        return NULL;

    /* item */
    localAddr->next = NULL;
    localAddr->prev = NULL;

    /* baseAddr */
    localAddr->addrType = LOCAL_FILE_ADDR;
    //localAddr->name = malloc(sizeof(char) * STR_LEN);

    /* file */
    //localAddr->path = malloc(sizeof(char) * STR_LEN);
    //localAddr->filename = malloc(sizeof(char) * STR_LEN);


    // if(!localAddr->path ||!localAddr->filename || !localAddr->name){
    //     free(localAddr->path);
    //     free(localAddr->filename);
    //     free(localAddr->name);
    //     free(localAddr);
    //     return NULL;
    // }


    /* localAddr */

    return localAddr;
}

emailAddr_t* CreateEmailAddr(void){
    emailAddr_t* emailAddr;

    emailAddr = malloc(sizeof(emailAddr_t));
    if(!emailAddr)
        return NULL;

    /* item */
    emailAddr->next = NULL;
    emailAddr->prev = NULL;

    /* baseAddr */
    emailAddr->addrType = EMAIL_ADDR;
    //emailAddr->name = malloc(sizeof(char) * STR_LEN);

    /* emailAddr */
    //emailAddr->userName = malloc(sizeof(char) * STR_LEN);

    // if(!emailAddr->name ||!emailAddr->userName){
    //     free(emailAddr->name);
    //     free(emailAddr->userName);
    //     free(emailAddr);
    //     return NULL;
    // }

    return emailAddr;
}
//-------------------
void Print(void* netAddr){
	addrType_t type;
	if(!netAddr)
    	return;
    type = ((baseAddr_t*)netAddr)->addrType;
    switch(type){
        case NETWORK_ADDR:
            PrintNetAddr(netAddr);
            break;
        case LOCAL_NETWORK_ADDR:
            PrintLocalAddr(netAddr);
            break;
        case LOCAL_FILE_ADDR:
            PrintLocalNetAddr(netAddr);
            break;
        case EMAIL_ADDR:
            PrintEmailAddr(netAddr);
            break;
        case NONE:

        	break;
    }
}

void PrintNetAddr(netAddr_t* netAddr){
	printf("%s://%s/%s/%s\n", netAddr->protocol,netAddr->name, netAddr->path, netAddr->filename);
}

void PrintLocalNetAddr(localNetAddr_t* localNetAddr){
	printf("%s\\%s\\%s\n", localNetAddr->name, localNetAddr->path, localNetAddr->filename);
}

void PrintLocalAddr(localAddr_t* localAddr){
	printf("%s\\%s\\%s\n", localAddr->name, localAddr->path, localAddr->filename);
}

void PrintEmailAddr(emailAddr_t* emailAddr){
	printf("%s@%s\n", emailAddr->userName, emailAddr->name);
}
//-------------------
void Input(void* netAddr){
    addrType_t type;
    if(!netAddr)
    	return;
    type = ((baseAddr_t*)netAddr)->addrType;
    switch(type){
        case NETWORK_ADDR:
            InputNetAddr(netAddr);
            break;
        case LOCAL_NETWORK_ADDR:
            InputLocalNetAddr(netAddr);
            break;
        case LOCAL_FILE_ADDR:
            InputLocalAddr(netAddr);
            break;
        case EMAIL_ADDR:
            InputEmailAddr(netAddr);
            break;
        case NONE:

        	break;
    }
    clearScreen();
}

void InputNetAddr(netAddr_t *netAddr){
    printf("Please enter local node's name: ");
    enterString(netAddr->name, STR_LEN);

    printf("Please enter descriprion: ");
    enterString(netAddr->descr, DES_LEN);

    printf("Please enter file path: ");
    enterString(netAddr->path, STR_LEN);


    printf("Please enter filename: ");
    enterString(netAddr->filename, STR_LEN);

    printf("Please enter protocol: ");
    enterString(netAddr->protocol, STR_PROTOCOL);
}

void InputLocalNetAddr(localNetAddr_t *localNetAddr){

	printf("Please enter local node's name: ");
    enterString(localNetAddr->name, STR_LEN);

    printf("Please enter descriprion: ");
    enterString(localNetAddr->descr, DES_LEN);

    /* file */
    printf("Please enter file path: ");
    enterString(localNetAddr->path, STR_LEN);

    printf("Please enter filename: ");
    enterString(localNetAddr->filename, STR_LEN);
}

void InputLocalAddr(localAddr_t *localAddr){
 printf("Please enter disk's name: ");
    enterString(localAddr->name, 2);

    printf("Please enter descriprion: ");
    enterString(localAddr->descr, DES_LEN);

    printf("Please enter file path: ");
    enterString(localAddr->path, STR_LEN);

    printf("Please enter filename: ");
    enterString(localAddr->filename, STR_LEN);
}

void InputEmailAddr(emailAddr_t *emailAddr){
	printf("Please enter email's node: ");
    enterString(emailAddr->name, STR_LEN);

    printf("Please enter descriprion: ");
    enterString(emailAddr->descr, DES_LEN);

    printf("Please enter username: ");
    enterString(emailAddr->userName, STR_LEN);
}
//-------------------
void Sort(list_t *list){
	int i, j, js;
	int quanity;
	baseAddr_t* p1;
	baseAddr_t* p2;

	if(!list)
		return;

	quanity = Count(list);
	for(i = 0; i < quanity - 1; i++){
		p1 = (baseAddr_t*)GetItem(list, i);
		js = i;
		for(j = i + 1; j < quanity; j++){
			p2 = (baseAddr_t*)GetItem(list, j);
			if(strcmp(p1->name, p2->name) > 0){
				p1 = p2;
				js = j;
			}
		}
		Insert(list, Remove(list, js), i);
	}
}

void Find(list_t *list, const char *pattern){
	baseAddr_t* ptr;
	int i;

	if(!list || !pattern)
		return;

	for(ptr = (baseAddr_t*)list->head, i = 0;
		ptr!=NULL;
		ptr = (baseAddr_t*)ptr->next, i++)
	{
  		if (strstr(ptr->descr, pattern) != NULL) {
            printf("%d)", i);
            Print(ptr);
            printf("%s\n", ptr->descr);
        }
	}
}
