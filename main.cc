#include "machine/configure.hh"

int main() {
    Enigma machine;

    machine.initialize_components();
    machine.set_plugboard();
    machine.configure_rotors();
    machine.set_reflector();
    machine.set_list_rotors();

    char a;
    cin >> a;

    while(a != 'Y') {
        cout << "Are you ready to Encrypt/Decrypt your message? Y/N" << endl;
        cin >> a;
    }

    int i = 0;
    while(cin >> a) {
        a = tolower(a);
        ++i;
        cout << machine.translate(a);
        if(i == 4) {
            cout << ' ';
            i = 0;
        }
    }
}