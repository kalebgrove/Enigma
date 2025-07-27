#include "plugboard.hh"
#include "rotor.hh"
#include "reflector.hh"
#include <iostream>
#include <vector>
#include <set>

#define NUM_ROTORS 5;
#define NUM_LETTERS = 26;
#define LAST_LETTER 'z';

//Machine class that contains the three components: Rotors, Plugboard and Reflector.
class Enigma {
    private:
        //5 rotors to initialize the set of rotors.
        Rotor rotor1, rotor2, rotor3, rotor4, rotor5;

        //Rotors can be stored in a vector. Access time is O(1)
        vector<Rotor> rotors;

        //Plugboard, that allows us to swap different letters.
        Plugboard plugboard;

        //Reflector, similar to a plugboard but swaps all of the letters.
        Reflector reflector;

        //List of rotors in order that is displayed on the machine.
        vector<Rotor> list_rotors;
        
    public:

        /// @brief initializes the components to default value. These will always change since the following functions will be called later.
        void initialize_components();

        /// @brief Sets the list of rotors that will be displayed and in order.
        void set_list_rotors();

        /// @brief will set the plugboard according to the number of connections desired.
        void set_plugboard();

        /// @brief configures all of the rotors.
        void configure_rotors();

        /// @brief Sets the reflector to the designated values.
        void set_reflector();

        /// @brief configures a singular rotor according to the user input.
        /// @param n rotor number desired to configure.
        void set_sel_rotor(int n);

        /// @brief function that translates the character: it consists of the enigma mechanism.
        /// @param a character inputted
        /// @return character output.
        char translate(char a);
};