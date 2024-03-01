#ifndef pokemon_h
#define pokemon_h
#include <iostream>
#include <fstream>

using namespace std;

struct Pokemon {
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};

struct Pokedex {
    string trainer;
    int num_pokemon;
    Pokemon* dex;
};

int getIntegerValue(string, int, int, string);
Pokemon* create_pokemons(int);
string* create_moves(int);
void populate_pokemon(Pokemon &, ifstream &);
void populate_pokedex_data(Pokedex &, ifstream &);
void delete_info(Pokedex &);
void fileOutput(Pokedex &, int);
void fileOrTerm(Pokedex &, int);
void searchDex(Pokedex &);
void searchName(Pokedex &);
void searchType(Pokedex &);
void addPokemon(Pokedex &);
void printStuff(Pokedex &);


#endif
