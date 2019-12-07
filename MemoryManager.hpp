/* 
 * File:   MemoryManager.hpp
 * Author: fofan
 * Description: Static library for creation of a memory pool of POOLSIZE objects
 * 
 * Created on November 23, 2019, 8:16 PM
 */

#ifndef MEMORYMANAGER_HPP
#define MEMORYMANAGER_HPP

#include <cstdlib>
#include "IMemoryInterface.hpp"
#include "FreeStoreObj.hpp"

class MemoryManager : public IMemoryInterface{
public:
    MemoryManager();
    ~MemoryManager();
    MemoryManager& operator = (const MemoryManager& memMgr);
    virtual void * allocate(size_t size);
    virtual void free(void * pMemObj);
    static MemoryManager * getInstance();
private:
    void cleanup();
    void createPoolSize(size_t);
    FreeStore * headFreeStore;
    static MemoryManager * pMemMgr;
    static const int POOLSIZE = 10; 
};


#endif /* MEMORYMANAGER_HPP */

