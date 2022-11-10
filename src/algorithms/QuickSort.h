//
// Created by abdoulayedia on 09.11.2022
//
#pragma once

#include "SortingAlgorithm.h"

namespace sa
{
	// QuickSort
	template <typename T>
	class QuickSort : public SortingAlgorithm<T>
	{
	public:
		QuickSort<T>()
			: SortingAlgorithm<T>("Bubble Sort")
		{
		}

		QuickSort<T>(std::vector<T> *m_Collection)
			: SortingAlgorithm<T>("Bubble Sort", m_Collection)
		{
		}

		~QuickSort<T>()
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

			if (this->m_IsSorting)
			{
				Sort(0, this->m_Collection->size());
				this->m_IsSorting = false;
			}
		}

	private:
		size_t Partition(size_t low, size_t high)
		{
			size_t i = low;
			size_t j = high;
			T pivot = this->GetAt(low);

			while (i < j)
			{
				do
				{
					this->TriggerCallback("OnComparison");
					i++;
				} while (i < high && this->GetAt(i) < pivot);

				do
				{
					this->TriggerCallback("OnComparison");
					j--;
				} while (j > low && this->GetAt(j) > pivot);

				if (i < j)
				{
					this->Swap(i, j);
					this->TriggerCallback("OnRender");
				}
			}
			this->Swap(low, j);
			this->TriggerCallback("OnRender");
			return j;
		}

		void Sort(size_t low, size_t high)
		{
			if (low >= high)
				return;

			size_t j = Partition(low, high);

			Sort(low, j);
			Sort(j + 1, high);
		}
	};
} // sa
