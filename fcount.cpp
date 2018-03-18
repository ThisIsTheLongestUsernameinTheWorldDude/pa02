#include <iostream>
#include <string>
#include <dirent.h> 
#include <sys/stat.h>

using namespace std;

int directories = 0; //# of directories
int files = 0; //# of files
int size = 0; //total filesize in bytes

//this program was a nice reminder of how pointers work
void peruse(char *dir_name){
    DIR *dir; //direcotry pointer
    struct dirent *contents; //contents of the current directory
    struct stat info; //supplimentary data


    //open the dir
    dir = opendir(dir_name);
    //error handling
    if(!dir){
        cout << "File not found\n";
        return;
    }

    //read the dir
    while((contents = readdir(dir)) != NULL){
        if(contents->d_name[0] != '.'){
            string path = string(dir_name) + "/" + string(contents->d_name);
            //cout << info.st_size << endl;
            stat(path.c_str(),&info);
            if(S_ISDIR(info.st_mode)){
                directories++;
                peruse((char*)path.c_str());
            }else{
                files++;
                size += info.st_size;
            }
        }
    }
    //close the dir
    closedir(dir);
}
int main(int argc, char** argv){
    //comment lol
    string in(argv[1]);
    //cin >> in;
    peruse((char*)in.c_str());
    
    cout << "The total number of directories in " << in << " is "<< directories << endl;
    cout << "The total number of files in " << in << " is "<< files << endl;
    cout << "The total size of files in " << in << " is "<< size << " bytes" << endl;
    return 0;
}