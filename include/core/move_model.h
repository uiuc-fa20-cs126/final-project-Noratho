//
// Created by Nathaniel Smith on 11/15/20.
//

#pragma once

#include <Box2D/Box2D.h>
#include <string>
#include <vector>

namespace antares {

namespace models {

struct AttackHitBoxes {

    std::string name;

    std::vector<b2CircleShape> hit_boxes;

};

class Move {

public:

    //add an interval between attacks think linguini dash attack

    std::string move_image_;

    std::vector<int> attack_intervals_;

    std::vector<AttackHitBoxes> hit_boxes_;

private:


};

class Attack : public Move {

public:

    bool is_hurt_box_;

    float damage_;

    float knock_back_;

private:

};

    class NonAttack : public Move {

    public:

    private:

};



} //namespace models

} //namespace antares