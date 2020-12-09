//
// Created by Nathaniel Smith on 11/15/20.
//

#include "core/move_model.h"

#include <utility>

namespace antares {

namespace models {


Move::Move(std::vector<std::string> inputs) {
    this->possible_inputs_ = std::move(inputs);
}

Move::Move() {

}


Attack::Attack(std::vector<std::string> inputs) : Move(inputs){
    this->possible_inputs_ = std::move(inputs);
}

Attack::Attack() {

}

MobilityMove::MobilityMove(std::vector<std::string> inputs) : Move(inputs){
    this->possible_inputs_ = std::move(inputs);
}

MobilityMove::MobilityMove() {

}

Throw::Throw(std::vector<std::string> inputs) : Move(inputs) {

}

Throw::Throw() {

}

Shield::Shield(std::vector<std::string> inputs) : Move(inputs) {

}

Shield::Shield() {

}

} //namespace models

} //namespace antares