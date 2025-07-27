#include <map>

using namespace std;

class Rotor {
    private:
        //connections variable allows us to map the values inside of the rotor.
        map<char, char> connections;

        //next is the cut in the rotor that will allow the next rotor to rotate.
        char next;

    public:

        //displayed is the center character that is displayed in the visible part of the enigma machine.
        char displayed;

        //Sets the connections for the rotor.
        void set_connections(char a, char b);

        //sets the displayed characer.
        void set_displayed(char a);

        //sets the cut character.
        void set_next(char b);

        void add_displayed();

        bool next_displayed();

        char get_char(char a);

        char get_displayed();
};