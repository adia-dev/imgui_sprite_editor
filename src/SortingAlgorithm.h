#ifndef SORTINGALGORITHm_H
#define SORTINGALGORITHm_H

#pragma once

#include "GLFWImpl.h"

namespace sa
{

#define EMPTY_LAMDA(X) ([](std::vector<X> *) {})

    template <typename T>
    class SortingAlgorithm
    {
    public:
        SortingAlgorithm<T>()
            : m_Name("undefined !")
        {
        }

        SortingAlgorithm<T>(const std::string &m_Name)
            : m_Name(m_Name)
        {
        }

        SortingAlgorithm<T>(const std::string &m_Name, std::function<void(std::vector<T> *)> impl)
            : m_Name(m_Name), m_Impl(impl)
        {
        }

        virtual ~SortingAlgorithm<T>()
        {
        }

        virtual void Tick()
        {
            this->m_Impl(m_Collection);
        }

        virtual void SetCollection(std::vector<T> *collection)
        {
            m_Collection = collection;
        }

        const std::string &getName() const { return m_Name; }
        const std::function<void(std::vector<T> *)> &getImplementation() { return m_Impl; }

    private:
        std::string m_Name;
        std::vector<T> *m_Collection = nullptr;
        std::function<void(std::vector<T> *)> m_Impl;
    };
}

#endif