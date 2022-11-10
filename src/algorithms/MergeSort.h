//
// Created by abdoulayedia on 09.11.2022
//
#pragma once

#include "QuickSort.h"

namespace sa
{
	// MergeSort
	template <typename T>
	class MergeSort : public SortingAlgorithm<T>
	{
	public:
		MergeSort<T>()
			: SortingAlgorithm<T>("Bubble Sort")
		{
		}

		MergeSort<T>(std::vector<T> *m_Collection)
			: SortingAlgorithm<T>("Bubble Sort", m_Collection)
		{
		}

		~MergeSort<T>()
		{
		}

		void Reset() override
		{
			this->SortingAlgorithm<T>::Reset();

			m_Left = 0;
			m_Right = this->m_Collection->size() - 1;
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
				m_SortStack.emplace(std::make_pair(0, this->m_Collection->size()));
				ProcessMergeIndexes(0, this->m_Collection->size());
				this->m_IsSorting = false;
			}

			if (!m_SortStack.empty())
			{
				auto [left, right] = m_SortStack.top();
				m_SortStack.pop();

				size_t mid = left + (right - left) / 2;

				size_t leftLen = mid - left + 1;
				size_t rightLen = right - mid;

				std::vector<T> leftValues(this->m_Collection->begin() + left, this->m_Collection->begin() + left + leftLen);
				std::vector<T> rightValues(this->m_Collection->begin() + mid + 1, this->m_Collection->begin() + mid + 1 + rightLen);

				size_t i = 0;
				size_t j = 0;
				size_t k = left;

				while (i < leftLen && j < rightLen)
				{
					if (leftValues[i] < rightValues[j])
						this->SetAt(k, leftValues[i++]);
					else
						this->SetAt(k, rightValues[j++]);
					k++;
					this->TriggerCallback("OnRender");
				}

				while (i < leftLen)
				{
					this->SetAt(k++, leftValues[i++]);
					this->TriggerCallback("OnRender");
				}

				while (j < rightLen)
				{
					this->SetAt(k++, rightValues[j++]);
					this->TriggerCallback("OnRender");
				}
			}
		}

	private:
		size_t m_Left = 0, m_Right = 0;
		std::stack<std::pair<size_t, size_t>> m_SortStack;

		void ProcessMergeIndexes(size_t left, size_t right)
		{
			if (left >= right)
				return;

			size_t mid = left + (right - left) / 2;

			m_SortStack.push(std::make_pair(mid + 1, right));
			m_SortStack.push(std::make_pair(left, mid));

			ProcessMergeIndexes(mid + 1, right);
			ProcessMergeIndexes(left, mid);
		}

		void Merge(size_t left, size_t mid, size_t right)
		{
			size_t leftLen = mid - left + 1;
			size_t rightLen = right - mid;

			std::vector<T> leftValues(this->m_Collection->begin() + left, this->m_Collection->begin() + left + leftLen);
			std::vector<T> rightValues(this->m_Collection->begin() + mid + 1, this->m_Collection->begin() + mid + 1 + rightLen);

			size_t i = 0;
			size_t j = 0;
			size_t k = left;

			while (i < leftLen && j < rightLen)
			{
				if (leftValues[i] < rightValues[j])
					this->SetAt(k, leftValues[i++]);
				else
					this->SetAt(k, rightValues[j++]);
				k++;
				this->TriggerCallback("OnRender");
			}

			while (i < leftLen)
			{
				this->SetAt(k++, leftValues[i++]);
				this->TriggerCallback("OnRender");
			}

			while (j < rightLen)
			{
				this->SetAt(k++, rightValues[j++]);
				this->TriggerCallback("OnRender");
			}
		}
	};
} // sa
