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

    struct AirAttacks {

    public:

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(AirAttacks, neutral_air, forward_air,
                back_air, up_air, down_air);

        const Attack &GetNeutralAir() const {
            return neutral_air;
        }

        const Attack &GetForwardAir() const {
            return forward_air;
        }

        const Attack &GetBackAir() const {
            return back_air;
        }

        const Attack &GetUpAir() const {
            return up_air;
        }

        const Attack &GetDownAir() const {
            return down_air;
        }

        const std::map<std::string, Attack> &GetInputMapRight() const {
            return input_map_right;
        }

        const std::map<std::string, Attack> &GetInputMapLeft() const {
            return input_map_left;
        }

        void SetInputMapRight(const std::map<std::string, Attack> &inputMapRight) {
            input_map_right = inputMapRight;
        }

        void SetInputMapLeft(const std::map<std::string, Attack> &inputMapLeft) {
            input_map_left = inputMapLeft;
        }


    private:

        std::map<std::string, Attack> input_map_right;
        std::map<std::string, Attack> input_map_left;

        Attack neutral_air;
        Attack forward_air;
        Attack back_air;
        Attack up_air;
        Attack down_air;

    };

    struct Specials {

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Specials, neutral_special, down_special,
                up_special, left_special, right_special);

        const Attack &GetNeutralSpecial() const {
            return neutral_special;
        }

        const Attack &GetLeftSpecial() const {
            return left_special;
        }

        const Attack &GetRightSpecial() const {
            return right_special;
        }

        const Attack &GetDownSpecial() const {
            return down_special;
        }

        const Attack &GetUpSpecial() const {
            return up_special;
        }

        const std::map<std::string, Attack> &GetInputMap() const {
            return input_map;
        }

        void SetInputMap(const std::map<std::string, Attack> &inputMap) {
            input_map = inputMap;
        }


    private:
        std::map<std::string, Attack> input_map;

        Attack neutral_special;
        Attack left_special;
        Attack right_special;
        Attack down_special;
        Attack up_special;

    };

    struct GroundedNormals {

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(GroundedNormals, jab, right_tilt, left_tilt, down_tilt, up_tilt,
                right_strong, left_strong, down_strong, down_strong, up_strong);

        const Attack &GetJab() const {
            return jab;
        }

        const Attack &GetRightTilt() const {
            return right_tilt;
        }

        const Attack &GetLeftTilt() const {
            return left_tilt;
        }

        const Attack &GetUpTilt() const {
            return up_tilt;
        }

        const Attack &GetDownTilt() const {
            return down_tilt;
        }

        const Attack &GetRightStrong() const {
            return right_strong;
        }

        const Attack &GetLeftStrong() const {
            return left_strong;
        }

        const Attack &GetUpStrong() const {
            return up_strong;
        }

        const Attack &GetDownStrong() const {
            return down_strong;
        }

        const std::map<std::string, Attack> &GetInputMapTilts() const {
            return input_map_tilts;
        }

        const std::map<std::string, Attack> &GetInputMapStrong() const {
            return input_map_strong;
        }

        void SetInputMapTilts(const std::map<std::string, Attack> &inputMapTilts) {
            input_map_tilts = inputMapTilts;
        }

        void SetInputMapStrong(const std::map<std::string, Attack> &inputMapStrong) {
            input_map_strong = inputMapStrong;
        }

    private:

        std::map<std::string, Attack> input_map_tilts;
        std::map<std::string, Attack> input_map_strong;

        Attack jab;
        Attack right_tilt;
        Attack left_tilt;
        Attack up_tilt;
        Attack down_tilt;

        Attack right_strong;
        Attack left_strong;
        Attack up_strong;
        Attack down_strong;

    };

    struct Defense {

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(Defense, shield, roll_left, roll_right, spot_dodge,
                air_dodge);

        const Shield &GetShield() const {
            return shield;
        }

        const MobilityMove &GetRollLeft() const {
            return roll_left;
        }

        const MobilityMove &GetRollRight() const {
            return roll_right;
        }

        const MobilityMove &GetSpotDodge() const {
            return spot_dodge;
        }

        const MobilityMove &GetAirDodge() const {
            return air_dodge;
        }

        const std::map<std::string, MobilityMove> &GetInputMap() const {
            return input_map;
        }

        void SetInputMap(const std::map<std::string, MobilityMove> &inputMap) {
            input_map = inputMap;
        }

    private:

        std::map<std::string, MobilityMove> input_map;

        Shield shield;

        MobilityMove roll_left;
        MobilityMove roll_right;
        MobilityMove spot_dodge;
        MobilityMove air_dodge;

    };


    struct MoveSet {

    public:
        NLOHMANN_DEFINE_TYPE_INTRUSIVE(MoveSet, jump, defense);
        //  grounded_normals, air_attacks, specials

        MobilityMove &GetJump() {
            return jump;
        }

        Defense &GetDefense() {
            return defense;
        }

        GroundedNormals &GetGroundedNormals() {
            return grounded_normals;
        }

        AirAttacks &GetAirAttacks() {
            return air_attacks;
        }

        Specials &GetSpecials() {
            return specials;
        }

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

        MoveSet& GetMoveSet();

        float GetFallSpeedMultiplier() const;

        float GetFastFallSpeedMultiplier() const;

        float GetRunSpeed() const;

        float GetJumpHeight() const;

        const std::vector<b2CircleShapeDataHolder> &GetHurtBoxesData() const;

    private:

        //float health;

        std::string character_name;

        float fall_speed_multiplier;

        float fast_fall_speed_multiplier;
        float run_speed;
        float jump_height;

        MoveSet move_set;

        SpriteSet sprite_set;

        std::vector<b2CircleShapeDataHolder> hurt_boxes_data;


    };


} //namespace models

} //namespace antares