#include "cyk.h"
#include <iostream>

void process(Config& cfg) {
    int word_count;
    std::string word;
    std::cin >> word_count;
    for (int i = 0; i < word_count; ++i) {
        std::cin >> word;
        bool res = cfg.check(word);
        if (res) {
            std::cout << "+";
        }
        else {
            std::cout << "-";
        }
        std::cout << std::endl;
    }
}

Config read() {
    Config cfg;
    int n;
    std::cin >> n;
    std::vector <std::string> s(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> s[i];
        cfg.add(s[i]);
    }
    return cfg;
}

int main() {
    Config cfg = read();
    process(cfg);
}