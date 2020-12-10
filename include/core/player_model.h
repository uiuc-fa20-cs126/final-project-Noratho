//
// Created by Nathaniel Smith on 11/12/20.
//
#pragma once

#include <nlohmann/json.hpp>
#include <Box2D/Box2D.h>
#include <cinder/app/KeyEvent.h>
#include <tuple>

#include "move_model.h"
#include "character_data_model.h"
#include "move_handler.h"

namespace antares {

namespace models {

/**
 * Player Class
 * Used to model the player data and actions
*/
class Player {

public:

    /**Default constructor*/
    Player();

    /**
    * Method that generates the player given:
    * @param world to attach dynamic body to
     * @param pixel_per_meter_factor the factor for pixel to meter conversion
     * @param json_path the json path to the character data
     * @param window_size the size of the window
    */
    void GeneratePlayer(b2World &world, float pixel_per_meter_factor,
                        const std::string& json_path, std::vector<float> window_size);

    /** Method that parses the input in the input list and timers*/
    void ParseInput();

    /**List of the current inputs*/
    std::vector<std::string> input_list_;
    /**Map of the current inputs with a frame amount remaining*/
    std::map<std::string, int> input_timers_;

    /**Getters and Setters*/
    b2Body *GetPlayerBody() const;

    const b2Vec2 &GetPosition() const;

    bool IsInAir() const;

    const CharacterData &GetCharacterData() const;

    MoveHandler *GetHandler() const;

    void SetIsInAir(bool isInAir);

    void SetIsShielding(bool isShielding);

    void SetIsInvulnerable(bool isInvulnerable);

    void SetPosition(const b2Vec2 &position);

private:

    /**
    * Method that generates the player body given:
    * @param world to attach dynamic body to
     * @param pixel_per_meter_factor the factor for pixel to meter conversion
    * @param window_size the size of the window
    */
    void CreateBody(b2World &world, float pixel_per_meter_factor, std::vector<float> window_size);

    /** Method that sets up the input maps for the moves*/
    void SetUpMaps();

    /**
    * Method that deserializes the json data for a character
    * @param json_path the json path to the character data
    */
    void DeserializeJson(const std::string& json_path);

    /**
    * Method that cleans up the data for an input given:
    * @param input_string the input string
    * @param input_map map with input timers
    */
    std::tuple<std::string, int> CleanInput(std::vector<std::string> input_string,
                                            std::map<std::string, int> input_map);

    /**current player position*/
    b2Vec2 position_;

    /**pointer to player dynamic body*/
    b2Body* player_body_;
    /**pointer to move handler*/
    MoveHandler *handler_;

    /**The data for the character*/
    CharacterData character_data_;

    /**Bool to show whether player is facing right*/
    bool is_facing_right_;
    /**Bool to show whether player is in the air*/
    bool is_in_air_;
    /**Bool to show whether player is shielding*/
    bool is_shielding_;
    /**Bool to show whether player is in invul frames*/
    bool is_invulnerable_;

};

} //namespace models

} //namespace antares
