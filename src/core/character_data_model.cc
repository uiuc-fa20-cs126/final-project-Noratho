//
// Created by Nathaniel Smith on 12/7/20.
//
#include "core/character_data_model.h"

namespace antares {

namespace models {

    CharacterData::CharacterData() {

    }

    const std::vector<b2CircleShapeDataHolder> &CharacterData::GetHurtBoxesData() const {
        return hurt_boxes_data;
    }

    float CharacterData::GetFallSpeedMultiplier() const {
        return fall_speed_multiplier;
    }

    float CharacterData::GetFastFallSpeedMultiplier() const {
        return fast_fall_speed_multiplier;
    }

    float CharacterData::GetRunSpeed() const {
        return run_speed;
    }

    float CharacterData::GetJumpHeight() const {
        return jump_height;
    }

    MoveSet &CharacterData::GetMoveSet() {
        return this->move_set;
    }

} //namespace models

} //namespace antares