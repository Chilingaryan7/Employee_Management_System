#ifndef GET_BONUS_TYPE
#define GET_BONUS_TYPE
#include "get_bonus_type.hpp"
#include <iostream>

double get_bonus_type(BonusType type) {
    switch (type) {
        case bonus : return 10.5;
        case commissionRate : return 15.5;
        case additionalBonus : return 12.5;
        case performanceBonus : return 22.5;
        default: throw std::invalid_argument("wrong type");
    }
}

#endif //GET_BONUS_TYPE