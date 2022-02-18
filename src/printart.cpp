#include "printart.h"

printart::printart(std::string aFile)
{
    std::ifstream Reader (aFile);
    std::string Art = getFileContents(Reader);
    std::cout << Art << std::endl;
    Reader.close();
}
std::string printart::getFileContents (std::ifstream& File)
{
    std::string Lines = "";

    if (File)
    {
        while (File.good ())
        {
            std::string TempLine;
            std::getline (File, TempLine);
            TempLine += "\n";

            Lines += TempLine;
        }
        return Lines;
    } else
    {
        return "ERROR File does not exist.";
    }
}
