#include "plugboard.hh"

void Plugboard::set_connections(char a, char b) {
    connections[a] = b;
    connections[b] = a;
}

char Plugboard::get_char(char a) {
    return connections[a];
}