#include "reflector.hh"

void Reflector::set_connections(char a, char b) {
    connections[a] = b;
}

char Reflector::get_char(char a) {
    return connections[a];
}