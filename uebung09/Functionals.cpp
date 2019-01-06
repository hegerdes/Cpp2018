#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>


int main(int argc, char const *argv[])
{
    using namespace std::placeholders;

    std::vector<int> v = {1, 4, 2, 8, 5, 7};

    copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    auto it = remove_if(v.begin(), v.end(),
        std::bind(std::bind(std::equal_to<int>(), _1, 0),
            bind(std::modulus<int>(), _1, 2)));

    copy(v.begin(), it, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;





    // /**
    //  * @brief Test for task 1
    //  * 
    //  */
    // std::vector<int> v = {1,4,2,8,7};

    // auto it = std::bind(std::bind(std::equal_to<int>(),_1,0),
    //     std::bind(std::modulus<int>(),_1,2));

    // std::iterator<int> inter = std::remove_if(v.begin(), inter, it);
    
    // auto it = std::remove_if(v.begin(),v.end(), 
    //     std::bind(std::bind(std::equal_to<int>(),_1,0),
    //     std::bind(std::modulus<int>(),_1,2)));

    // auto it = std::remove_if(v.begin(),v.end(),
    //         std::bind(std::modulus<int>(),2,_1));

    // auto it = std::remove_if(v.begin(),v.end(), 
    //     std::bind1st(std::bind2nd(std::equal_to<int>(),0),
    //     std::bind2nd(std::modulus<int>(),2)));


    
    return 0;
}
