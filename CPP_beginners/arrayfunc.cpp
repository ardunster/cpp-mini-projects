#include <iostream>

using namespace std;

// Input array
void show_n(const int n, string input[]) 
{
    for(int i=0;i<n;i++)
    {
        cout << input[i] << endl;
    }
}

// Pointer to string/array
void show_n_with_p(const int n, string *input)
{
    for(int i=0;i<n;i++)
    {
        cout << input[i] << endl;
    }
}

// Can only take string array of 5 items
void show_with_p(string (&input)[5])
// void show_with_p(const int n, string (&input)[n]) // parameter not allowed
{
    for(int i=0;i<sizeof(input)/sizeof(string);i++)
    {
        cout << input[i] << endl;
    }
}

char *get_mem()
{
    char *p_mem = new char[100];

    return p_mem;
}

void free_willy(char *willy)
{
    delete [] willy;
}

int main() {

    string fruits[] = {"apple", "orange", "kiwi", "tomato", "pomegranate"};

    int elements = sizeof(fruits)/sizeof(string);



    show_n(elements, fruits);

    show_n_with_p(2, fruits);

    show_with_p(fruits);

    char *mems = get_mem();

    free_willy(mems);

    return 0;
}