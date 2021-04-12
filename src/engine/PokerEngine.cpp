//
// Created by Ciaran on 10/01/2021.
//

#include <PokerX/engine/Evaluator.h>
#include "PokerX/engine/PokerEngine.h"
#include "PokerX/engine/Reset.h"
#include "PokerX/Error.h"
#include "PokerX/Error.h"

namespace pokerx {

    PokerEngine::PokerEngine(IPlayerManager *playerManager, IGameVariables *variables)
            : StateMachine(&Reset::getInstance()), players_(playerManager), gameVariables_(variables) {

        CHECK_NULLPTR(playerManager, "playerManager");
        CHECK_NULLPTR(variables, "variables");

        // All players subscribe to the IGameVariables instance
        // in order to observe the game play
        playerManager->watch(gameVariables_);
    }


    void PokerEngine::setState(State &state) {

        // And we get a chance to do stuff to this new state immediately after switching
        // we use exit for moving to the next player, which
        // we only want to do after we have performed the action
        // this is different from the original state machine design
        // whereby exit was conducted after assigning state to state_ in setState().

        // also remember that we must call exit first since we'll be calling
        // exit on the last state before changing it.
        state_->exit(this);

        // we then set the new state
        state_ = &state;
        // When we initially enter the setState method we
        // can use the enter method to do stuff
        // with our existing state
        state_->enter(this);


        // enter and exit are by default empty
    }

    void PokerEngine::action() {

        // when all players or all but 1 players are all in, then play
        // continues to showdown with players automatically checking their turns.
        // if > 1 player still in the game then something more complicated must happen
        // with split pot etc. (not yet implemented)
//        if (players_->numPlayersAllIn() == (players_->getNumPlayersStillInPot() - 1) ||
//            players_->numPlayersAllIn() == players_->getNumPlayersStillInPot()) {
//            while (state_->getType() != SHOWDOWN_STATE){
//                state_->action(this);
//            }
//        }
        // when its time to take player input we just call action, since we
        // only want to take one action set. Also at showdown we also only want to execute
        // showdown action
        if (state_->getType() == PLAYER_TO_ACT_STATE | state_->getType() == SHOWDOWN_STATE) {
            state_->action(this);
        }
        // otherwise we keep turning the wheel until its a players turn to act
        // so that users only see the player action states
        while ((state_->getType() != PLAYER_TO_ACT_STATE) && !gameVariables_->isDone()) {
            state_->action(this);
        }

        // if isDone???

    }

    void PokerEngine::action(unsigned int times) {
        for (int i = 0; i < times; i++) {
            state_->action(this);
        }
    }

    void PokerEngine::reset() {
        gameVariables_->reset();
        players_->reset();
    }

    IGameVariables *PokerEngine::getGameVariables() const {
        return gameVariables_;
    }

    IPlayerManager *PokerEngine::getPlayers() const {
        return players_;
    }

    void PokerEngine::bind(IPlayerManager *manager) {
        CHECK_NULLPTR(manager->getCurrentPlayer(), "IPlayerManager::getCurrentPlayer()");
        players_ = manager;
    }

    void PokerEngine::bind(IGameVariables *gameVariables) {
        gameVariables_ = gameVariables;
    }

    void PokerEngine::nextPlayer(StateMachine *machine) {
        CHECK_NULLPTR(machine, "StateMachine");
        auto *engine = dynamic_cast<PokerEngine *>(machine);
        engine->getPlayers()->nextPlayer();
    }

    void PokerEngine::dealHoleCards() const {

        // get a reference to the deck
        Deck &deck = getGameVariables()->getDeck();

        // We shuffle the deck. This is the only time we do so
        deck.shuffle();

        // Start left of dealer ( the button)
        int number_of_players = getPlayers()->size();

        for (int card_number = 0; card_number < 2; card_number++) {
            for (int i = 1; i < number_of_players + 1; i++) {
                int idx = i % number_of_players;
                const auto &player = getPlayers()->getPlayer(idx);

                if (!player->getInjectedHoleCards().empty()) {
                    player->getHoleCards().add(player->getInjectedHoleCards()[card_number]);
                    player->getInjectedHoleCards().erase(card_number);
                    // otherwise normal game is dealt
                } else {
                    player->getHoleCards().add(deck.pop());
                }
            }
        }
    }

    CardCollection PokerEngine::dealFlop() {
        const std::vector<ICardPtr> &injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (injCards.size() >= 3) {
            CardCollection flop;
            flop.add(injCards[0]);
            flop.add(injCards[1]);
            flop.add(injCards[2]);
            return flop;
        }
        // otherwise its a random selection

        // get a reference to the deck
        Deck &deck = getGameVariables()->getDeck();
        CardCollection community = gameVariables_->getCommunityCards();
        // discard top card
        deck.pop();

        community.add(deck.pop());
        community.add(deck.pop());
        community.add(deck.pop());
        return community;

    }

    ICardPtr PokerEngine::dealTurn() const {
        const std::vector<ICardPtr> &injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (injCards.size() >= 4) {
            return injCards[3];
        }
        Deck &deck = getGameVariables()->getDeck();
        // discard top card
        deck.pop();

        return deck.pop();

    }

    ICardPtr PokerEngine::dealRiver() const {
        const std::vector<ICardPtr> &injCards = gameVariables_->getInjectedCommunityCards();
        // if we are reproducing some game then we just take the fist three cards for injected cards
        if (injCards.size() == 5) {
            return injCards[4];
        }
        Deck &deck = getGameVariables()->getDeck();
        // discard top card
        deck.pop();

        return deck.pop();

    }

}




















