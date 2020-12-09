//
// Created by Nathaniel Smith on 11/12/20.
//
#pragma once

#include <nlohmann/json.hpp>
#include <Box2D/Box2D.h>
#include <cinder/app/KeyEvent.h>

#include "move_model.h"

namespace antares {

namespace models {

struct AirAttacks {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(AirAttacks, neutral_air, forward_air,
                                   back_air, up_air, down_air);

private:
    std::vector<std::string> neutral_air_input{"j"};
    std::vector<std::string> forward_air_inputs{"jd", "dj", "ja", "aj"};
    std::vector<std::string> back_air_inputs{"jd", "dj", "ja", "aj"};
    std::vector<std::string> up_air_inputs{"jw", "wj"};
    std::vector<std::string> down_air_inputs{"js", "sj"};

    Attack neutral_air = Attack(neutral_air_input);
    Attack forward_air = Attack(forward_air_inputs);
    Attack back_air = Attack(back_air_inputs);
    Attack up_air = Attack(up_air_inputs);
    Attack down_air = Attack(down_air_inputs);

};

struct Specials {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Specials, neutral_special, down_special,
                                   up_special, forward_special);

private:
    std::vector<std::string> neutral_special_input{"k"};
    std::vector<std::string> forward_special_inputs{"kd", "dk", "ka", "ak"};
    std::vector<std::string> down_special_inputs{"ks", "sk"};
    std::vector<std::string> up_special_inputs{"kw", "wk"};

    Attack neutral_special = Attack(neutral_special_input);
    Attack down_special = Attack(forward_special_inputs);
    Attack up_special = Attack(down_special_inputs);
    Attack forward_special = Attack(up_special_inputs);

};

struct GroundedNormals {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(GroundedNormals, jab, forward_tilt, down_tilt, up_tilt,
                                   forward_strong, down_strong, down_strong, up_strong);

private:
    std::vector<std::string> jap_input{"j"};
    std::vector<std::string> forward_tilt_inputs{"jd", "dj", "ja", "aj"};
    std::vector<std::string> up_tilt_inputs{"jw", "wj"};
    std::vector<std::string> down_tilt_inputs{"js", "sj"};

    std::vector<std::string> forward_strong_inputs{"jd", "dj", "ja", "aj"};
    std::vector<std::string> up_strong_inputs{"jw", "wj"};
    std::vector<std::string> down_strong_inputs{"js", "sj"};

    Attack jab = Attack(jap_input);
    Attack forward_tilt = Attack(forward_tilt_inputs);
    Attack down_tilt = Attack(up_tilt_inputs);
    Attack up_tilt = Attack(down_tilt_inputs);

    Attack forward_strong = Attack(forward_strong_inputs);
    Attack down_strong = Attack(up_strong_inputs);
    Attack up_strong = Attack(down_strong_inputs);

};

struct Defense {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Defense, shield, roll_left, roll_right, spot_dodge,
                                   air_dodge);

private:
    std::vector<std::string> shield_input{"shift"};
    std::vector<std::string> roll_left_inputs{"ashift", "shifta"};
    std::vector<std::string> roll_right_inputs{"shiftd", "dshift"};
    std::vector<std::string> spot_dodge_inputs{"shiftw", "wshift", "dshift", "shiftd"};
    std::vector<std::string> air_dodge_input{"shift"};

    Shield shield = Shield(shield_input);

    MobilityMove roll_left = MobilityMove(roll_left_inputs);
    MobilityMove roll_right = MobilityMove(roll_right_inputs);
    MobilityMove spot_dodge = MobilityMove(spot_dodge_inputs);
    MobilityMove air_dodge = MobilityMove(air_dodge_input);

};


struct MoveSet {

public:
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(MoveSet, jump, defense);
  //  grounded_normals, air_attacks, specials

private:
    std::vector<std::string> jump_input{"space"};

    MobilityMove jump = MobilityMove(jump_input);
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

    std::vector<b2CircleShape> hurt_boxes;

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
