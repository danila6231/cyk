#pragma once
#include <vector>
#include <string>
#include <set>

class Config {
public:
    void add(const std::string& rule) {
        bool correct;
        if (rule.size() < 4 ||
            !(rule[1] == '-' && rule[2] == '>') ||
            ((rule[3] == '1') && (rule[0] != 'S')) ||
            !('A' <= rule[0] && rule[0] <= 'Z')) {
            throw(std::invalid_argument("Wrong rule format"));
        }
        else {
            correct = false;
            if ((('a' <= rule[3] && rule[3] <= 'z') || rule[3] == '1') && rule.size() == 4) {
                correct = true;
            }
            if ('A' <= rule[3] && rule[3] <= 'Z' && 'A' <= rule[4] && rule[4] <= 'Z' && rule.size() == 5 && rule[3] != 'S' && rule[4] != 'S') {
                correct = true;
            }
        }
        if (!correct) {
            throw std::invalid_argument("Wrong grammar");
        }
        if (rule.size() == 4) {
            if (rule[3] == '1') {
                empty_rule = true;
            } else {
                common.insert({rule[0], rule[3]});
            }
        }
        else {
            std::string temp;
            temp += rule[3];
            temp += rule[4];
            double_.insert({rule[0], temp });
        }
    }

    int check(const std::string& word) {
        // empty check
        if (word == "1") {
            return empty_rule;
        }
        size_t len = word.length();
        int n = 30;
        std::vector<std::vector<std::vector<bool>>>dp(n);
        for (int i = 0; i < n; i++) {
            dp[i].assign(len + 1, std::vector<bool>(len + 1, false));
        }
        for (std::pair<char, char> q : common) {
            for (int i = 0; i < len; i++) {
                if (q.second == word[i]) {
                    dp[q.first - 'A'][i][i + 1] = true;
                }
            }
        }
        for (int l = 2; l <= len; ++l) {
            for (int i = 0; i <= len - l; i++) {
                int j = i + l;
                for (int k = i + 1; k <= j - 1; ++k) {
                    for (std::pair<char, std::string> q : double_) {
                        if (dp[q.second[0] - 'A'][i][k] && dp[q.second[1] - 'A'][k][j]) {
                            dp[q.first - 'A'][i][j] = true;
                        }
                    }
                }
            }
        }
        if (dp['S' - 'A'][0][len]) {
            return true;
        }
        return false;
    }

private:
    std::set <std::pair<char, std::string>> double_;
    std::set <std::pair<char, char>> common;
    bool empty_rule = false;
};

