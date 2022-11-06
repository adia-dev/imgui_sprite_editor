#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>

class SortingAlgorithm
{
public:
    SortingAlgorithm()
    {
    }

    SortingAlgorithm(const std::string &name)
        : m_Name(name)
    {
    }

    virtual ~SortingAlgorithm()
    {
    }

    void setCollection(std::vector<int> *collection)
    {
        m_Collection = collection;
    }

    void printCollection()
    {
        for (auto &i : *m_Collection)
        {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    virtual void sort() = 0;

protected:
    std::string m_Name;
    std::vector<int> *m_Collection = nullptr;
};

class BubbleSort : public SortingAlgorithm
{
public:
    BubbleSort()
    {
    }

    ~BubbleSort()
    {
    }

    void sort() override
    {
        std::cout << "Sorting with BubbleSort" << std::endl;
    }
};

class QuickSort : public SortingAlgorithm
{
public:
    QuickSort()
    {
    }

    ~QuickSort()
    {
    }

    void sort() override
    {
        std::cout << "Sorting with QuickSort" << std::endl;
    }
};

int main()
{
    std::cout << "Hello World\n";
    // create an unique pointer to a sorting algorithm object of type BubbleSort
    std::unique_ptr<SortingAlgorithm> sortingAlgorithm = std::make_unique<BubbleSort>();
    std::unique_ptr<SortingAlgorithm> sortingAlgorithm2 = std::make_unique<QuickSort>();

    // create a vector of integers
    std::vector<int> collection = {3, 1, 2, 5, 4};

    for (auto &i : collection)
    {
        std::cout << i << " ";
    }

    // set the collection to the sorting algorithm
    sortingAlgorithm->setCollection(&collection);
    sortingAlgorithm2->setCollection(&collection);

    sortingAlgorithm->sort();
    sortingAlgorithm2->sort();

    sortingAlgorithm->printCollection();
    sortingAlgorithm2->printCollection();

    return 0;
}