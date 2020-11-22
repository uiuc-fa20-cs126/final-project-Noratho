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

    std::string move_image_;

    std::vector<int> move_part_intervals_;

    int start_up_frames_;
    int active_frames_;
    int end_lag_;

private:


};

class Attack : public Move {

public:

    std::vector<AttackHitBoxes> hit_boxes_;

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