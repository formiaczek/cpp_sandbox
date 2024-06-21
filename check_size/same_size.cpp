#include <vector>
#include <set>
#include <array>
#include <iostream>

#include "same_size.h"


int main(int argc, char **argv) {

    std::vector<int> v1(4), v2(2), v3(4), v4(2), v5 = {6, 5, 4, 3};
    std::set<double> s1	= {1.0, 2.0, 3.0};
    std::array<int, 3> a1 = {1, 2, 3};
    ASSERT_ALL_THIS_SIZE(4ul, v1, v3, v5);

    ASSERT_ALL_THIS_SIZE(3ul, v1, v2, s1, a1, v3, v4, v5);

    return 0;
}

// Output:
// terminate called after throwing an instance of 'std::logic_error'
//  what():  Size mismatch for: [v1, v2, s1, a1, v3, v4, v5], expected size was: 3 but actual sizes were: [4, 2, 3, 3, 4, 2, 4]
