#include <iostream>
#include <fstream>
#include <cctype>
#include <string>
#include <stdio.h>

static bool     parser(char **argv, std::ifstream& infile ){
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string name = argv[1];
    
    if (s1.empty()){
        std::cerr << "ERROR Nothing to be replaced!" << std::endl;
        return false;
    }
    if (s2.empty()){
        std::cerr << "ERROR Nothing to replace!" << std::endl;
        return false;
    }
    for (int i = 0; i < name.length(); i++){
        if (!isprint(static_cast <unsigned char> (name[i]))){
            std::cerr << "ERROR File name cant have non printable chars!" << std::endl;
            return false; 
        }
    }
    infile.open(argv[1]);
    if (infile.fail()){
        std::cerr << "ERROR Failed to open file!" << std::endl;
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    //printf("ola\n");
    if (argc != 4)
        return 1;
    std::ifstream infile;
    if (!parser(argv, infile))
        return 1;
    std::string outname = (std::string (argv[1]) + ".replace");
    std::ofstream outfile(outname);
    if (outfile.fail()){
        std::cerr << "ERROR Cant create outfile!" << std::endl;
        return 1;
    }
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string buffer;
    while (std::getline(infile, buffer))
    {
        buffer += "\n";
        size_t pos = 0;
        while ((pos = buffer.find(s1, pos)) != std::string::npos)
        {
            buffer.erase(pos, s1.length());
            buffer.insert(pos, s2);
            pos += s2.length();
        }
        outfile << buffer;
    }
    infile.close();
    outfile.flush();
    outfile.close();
    return 0;
}