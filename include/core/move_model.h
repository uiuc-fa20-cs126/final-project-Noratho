//
// Created by Nathaniel Smith on 11/15/20.
//

#pragma once

#include <Box2D/Box2D.h>
#include <string>

namespace antares {

namespace models {

struct HitBox {

};

class Move {

public:

    std::string move_image_;

    HitBox hit_box_;

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