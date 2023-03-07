//add include statements
#include "func.h"
//add function code here
double get_gc_content(const string& dna)
{
     int i=0,count=0;

    for(i = 0; i < dna.size(); i++)
    {
        if(dna[i] == 'G' || dna[i] == 'g' || dna[i] == 'C' || dna[i] == 'c')
        {
            count++;
        }
    }
    return ((double)count)/dna.size();
}

string reverse_string(string dna)
{
    string reverse = "";

    for(int i = dna.length()-1;i >= 0; i--)
    {
        reverse += dna[i];
    }

    return reverse;
}

string get_dna_complement(string dna)
{
    string complement = "";

     dna = reverse_string(dna);

    for(int i=0; i< dna.length();i++)
    {
        if(dna[i] == 'A')
        {
            complement += 'T';
        }
        else if(dna[i] == 'T')
        {
            complement += 'A';
        }
        else if(dna[i] == 'G')
        {
            complement += 'C';
        }
        else if(dna[i] == 'C')
        {
            complement += 'G';
        }
    }
    return complement;
}

void display_menu()
{
    cout << "1- Get GC Content \n";
    cout << "2- Get DNA Complement \n";
    cout << "3- Exit \n";
}

void run_menu()
{
    auto option = 0;

    do
    {
        display_menu();
        cout << "Enter Menu Option:  \n";
        cin >> option;

        handle_menu_option(option);

    } while (option != 3);

}

void handle_menu_option(int num)
{

    string dna = "";

    switch(num)
    {
        case 1:
        cout << "Enter GC to get GC content:  \n";
        cin >> dna;
        cout << "Your GC content is: " << get_gc_content(dna) << "\n";
            break;
        case 2:
        cout << "Enter DNA string to get DNA complement:  \n";
        cin >> dna;
        cout << "Your DNA string complement is: " << get_dna_complement(dna) << "\n";
            break;
        case 3: 
        cout << "Exiting program... \n";
            break;
        default:
        cout << "Invalid option! \n";

    }

}