//
// Created by Nathaniel Smith on 11/12/20.
//

#include <iostream>
#include <fstream>
#include <utility>
#include "core/player_model.h"


namespace antares {

namespace models {

//have player model store position and attributes struct moveset struct, and image reference


void Player::GeneratePlayer(b2World &world, float pixel_per_meter_factor,
                            const std::string& json_path, std::vector<float> window_size) {

    DeserializeJson(json_path);
    SetUpMaps();
    handler_ = new MoveHandler;
    CreateBody(world, pixel_per_meter_factor, std::move(window_size));
}


void Player::SetUpMaps() {

    Defense &defense = this->character_data_.GetMoveSet().GetDefense();
    AirAttacks &air_attacks = this->character_data_.GetMoveSet().GetAirAttacks();
    GroundedNormals &grounded_normals = this->character_data_.GetMoveSet().GetGroundedNormals();
    Specials &specials = this->character_data_.GetMoveSet().GetSpecials();

    //defense map
    std::map<std::string, MobilityMove> defense_map = {
            {"2a", defense.GetRollLeft()},
            {"2d", defense.GetRollRight()},
            {"2w", defense.GetSpotDodge()},
            {"2s", defense.GetSpotDodge()},
    };

    //air attack right map
    std::map<std::string, Attack> air_attacks_map_right = {
            {"j", air_attacks.GetNeutralAir()},
            {"jd", air_attacks.GetForwardAir()},
            {"ja", air_attacks.GetBackAir()},
            {"jw", air_attacks.GetUpAir()},
            {"js", air_attacks.GetDownAir()},
    };

    //air attack left map
    std::map<std::string, Attack> air_attacks_map_left = {
            {"j", air_attacks.GetNeutralAir()},
            {"jd", air_attacks.GetBackAir()},
            {"ja", air_attacks.GetForwardAir()},
            {"jw", air_attacks.GetUpAir()},
            {"js", air_attacks.GetDownAir()},
    };

    //grounded normals tilts map
    std::map<std::string, Attack> grounded_normals_input_map_tilts = {
            {"j", grounded_normals.GetJab()},
            {"jd", grounded_normals.GetRightTilt()},
            {"ja", grounded_normals.GetLeftTilt()},
            {"jw", grounded_normals.GetUpTilt()},
            {"js", grounded_normals.GetDownTilt()},
        };

    //grounded normals strong map
    std::map<std::string, Attack> grounded_normals_input_map_strong = {
            {"j", grounded_normals.GetJab()},
            {"jd", grounded_normals.GetRightStrong()},
            {"ja", grounded_normals.GetLeftStrong()},
            {"jw", grounded_normals.GetUpStrong()},
            {"js", grounded_normals.GetDownStrong()},
        };

    //specials map
    std::map<std::string, Attack> specials_input_map = {
            {"k", specials.GetNeutralSpecial()},
            {"kd", specials.GetRightSpecial()},
            {"ka", specials.GetLeftSpecial()},
            {"ks", specials.GetDownSpecial()},
            {"kw", specials.GetUpSpecial()},
        };

    defense.SetInputMap(defense_map);
    air_attacks.SetInputMapLeft(air_attacks_map_left);
    air_attacks.SetInputMapRight(air_attacks_map_right);
    grounded_normals.SetInputMapTilts(grounded_normals_input_map_tilts);
    grounded_normals.SetInputMapStrong(grounded_normals_input_map_strong);
    specials.SetInputMap(specials_input_map);
}

void Player::DeserializeJson(const std::string& json_path) {
    std::ifstream file(json_path);
    nlohmann::json json;
    file >> json;
    this->character_data_ = json;
}


void Player::CreateBody(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size) {

    float meter_per_pixel_factor = (1.0f / pixel_per_meter_factor);

    float window_length = window_size[0];
    float window_height = window_size[1];

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(window_length / 2.0f * meter_per_pixel_factor,
                         window_height / 2.0f * meter_per_pixel_factor);

    b2Body* body = world.CreateBody(&bodyDef);
    this->player_body_ = body;

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(10.0f * meter_per_pixel_factor, 10.0f * meter_per_pixel_factor);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.0f;
    fixtureDef.restitution = 0.5;
    body->CreateFixture(&fixtureDef);
}

std::tuple<std::string, int> Player::CleanInput(std::vector<std::string> input_string,
                                                std::map<std::string, int> input_map) {

    std::tuple<std::string, int> clean_input;
    int input_interval;
    std::string full_input_string;

    for (const auto &piece : input_string) full_input_string += piece;
    std::string input;
    if (full_input_string.size() <= 1) {
        input = full_input_string;
    } else {
        input = full_input_string.substr(full_input_string.size() - 2);
    }

    std::string directions = "wasd";
    for (char let : directions) {
        if (input[0] == let) {
            std::reverse(input.begin(), input.end());
        }
    }

    if (input.size() > 1) {
        int first = input_map.find(std::string(1, input[0]))->second;
        int second = input_map.find(std::string(1, input[1]))->second;
        input_interval = abs(first - second);
    } else {
        input_interval = 0;
    }

    clean_input = std::make_tuple(input, input_interval);

    return clean_input;
}

void Player::ParseInput() {

    auto &move_set = this->character_data_.GetMoveSet();

    //input is put into standard form of command then direction e.g. jw
    std::tuple<std::string, int> cleaned_input =
            CleanInput(input_list_, input_timers_);

    std::string command = std::string(1, (std::get<0>(cleaned_input)[0]));


    if (command == "d") {
        b2Vec2 run_right = b2Vec2(10 * character_data_.GetRunSpeed(), 0);
        player_body_->SetLinearVelocity(run_right);
    } else if (command == "a") {
        b2Vec2 run_right = b2Vec2(-10 * character_data_.GetRunSpeed(), 0);
        player_body_->SetLinearVelocity(run_right);
    }

    //    std::cout << std::get<0>(cleaned_input) << std::endl;
//    std::cout << input[0];
//    switch (input[0]) {
//        case 1:
//            break;
//    }


}

Player::Player() {

}

void Player::InitiateMove(Attack &move) {

}

void Player::InitiateMove(MobilityMove &move) {

}

void Player::InitiateMove(Shield &move) {

}

b2Body *Player::GetPlayerBody() const {
    return player_body_;
}

const b2Vec2 &Player::GetPosition() const {
    return position_;
}

int Player::GetCurrentLag() const {
    return current_lag_;
}

bool Player::IsFacingRight() const {
    return is_facing_right_;
}

bool Player::IsInAir() const {
    return is_in_air_;
}

bool Player::IsShielding() const {
    return is_shielding_;
}

const CharacterData &Player::GetCharacterData() const {
    return character_data_;
}

bool Player::IsInvulnerable() const {
    return is_invulnerable;
}

void Player::SetIsFacingRight(bool isFacingRight) {
    is_facing_right_ = isFacingRight;
}

void Player::SetIsInAir(bool isInAir) {
    is_in_air_ = isInAir;
}

void Player::SetIsShielding(bool isShielding) {
    is_shielding_ = isShielding;
}

void Player::SetIsInvulnerable(bool isInvulnerable) {
    is_invulnerable = isInvulnerable;
}

void Player::SetPosition(const b2Vec2 &position) {
    position_ = position;
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