#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

int update();
int install();

class cli{
    public:
        void Upperbanner(){
            system("cls");
            cout << "BACKUPPER SETUP WIZARD" << endl;
            cout << "__________________________________________________________________" << endl << endl;
        }
};

namespace software{
    string setupPath = "";
    int version = 0;
}

int main(int argc, char* argv[]){
    //welcome screen
    system("cls");
    system("color 2F");
    system("type logo.txt");
    cout << endl << "Starting setup...";

    string param1 = argv[1];
    int result = 0;

    time_t timer;

    if (param1 == "/u"){
        result = update();
    }
    else if (param1 == "/i"){
        result = install(); 
    }

    if (result == 1){
        cout << "Operation aborted due to user's choise" << endl;
    }
    else if (result == 2){
        cout << "Operation aborted due to an error" << endl;
    }

    return 0;
}

int install(){
    //setting variables
    int selection = 0;
    string setup_dir = "C:\\Program Files";

    cli ui;

    //introduction screen
    ui.Upperbanner();
    cout << "Welcome to backupper setup wizard.This program" << endl;
    cout << "will guide you through the process of installing " << endl;
    cout << "Backupper on your computer. Before you begin," << endl;
    cout << "make sure you have closed your running programs," << endl;
    cout << "Otherwise, you may encounter issues during installation." << endl << endl;
    cout << "If you need assistance during installation or have questions about the software, please" << endl;
    cout << "visit the forum on the GitHub repository" << endl << endl;
    cout << "To continue with the installation, select an option below and follow the instructions" << endl; 
    cout << "displayed on the screen." << endl << endl;
    cout << "Powered by 7-zip" << endl << endl;
    
    cout << " 1) Next         2) Exit" << endl << endl;
    cout << "Enter selection...";
    cin >> selection;

    while (selection != 1 && 2){
        cin >> selection;
    }

    if (selection == 2){
        return 1;
    }

    //displaying license
    ui.Upperbanner();
    system ("type license.txt");
    cout << endl << endl;
    cout << "1) I read ad agree to licence terms         2) Exit" << endl << endl;
    cout << "Enter selection...";
    cin >> selection;

    while (selection != 1 && selection != 2){
        cin >> selection;
    }

    if (selection == 2){
        return 1;
    }

    //asking for destination directory
    cout << "Where do you want to install Backupper? (default: <<C:\\Program Files>>, type default to use it)...";
    cin >> software::setupPath;

    if (setup_dir == "default" || "DEFAULT"){
        setup_dir == "C:\\Program Files";
    }

    //summary
    ui.Upperbanner();
    cout << "Ready to begin installation." << endl << endl;
    cout << "Destination directory = " << software::setupPath << endl << endl;
    cout << "1) Confirm and Install         2) Exit" << endl << endl;
    cout << "Enter selection...";
    cin >> selection;

    while (selection != 1 && selection != 2){
        cin >> selection;
    }

    if (selection == 2){
        return 1;
    }

    //installing
    ui.Upperbanner();
    int progress = 0;

    cout << "Downloading necessary files..." << endl << endl;
    cout << "    " << progress << " |                        |";
    
    cout << endl;
    system ("pause");


    return 0;
}

int update(){
    ifstream settingsFile (".\\setup-path.txt");
}
