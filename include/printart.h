#ifndef PRINTART_H
#define PRINTART_H

#include <iostream>
#include <fstream>
#include <string>

class printart
{
    public:
        printart(std::string aFile);
        std::string getFileContents (std::ifstream& File);

        std::string aFile;
        std::string Art;



    protected:

    private:
};

#endif // PRINTART_H
