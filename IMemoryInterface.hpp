/* 
 * File:   IMemoryInterface.hpp
 * Author: fofan
 * Description: Interface class for Memory Management
 *
 * Created on November 23, 2019, 8:13 PM
 */

#ifndef IMEMORYINTERFACE_HPP
#define IMEMORYINTERFACE_HPP

#include <cstdint>

class IMemoryInterface{
public:
    virtual void * allocate(size_t) = 0;
    virtual void free(void *) = 0;
};

#endif /* IMEMORYINTERFACE_HPP */

