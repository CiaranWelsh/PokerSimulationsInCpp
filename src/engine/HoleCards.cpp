//
// Created by CiaranWelsh on 18/12/2019.
//

#include "PokerX/engine/HoleCards.h"

using namespace std;

namespace pokerx {


    HoleCards::HoleCards(ICard* card1, ICard* card2)
        : RestrictedCardCollection({card1, card2}, 2){
    }
}