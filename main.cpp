//including libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h> //C Library containing system() function.
#include <fstream>
#include <chrono>
#include <ctime>
#include <unistd.h>

using std::string;
using std::fstream;

//declaring functions
int backup();
int restore();
int help();
int perform_backup(string source_dir, string dest_dir, string name);
int save(string sourceDir, string destDir, string name, string saveFileName);
int load(string filename, string& sourceDir, string& destDir, string& name);

//namespaces
namespace backupper{
    int version = 1;
    int result = 0;
}

int main(){ //main() contains the main UI (CLI)
    //declaring string cmd
    string cmd = "";
    string sysOutput = "";

    //checking saves folder
    system("if not exist saves\\ (mkdir saves);");

    //welcome screen
    std::system("cls");
    std::system("type logo.txt");
    std::cout << std::endl << std::endl;
    std::system("color 1F");
    std::cout << "Welcome to Backupper v" << backupper::version << " CLI" << std::endl;
    std::cout << "Running on :";
    std::system("ver");
    std::cout << std::endl;
    std::cout << "________________________________________" << std::endl << " " << std::endl;
    

    // getting and checking user input
    while (true){
        
        std::cout << "Backupper >> ";
        std::cin >> cmd;

        if (cmd == "exit"){
            system("cls");
            std::cout << "Closing Backupper..." << std::endl;
            std::cout << std::endl;
            system("color 0F");
            exit(0);
        } 
        else if (cmd == "backup"){
            backupper::result = backup(); //calling function backup
        }
        else if (cmd == "restore"){
            backupper::result = restore(); //calling function restore
        }
        else if (cmd == "help"){
            backupper::result = help(); //shows help page
        }
        else{
            std::cout << "Bad usage, Type help to view a list of commands" << std::endl << " " << std::endl; //bad usage
        }

        

    }

    return 0;
}

int backup(){
    string cmd = "";
    string confirm = "";
    string source_dir = "";
    string destination_dir = "";
    string name = "";
    string date = "";
    string settingsFileName = "";
    string settingsFilePath = "";
    int result = 0;

    // getting and checking user input
    while (true){
        std::cout << std::endl;
        std::cout << "Backupper >> Backup >> ";
        std::cin >> cmd;

        if (cmd == "back" || "b"){
            return 100; //return code for "operation complete"
        }
        else if (cmd == "exit" || "e"){
            system("cls");
            std::cout << "Closing Backupper..." << std::endl;
            std::cout << std::endl;
            system("color 0F");
            exit(0);
        } 
        else if (cmd == "set"  || "s"){
            
            //asking for backup settings
            std::cout << std::endl;
            std::cout << "Set Backup Task" << std::endl;
            std::cout << "Insert source directory...";
            std::cin >> source_dir;
            std::cout << "Insert destination directory...";
            std::cin >> destination_dir;
            std::cout << "Insert backup name...";
            std::cin >> name;
            std::cout << std::endl;
                    
            //summary
            std::cout << "Task Saved:" << std::endl;
            std::cout << "Backup name = " << name << std::endl;
            std::cout << "Source directory: " << source_dir << std::endl;
            std::cout << "Destination directory = " << destination_dir << std::endl;
            std::cout << "now you can apply or discard this task" << std::endl;
            std::cout << std::endl;
        }
        else if (cmd == "apply" || "a"){
            std::cout << std::endl;
            if (name == "" || source_dir == "" || destination_dir == ""){
                std::cout << "backup not configured, type set to configure it" << std::endl;
                std::cout << std::endl;
            }
            else{
                std::cout << "Backup name = " << name << std::endl;
                std::cout << "Source directory: " << source_dir << std::endl;
                std::cout << "Destination directory = " << destination_dir << std::endl;
                std::cout << "During Backup you mustn't turn off your computer" << std::endl;
                std::cout << std::endl;
                std::cout << "Apply pending operation? ";
                std::cin >> confirm;
                if (confirm == "yes"){
                    result = perform_backup(source_dir, destination_dir, name);
                }
            }
        }

        else if (cmd == "reset" || "r"){
            //settings reset
            source_dir.clear();
            destination_dir.clear();
            name.clear();
            std::cout << std::endl;
            std::cout << "settings resetted due to user choise" << std::endl;
            std::cout << std::endl;
        }
        else if (cmd == "help" || "h"){
            std::cout << std::endl << "Backup Mode Usage:"<< std::endl;
            std::cout << "set | s           configure backup" << std::endl;
            std::cout << "apply | a         perform configured backup" << std::endl;
            std::cout << "reset | r         reset backup settings" << std::endl;
            std::cout << "help | h          shows this page" << std::endl;
            std::cout << "view | v          shows current settings" << std::endl;
            std::cout << "delete | del      delete save file" << std::endl;
            std::cout << "save | sa         save settings, usefull to load them quickly" << std::endl;
            std::cout << "load | l          load settings from file";
            std::cout << "back | b          go to home page" << std::endl << std::endl;
        }
        else if (cmd == "save" || "s"){
            std::cout << std::endl << "Save backup settings...";

            result = save(source_dir, destination_dir, name, settingsFileName);

            if (result == 0){
                std::cout << "Done!" << std::endl << std::endl;
            }
            else{
                std::cout << "Failed" << std::endl;
                std::cout << "Settings not saved due to an error" << std::endl << std::endl;
            }
        }
        else if (cmd == "load" || "l"){
            std::cout << std::endl << "Load backup settings" << std::endl;
            std::cout << "Insert save name...";
            std::cin >> settingsFileName;
            std::cout << std::endl;
            settingsFilePath = "saves\\" + settingsFileName + ".txt";
            result = load(settingsFilePath, source_dir, destination_dir, name);
            if (result == 0){
                std::cout << "Settings loaded successfully!" << std::endl << std::endl;
            }
            else{
                std::cout << "Unable to load settings" << std::endl << std::endl;
            }
        }
        else if (cmd == "view" || "v"){
            std::cout << std::endl << std::endl;
            std::cout << "Backup name = " << name << std::endl;
            std::cout << "Source directory: " << source_dir << std::endl;
            std::cout << "Destination directory = " << destination_dir << std::endl << std::endl;
        }
        else if (cmd == "delete" || "del"){
            std::cout << std::endl;
            std::cout << "Delete backup settings" << std::endl;
            std::cout << "Insert save name...";
            std::cin >> settingsFileName;
            cmd = "if exist saves\\" + settingsFileName + ".txt (del saves\\" + settingsFileName + ".txt) else (exit /b 2)";
            result == std::system(cmd.c_str());

            if (result != 0){
                std::cout << "Error: unable to delete " << settingsFileName << std::endl;
            }
            else{
                std::cout << "Successfully deleted " << settingsFileName << std::endl;
            }

        }
        else{
            std::cout << std::endl << std::endl;
            std::cout << "Bad usage, Type help to view a list of commands" << std::endl << std::endl;
        } 
    }
}

