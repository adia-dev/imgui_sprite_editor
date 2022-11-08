#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H

#pragma once

#include "SortingAlgorithm.h"

namespace sa
{

    template <typename T>
    class SelectionSort : public SortingAlgorithm<T>
    {
    public:
        SelectionSort<T>()
            : SortingAlgorithm<T>("Bubble Sort")
        {
        }

        SelectionSort<T>(std::vector<T> *m_Collection)
            : SortingAlgorithm<T>("Bubble Sort", m_Collection)
        {
        }

        ~SelectionSort<T>()
        {
        }

        void Reset() override
        {
            this->SortingAlgorithm<T>::Reset();
            m_CurrentIndex = 0;
            m_CurrentPass = 0;
        }

        void Tick() override
        {
            if (this->m_Collection == nullptr || this->m_Collection->size() <= 1 || std::is_sorted(this->m_Collection->begin(), this->m_Collection->end()))
            {
                Reset();
                return;
            }

            if (m_CurrentIndex >= this->m_Collection->size())
            {
                m_CurrentIndex = 0;
                m_CurrentPass++;
                return;
            }

            if (m_CurrentPass >= this->m_Collection->size())
            {
                return;
            }

            // int min = m_CurrentIndex;
            // for (int j = m_CurrentIndex + 1; j < this->m_Collection->size(); j++)
            // {
            //     if (this->m_Collection->at(j) < this->m_Collection->at(min))
            //     {
            //         if (this->m_RenderCallback != nullptr)
            //             this->m_RenderCallback();
            //         min = j;
            //     }
            // }
            // std::swap(this->m_Collection->at(m_CurrentIndex), this->m_Collection->at(min));
            // m_CurrentIndex++;

            int min = m_CurrentIndex;
            for (int j = m_CurrentIndex + 1; j < this->m_Collection->size(); j++)
            {
                if (this->m_Collection->at(j) < this->m_Collection->at(min))
                {
                    // if (this->m_RenderCallback != nullptr)
                    //     this->m_RenderCallback();
                    min = j;
                }
            }

            std::swap(this->m_Collection->at(m_CurrentIndex), this->m_Collection->at(min));
            m_CurrentIndex++;
        }

    private:
        int m_CurrentIndex = 0;
        int m_CurrentPass = 0;
    };
}
#endif