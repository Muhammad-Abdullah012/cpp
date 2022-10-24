#ifndef __ManageFiles__

#include<fstream>
#include<vector>
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
class ManageFiles {
    ofstream fout;
    ifstream fin;
    public:
        ManageFiles();
        ~ManageFiles() {
            if(fin.is_open())
                fin.close();
            if(fout.is_open())
                fout.close();
        }
        void readNumbersFromFile(const string&, vector<int>&);
        void writeRandomNumbersToFile(const string&, const unsigned short int&);   //size min = 100, max =  9000
};

#endif 