//
// Created by Nathaniel Smith on 12/7/20.
//

#include "core/move_handler.h"


namespace antares {

namespace models {

MoveHandler::MoveHandler() {

}

void MoveHandler::InitiateMove(Attack &attack) {
    is_attack_in_progress_ = true;
    type_ = MoveType::AttackType;
    attack_ = attack;

    total_start_up_ = attack.start_up_frames_;
    total_active_frames_ = attack.active_frames_;
    total_end_lag_ = attack.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
    velocity_interval_index_ = 0;
}

void MoveHandler::InitiateMove(MobilityMove &mobility) {
    is_attack_in_progress_ = true;
    type_ = MoveType::MobilityType;
    mobility_ = mobility;

    total_start_up_ = mobility.start_up_frames_;
    total_active_frames_ = mobility.active_frames_;
    total_end_lag_ = mobility.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
    velocity_interval_index_ = 0;
}

void MoveHandler::InitiateMove(Shield &shield) {
    is_attack_in_progress_ = true;
    type_ = MoveType::ShieldType;
    shield_ = shield;

    total_start_up_ = shield.start_up_frames_;
    total_active_frames_ = shield.active_frames_;
    total_end_lag_ = shield.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
}

void MoveHandler::NextFrame() {


    if (current_startup_ != total_start_up_) {
        current_startup_++;
        return;
    }
    if (current_active_frame_ != total_active_frames_) {
        if (type_ == MoveType::AttackType) {
            Attack *attack = attack_;

        } else if (type_ == MoveType::MobilityType) {
            MobilityMove *move = mobility_;

        } else if (type_ == MoveType::ShieldType) {
            Shield *move = shield_;

        }
        current_active_frame_++;
    }

    if (current_end_lag_ != total_end_lag_) {
        current_end_lag_++;
        return;
    }
}


void MoveHandler::ChangePlayerColor(int r, int g, int b) {
    auto *rgb = new std::vector<int>;
    rgb->push_back(r);
    rgb->push_back(g);
    rgb->push_back(b);

    for (b2Fixture *fixture = player_body_->GetFixtureList();
         fixture; fixture = fixture->GetNext()) {
        fixture->SetUserData(rgb);
    }
}

void MoveHandler::RemoveAllFixtures() {
    for (auto fixture : fixtures_) {
        player_body_->DestroyFixture(fixture);
    }
    fixtures_.clear();
}

bool MoveHandler::IsAttackInProgress() const {
    return is_attack_in_progress_;
}

void MoveHandler::SetIsAttackInProgress(bool isAttackInProgress) {
    is_attack_in_progress_ = isAttackInProgress;
}

MoveType MoveHandler::GetType() const {
    return type_;
}

void MoveHandler::SetType(MoveType type) {
    type_ = type;
}

void MoveHandler::SetPlayerBody(b2Body *playerBody) {
    player_body_ = playerBody;
}

} //namespace models

} //namespace antares