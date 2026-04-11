#include <exception>
#include <fstream>
#include <iostream>
#include <random>
#include <string>
#include <utility>

const int MAX_ID = 27000;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "invalid argument\n";
        return 1;
    }
    int num_ids;
    try {
        num_ids = std::stoi(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << "invalid argument\n";
        return 1;
    }
    if (num_ids < 1 || num_ids > MAX_ID) {
        std::cerr << "invalid argument\n";
        return 1;
    }

    std::vector<int> ids;
    ids.reserve(MAX_ID);
    for (int i = 1; i <= MAX_ID; i++) {
        ids.push_back(i);
    }
    int n = ids.size();

    std::random_device rd;
    std::mt19937 gen(rd());
    std::ofstream out_file(argv[2]);
    for (int i = 0; i != num_ids; i++) {
        std::uniform_int_distribution<> distrib(i, n - 1);
        int idx = distrib(gen);
        std::swap(ids[i], ids[idx]);
        out_file << std::to_string(ids[i]) << '\n';
    }
    return 0;
}
