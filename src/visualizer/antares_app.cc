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

}

void antares::visualizer::AntaresApp::draw() {
    AppBase::draw();
}

void antares::visualizer::AntaresApp::update() {
    AppBase::update();
}

void antares::visualizer::AntaresApp::setup() {
    AppBase::setup();
}

void antares::visualizer::AntaresApp::keyDown(ci::app::KeyEvent event) {
    AppBase::keyDown(event);

    switch (event.getCode()) {
        case ci::app::KeyEvent::KEY_r:
            break;
    }
}

} //namespace visualizer

} //namespace antares
