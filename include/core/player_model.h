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

struct CharacterData {

    std::string character_name;

    int fall_speed;
    int fast_fall_speed;
    int run_speed;
    int weight;

};

class Player {

public:

    void InitiateMove(Move& move);

private:

    int current_lag_;

    CharacterData character_data_;

};

} //namespace models

} //namespace antares
