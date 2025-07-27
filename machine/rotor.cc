#include "rotor.hh"

void Rotor::set_connections(char a, char b) {
    connections[a] = b;
}

void Rotor::set_displayed(char a) {
    displayed = a;
}

void Rotor::set_next(char a) {
    next = a;
}

void Rotor::add_displayed() {
    if(displayed < 'z') displayed++;
    else displayed = 'a';
}

bool Rotor::next_displayed() {
    return (displayed == next);
}

char Rotor::get_char(char a) {
    return connections[a];
}

char Rotor::get_displayed() {
    return displayed;
}