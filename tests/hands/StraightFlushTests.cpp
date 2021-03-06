//
// Created by Ciaran Welsh on 25/01/2021.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "Mockups/MockCard.h"
#include "TestHands.h"
#include "PokerX/engine/hands/StraightFlush.h"

using namespace pokerx;

class StraightFlushTests : public ::testing::Test {
public:
    TestHands hands;
    Cards cards;

    StraightFlushTests() = default;
};

TEST_F(StraightFlushTests, TestStraightFlush1) {
    StraightFlush sflush(hands.straightFlushSixHigh);
    ASSERT_TRUE(sflush.isA());
}


TEST_F(StraightFlushTests, TestStraightFlush2) {
    StraightFlush sflush(hands.straightFlushTenHigh);
    ASSERT_TRUE(sflush.isA());
}


TEST_F(StraightFlushTests, TestStraightFlush1BestFive) {
    StraightFlush sflush(hands.straightFlushSixHigh);
    CardCollection cc(
            {
                    &cards.twoOfClubs,
                    &cards.threeOfClubs,
                    &cards.fourOfClubs,
                    &cards.fiveOfClubs,
                    &cards.sixOfClubs,
            }
    );
    ASSERT_EQ(cc, *sflush.getBestFive());
}


TEST_F(StraightFlushTests, TestStraightFlush2BestFive) {
    StraightFlush sflush(hands.straightFlushTenHigh);
    CardCollection cc(
            {
                    &cards.sixOfClubs,
                    &cards.sevenOfClubs,
                    &cards.eightOfClubs,
                    &cards.nineOfClubs,
                    &cards.tenOfClubs
            }
    );
    ASSERT_EQ(cc, *sflush.getBestFive());
}


TEST_F(StraightFlushTests, TestStraightFlush3BestFive) {
    StraightFlush sflush(hands.straight_flush3);
    CardCollection cc(
            {
                    &cards.threeOfClubs,
                    &cards.fourOfClubs,
                    &cards.fiveOfClubs,
                    &cards.sixOfClubs,
                    &cards.sevenOfClubs,
            }
    );
    ASSERT_EQ(cc, *sflush.getBestFive());
}

TEST_F(StraightFlushTests, TestStraightFlushValueOf1) {
    StraightFlush sflush10(hands.straightFlushTenHigh);
    StraightFlush sflush6(hands.straightFlushSixHigh);
    std::cout << sflush10.getValue() << std::endl;
    std::cout << sflush6.getValue() << std::endl;
}







