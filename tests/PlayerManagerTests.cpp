//
// Created by Ciaran on 17/01/2021.
//

#include "gtest/gtest.h"
#include "PokerX/engine/PlayerManager.h"
#include "Mockups/FakePlayer.h"
#include <memory>

using namespace pokerx;

class PlayerManagerTests : public ::testing::Test {
public:
    FakePlayer btn;
    PlayerManager playerManager;

    PlayerManagerTests() {
        for (int i = 0; i < 6; i++) {
            std::ostringstream os;
            os << "Player" << i;
            std::shared_ptr<FakePlayer> playerPtr =
                    std::make_shared<FakePlayer>(FakePlayer(os.str(), 1000.0));
            playerManager.addPlayer(playerPtr);
        }
    };
};


TEST_F(PlayerManagerTests, CheckThatNoneOfThePlayersAreNullptr) {
    for (const auto &player : playerManager) {
        ASSERT_FALSE(player == nullptr);
    }
}

TEST_F(PlayerManagerTests, CheckThatButtonIsNotNullptr) {
    ASSERT_FALSE(playerManager.getButton() == nullptr);
}

TEST_F(PlayerManagerTests, CheckThatCurrentPlayerIsNotNullptr) {
    ASSERT_FALSE(playerManager.getCurrentPlayer() == nullptr);
}

TEST_F(PlayerManagerTests, CheckThatTheOrderingOfPlayersCanBeRotated) {

    ASSERT_FALSE(playerManager.getCurrentPlayer() == nullptr);
}






















