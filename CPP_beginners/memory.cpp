#include <iostream>

using namespace std;

/** chirpiest class ever */
class Bird 
{
private:
    string name;
public:
    Bird() 
    {
        cout << "Building a bird!" << endl;
    }
    Bird(string name): name(name) 
    {
        cout << "Building a bird named " << name << " :D" << endl;
    }

    Bird(const Bird& original): name(original.name)
    {
        cout << "Budding a bird named " << name << endl;
    }

    ~Bird() 
    {
        cout << "Unbuilding bird " << name << " .... :(" << endl;
    }

    void set_name(string name)
    {
        this->name = name;
    }

    void tweet()
    {
        cout << "Chirp, cheep, " << name << ", chitter, chirp!" << endl;
    }

};

int main()
{

    // Create array of 26, set each one's name to alphabet letter

    // string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    Bird *pbird = new Bird[26];

    char letter = 'A';
    for(int i=0; i<26; i++)
    {
        string alphabet_name = "Polly ";
        // alphabet_name += alphabet[i];
        alphabet_name += letter;
        letter++;
        pbird[i].set_name(alphabet_name);
        pbird[i].tweet();
    }

    pbird[5].set_name("Polly");
    pbird[5].tweet();

    delete [] pbird;

    char *p_mem = new char[1000];

    cout << &p_mem << endl;

    delete [] p_mem;

    return 0;
}