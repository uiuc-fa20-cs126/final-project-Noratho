//
// Created by Nathaniel Smith on 11/12/20.
//

#include "visualizer/antares_app.h"

namespace antares {

namespace visualizer {

const std::string AntaresApp::kMapPath = "";

const ci::Color AntaresApp::kTextColor = ci::Color::black();
const ci::Color8u AntaresApp::kBackgroundColor(255, 246, 148);

antares::visualizer::AntaresApp::AntaresApp() {
    ci::app::setWindowSize((int) kWindowLength, (int) kWindowHeight);
}

void antares::visualizer::AntaresApp::draw() {
    cinder_map_.Render();
}

void antares::visualizer::AntaresApp::update() {
    cinder_map_.UpdateState();
}

void antares::visualizer::AntaresApp::setup() {
    cinder_map_.map_model_.GenerateWorld();
}

void antares::visualizer::AntaresApp::keyDown(ci::app::KeyEvent event) {
    AppBase::keyDown(event);

    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_w:
            break;
        case ci::app::KeyEvent::KEY_a:
            break;
        case ci::app::KeyEvent::KEY_s:
            break;
        case ci::app::KeyEvent::KEY_d:
            break;
        case ci::app::KeyEvent::KEY_SPACE:
            break;
        case ci::app::KeyEvent::KEY_j:
            break;
        case ci::app::KeyEvent::KEY_k:
            break;
        case ci::app::KeyEvent::KEY_l:
            break;
        case ci::app::KeyEvent::KEY_ESCAPE:
            break;
        case ci::app::KeyEvent::KEY_RETURN:
            break;
    }
}

} //namespace visualizer

} //namespace antares
