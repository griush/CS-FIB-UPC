#include <iostream>

bool is_increasing(int n) {
    if (n < 10) 
        return true;

    int last = n % 10;
    return is_increasing(n / 10) && (last >= ((n % 100) - last) / 10);
}

int main(int argc, char const *argv[])
{
    std::cout << is_increasing(123378) << std::endl;
    std::cout << is_increasing(125433) << std::endl;
    std::cout << is_increasing(7) << std::endl;


    return 0;
}
