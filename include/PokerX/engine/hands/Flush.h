//
// Created by Ciaran Welsh on 25/01/2021.
//

#ifndef POKERX_FLUSH_H
#define POKERX_FLUSH_H

#include "PokerX/engine/hands/IHand.h"
#include "PokerX/engine/hands/Best5.h"

namespace pokerx {


    class Flush : public IHand {

    public:
        using IHand::IHand;

        [[nodiscard]] bool isA() const override;

        [[nodiscard]] std::shared_ptr<CardCollection> getBestFive() const override;

        [[nodiscard]] HandType getHandType() const override;
        int getValue() override;

    };
}

#endif //POKERX_FLUSH_H
