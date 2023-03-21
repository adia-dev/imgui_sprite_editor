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
    // vector of pointers to SortingAlgorithm and a pointer to a SortingAlgorithm shared_ptr
    std::vector<std::shared_ptr<SortingAlgorithm>> sortingAlgorithms;
    std::shared_ptr<SortingAlgorithm> sortingAlgorithm;

    // create a vector of integers
    std::vector<int> collection = {5, 4, 3, 2, 1};

    // create a BubbleSort object and set the collection
    sortingAlgorithm = std::make_shared<BubbleSort>();
    sortingAlgorithm->setCollection(&collection);

    // add the BubbleSort object to the vector of pointers to SortingAlgorithm
    sortingAlgorithms.push_back(sortingAlgorithm);

    // create a QuickSort object and set the collection
    sortingAlgorithm = std::make_shared<QuickSort>();
    sortingAlgorithm->setCollection(&collection);

    // add the QuickSort object to the vector of pointers to SortingAlgorithm
    sortingAlgorithms.push_back(sortingAlgorithm);

    // create a heap vector of integers
    std::vector<int> heapCollection = {5, 4, 3, 2, 1};

    // iterate over the vector of pointers to SortingAlgorithm and call the sort method
    for (auto &i : sortingAlgorithms)
    {
        i->sort();
    }

    return 0;
}