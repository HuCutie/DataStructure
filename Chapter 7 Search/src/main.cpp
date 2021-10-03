#include <iostream>
#include <thread>
#include <vector>
#include <math.h>

typedef unsigned long long ElemType;

std::vector<ElemType> arr;
ElemType key;
bool flag = false;

void Init(int n)
{
    for (ElemType i = 0; i < n; i++)
    {
        arr.push_back(i);
    }
}

void search(ElemType p, ElemType q)
{
    for (auto i = p; i <= q && i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            std::cout << "Element found in the vector \n";
            return ;
        }
    }
}

int main()
{
    ElemType block_start = 0, block_end, n;
    n = 100000000;
    key = 10000;

    Init(n);

    unsigned long const length = arr.size();

    if (!length)
    {
        return 0;
    }

    const ElemType hardware_threads = std::thread::hardware_concurrency();
    const ElemType num_threads = hardware_threads;
    const ElemType block_size = length / num_threads;

    std::cout << "Number of threads created : " << num_threads << "\n";

    std::vector<std::thread> threads(num_threads);
    block_start = 0;
    for (ElemType i = 0; i < num_threads; ++i)
    {
        block_end = block_start;
        block_end = block_end + block_size;

        threads[i] = std::thread(search, block_start, block_end);
        block_start = block_end + 1;
    }

    for (auto &entry : threads)
    {
        if (entry.joinable())
        {
            entry.join(); //join is used to make sure that every thread will execute before the main() ends
        }            
    }

    if (flag)
    {
        std::cout << "Element not present in the vector \n";
    }

    return 0;
}