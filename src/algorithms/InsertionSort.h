#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

#pragma once

#include "MergeSort.h"

namespace sa
{
    template <typename T>
    class InsertionSort : public SortingAlgorithm<T>
    {
    public:
        InsertionSort<T>()
            : SortingAlgorithm<T>("Bubble Sort")
        {
            this->m_CurrentIndex = 1;
        }

        InsertionSort<T>(std::vector<T> *m_Collection)
            : SortingAlgorithm<T>("Bubble Sort", m_Collection)
        {
            this->m_CurrentIndex = 1;
        }

        ~InsertionSort<T>()
        {
        }

        void Tick() override
        {
            if (this->m_Collection == nullptr || this->m_Collection->size() <= 1 || std ::is_sorted(this->m_Collection->begin(), this->m_Collection->end()) || this->m_CurrentPass >= this->m_Collection->size())
            {
                this->Reset();
                return;
            }

            if (this->m_CurrentIndex >= this->m_Collection->size())
            {
                this->m_CurrentIndex = 0;
                this->m_CurrentPass++;
                return;
            }

            T key = this->GetAt(this->m_CurrentIndex);
            int j = this->m_CurrentIndex - 1;
            while (j >= 0 && this->GetAt(j) > key)
            {
                this->SetAt(j + 1, this->GetAt(j));
                this->TriggerCallback("OnSwap");
                j--;
            }
            this->SetAt(j + 1, key);
            this->m_CurrentIndex++;
        }

    private:
    };
}
#endif