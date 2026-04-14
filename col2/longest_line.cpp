#include <climits>
#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char* argv[]) {
    std::ifstream file(argv[1]);
    std::string line;
    size_t longest = 0;
    int i = 0;
    int lineno = -1;
    while (file) {
        i++;
        std::getline(file, line);
        if (longest < line.size()) {
            longest = line.size();
            lineno = i;
        }
    }
    std::cout << longest << '\n';
    std::cout << lineno << '\n';
    return 0;
}
