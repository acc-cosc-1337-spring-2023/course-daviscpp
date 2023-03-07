//add function(s) prototype here
#include <iostream>
#include <string>

using std::cin; using std::cout; using std::string;

double get_gc_content(const string& dna);
string get_dna_complement(string dna);
string reverse_string(string dna);
void display_menu();
void run_menu();
void handle_menu_option(int num);