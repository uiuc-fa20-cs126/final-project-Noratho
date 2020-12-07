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

struct AirAttacks {

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AirAttacks, neutral_air, forward_air,
                                   back_air, up_air, down_air);

private:

    Attack neutral_air;
    Attack forward_air;
    Attack back_air;
    Attack up_air;
    Attack down_air;

public:

    std::map<std::string, Attack> input_map_right = {
            {"j", neutral_air},
            {"jd", forward_air},
            {"ja", back_air},
            {"jw", up_air},
            {"js", down_air},
//            {"dj", forward_air},
//            {"aj", back_air},
//            {"wj", up_air},
//            {"sj", down_air},
        };


    std::map<std::string, Attack> input_map_left = {
            {"j", neutral_air},
            {"ja", forward_air},
            {"jd", back_air},
            {"jw", up_air},
            {"js", down_air},
//            {"aj", forward_air},
//            {"dj", back_air},
//            {"wj", up_air},
//            {"sj", down_air},
    };

};

struct Specials {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Specials, neutral_special, down_special,
                                   up_special, left_special, right_special);

private:

    Attack neutral_special;
    Attack left_special;
    Attack right_special;
    Attack down_special;
    Attack up_special;

public:

    std::map<std::string, Attack> input_map_strong = {
            {"k", neutral_special},
            {"kd", right_special},
            {"ka", left_special},
            {"ks", down_special},
            {"kw", up_special},
//            {"dk", forward_special},
//            {"ak", forward_special},
//            {"sk", down_special},
//            {"wk", up_special},
    };

};

struct GroundedNormals {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GroundedNormals, jab, right_tilt, left_tilt, down_tilt, up_tilt,
                                   right_strong, left_strong, down_strong, down_strong, up_strong);

private:

    Attack jab;
    Attack right_tilt;
    Attack left_tilt;
    Attack up_tilt;
    Attack down_tilt;

    Attack right_strong;
    Attack left_strong;
    Attack up_strong;
    Attack down_strong;

public:

    std::map<std::string, Attack> input_map_tilts = {
            {"j", jab},
            {"jd", right_tilt},
            {"ja", left_tilt},
            {"jw", up_tilt},
            {"js", down_tilt},
//            {"dj", forward_tilt},
//            {"aj", forward_tilt},
//            {"wj", up_tilt},
//            {"sj", down_tilt},
    };

    std::map<std::string, Attack> input_map_strong = {
            {"jd", right_strong},
            {"ja", left_strong},
            {"jw", up_strong},
            {"js", down_strong},
//            {"dj", forward_strong},
//            {"aj", forward_strong},
//            {"wj", up_strong},
//            {"sj", down_strong},
    };

};

struct Defense {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Defense, shield, roll_left, roll_right, spot_dodge,
                                   air_dodge);

private:

    Shield shield;

    MobilityMove roll_left;
    MobilityMove roll_right;
    MobilityMove spot_dodge;
    MobilityMove air_dodge;

public:

    std::map<std::string, MobilityMove> input_map = {
            {"2a", roll_left},
            {"2d", roll_right},
            {"2w", spot_dodge},
            {"2s", spot_dodge},
//            {"a2", roll_left},
//            {"d2", roll_right},
//            {"w2", spot_dodge},
//            {"s2", spot_dodge},
    };
};


struct MoveSet {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(MoveSet, jump, defense);
  //  grounded_normals, air_attacks, specials

private:

    MobilityMove jump;
    Defense defense;
    GroundedNormals grounded_normals;
    AirAttacks air_attacks;
    Specials specials;

};

struct SpriteSet {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(SpriteSet, idle, hit, out, jump, run, turn);

private:
    std::string idle;
    std::string hit;
    std::string out;

    std::string jump;
    std::string run;
    std::string turn;
};

struct CharacterData {

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(CharacterData, character_name, fall_speed_multiplier,
                                   fast_fall_speed_multiplier, run_speed, jump_height,
                                   move_set, sprite_set, hurt_boxes_data);

    CharacterData();

private:

    float health_;

    std::string character_name;

    float fall_speed_multiplier;
    float fast_fall_speed_multiplier;
    float run_speed;
    float jump_height;

    MoveSet move_set;

    SpriteSet sprite_set;

    std::vector<b2CircleShapeDataHolder> hurt_boxes_data;

};

class Player {

public:

    Player();

    void GeneratePlayer(const std::string& json_path);

    void InitiateMove(Move& move);

    void ParseInput();

    std::vector<std::string> input_list_;
    std::map<std::string, int> input_timers_;

private:

    std::string current_sprite_;

    b2Vec2 position_;

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
