//
// Created by Nathaniel Smith on 11/15/20.
//

#pragma once

#include <nlohmann/json.hpp>

#include <Box2D/Box2D.h>
#include <string>
#include <vector>

namespace antares {

namespace models {

//I created this to hold the data for circle shapes because I didn't want to altar
//the actual class
struct b2CircleShapeDataHolder {

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(b2CircleShapeDataHolder, m_radius, x, y);

    float m_radius;
    float x;
    float y;
};

class Move {

public:

    Move(std::vector<std::string> inputs);

    Move();

    std::string move_image_;

    std::vector<int> move_part_intervals_;

    int start_up_frames_;
    int active_frames_;
    int end_lag_;

private:


};

class Attack : public Move {

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Attack, move_image_, move_part_intervals_,  start_up_frames_,
                                   active_frames_, end_lag_, hit_boxes_, is_hurt_box_, is_projectile_,
                                   damage_, knock_back_);

    Attack(std::vector<std::string> inputs);

    Attack();

private:

    std::vector<b2CircleShapeDataHolder> hit_boxes_data_;

    bool is_hurt_box_;

    bool is_projectile_;

    float damage_;
    float knock_back_;

private:

};

class MobilityMove : public Move {

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(MobilityMove, move_image_, move_part_intervals_,  start_up_frames_,
                                   active_frames_, end_lag_, has_invulnerability_,
                                   x_velocity_change_, y_velocity_change_);

    MobilityMove(std::vector<std::string> inputs);

    MobilityMove();

private:

    bool has_invulnerability_;

    float x_velocity_change_;

    float y_velocity_change_;
};


class Shield : public Move {

public:

    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Shield, move_image_, move_part_intervals_,  start_up_frames_,
                                   active_frames_, end_lag_, shield_hit_box_data_);

    Shield(std::vector<std::string> inputs);

    Shield();

private:

    b2CircleShapeDataHolder shield_hit_box_data_;

};

} //namespace models

} //namespace antares
