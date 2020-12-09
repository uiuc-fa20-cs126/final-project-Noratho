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

        MoveHandler();

        void InitiateMove(Attack& attack);

        void InitiateMove(MobilityMove& mobility);

        void InitiateMove(Shield& shield);

        void GenerateFixtures(Attack& attack);

        void VelocityChange(Attack& attack);

        void VelocityChange(MobilityMove& mobility);

        void GenerateFixtures(Shield& shield);

        void NextFrame();

        void RemoveAllFixtures();

        void ChangePlayerColor(int r, int g, int b);

        bool IsAttackInProgress() const;

        MoveType GetType() const;

        void SetPlayerBody(b2Body *playerBody);

        bool IsInvulnerable() const;

        bool IsShielding() const;


    private:

        const float kPixelPerMeterFactor = 50;

        b2Body* player_body_;

        bool is_attack_in_progress_ = false;
        bool is_invulnerable_;
        bool is_shielding_;

        int total_start_up_;
        int current_startup_;

        int total_active_frames_;
        int current_active_frame_;

        int total_end_lag_;
        int current_end_lag_;

        int move_part_interval_index_;
        int velocity_interval_index_;

        std::vector<b2Fixture*> fixtures_;

        MoveType type_;

        Attack attack_;
        MobilityMove mobility_;
        Shield shield_;


    };

} //namespace models

} //namespace antares