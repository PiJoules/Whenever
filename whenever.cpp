#include <iostream>
#include <sstream>
#include <fstream>
#include "whenever.h"


class WheneverCode {
    public:
        WheneverCode(const std::string filename, const int traceLevel=0): traceLevel(traceLevel){
            CodeTable code();
            std::ifstream infile(filename.c_str());
            int i = 0;
            for (std::string line; std::getline(infile, line); ){
                parse(trim(line));
                i++;
            }
            std::cerr << i << " line(s) successfully parsed from sourcefile " << filename << std::endl;
            infile.close();
        }

        void run(){}

    private:
        int traceLevel;

        void parse(std::string line){
        
        }
};


int main(int argc, char* argv[]){
    if (argc == 2){
        WheneverCode code(argv[1]);
        code.run();
        return 0;
    }
    else if (argc == 3){
        std::string tempStr(argv[2]);
        std::stringstream tempStream(tempStr);
        int traceLevel;
        tempStream >> traceLevel;
        if (tempStream){
            WheneverCode code(argv[1], traceLevel);
            code.run();
            return 0;
        }
    }

    std::cerr << "Usage: whenever <sourcefile> [tracelevel]" << std::endl;
}

