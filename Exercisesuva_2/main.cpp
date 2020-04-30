#include <iostream>
#include <vector>

unsigned countSwaps (std::vector<int> v)
{
    int count = 0;
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j+1])
            {
                std::swap(v[j], v[j+1]);
                ++count;
            }
        }
    }
    return count;
}



int main() {
    std::vector<int> v = {1, 3, 2};
    std::cout << countSwaps(v);
    return 0;
}