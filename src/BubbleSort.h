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

        void Tick() override
        {

            if (this->m_Collection == nullptr || this->m_Collection->size() <= 1 || std ::is_sorted(this->m_Collection->begin(), this->m_Collection->end()) || this->m_CurrentPass >= this->m_Collection->size())
            {
                this->Reset();
                return;
            }

            if (this->m_CurrentIndex >= this->m_Collection->size() - this->m_CurrentPass - 1)
            {
                this->m_CurrentIndex = 0;
                this->m_CurrentPass++;
                return;
            }

            // if (this->m_Collection->at(this->m_CurrentIndex) > this->m_Collection->at(this->m_CurrentIndex + 1))
            // {
            //     std::swap(this->m_Collection->at(this->m_CurrentIndex), this->m_Collection->at(this->m_CurrentIndex + 1));
            //     if (this->m_RenderCallback)
            //         this->m_RenderCallback();
            // }

            for (int i = 0; i < this->m_Collection->size() - 1; i++)
            {
                if (this->GetAt(i) > this->GetAt(i + 1))
                {
                    std::swap(this->GetAt(i), this->GetAt(i + 1));
                    this->TriggerCallback("OnSwap");
                    this->TriggerCallback("OnComparison");
                }
            }

            this->m_CurrentIndex++;
        }

    private:
    };
}
#endif