//
// Created by Ciaran on 16/01/2021.
//

#include <iostream>
#include "PokerX/engine/BigBlind.h"
#include "PokerX/engine/DealHoleCards.h"
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/eGamePlayState.h"

namespace pokerx {

    void BigBlind::enter(StateMachine *machine) {
        std::cout << "Entering BigBlind" << std::endl;

    }

    void BigBlind::action(StateMachine *machine) {
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        IPlayerManager *manager = engine->getPlayers();
        manager->getCurrentPlayer()->postBigBlind();
        machine->setState(DealHoleCards::getInstance());
    }

    void BigBlind::exit(StateMachine *machine) {
        PokerEngine::nextPlayer(machine);
    }

    BigBlind &BigBlind::getInstance() {
        static BigBlind singleton;
        return singleton;
    }

    unsigned int BigBlind::getType() const {
        return BIG_BLIND_STATE;
    }
}

