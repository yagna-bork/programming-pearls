#include <fstream>
#include <iostream>
#include <random>

const int8_t NUM_BITS = 20;
const int32_t MAX_VAL = INT32_MAX >> (31 - NUM_BITS);
const int32_t MIN_VAL = -MAX_VAL;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "invalid args\n";
    }
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(MIN_VAL, MAX_VAL);
    std::ofstream file(argv[1]);
    for (int i = 0; i != 1e6; i++) {
        file << dist(gen) << '\n';
    }
    return 0;
}
