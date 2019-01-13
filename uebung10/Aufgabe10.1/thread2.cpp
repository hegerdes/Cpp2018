#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <atomic>

using namespace std;

//int square_sum = 0;

void pow2(int& square_sum, int x)
{
    int s = square_sum.load(memory_order_relaxed);
    square_sum.store(s + x * x, memory_order_relaxed)
}

int main(int argc, char const *argv[])
{
    //auto square_sum = std::ref(int zero(0));
    std::atomic<int> square_sum(0);

    vector<thread> threads;
    for (int i = 1; i <= 20; i++)
    {
        threads.push_back(thread(&pow2, square_sum, i));
    }

    vector<thread>::iterator it;
    for (it = threads.begin(); it != threads.end(); it++)
    {
       (*it).join();
    }
    cout << "Sum auf squares up to 20 is = " << square_sum << endl;
    return 0;
}