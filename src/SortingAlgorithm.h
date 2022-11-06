#ifndef SORTINGALGORITHm_H
#define SORTINGALGORITHm_H

#pragma once

#include "GLFWImpl.h"

namespace sa
{

#define EMPTY_LAMDA(X) ([](const std::vector<X> &) {})

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
            this->m_Impl(m_Collection);
        }

        const std::string &getName() const { return name; }
        const std::function<void(const std::vector<T> &)> &getImplementation() { return impl; }

    private:
        std::string m_Name;
        std::vector<T> *m_Collection = nullptr;
        std::function<void(const std::vector<T> *)> m_Impl;
    };
}

#endif