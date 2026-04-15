#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <ostream>
#include <string>
#include <vector>

bool parse_args(std::vector<int>& out_arr, int& out_rot) {
    std::cout << "Enter the array (space separated): ";
    std::string line;
    std::getline(std::cin, line);

    auto i = line.begin();
    while (i != line.end()) {
        i = std::find_if_not(i, line.end(), isspace);
        auto j = std::find_if(i, line.end(), isspace);
        if (std::find_if_not(i, j, isdigit) != j) {
            std::cerr << "invalid array\n";
            return false;
        }
        out_arr.push_back(std::stoi(std::string(i, j)));
        i = j;
    }
    if (out_arr.empty()) {
        std::cerr << "invalid array\n";
        return false;
    }

    std::cout << "Rotate by: ";
    std::getline(std::cin, line);
    auto beg = line.begin();
    bool is_neg = false;
    if (*beg == '-') {
        beg++;
        is_neg = true;
    }
    if (std::find_if_not(beg, line.end(), isdigit) != line.end()) {
        std::cerr << "invalid rotation\n";
        return false;
    }
    out_rot = std::stoi(std::string(beg, line.end()));
    if (is_neg) {
        out_rot *= -1;
    }
    return true;
}

// my own attempt before i remembered the leetcode solution
template <class RndIt> void my_rotate(RndIt beg, RndIt end, int rotate) {
    int size = end - beg;
    if (size < 2) {
        return;
    }

    rotate %= size;
    if (rotate < 0) {
        rotate += size;
    } else if (rotate == 0) {
        return;
    }

    int out = rotate;
    while (out < size) {
        for (int in = 0; in != rotate; in++, out++) {
            std::iter_swap(beg + in, beg + out % size);
        }
    }
}

// solution from memory of a leetcode problem i already looked at solutions for
template <class RndIt> void solution(RndIt beg, RndIt end, int rotate) {
    int size = end - beg;
    if (size < 2) {
        return;
    }

    rotate %= size;
    if (rotate < 0) {
        rotate += size;
    } else if (rotate == 0) {
        return;
    }

    std::reverse(beg, end);
    std::reverse(beg, beg + rotate);
    std::reverse(beg + rotate, end);
}

int main(int argc, char* argv[]) {
    std::vector<int> arr;
    int rot;
    if (!parse_args(arr, rot)) {
        return 1;
    }

    // my_rotate(arr.begin(), arr.end(), rot);
    solution(arr.begin(), arr.end(), rot);

    std::ostream_iterator<int> out(std::cout, " ");
    std::copy(arr.begin(), arr.end(), out);
    std::cout << '\n';
    return 0;
}
