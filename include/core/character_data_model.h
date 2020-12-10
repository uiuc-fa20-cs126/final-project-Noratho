//
// Created by Nathaniel Smith on 12/7/20.
//

#pragma once

#include <nlohmann/json.hpp>
#include <Box2D/Box2D.h>
#include <cinder/app/KeyEvent.h>
#include <tuple>

#include "move_model.h"

namespace antares {

namespace models {

/**
* AirAttacks struct
* Stores data regarding air attacks
*/
    struct AirAttacks {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AirAttacks, neutral_air, forward_air,
                back_air, up_air, down_air);

        /**Getters and Setters*/
        const Attack &GetNeutralAir() const;

        const Attack &GetForwardAir() const;

        const Attack &GetBackAir() const;

        const Attack &GetUpAir() const;

        const Attack &GetDownAir() const;

        const std::map<std::string, Attack> &GetInputMapRight() const;

        const std::map<std::string, Attack> &GetInputMapLeft() const;

        void SetInputMapRight(const std::map<std::string, Attack> &inputMapRight);

        void SetInputMapLeft(const std::map<std::string, Attack> &inputMapLeft);

    private:

        /**A map of inputs to right*/
        std::map<std::string, Attack> input_map_right;
        /**A map of inputs to left*/
        std::map<std::string, Attack> input_map_left;

        /**Neutral Air Attack*/
        Attack neutral_air;
        /**forward Air Attack*/
        Attack forward_air;
        /**back Air Attack*/
        Attack back_air;
        /**up Air Attack*/
        Attack up_air;
        /**down Air Attack*/
        Attack down_air;

    };

/**
* Specials struct
* Stores data regarding special moves
*/
    struct Specials {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Specials, neutral_special, down_special,
                up_special, left_special, right_special);

        /**Getters and Setters*/
        const Attack &GetNeutralSpecial() const;

        const Attack &GetLeftSpecial() const;

        const Attack &GetRightSpecial() const;

        const Attack &GetDownSpecial() const;

        const Attack &GetUpSpecial() const;

        const std::map<std::string, Attack> &GetInputMap() const;

        void SetInputMap(const std::map<std::string, Attack> &inputMap);

    private:
        /**A map of inputs*/
        std::map<std::string, Attack> input_map;

        /**neutral special Attack*/
        Attack neutral_special;
        /**left special Attack*/
        Attack left_special;
        /**right special Attack*/
        Attack right_special;
        /**down special Attack*/
        Attack down_special;
        /**up special Attack*/
        Attack up_special;

    };

/**
* GroundedNormals struct
* Stores data regarding grounded normal moves
*/
    struct GroundedNormals {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(GroundedNormals, jab, right_tilt, left_tilt, down_tilt, up_tilt,
                right_strong, left_strong, down_strong, down_strong, up_strong);

        /**Getters and Setters*/
        const Attack &GetJab() const;

        const Attack &GetRightTilt() const;

        const Attack &GetLeftTilt() const;

        const Attack &GetUpTilt() const;

        const Attack &GetDownTilt() const;

        const Attack &GetRightStrong() const;

        const Attack &GetLeftStrong() const;

        const Attack &GetUpStrong() const;

        const Attack &GetDownStrong() const;

        const std::map<std::string, Attack> &GetInputMapTilts() const;

        const std::map<std::string, Attack> &GetInputMapStrong() const;

        void SetInputMapTilts(const std::map<std::string, Attack> &inputMapTilts);

        void SetInputMapStrong(const std::map<std::string, Attack> &inputMapStrong);

    private:

        /**A map of inputs for tilts attacks*/
        std::map<std::string, Attack> input_map_tilts;
        /**A map of inputs for strong attacks*/
        std::map<std::string, Attack> input_map_strong;

        /**jab attack*/
        Attack jab;
        /**right tilt attack*/
        Attack right_tilt;
        /**left tilt attack*/
        Attack left_tilt;
        /**up tilt attack*/
        Attack up_tilt;
        /**down tilt attack*/
        Attack down_tilt;

        /**right strong attack*/
        Attack right_strong;
        /**left strong attack*/
        Attack left_strong;
        /**up strong attack*/
        Attack up_strong;
        /**down strong attack*/
        Attack down_strong;

    };

/**
* Defense struct
* Stores data regarding defensive moves
*/
    struct Defense {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Defense, shield, roll_left, roll_right, spot_dodge,
                air_dodge);

        /**Getters and Setters*/
        const Shield &GetShield() const;

        const MobilityMove &GetRollLeft() const;

        const MobilityMove &GetRollRight() const;

        const MobilityMove &GetSpotDodge() const;

        const MobilityMove &GetAirDodge() const;

        const std::map<std::string, MobilityMove> &GetInputMap() const;

        void SetInputMap(const std::map<std::string, MobilityMove> &inputMap);

    private:

        /**An input map for defensive moves*/
        std::map<std::string, MobilityMove> input_map;

        /**Shield mobility move*/
        Shield shield;

        /**roll right mobility move*/
        MobilityMove roll_left;
        /**roll left mobility move*/
        MobilityMove roll_right;
        /**spot dodge mobility move*/
        MobilityMove spot_dodge;
        /**air dodge mobility move*/
        MobilityMove air_dodge;

    };

/**
* MoveSet struct
* Holds all the data for a character move set
*/
    struct MoveSet {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MoveSet, jump, defense, grounded_normals, specials, air_attacks);

        /**Getters and Setters*/
        Defense &GetDefense();

        GroundedNormals &GetGroundedNormals();

        AirAttacks &GetAirAttacks();

        Specials &GetSpecials();

    private:
        /**Jump Mobility Move*/
        MobilityMove jump;
        /**Field to hold defense moves*/
        Defense defense;
        /**Field to hold grounded normals*/
        GroundedNormals grounded_normals;
        /**Field to hold air attacks*/
        AirAttacks air_attacks;
        /**Field to hold specials*/
        Specials specials;

    };

/**
* SpriteSet struct
* Holds all the data for a different sprites(unimplemented)
*/
    struct SpriteSet {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(SpriteSet, idle, hit, out, jump, run, turn);

    private:
        /**idle sprite path*/
        std::string idle;
        /**hit sprite path*/
        std::string hit;
        /**death sprite path*/
        std::string out;

        /**jump sprite path*/
        std::string jump;
        /**run sprite path*/
        std::string run;
        /**turn sprite path*/
        std::string turn;
    };

/**
* CharacterData struct
* Holds all the data for a character
*/
    struct CharacterData {

    public:
        /**Json macro*/
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(CharacterData, character_name, fall_speed_multiplier,
                                       fast_fall_speed_multiplier, run_speed, jump_height,
                                       move_set, sprite_set, hurt_boxes_data);

        /**Constructor's hurt box*/
        CharacterData();

        /**Getters and Setters*/
        MoveSet& GetMoveSet();

        float GetRunSpeed() const;

        float GetJumpHeight() const;

        const std::vector<b2CircleShapeDataHolder> &GetHurtBoxesData() const;

    private:

        /**character's name*/
        std::string character_name;

        /**the rate a character falls(unimplemented)*/
        float fall_speed_multiplier;
        /**The speed a character goes down when fast falling(unimplemented)*/
        float fast_fall_speed_multiplier;

        /**multiplier for character run speed*/
        float run_speed;
        /**height a character can jump*/
        float jump_height;

        /**character's move set*/
        MoveSet move_set;

        /**character's sprite set*/
        SpriteSet sprite_set;

        /**character's hurt box*/
        std::vector<b2CircleShapeDataHolder> hurt_boxes_data;

    };

} //namespace models

} //namespace antares