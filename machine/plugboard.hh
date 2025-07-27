#include <map>

using namespace std;

class Plugboard {
    private:
        map<char, char> connections;

    public:
        void set_connections(char a, char b);

        char get_char(char a);
};