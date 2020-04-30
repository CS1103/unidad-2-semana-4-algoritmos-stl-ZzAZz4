#include <iostream>
#include <algorithm>
#include <vector>

std::string next_code (std::string s) {
    return (std::next_permutation(s.begin(), s.end())) ? s : "No solution";
}

int main() {
    std::vector<std::string> inputs(0);
    for(std::string input;;) {
        std::cin >> input;
        if (input == "#")
            break;
        inputs.emplace_back(input);
    }
    for (const auto& i : inputs)
        std::cout << next_code(i) << std::endl;
    return 0;
}