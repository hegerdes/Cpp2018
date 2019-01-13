#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <future>
#include <chrono>

using namespace std;

//int square_sum = 0;

int pow2(int x)
{
    return (x * x);
}

int main(int argc, char const *argv[])
{
    //auto square_sum = std::ref(int zero(0));
    int square_sum = 0;

    vector<std::future<int>> threads;
    for (int i = 1; i <= 20; i++)
    {
        threads.push_back(std::async(&pow2, i));
    }

    // vector<std::future<int>>::iterator it;
    // for (it = threads.begin(); it != threads.end(); it++)
    // {
    //     square_sum += it.get();
    // }

    for(auto &e : threads) {
        square_sum += e.get();
    }
    cout << "Sum auf squares up to 20 is = " << square_sum << endl;
    return 0;
}