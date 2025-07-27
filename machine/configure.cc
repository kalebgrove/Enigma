#include "configure.hh"

void Enigma::initialize_components() {
    rotors = {rotor1, rotor2, rotor3, rotor4, rotor5};

    //Set default values for all of the rotors. Will be changes in the configure rotors function.
    rotors[1].set_displayed('a');
    rotors[2].set_displayed('a');
    rotors[3].set_displayed('a');
    rotors[4].set_displayed('a');
    rotors[0].set_displayed('a');

    rotors[1].set_next('w');
    rotors[2].set_next('w');
    rotors[3].set_next('w');
    rotors[4].set_next('w');
    rotors[0].set_next('w');

    //Set all of the connections to themselves.
    for(char a = 'a'; a <= 'z'; ++a) {
        rotors[1].set_connections(a, a);
        rotors[2].set_connections(a, a);
        rotors[3].set_connections(a, a);
        rotors[4].set_connections(a, a);
        rotors[0].set_connections(a, a);
        
        //The plugboard by default is itself.
        plugboard.set_connections(a, a);
        reflector.set_connections(a, a);
    }
}

void Enigma::set_plugboard() {
    int number_connections;
    cout << "Please indicate the number of connections you'd like to insert: " << endl;
    //Number of swaps between the letters.
    cin >> number_connections;
    cout << "Please enter the pairs of combinations between the letters: " << endl;

    for(int i = 0; i < number_connections; ++i) {
        char a, b;
        cin >> a >> b;

        plugboard.set_connections(a, b);
    }
}

void Enigma::set_list_rotors() {
    int i;
    set<int> nums = {1, 2, 3, 4, 5};

    cout << "Please indicate the number and in order of the rotors that you want to use:" << endl;

    for(int j = 0; j < 3; ++j) {
        cin >> i;
        
        if(nums.find(i) == nums.end()) {
            cout << "Please select a valid number" << endl;
            --j;
        }
        else {
            nums.erase(i);
            list_rotors.push_back(rotors[i-1]);
        }
    }
    
}

void Enigma::configure_rotors() {
    for(int i = 0; i < 5; ++i) {
        cout << "Editing connections for the Rotor number " << i+1 << endl;
        cout << "Please enter the letters in a string format for the connections: " << endl;
        char b;
        char a = 'a';
        while(a <= 'z' && cin >> b) {
            b = tolower(b);
            rotors[i].set_connections(a, b);
            a++;
        }

        char d;
        cout << "Please set the displayed letter:" << endl;
        cin >> d;

        rotors[i].set_displayed(d);

        cout << "Please set the letter with the nook:" << endl;
        cin >> d;

        rotors[i].set_next(d);
    }
}

void Enigma::set_reflector() {
    cout << "Now you'll start setting up the reflector." << endl;
    cout << "Please enter the pairs of combinations between the letters: " << endl;
    char a, b;
    for(int i = 0; i < 13; ++i) {
        cin >> a >> b;
        reflector.set_connections(a, b);
    }
}

void Enigma::set_sel_rotor(int i) {
    // Error control
    if(i < 1 and i > 5) {
        cout << "Please enter a valid number." << endl;
        return;
    }

    //values 1-5 will be entered, the indexes range from 0-4, therefore the input should be subtracted by 1.
    cout << "Editing connections for the Rotor number " << i << endl;
    cout << "Please enter the letters in a string format for the connections: " << endl;
    char b;
    char a = 'a';
    while(a <= 'z' && cin >> b) {
        b = tolower(b);
        rotors[i-1].set_connections(a, b);
        ++a;
    }
    
    char d;
    cout << "Please set the displayed letter:" << endl;
    cin >> d;

    rotors[i-1].set_displayed(d);

    cout << "Please set the letter with the nook:" << endl;
    cin >> d;

    rotors[i-1].set_next(d);
}

char Enigma::translate(char a) {
    //Steps:

    //0. Rotate Rotor 1
    if(list_rotors[0].next_displayed()) {
        list_rotors[1].add_displayed();
    }
    if(list_rotors[1].next_displayed()) {
        list_rotors[2].add_displayed();
    }
    list_rotors[0].add_displayed();

    //1. Plugboard
    char mod = plugboard.get_char(a);

    //2. Rotor #1
    mod = list_rotors[0].get_char(mod);

    //Find the next letter between the connection of rotor 1 and rotor 2:
    char c1 = list_rotors[0].get_displayed();
    char c2 = list_rotors[1].get_displayed();

    mod = mod + c2 - c1;

    //3. Rotor #2
    mod = list_rotors[1].get_char(mod);

    c1 = list_rotors[1].get_displayed();
    c2 = list_rotors[2].get_displayed();

    mod = mod + c2 - c1;

    //4. Rotor #3
    mod = list_rotors[2].get_char(mod);

    //5. Reflector
    mod = reflector.get_char(mod);

    //6. Rotor #3
    mod = list_rotors[2].get_char(mod);
    //7. Rotor #2
    mod = list_rotors[1].get_char(mod);
    //8. Rotor #1
    mod = list_rotors[0].get_char(mod);

    //9. Plugboard
    mod = plugboard.get_char(mod);

    //10. Output
    return mod;
}