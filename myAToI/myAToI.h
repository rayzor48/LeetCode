//
// Created by rayzo on 18.06.2023.
//

#ifndef MYATOI_MYATOI_H
#define MYATOI_MYATOI_H

#include <String>

namespace MyStd {
    class Solution {

    private:
        enum state {
            START,
            DIGIT,
            SPACE = 10,
            CHAR  = 11,
            SIGN  = 12,
            POINT = 13,
            RETURN
        };

    public:
        Solution();
        ~Solution() = default;

    public:
        int myAtoi(std::string s="");

    private:
        state getType(const char c) const;
        int getNumvber(const char c) const;

        state turnType(const state curr, const state next) const;

        int returnInteger(double num) const;

    private:
        bool isNegative;

    };

}
#endif //MYATOI_MYATOI_H
