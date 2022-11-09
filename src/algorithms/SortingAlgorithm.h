#ifndef SORTINGALGORITHm_H
#define SORTINGALGORITHm_H

#pragma once

#include "../GLFWImpl.h"

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
            m_CurrentIndex = 0;
            m_CurrentPass = 0;
        }

        bool IsSorted() const { return m_IsSorted; }
        bool IsSorting() const { return m_IsSorting; }

        virtual void SetCollection(std::vector<T> *collection)
        {
            m_Collection = collection;
        }

        std::map<std::string, std::function<void()>> &GetCallbacks()
        {
            return m_Callbacks;
        }

        void SetCallback(const std::string &name, std::function<void()> callback)
        {
            m_Callbacks[name] = callback;
        }

        void TriggerCallback(const std::string &name)
        {
            if (m_Callbacks.find(name) != m_Callbacks.end())
                m_Callbacks[name]();
            else
                std::cout << "Could not trigger callback: " << name << "\n";
        }

        T &GetAt(size_t index)
        {
            TriggerCallback("OnCollectionAccess");
            return m_Collection->at(index);
        }

        void SetAt(size_t index, const T &value)
        {
            // TriggerCallback("OnRender");
            // m_Collection->emplace(m_Collection->begin() + index, value);
            (*m_Collection)[index] = value;
        }

        void Swap(size_t left, size_t right)
        {
            if (m_Collection == nullptr)
                return;
            if ((left < 0 && left >= m_Collection->size()) || (right < 0 && right >= m_Collection->size()))
                return;

            std::swap(this->GetAt(left), this->GetAt(right));
            // TriggerCallback("OnRender");
            this->TriggerCallback("OnSwap");
        }

        const std::string &getName() const
        {
            return m_Name;
        }

    protected:
        std::string m_Name;
        std::vector<T> *m_Collection = nullptr;
        bool m_IsSorted = false;
        bool m_IsSorting = false;
        int m_CurrentIndex = 0;
        int m_CurrentPass = 0;
        int m_StepsPerTick = 1;

        std::map<std::string, std::function<void()>> m_Callbacks;
    };

}

#endif