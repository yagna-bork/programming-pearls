#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int MAX_ID = 27000;
int WORDS = 1000;
int BITMAP_SZ = WORDS * 16;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "invalid argument\n";
        return 1;
    }

    std::ifstream in_file(argv[1]);
    std::ofstream out_file(argv[2]);
    int id;
    std::vector<bool> bitmap(BITMAP_SZ);
    for (int i = 1; i <= MAX_ID; i += BITMAP_SZ) {
        std::fill(bitmap.begin(), bitmap.end(), false);
        in_file.clear();
        in_file.seekg(0);
        while (in_file) {
            in_file >> id;
            if ((i <= id) && (id < i + BITMAP_SZ)) {
                int idx = (id - 1) % BITMAP_SZ;
                bitmap[idx] = true;
            }
        }

        for (int j = 0; j != bitmap.size(); j++) {
            if (bitmap[j]) {
                out_file << std::to_string(i + j) << '\n';
            }
        }
    }
    return 0;
}
