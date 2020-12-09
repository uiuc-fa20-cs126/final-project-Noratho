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

/**
 * b2CircleShapeDataHolder Struct
 * Holds data for the circle shapes from box2D
 * I created this to hold the data for circle shapes because I didn't want to altar
 * the actual class for the json macro
*/
struct b2CircleShapeDataHolder {

    /**Json Macro*/
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(b2CircleShapeDataHolder, m_radius, x, y, r, g, b);

    /**circle radius*/
    float m_radius;
    /**circle x position*/
    float x;
    /**circle y position*/
    float y;

    /**Color R value*/
    int r;
    /**Color G value*/
    int g;
    /**Color BR value*/
    int b;
};

/**
 * Move Class
 * The parent class for all of the actual used classes
*/
class Move {

public:

    /**Default constructor*/
    Move();

    //Json parsing breaks when I encapsulate these and I don't have enough time to fix it

    /**Move image path(Unimplemented)*/
    std::string move_image_;

    /**The intervals for the move*/
    std::vector<int> move_part_intervals_;

    /**Amount of start up frames*/
    int start_up_frames_;
    /**Amount of active frames*/
    int active_frames_;
    /**Amount of end lag frames*/
    int end_lag_;
};

/**
 * Attack Class inherits from Move
 * The class to model attacks
*/
class Attack : public Move {

public:

    /**Json Macro*/
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Attack, move_image_, move_part_intervals_, start_up_frames_,
                                   active_frames_, end_lag_, hit_boxes_data_, is_hurt_box_, is_projectile_,
                                   damage_, knock_back_, velocity_interval_frames_, x_velocity_changes_, y_velocity_changes_);

    /**Default constructor*/
    Attack();

    /**Getters and setters*/
    const std::vector<std::vector<b2CircleShapeDataHolder>> &GetHitBoxesData() const;

    const std::vector<int> &GetVelocityIntervalFrames() const;

    const std::vector<float> &GetXVelocityChanges() const;

    const std::vector<float> &GetYVelocityChanges() const;

private:

    /**A vector of a vectors that hold the hitboxes*/
    std::vector<std::vector<b2CircleShapeDataHolder>> hit_boxes_data_;

    /**Shows whether a move hitbox getting hit will damage player.
     * Think hitting a punch while its happening */
    bool is_hurt_box_;
    /**Shows whether a move is a projectile or not*/
    bool is_projectile_;

    /**Amount of damage a move does*/
    float damage_;
    /**How much knock back a move has*/
    float knock_back_;

    /**A vector of what frames the velocity changes*/
    std::vector<int> velocity_interval_frames_;
    /**A vector of what the x velocity changes are*/
    std::vector<float> x_velocity_changes_;
    /**A vector of what the y velocity changes are*/
    std::vector<float> y_velocity_changes_;

};

/**
 * MobilityMove Class inherits from Move
 * The class to model Mobility Moves
*/
class MobilityMove : public Move {

public:

    /**Json Macro*/
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(MobilityMove, move_image_, move_part_intervals_, start_up_frames_,
                                   active_frames_, end_lag_, has_invulnerability_,
                                   velocity_interval_frames_, x_velocity_changes_, y_velocity_changes_)

    /**Default constructor*/
    MobilityMove();

    /**Getters and setters*/
    const std::vector<int> &GetVelocityIntervalFrames() const;

    const std::vector<float> &GetXVelocityChanges() const;

    const std::vector<float> &GetYVelocityChanges() const;

private:

    /**Shows whether a move gives the player invulnerability during the active frames*/
    bool has_invulnerability_;

    /**A vector of what frames the velocity changes*/
    std::vector<int> velocity_interval_frames_;
    /**A vector of what the x velocity changes are*/
    std::vector<float> x_velocity_changes_;
    /**A vector of what the y velocity changes are*/
    std::vector<float> y_velocity_changes_;

};


/**
 * Shield Class inherits from Move
 * The class to model Shielding
*/
class Shield : public Move {

public:

    /**Json Macro*/
    NLOHMANN_DEFINE_TYPE_INTRUSIVE(Shield, move_image_, move_part_intervals_,  start_up_frames_,
                                   active_frames_, end_lag_, shield_hit_box_data_);

    /**Default constructor*/
    Shield();

    /**Getters and setters*/
    const b2CircleShapeDataHolder &GetShieldHitBoxData() const;

private:

    /**The data for the shield shape*/
    b2CircleShapeDataHolder shield_hit_box_data_;

};

} //namespace models

} //namespace antares