int restore(){
    std::cout << std::endl;
    std::cout << "Restore Mode isn't available. To use it, please reboot your computer from backupper USB Drive" << std::endl;
    std::cout << std::endl;
    return 0;
}

int help(){
    std::cout << std::endl;
    std::cout << "Backupper Usage:" << std::endl;
    std::cout << "backup    make a full device backup" << std::endl;
    std::cout << "restore   restore a disk from backup" << std::endl;
    std::cout << "help      show this page" << std::endl;
    std::cout << std::endl;
    return 0;
}

int perform_backup(string source_dir, string dest_dir, string name){
    // creating variables
    string cmd = "";
    int result = 0;
    string logFileDir = "";
    string infoFileDir = "";
    string num_dir_str = "";
    int i = 0;

    // creating and opening log file
    logFileDir = dest_dir + "\\" + name + "\\events.log";
    infoFileDir = dest_dir + "\\" + name + "\\backup-info.txt";
    

    // executing script: create_info_file.bat
    std::cout << "Creating backup...\n";
    cmd = "create-info-file.bat " + dest_dir + " " + name;
    
    result = std::system(cmd.c_str());
    if (result != 0){
        std::cout << "Failed!" << std::endl << "Failed to create backup";
    }
    else{
        std::cout << "Done!";
    }
    
    fstream logFile (logFileDir);
    fstream infoFile (infoFileDir);
    logFile << "Backupper v" + backupper::version;
    logFile << " Backup Mode\n";
    logFile << "backup name: " << name << "\n\n";

    infoFile << "Backupper v" << backupper::version;
    infoFile << " Backup Mode\n\n";
    infoFile << "Source dir: " << source_dir << "\n";
    infoFile << "Destination Dir: " << dest_dir << "\n";
    infoFile << "Backup Name: " << name << "\n";

    //setting destination dir as the new directory created
    dest_dir = dest_dir + "\\" + name;
    std::cout << std::endl;
    std::cout << "setted backup directory as " << dest_dir << std::endl << std::endl;

    //executing script: backup-data.bat
    std::cout << "Baking up " << source_dir << std::endl;
    logFile << "Backing up " << source_dir << "\n";
    cmd = "backup-data.bat " + source_dir + " " + dest_dir; //setting cmd
    logFile << "Executing " + cmd + "\n\n";

    logFile.close();
    result = std::system(cmd.c_str()); //running string cmd

    fstream logFile2 (logFileDir);
    if (result == 0){
        std::cout << "Done!" << std::endl;
        logFile2 << "Succesfully Backed up " << source_dir[i] << "\n";
    }
    else{
        std::cout << "Failed" << std::endl;
        logFile2 << "Failed to backup " << source_dir[i] << ". See info Above\n";
    }
}   

int save(string sourceDir, string destDir, string name, string saveFileName){
    int result = 0;
    string cmd = "";
    string settingsFilePath = "saves\\" + name + ".txt";
    cmd = "copy nul saves\\" + name + ".txt"; //creating file
    result = std::system(cmd.c_str());
    if (result != 0){
        return 1;
    }

    fstream settingsFile (settingsFilePath); // opening file
    settingsFile << sourceDir << "\n";
    settingsFile << destDir << "\n";
    settingsFile << name << "\n";

    return 0;
}

int load(string filename, string& sourceDir, string& destDir, string& name){

    std::cout << "Loading " << filename << std::endl;
    std::ifstream settingsFile(filename);
    if (settingsFile.is_open()) {
        getline(settingsFile, sourceDir);
        getline(settingsFile, destDir);
        getline(settingsFile, name);
        settingsFile.close();
    }
    else{
        return 1;
    }

    return 0;
}
