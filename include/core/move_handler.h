//
// Created by Nathaniel Smith on 12/7/20.
//

#pragma once

#include "move_model.h"

namespace antares {

namespace models {

    enum MoveType {
        AttackType,
        MobilityType,
        ShieldType,
    };


    class MoveHandler {

    public:

    private:

        b2Body* player_body_;

        bool is_attack_in_progress_;

        int total_start_up_;
        int current_startup_;

        int total_active_frames_;
        int current_active_frame_;

        int total_end_lag_;
        int current_end_lag_;

        int interval_index;

        std::vector<b2Fixture*> fixtures_;

        MoveType type_;

        Attack *attack_;
        MobilityMove *mobility_;
        Shield *shield_;


    };

} //namespace models

} //namespace antares