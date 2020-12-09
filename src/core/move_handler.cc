//
// Created by Nathaniel Smith on 12/7/20.
//

#include "core/move_handler.h"


namespace antares {

namespace models {

MoveHandler::MoveHandler() {

}

void MoveHandler::InitiateMove(Attack &attack) {
    is_attack_in_progress_ = true;
    type_ = MoveType::AttackType;
    attack_ = attack;

    total_start_up_ = attack.start_up_frames_;
    total_active_frames_ = attack.active_frames_;
    total_end_lag_ = attack.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
    velocity_interval_index_ = 0;
}

void MoveHandler::InitiateMove(MobilityMove &mobility) {
    is_attack_in_progress_ = true;
    type_ = MoveType::MobilityType;
    mobility_ = mobility;

    total_start_up_ = mobility.start_up_frames_;
    total_active_frames_ = mobility.active_frames_;
    total_end_lag_ = mobility.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
    velocity_interval_index_ = 0;
}

void MoveHandler::InitiateMove(Shield &shield) {
    is_attack_in_progress_ = true;
    type_ = MoveType::ShieldType;
    shield_ = shield;

    total_start_up_ = shield.start_up_frames_;
    total_active_frames_ = shield.active_frames_;
    total_end_lag_ = shield.end_lag_;

    current_startup_ = 0;
    current_active_frame_ = 0;
    current_end_lag_ = 0;
    move_part_interval_index_ = 0;
}


void MoveHandler::GenerateFixtures(Attack &attack) {

    float meter_per_pixel_factor = (1.0f / kPixelPerMeterFactor);

   for (auto data : attack.GetHitBoxesData()) {
       b2Vec2 pos(data.x  * meter_per_pixel_factor,
                  data.y  * meter_per_pixel_factor);

       b2CircleShape circle;
       circle.m_p = pos;
       circle.m_radius = data.m_radius * meter_per_pixel_factor;

       b2FixtureDef fixture_circle_def;
       fixture_circle_def.shape = &circle;
       fixture_circle_def.density = 0.0f;
       fixture_circle_def.friction = 0.0f;

       //Set Hitbox Color
       auto *rgb = new std::vector<int>;
       rgb->push_back(data.r);
       rgb->push_back(data.g);
       rgb->push_back(data.b);
       fixture_circle_def.userData = rgb;

       //Set Collision filter
       fixture_circle_def.filter.maskBits = 0x0000;

       player_body_->CreateFixture(&fixture_circle_def);
       fixtures_.push_back(player_body_->GetFixtureList());
   }


}

void MoveHandler::VelocityChange(Attack &attack) {

    if (attack.GetVelocityIntervalFrames().size() > velocity_interval_index_) {
        if (current_active_frame_ ==
            attack.GetVelocityIntervalFrames()[velocity_interval_index_]) {

            b2Vec2 velocity(attack.GetXVelocityChanges()[velocity_interval_index_],
                            attack.GetYVelocityChanges()[velocity_interval_index_]);
            player_body_->SetLinearVelocity(velocity);
            velocity_interval_index_++;
        }
    }
}

void MoveHandler::VelocityChange(MobilityMove &mobility) {

    ChangePlayerColor(1, 1, 1);
    if (mobility.GetVelocityIntervalFrames().size() > velocity_interval_index_) {
        if (current_active_frame_ ==
            mobility.GetVelocityIntervalFrames()[velocity_interval_index_]) {

            b2Vec2 velocity(mobility.GetXVelocityChanges()[velocity_interval_index_],
                            mobility.GetYVelocityChanges()[velocity_interval_index_]);
            player_body_->SetLinearVelocity(velocity);
            velocity_interval_index_++;
        }
    }
}

void MoveHandler::GenerateFixtures(Shield &shield) {

    auto data = shield.GetShieldHitBoxData();
    float meter_per_pixel_factor = (1.0f / kPixelPerMeterFactor);

    b2Vec2 pos(data.x  * meter_per_pixel_factor,
                   data.y  * meter_per_pixel_factor);

    b2CircleShape circle;
    circle.m_p = pos;
    circle.m_radius = data.m_radius * meter_per_pixel_factor;

    b2FixtureDef fixture_circle_def;
    fixture_circle_def.shape = &circle;
    fixture_circle_def.density = 0.0f;
    fixture_circle_def.friction = 0.0f;

    //Set Hitbox Color
    auto *rgb = new std::vector<int>;
    rgb->push_back(data.r);
    rgb->push_back(data.g);
    rgb->push_back(data.b);
    fixture_circle_def.userData = rgb;

    //Set Collision filter
    fixture_circle_def.filter.maskBits = 0x0000;

    player_body_->CreateFixture(&fixture_circle_def);
    fixtures_.push_back(player_body_->GetFixtureList());
    }

void MoveHandler::NextFrame() {

    if (current_startup_ != total_start_up_) {
        current_startup_++;
        return;
    }
    if (current_active_frame_ != total_active_frames_) {
        if (type_ == MoveType::AttackType) {
            Attack *attack = attack_;

        } else if (type_ == MoveType::MobilityType) {
            MobilityMove *move = mobility_;

        } else if (type_ == MoveType::ShieldType) {
            Shield *move = shield_;

        }
        current_active_frame_++;
    }

    if (current_end_lag_ != total_end_lag_) {
        current_end_lag_++;
        return;
    }
}


void MoveHandler::ChangePlayerColor(int r, int g, int b) {
    auto *rgb = new std::vector<int>;
    rgb->push_back(r);
    rgb->push_back(g);
    rgb->push_back(b);

    for (b2Fixture *fixture = player_body_->GetFixtureList();
         fixture; fixture = fixture->GetNext()) {
        fixture->SetUserData(rgb);
    }
}

void MoveHandler::RemoveAllFixtures() {
    for (auto fixture : fixtures_) {
        player_body_->DestroyFixture(fixture);
    }
    fixtures_.clear();
}

bool MoveHandler::IsAttackInProgress() const {
    return is_attack_in_progress_;
}

MoveType MoveHandler::GetType() const {
    return type_;
}

void MoveHandler::SetPlayerBody(b2Body *playerBody) {
    player_body_ = playerBody;
}

bool MoveHandler::IsInvulnerable() const {
    return is_invulnerable_;
}

bool MoveHandler::IsShielding() const {
    return is_shielding_;
}


} //namespace models

} //namespace antares