#ifndef SORTINGALGORITHm_H
#define SORTINGALGORITHm_H

#pragma once

#include "GLFWImpl.h"

namespace sa
{

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

        SortingAlgorithm<T>(const std::string &m_Name, std::vector<T> *m_Collection)
            : m_Name(m_Name), m_Collection(m_Collection)
        {
        }

        virtual ~SortingAlgorithm<T>()
        {
        }

        virtual void Tick() = 0;

        virtual void Reset()
        {

            m_IsSorting = true;
            m_IsSorted = false;
        }

        bool IsSorted() const { return m_IsSorted; }
        bool IsSorting() const { return m_IsSorting; }

        virtual void SetCollection(std::vector<T> *collection)
        {
            m_Collection = collection;
        }

        void SetRenderCallback(std::function<void()> callback)
        {
            m_RenderCallback = callback;
        }

        const std::string &getName() const { return m_Name; }

    protected:
        std::string m_Name;
        std::vector<T> *m_Collection = nullptr;
        bool m_IsSorted = false;
        bool m_IsSorting = false;

        std::function<void()> m_RenderCallback = nullptr;
    };

}

#endif