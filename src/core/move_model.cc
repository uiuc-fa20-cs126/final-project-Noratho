//
// Created by Nathaniel Smith on 11/15/20.
//

#include "core/move_model.h"

#include <utility>

namespace antares {

namespace models {


Move::Move(std::vector<std::string> inputs) {

}

Move::Move() {

}


Attack::Attack(std::vector<std::string> inputs) : Move(inputs){

}

Attack::Attack() {

}

const std::vector<std::vector<b2CircleShapeDataHolder>> &Attack::GetHitBoxesData() const {
    return hit_boxes_data_;
}

bool Attack::IsHurtBox() const {
    return is_hurt_box_;
}

bool Attack::IsProjectile() const {
    return is_projectile_;
}

float Attack::GetDamage() const {
    return damage_;
}

float Attack::GetKnockBack() const {
    return knock_back_;
}

const std::vector<int> &Attack::GetVelocityIntervalFrames() const {
    return velocity_interval_frames_;
}

const std::vector<float> &Attack::GetXVelocityChanges() const {
    return x_velocity_changes_;
}

const std::vector<float> &Attack::GetYVelocityChanges() const {
    return y_velocity_changes_;
}

MobilityMove::MobilityMove(std::vector<std::string> inputs) : Move(inputs){

}

MobilityMove::MobilityMove() {

}

bool MobilityMove::HasInvulnerability() const {
    return has_invulnerability_;
}

const std::vector<int> &MobilityMove::GetVelocityIntervalFrames() const {
    return velocity_interval_frames_;
}

const std::vector<float> &MobilityMove::GetXVelocityChanges() const {
    return x_velocity_changes_;
}

const std::vector<float> &MobilityMove::GetYVelocityChanges() const {
    return y_velocity_changes_;
}

Shield::Shield(std::vector<std::string> inputs) : Move(inputs) {

}

Shield::Shield() {

}

const b2CircleShapeDataHolder &Shield::GetShieldHitBoxData() const {
    return shield_hit_box_data_;
}

} //namespace models

} //namespace antares