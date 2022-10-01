#include <conio.h>
#include <iostream>

#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
    system("cls");
    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6.Write word to the file\n7.Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("cls");
    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void Edit(Tree& tree) {             //Edit
    system("cls");
    short input;
    cout << "1.Edit russian word.\n2. Edit English Word." << endl;
    cin >> input;
    if (input < 1 && input > 2) {

        cout << "Something went wrong.." << endl;
        system("pause");
        return;
    }
    system("cls");

    cout << "Enter a word: " << endl;
    char buffer[32];
    cin >> buffer;

    Node* temp = tree.Search(tree.GetRoot(), buffer);

    cout << "Enter changes: " << endl;
    if (input == 1)cin >> temp->m_russian;
    else if (input == 2)cin >> temp->m_english;

    system("cls");

    cout << "Success!" << endl;
    system("pause");

}

void File(Tree& tree) // Write to file
{
    system("cls");
    FILE* file;
    char path[] = "C:\\examples\\data.txt";
    errno_t err = fopen_s(&file, path, "w");

    
    if (err == 0)
    {
        system("cls");
        cout << "Enter the word to write in the file:" << endl;

        char buffer[15] = {};
        cin >> buffer;

        Node* node = tree.Search(tree.GetRoot(), buffer);
        if (node != nullptr)
        {
            if (err == 0) {
                fprintf(file, "%s\n", buffer);
                cout << "Success!" << endl;
                system("pause");
            }
        }
        else
        {
            cout << "Word not found" << endl;
        }
    }
    else {
        cout << "The file couldn't be opened.." << endl;
        system("pause");
    }
}

