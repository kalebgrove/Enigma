#include <map>

using namespace std;

class Reflector {
    private:
        map<char, char> connections;

    public:
        void set_connections(char a, char b);

        char get_char(char a);
};