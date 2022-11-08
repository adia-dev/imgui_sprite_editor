#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#pragma once

#include "SelectionSort.h"

namespace sa
{

    template <typename T>
    class BubbleSort : public SortingAlgorithm<T>
    {
    public:
        BubbleSort<T>()
            : SortingAlgorithm<T>("Bubble Sort")
        {
        }

        BubbleSort<T>(std::vector<T> *m_Collection)
            : SortingAlgorithm<T>("Bubble Sort", m_Collection)
        {
        }

        ~BubbleSort<T>()
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

            if (this->m_Collection == nullptr || this->m_Collection->size() <= 1 || std ::is_sorted(this->m_Collection->begin(), this->m_Collection->end()) || m_CurrentPass >= this->m_Collection->size())
            {
                Reset();
                return;
            }

            if (m_CurrentIndex >= this->m_Collection->size() - m_CurrentPass - 1)
            {
                m_CurrentIndex = 0;
                m_CurrentPass++;
                return;
            }

            // if (this->m_Collection->at(m_CurrentIndex) > this->m_Collection->at(m_CurrentIndex + 1))
            // {
            //     std::swap(this->m_Collection->at(m_CurrentIndex), this->m_Collection->at(m_CurrentIndex + 1));
            //     if (this->m_RenderCallback)
            //         this->m_RenderCallback();
            // }

            for (int i = 0; i < this->m_Collection->size() - m_CurrentPass - 1; i++)
            {
                if (this->m_Collection->at(i) > this->m_Collection->at(i + 1))
                {
                    std::swap(this->m_Collection->at(i), this->m_Collection->at(i + 1));
                }
            }

            m_CurrentIndex++;
        }

    private:
        int m_CurrentIndex = 0;
        int m_CurrentPass = 0;
    };
}
#endif