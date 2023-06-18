//
// Created by rayzo on 18.06.2023.
//

#include "myAToI.h"
#include <limits.h>

using namespace MyStd;

Solution::Solution() : isNegative(false) {

}

int Solution::myAtoi(std::string s) {

    if(s.size() == 0) return 0;

    double num = 0;

    auto currType = START;

    for(auto c : s){
        auto currNum = getNumvber(c);

        auto nextType = getType(c);

        //Код отвечающий за переключение типов
        if(currType == START){
            if(nextType == CHAR || nextType == POINT) return num;
            else currType = nextType;
        } else {
            if(currType == SPACE) {
                switch (nextType) {
                    case SPACE:
                    case SIGN:
                    case DIGIT:
                        currType = nextType;
                        break;
                    default:
                        return num;
                }
            } else if(currType == SIGN) {
                switch (nextType) {
                    case DIGIT:
                        currType = nextType;
                        break;
                    default:
                        return num;
                }
            } else if(currType == DIGIT) {
                switch (nextType) {
                    case DIGIT:
                        currType = nextType;
                        break;
                    default:
                        return returnInteger(num);
                }
            } else if(currType == CHAR) {
                currType = RETURN;
            } else if(currType == POINT) {
                currType = RETURN;
            }
        }

        switch (currType) {
            case SPACE:
                continue;
            case SIGN:
                if(c == '-') isNegative = true;
                continue;
            case DIGIT:
                num *=10;
                num += currNum;
                break;
            case POINT:
            case CHAR:
            case RETURN:
                return returnInteger(num);
        }
    }

    return returnInteger(num);
}

Solution::state Solution::getType(const char c) const {
    if(c == ' '){
        return SPACE;
    } else if (c == '-' || c == '+'){
        return SIGN;
    } else if (getNumvber(c) != -1){
        return DIGIT;
    } else if(c == '.') {
        return POINT;
    } else {
        return CHAR;
    }
}

int Solution::getNumvber(const char c) const {
    if(c == '0') {
        return 0;
    } else if(c == '1') {
        return 1;
    } else if(c == '2') {
        return 2;
    } else if(c == '3') {
        return 3;
    } else if(c == '4') {
        return 4;
    } else if(c == '5') {
        return 5;
    } else if(c == '6') {
        return 6;
    } else if(c == '7') {
        return 7;
    } else if(c == '8') {
        return 8;
    } else if(c == '9') {
        return 9;
    } else {
        return -1;
    }
}

int Solution::returnInteger(double num) const {
    if(isNegative) num = -num;

    if(num < INT_MIN) return INT_MIN;
    if(num > INT_MAX) return INT_MAX;

    return num;
}

