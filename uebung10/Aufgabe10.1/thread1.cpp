#include <iostream>
#include <vector>
#include <thread>
#include <functional>
#include <mutex>

using namespace std;

//int square_sum = 0;
std::mutex mtx;

void pow2(int& square_sum, int x)
{
    mtx.lock();
    square_sum += x * x;
    mtx.unlock();
}

int main(int argc, char const *argv[])
{
    int zero(0);
    auto square_sum = std::ref(zero);
    
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