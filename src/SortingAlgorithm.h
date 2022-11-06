#ifndef SORTINGALGORITHM_H
#define SORTINGALGORITHM_H

#pragma once

#include "GLFWImpl.h"

template <typename T>
class SortingAlgorithm
{
public:
    SortingAlgorithm<T>()
        : name("undefined !")
    {
    }

    SortingAlgorithm<T>(const std::string &name)
        : name(name)
    {
    }

    SortingAlgorithm<T>(const std::string &name, std::function<void(const std::vector<T> &)> impl)
        : name(name), impl(impl)
    {
    }

    virtual ~SortingAlgorithm<T>()
    {
    }

    virtual void Tick()
    {
    }

    const std::string &getName() const { return name; }
    const std::function<void(const std::vector<T> &)> &getImplementation() { return impl; }

private:
    std::string name;

    std::function<void(const std::vector<T> &)> impl;
};

#endif