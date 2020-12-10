//
// Created by Nathaniel Smith on 12/7/20.
//
#include "core/character_data_model.h"

namespace antares {

namespace models {

CharacterData::CharacterData() {

}

const std::vector<b2CircleShapeDataHolder> &CharacterData::GetHurtBoxesData() const {
    return hurt_boxes_data;
}

float CharacterData::GetRunSpeed() const {
    return run_speed;
}

float CharacterData::GetJumpHeight() const {
    return jump_height;
}

MoveSet &CharacterData::GetMoveSet() {
    return this->move_set;
}

Defense &MoveSet::GetDefense() {
    return defense;
}

GroundedNormals &MoveSet::GetGroundedNormals() {
    return grounded_normals;
}

AirAttacks &MoveSet::GetAirAttacks() {
    return air_attacks;
}

Specials &MoveSet::GetSpecials() {
    return specials;
}

const Shield &Defense::GetShield() const {
    return shield;
}

const MobilityMove &Defense::GetRollLeft() const {
    return roll_left;
}

const MobilityMove &Defense::GetRollRight() const {
    return roll_right;
}

const MobilityMove &Defense::GetSpotDodge() const {
    return spot_dodge;
}

const MobilityMove &Defense::GetAirDodge() const {
    return air_dodge;
}

const std::map<std::string, MobilityMove> &Defense::GetInputMap() const {
    return input_map;
}

void Defense::SetInputMap(const std::map<std::string, MobilityMove> &inputMap) {
    input_map = inputMap;
}

const Attack &GroundedNormals::GetJab() const {
    return jab;
}

const Attack &GroundedNormals::GetRightTilt() const {
    return right_tilt;
}

const Attack &GroundedNormals::GetLeftTilt() const {
    return left_tilt;
}

const Attack &GroundedNormals::GetUpTilt() const {
    return up_tilt;
}

const Attack &GroundedNormals::GetDownTilt() const {
    return down_tilt;
}

const Attack &GroundedNormals::GetRightStrong() const {
    return right_strong;
}

const Attack &GroundedNormals::GetLeftStrong() const {
    return left_strong;
}

const Attack &GroundedNormals::GetUpStrong() const {
    return up_strong;
}

const Attack &GroundedNormals::GroundedNormals::GetDownStrong() const {
    return down_strong;
}

const std::map<std::string, Attack> &GroundedNormals::GetInputMapTilts() const {
    return input_map_tilts;
}

const std::map<std::string, Attack> &GroundedNormals::GetInputMapStrong() const {
    return input_map_strong;
}

void GroundedNormals::SetInputMapTilts(const std::map<std::string, Attack> &inputMapTilts) {
    input_map_tilts = inputMapTilts;
}

void GroundedNormals::SetInputMapStrong(const std::map<std::string, Attack> &inputMapStrong) {
    input_map_strong = inputMapStrong;
}

const Attack &Specials::GetNeutralSpecial() const {
    return neutral_special;
}

const Attack &Specials::GetLeftSpecial() const {
    return left_special;
}

const Attack &Specials::GetRightSpecial() const {
    return right_special;
}

const Attack &Specials::GetDownSpecial() const {
    return down_special;
}

const Attack &Specials::GetUpSpecial() const {
    return up_special;
}

const std::map<std::string, Attack> &Specials::GetInputMap() const {
    return input_map;
}

void Specials::SetInputMap(const std::map<std::string, Attack> &inputMap) {
    input_map = inputMap;
}

const Attack &AirAttacks::GetNeutralAir() const {
    return neutral_air;
}

const Attack &AirAttacks::GetForwardAir() const {
    return forward_air;
}

const Attack &AirAttacks::GetBackAir() const {
    return back_air;
}

const Attack &AirAttacks::GetUpAir() const {
    return up_air;
}

const Attack &AirAttacks::GetDownAir() const {
    return down_air;
}

const std::map<std::string, Attack> &AirAttacks::GetInputMapRight() const {
    return input_map_right;
}

const std::map<std::string, Attack> &AirAttacks::GetInputMapLeft() const {
    return input_map_left;
}

void AirAttacks::SetInputMapRight(const std::map<std::string, Attack> &inputMapRight) {
    input_map_right = inputMapRight;
}

void AirAttacks::SetInputMapLeft(const std::map<std::string, Attack> &inputMapLeft) {
    input_map_left = inputMapLeft;
}

} //namespace models

} //namespace antares