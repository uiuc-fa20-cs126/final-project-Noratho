//
// Created by Nathaniel Smith on 11/15/20.
//

#include "core/move_model.h"

namespace antares {

namespace models {

Move::Move() {

}

Attack::Attack() {

}

Shield::Shield() {

}

MobilityMove::MobilityMove() {

}

const std::vector<std::vector<b2CircleShapeDataHolder>> &Attack::GetHitBoxesData() const {
    return hit_boxes_data_;
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

const std::vector<int> &MobilityMove::GetVelocityIntervalFrames() const {
    return velocity_interval_frames_;
}

const std::vector<float> &MobilityMove::GetXVelocityChanges() const {
    return x_velocity_changes_;
}

const std::vector<float> &MobilityMove::GetYVelocityChanges() const {
    return y_velocity_changes_;
}

const b2CircleShapeDataHolder &Shield::GetShieldHitBoxData() const {
    return shield_hit_box_data_;
}

} //namespace models

} //namespace antares
