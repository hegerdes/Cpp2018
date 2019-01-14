#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

using namespace std;

atomic<int> square_sum(0);

int pow2(int x)
{
    int s;
    s = square_sum.load(memory_order_relaxed);
    square_sum.store(s + x * x, memory_order_relaxed);

    return square_sum.load(memory_order_relaxed);
};

int main(int argc, char const *argv[])
{
    std::atomic<int> square_sum(0);

    vector<thread> threads;
    for (int i = 1; i <= 20; i++)
    {
        threads.push_back(thread(pow2, i));
    }

    vector<thread>::iterator it;
    for (it = threads.begin(); it != threads.end(); it++)
    {
       it->join();
    }
    cout << "Sum auf squares up to 20 is = " << pow2(0) << endl;
    return 0;
}