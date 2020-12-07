//
// Created by Nathaniel Smith on 11/12/20.
//

#include <cinder/gl/gl.h>
#include "visualizer/antares_app.h"
#include <algorithm>

namespace antares {

namespace visualizer {

const std::string AntaresApp::kMapPath = "";

const ci::Color AntaresApp::kTextColor = ci::Color::black();
const ci::Color8u AntaresApp::kBackgroundColor(255, 246, 148);

const int AntaresApp::kFrameInputDuration = 10;

antares::visualizer::AntaresApp::AntaresApp() {
    ci::app::setWindowSize((int) kWindowLength, (int) kWindowHeight);
}

void antares::visualizer::AntaresApp::draw() {
    ci::gl::clear(kBackgroundColor);

    cinder_map_.Render();
}

void antares::visualizer::AntaresApp::update() {
    if (input_hold_ != 0) {
        std::cout << input_hold_ << std::endl;
    }

    if (input_hold_ == 1) {
        world_model_->player_->ParseInput();
    }
    if (input_hold_ > 0) {
        input_hold_--;
    }
    cinder_map_.UpdateState();
}

void antares::visualizer::AntaresApp::setup() {
    cinder_map_.world_model_.GenerateWorld();
    cinder_map_.world_model_.player_->GeneratePlayer(kPlayerJsonPath);
    std::cout << "ok";
}

void antares::visualizer::AntaresApp::keyDown(ci::app::KeyEvent event) {
    AppBase::keyDown(event);

    //Repeat inputs are read every 5-6 frames
    switch (event.getCode()) {
        // WASD are directional keys
        case ci::app::KeyEvent::KEY_w:
            world_model_.player_->input_list_.emplace_back("w");
            world_model_.player_->input_timers_["w"] = 5;
            break;
        case ci::app::KeyEvent::KEY_a:
            world_model_.player_->input_list_.emplace_back("a");
            world_model_.player_->input_timers_["a"] = 5;
            break;
        case ci::app::KeyEvent::KEY_s:
            world_model_.player_->input_list_.emplace_back("s");
            world_model_.player_->input_timers_["s"] = 5;
            break;
        case ci::app::KeyEvent::KEY_d:
            world_model_.player_->input_list_.emplace_back("d");
            world_model_.player_->input_timers_["d"] = 5;
            break;
        // Space is jump
        case ci::app::KeyEvent::KEY_SPACE:
            world_model_.player_->input_list_.emplace_back("space");
            world_model_.player_->input_timers_["space"] = 5;
            break;
        // j is normal attacks ie tilts, air attacks and strong attacks.
        case ci::app::KeyEvent::KEY_j:
            world_model_.player_->input_list_.emplace_back("j");
            world_model_.player_->input_timers_["j"] = 5;
            break;
        // k is for specials
        case ci::app::KeyEvent::KEY_k:
            world_model_.player_->input_list_.emplace_back("k");
            world_model_.player_->input_timers_["k"] = 5;
            break;
        // l is for throws
        case ci::app::KeyEvent::KEY_l:
            world_model_.player_->input_list_.emplace_back("l");
            world_model_.player_->input_timers_["l"] = 5;
            break;
        // : is for shields
        case ci::app::KeyEvent::KEY_LSHIFT:
            world_model_.player_->input_list_.emplace_back("shift");
            world_model_.player_->input_timers_["shift"] = 5;
            break;
        case ci::app::KeyEvent::KEY_ESCAPE:
            break;
        case ci::app::KeyEvent::KEY_RETURN:
            break;
    }
}

void AntaresApp::RemoveDuplicatesHelper(const std::string& input) {

    std::vector<std::string> &input_list = world_model_->player_->input_list_;

    if (std::find(input_list.begin(), input_list.end(), input) != input_list.end()) {
        auto index = find(input_list.begin(), input_list.end(), input);
        input_list.erase(index);
        world_model_->player_->input_list_.emplace_back(input);
    } else {
        world_model_->player_->input_list_.emplace_back(input);
    }
}

void AntaresApp::UpdateInputTimers() {
//added remove inputs in input_list
    auto &player = world_model_->player_ ;
    std::vector<std::string> input_remove_list_;
    for (auto &input : player->input_timers_) {
        if (input.second == 0) {
            input_remove_list_.push_back(input.first);
        }
        input.second -= 1;
    }
    for (const std::string& input : input_remove_list_) {
        player->input_timers_.erase(input);
        //erase remove idiom
        player->input_list_.erase(std::remove(player->input_list_.begin(), player->input_list_.end(), input),
                                  player->input_list_.end());
    }

    input_remove_list_.clear();
}


} //namespace visualizer

} //namespace antares
