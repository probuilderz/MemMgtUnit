
#include "MemoryManager.hpp"

MemoryManager * MemoryManager::pMemMgr = NULL;

MemoryManager::MemoryManager(){
    headFreeStore = NULL;
    createPoolSize(sizeof(new char[POOLSIZE]));
}

MemoryManager::~MemoryManager(){
    cleanup();
}

MemoryManager& MemoryManager::operator =(const MemoryManager& memMgr){
    if(this != &memMgr){
        headFreeStore = memMgr.headFreeStore;
    }
    return *this;
}

void * MemoryManager::allocate(size_t size){
    
    if(headFreeStore == NULL){
        createPoolSize(size);
    }
    
    FreeStore * head = headFreeStore;
    headFreeStore = headFreeStore->pNextFreeStore;
    return head;
}

void MemoryManager::cleanup(){

    while(headFreeStore != NULL){
        FreeStore * temp = headFreeStore;
        headFreeStore = headFreeStore->pNextFreeStore;
        delete[] temp;
    }
}

void MemoryManager::free(void* pMemObj){
    FreeStore * newTemp = reinterpret_cast<FreeStore*>(pMemObj);
    newTemp->pNextFreeStore = headFreeStore;
    headFreeStore = newTemp;
}

void MemoryManager::createPoolSize(size_t sizeObj){
    size_t size = sizeObj > sizeof(FreeStore *)? sizeObj: sizeof(FreeStore *);
    FreeStore * head = reinterpret_cast<FreeStore*>(new char[size]);
    headFreeStore = head;
    
    for(int i = 0; i < POOLSIZE; i++){  // todo this should start at 1
        head->pNextFreeStore = reinterpret_cast<FreeStore*>(new char[size]);
        head = head->pNextFreeStore;
    }
    head->pNextFreeStore = NULL;
            
}

MemoryManager * MemoryManager::getInstance(){
    if (pMemMgr == NULL){
        pMemMgr = new MemoryManager();
    }
    return pMemMgr;
}