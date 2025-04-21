#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int g = 10;

int main()
{

    int x = 10;
    int y = 2;
    std::vector<int> sum;

    // Usually we use lambda with std::foreach  (for each is inside algorithm library)
    std::vector<int> values{2, 6, 3, 6, 4, 11, 5, 21};

    // we can pass any out side scope variables in the whole file to the lambda by reference if we make [&], so the lambda can modify any outside scope parameters
    std::for_each(values.begin(), values.end(), [&](int z)
                  { sum.push_back(x + y + z + g); }); // first element = 10 + 2 + values[0]=2 + 10 = 14 + 10 =m 24

    for (auto elem : sum)
        std::cout << elem << " ";

    return 0;
}
