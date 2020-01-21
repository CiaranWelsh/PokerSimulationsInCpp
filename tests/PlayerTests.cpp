//
// Created by CiaranWelsh on 27/12/2019.
//

#include <game/Players.h>
#include "gtest/gtest.h"
#include "players/CallStation.h"
#include "iostream"
#include "players/FoldStation.h"

using namespace std;

TEST(PlayerTests, TestOstreamOperator) {
    CallStation callStation("Boid");
    string expected = "Player(name=\"Boid\", stack=0)";
    ostringstream actual;
    actual << callStation;
    cout << callStation;
    ASSERT_EQ(expected, actual.str());
}

TEST(PlayerTests, TestCallStationType) {
    CallStation callStation("Boid");
    std::string expected = "CallStation";
    std::string actual = callStation.getType();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestFoldStationType) {
    FoldStation foldStation("Boid");
    std::string expected = "FoldStation";
    std::string actual = foldStation.getType();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestYouCanSetInplay) {
    FoldStation foldStation("Boid");
    foldStation.inplay  = false;
    ASSERT_FALSE(foldStation.inplay);
}

TEST(PlayerTests, TestYouCanSetInplayFromPtr) {
    FoldStation foldStation("Boid");
    foldStation.inplay = false;
    std::shared_ptr<Player> foldStationPtr = std::make_shared<FoldStation>(foldStation);
    ASSERT_FALSE(foldStationPtr->inplay);
}

TEST(PlayerTests, TestFoldStationTypeFromPtr) {
    FoldStation foldStation("Boid");
    game::PlayerPtr foldStationPtr = std::make_shared<FoldStation>(foldStation);
    std::string expected = "FoldStation";
    std::string actual = foldStationPtr->getType();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestAssignmentOperator) {
    Player player("Boid");
    Player other = player;
    std::string expected = "Boid";
    std::string actual = other.getName();
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestFoldStationActionType) {
    game::GamePlay gamePlay;
    FoldStation foldStation("Boid");
    ActionType expected = Fold;
    ActionType actual = foldStation.choose_action(gamePlay.action_set_check_ptr);
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestFoldStationActionTypeFromPtr) {
    game::GamePlay gamePlay;
    FoldStation foldStation("Boid");
    std::shared_ptr<Player> foldStationPtr = std::make_shared<FoldStation>(foldStation);
    ActionType expected = Fold;
    ActionType actual = foldStationPtr->choose_action(gamePlay.action_set_check_ptr);
    ASSERT_EQ(expected, actual);
}

TEST(PlayerTests, TestCallStationActionTypeFromPtr) {
    game::GamePlay gamePlay;
    CallStation callStation("Boid");
    std::shared_ptr<Player> callStationPtr = std::make_shared<CallStation>(callStation);
    ActionType expected = Call;
    ActionType actual = callStationPtr->choose_action(gamePlay.action_set_check_ptr);
    ASSERT_EQ(expected, actual);
}



//TEST(PlayerTests, TestFolder){
//    FoldStation foldStation("nag");
//    cout << foldStation << endl;
//    cout << foldStation.getType() << endl;
//    string expected = "Player(name=\"\", stack=0)";
//    ostringstream actual;
//    actual << callStation;
//    cout << callStation;
//    ASSERT_EQ(expected, actual.str());
//}

