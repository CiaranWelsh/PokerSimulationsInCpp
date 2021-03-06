//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/FullHouse.h"

using namespace pokerx;

class FlushTests : public ::testing::Test {
public:
    TestHands hands;
    Cards cards;

    FlushTests() = default;
};

TEST_F(FlushTests, TestFullhouse1) {
    pokerx::FullHouse fullHouse(hands.fullHouseTwosfullOfThrees);
    ASSERT_TRUE(fullHouse.isA());
}


TEST_F(FlushTests, TestFullHouse) {
    pokerx::FullHouse fullHouse(hands.fullHouseEightsFullOfQueens);
    ASSERT_TRUE(fullHouse.isA());
}

TEST_F(FlushTests, TestFullhouse1BestFive) {
    pokerx::FullHouse fullHouse(hands.fullHouseTwosfullOfThrees);
    CardCollection cc(
            {
                    &cards.twoOfClubs,
                    &cards.twoOfDiamonds,
                    &cards.twoOfHearts,
                    &cards.queenOfClubs,
                    &cards.queenOfDiamonds,
            }
    );
    ASSERT_EQ(cc, *fullHouse.getBestFive());
}


TEST_F(FlushTests, TestFullHouseBestFive) {
    pokerx::FullHouse fullHouse(hands.fullHouseEightsFullOfQueens);
    CardCollection cc(
            {
                    &cards.eightOfClubs,
                    &cards.eightOfDiamonds,
                    &cards.eightOfHearts,
                    &cards.queenOfClubs,
                    &cards.queenOfDiamonds,
            }
    );
    ASSERT_EQ(cc, *fullHouse.getBestFive());
}








