#include <cstdint>
#include <fstream>
#include <iostream>
#include <unordered_set>
#include <vector>

const int8_t NUM_BITS = 20;
const int32_t MAX_VAL = INT32_MAX >> (31 - NUM_BITS);
const int32_t MIN_VAL = -MAX_VAL;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "invalid args\n";
        return 1;
    }
    std::vector<bool> bitmap(2 * MAX_VAL + 1, false);
    std::ifstream file(argv[1]);
    int32_t n;
    while (file >> n) {
        bitmap[n - MIN_VAL] = true;
    }

    for (int i = 0; i != bitmap.size(); i++) {
        if (!bitmap[i]) {
            std::cout << (MIN_VAL + i) << '\n';
            return 0;
        }
    }
    std::cout << "not found\n";
    return 1;
}
