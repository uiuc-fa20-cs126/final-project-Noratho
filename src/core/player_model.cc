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
    CreateBody(world, pixel_per_meter_factor, std::move(window_size));
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