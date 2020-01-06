//
// Created by CiaranWelsh on 02/01/2020.
//

#include <game/GamePlay.h>
#include "BeginGame.h"


namespace events {


    void BeginGame::go(game::GamePlay &gamePlay, game::PlayerPtr &player) {
        cout << "In BeginGame::go" << endl;
        gamePlay.game_started = true;
    }


}




