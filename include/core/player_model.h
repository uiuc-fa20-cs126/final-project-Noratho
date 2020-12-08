//
// Created by Nathaniel Smith on 11/12/20.
//
#pragma once

#include <nlohmann/json.hpp>
#include <Box2D/Box2D.h>
#include <cinder/app/KeyEvent.h>
#include <tuple>

#include "move_model.h"

namespace antares {

namespace models {

class Player {

public:

    Player();

    void GeneratePlayer(b2World &world, float pixel_per_meter_factor,
                        const std::string& json_path, std::vector<float> window_size);

    void DeserializeJson(const std::string& json_path);

    void CreateBody(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size);

    void InitiateMove(Attack& move);

    void InitiateMove(MobilityMove& move);

    void InitiateMove(Shield& move);

    void ParseInput();

    std::tuple<std::string, int> CleanInput(std::vector<std::string> input_string,
                                            std::map<std::string, int> input_map);

    std::vector<std::string> input_list_;
    std::map<std::string, int> input_timers_;

    b2Body *GetPlayerBody() const;

    const b2Vec2 &GetPosition() const;

    int GetCurrentLag() const;

    bool IsFacingRight() const;

    bool IsInAir() const;

    bool IsShielding() const;

    bool IsInvulnerable() const;

    const CharacterData &GetCharacterData() const;

    void SetIsFacingRight(bool isFacingRight);

    void SetIsInAir(bool isInAir);

    void SetIsShielding(bool isShielding);

    void SetIsInvulnerable(bool isInvulnerable);

    void SetPosition(const b2Vec2 &position);

private:

    std::string current_sprite_;

    b2Vec2 position_;

    b2Body* player_body_;

    std::vector<b2CircleShape> hurt_boxes_;

    int current_lag_;

    int lives_left_;
    int shield_charge_;

    float current_damage_;

    float damage_dealt_;

    CharacterData character_data_;

    bool is_facing_right_;
    bool is_in_air_;
    bool is_shielding_;



};



} //namespace models

} //namespace antares
