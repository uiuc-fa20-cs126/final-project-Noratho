//
// Created by Nathaniel Smith on 11/12/20.
//

#include <fstream>
#include <iostream>
#include "core/player_model.h"


namespace antares {

namespace models {

//have player model store position and attributes struct moveset struct, and image reference

void Player::ParseInput() {


}

void Player::GeneratePlayer(const std::string& json_path) {
    std::ifstream file(json_path);
    nlohmann::json json;
    if (file.is_open()) {
        std::cout << "good";
    }
    file >> json;
    this->character_data_ = json;

    std::cout << "test";
}

Player::Player() {

}

void Player::InitiateMove(Move &move) {

}


CharacterData::CharacterData() {

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

} //namespace models

} //namespace antares