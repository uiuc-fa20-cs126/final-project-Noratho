//
// Created by Nathaniel Smith on 11/15/20.
//

#include "core/move_model.h"

#include <utility>

namespace antares {

namespace models {


Move::Move(std::vector<std::string> inputs) {

}

Move::Move() {

}


Attack::Attack(std::vector<std::string> inputs) : Move(inputs){

}

Attack::Attack() {

}

MobilityMove::MobilityMove(std::vector<std::string> inputs) : Move(inputs){

}

MobilityMove::MobilityMove() {

}

Shield::Shield(std::vector<std::string> inputs) : Move(inputs) {

}

Shield::Shield() {

}

} //namespace models

} //namespace antares