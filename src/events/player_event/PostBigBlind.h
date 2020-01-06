//
// Created by CiaranWelsh on 04/01/2020.
//

#ifndef POKERSIMULATIONSINCPP_POSTBIGBLIND_H
#define POKERSIMULATIONSINCPP_POSTBIGBLIND_H

#include "PlayerEvent.h"

namespace events {
    class PostBigBlind : public PlayerEvent {
    public:
        PostBigBlind() {
            target = Players;
            id = "PostBigBlind";
            done = false;
            description = "Post the big blind";
        }

        void go(game::GamePlay &gamePlay, game::PlayerPtr &player) override;


    };
}


#endif //POKERSIMULATIONSINCPP_POSTBIGBLIND_H
