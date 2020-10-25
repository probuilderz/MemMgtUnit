/* 
 * File:   IMemoryInterface.hpp
 * Author: fofan
 * Description: Interface class for Memory Management
 *
 * Created on November 23, 2019, 8:13 PM
 * Credit to Arpan Sen, Rahul Kardam, Published February 19, 2008
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

