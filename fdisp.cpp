#include <iostream>
#include <string>

using namespace std;
int main(int argc, char** argv){
    //sets to 0 if the user inputs an valid command, if it is still 0 it displays an error message
    int commandFailed = 1;
    string line = "";
    //convert the option to a string for convienience
    string option(argv[1]);
    while(getline(cin, line)){
        if(option.compare("-b") == 0){
            if(line.find("bytes") <= line.size()){
                cout << line << endl;
            }
            commandFailed = 0;
        }
        else if(option.compare("-d") == 0){
            if(line.find("directories") <= line.size()){
                cout << line << endl;
            }
            commandFailed = 0;
        }
        else if(option.compare("-f") == 0){
            //i have to make sure that this one contains files, but not bytes, otherwise it will activate twice. I thought the if/else would avoid it, but it didn't.
            if(line.find("files") <= line.size() && line.find("bytes") >= line.size()){
                cout << line << endl;
            }
            commandFailed = 0;
        }
    }
    //cout << argv[1] << endl;
    if(commandFailed == 1){
        cout << "Command not recognized. Valid commands are\n -f:number of files\n -d:number of directories\n -b:total size of all files within directory" << endl;
    }
    return 0;
}