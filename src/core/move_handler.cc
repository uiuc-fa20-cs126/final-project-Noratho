//
// Created by Nathaniel Smith on 12/7/20.
//

#include "core/move_handler.h"


namespace antares {

namespace models {

MoveHandler::MoveHandler() {

}

void MoveHandler::InitiateMove(Attack &move) {
    is_attack_in_progress_ = true;
    type_ = MoveType::AttackType;
    attack_ = &move;

    total_start_up_ = move.start_up_frames_;
    total_active_frames_ = move.active_frames_;
    total_end_lag_ = move.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    interval_index = 0;
}

void MoveHandler::InitiateMove(MobilityMove &move) {
    is_attack_in_progress_ = true;
    type_ = MoveType::MobilityType;
    mobility_ = &move;

    total_start_up_ = move.start_up_frames_;
    total_active_frames_ = move.active_frames_;
    total_end_lag_ = move.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    interval_index = 0;
}

void MoveHandler::InitiateMove(Shield &move) {
    is_attack_in_progress_ = true;
    type_ = MoveType::ShieldType;
    shield_ = &move;

    total_start_up_ = move.start_up_frames_;
    total_active_frames_ = move.active_frames_;
    total_end_lag_ = move.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    interval_index = 0;
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