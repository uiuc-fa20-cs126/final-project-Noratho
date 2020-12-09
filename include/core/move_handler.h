//
// Created by Nathaniel Smith on 12/7/20.
//

#pragma once

#include "move_model.h"

namespace antares {

namespace models {

    /**
     * Enum to differentiate move types
    */
    enum MoveType {
        AttackType,
        MobilityType,
        ShieldType,
    };

/**
 * MoveHandler Class
 * When given a move to initiate it handles the body generation and
 * frame counting
*/
    class MoveHandler {

    public:

        /**
        * Default constructor
        */
        MoveHandler();

        /**
         * Method that sets all of the values in the move handler object to start the process
         * @param attack the attack to start doing
        */
        void InitiateMove(Attack& attack);

        /**
         * Method that sets all of the values in the move handler object to start the process
         * @param mobility the mobility to start doing
        */
        void InitiateMove(MobilityMove& mobility);

        /**
        * Method that sets all of the values in the move handler object to start the process
        * @param shield the shield to start doing
        */
        void InitiateMove(Shield& shield);

        /**Resets the state of the iterated handler values*/
        void ResetHandler();

        /**
         * Method that generates all of the hitbox fixtures
         * @param attack to create fixtures for
        */
        void GenerateFixtures(Attack& attack);

        /**
         * Method that altars all of the velocity values for player
         * at certain frame intervals
         * @param attack to create base changes off of
        */
        void VelocityChange(Attack& attack);

        /**
         * Method that altars all of the velocity values for player
         * at certain frame intervals
         * @param mobility to create base changes off of
        */
        void VelocityChange(MobilityMove& mobility);

        /**
         * Method that generates all of the hitbox fixtures
         * @param shield to create fixtures for
        */
        void GenerateFixtures(Shield& shield);

        /**Method that handles the next frame and is called in the update*/
        void NextFrame();

        /**Method that removes all of the fixtures created by the handler*/
        void RemoveAllFixtures();

        /**Method that changes the players color based on the rgb values*/
        void ChangePlayerColor(int r, int g, int b);

        /**Getters and setters*/
        bool IsAttackInProgress() const;

        MoveType GetType() const;

        void SetPlayerBody(b2Body *playerBody);

        bool IsInvulnerable() const;

        bool IsShielding() const;


    private:

        /**Pixel to Meter conversion factor*/
        const float kPixelPerMeterFactor = 50;

        /**Pointer to player body to fix fixtures to*/
        b2Body* player_body_;

        /**Bool that shows whether a move is in progress*/
        bool is_move_in_progress_ = false;
        /**Bool that shows whether a player has invul frames or not*/
        bool is_invulnerable_;
        /**Bool that shows whether a player is shielding or not*/
        bool is_shielding_;

        /**Total start up frames for current move*/
        int total_start_up_;
        /**Which frame of start up handler is on*/
        int current_startup_;

        /**Total active frames for current move*/
        int total_active_frames_;
        /**Which frame of active handler is on*/
        int current_active_frame_;

        /**Total end lag frames for current move*/
        int total_end_lag_;
        /**Which frame of end lag handler is on*/
        int current_end_lag_;

        /**The index that handle is on for the move parts*/
        int move_part_interval_index_;
        /**The index that handle is on for the velocity parts*/
        int velocity_interval_index_;

        /**List of pointers to fixtures created by the handler*/
        std::vector<b2Fixture*> fixtures_;

        /**The type of the current move in action*/
        MoveType type_;

        /**The current Attack in progress if applicable*/
        Attack attack_;
        /**The current MobilityMove in progress if applicable*/
        MobilityMove mobility_;
        /**The current Shield in progress if applicable*/
        Shield shield_;

    };

} //namespace models

} //namespace antares