#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

// 8mb for faster i/o
char buff[1 << 23];

int main(int argc, char* argv[]) {
    std::cin.rdbuf()->pubsetbuf(buff, sizeof(buff));
    std::cout.rdbuf()->pubsetbuf(buff, sizeof(buff));

    std::string word, key;
    word.reserve(100);
    key.reserve(100);
    std::unordered_map<std::string, std::vector<std::string>> anagram_sets;
    anagram_sets.reserve(1 << 19);
    while (std::cin >> word) {
        key = word;
        std::sort(key.begin(), key.end());
        anagram_sets[key].emplace_back(word.begin(), word.end());
    }

    for (const auto& [k, anagrams] : anagram_sets) {
        if (anagrams.size() < 2) {
            continue;
        }
        for (int i = 0; i != anagrams.size(); i++) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << anagrams[i];
        }
        std::cout << '\n';
    }
    return 0;
}
