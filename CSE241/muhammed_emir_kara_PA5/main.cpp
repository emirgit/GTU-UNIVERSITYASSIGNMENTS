#include "Catalog.h"
#include <fstream>

int main(){
    //file names
    const string text = "data.txt";
    const string commands = "commands.txt";
    const string outputText = "output.txt";

    //instantinate the catalog
    Catalog c;
    try
    {
        //read File
        c.readDataFile(text, outputText);
        //read and apply the commands
        c.readCommands(commands, outputText);
        //delete datas because it is dynamic memory
        c.deleteDatas();
    }
    catch(FileOpenError e)
    {
        cout << e.what();
    }

    return (0);
}