#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

struct adder : public std::unary_function<int, void> 
{   
    int sum;  
    adder() : sum(0) { }  
    void operator()(int x) 
    { 
        sum += x; 
    } 
};

int main(int argc, char const *argv[])
{
    std::vector<int> numVec(4, 100);

    adder result = std::for_each(numVec.begin(), numVec.end(), adder());
    std::cout << "Sum is " << result.sum << std::endl;
    std::cout << "Sum should be 400" << std::endl;
}