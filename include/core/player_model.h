//
// Created by Nathaniel Smith on 11/12/20.
//
#pragma once

#include <nlohmann/json.hpp>

#include <Box2D/Box2D.h>

#include "move_model.h"

namespace antares {

namespace models {

struct MoveSet {



};

struct SpriteSet {

    std::string idle;
    std::string hit;
    std::string out;

    std::string jump;
    std::string run;
    std::string turn;
};

struct CharacterData {

    std::string character_name;

    int fall_speed;
    int fast_fall_speed;
    int run_speed;
    int weight;

    MoveSet move_set;

    SpriteSet character_set;

    std::vector<b2CircleShape> hurt_boxes;

    //add class template to allow for unique interactions for kits, think cloud limit and resource characters

};

class Player {

public:

    void InitiateMove(Move& move);

private:

    int current_lag_;

    float current_damage_;

    float damage_dealt_;

    CharacterData character_data_;

};

} //namespace models

} //namespace antares
