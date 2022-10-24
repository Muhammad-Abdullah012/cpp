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
    int getValidFinishTime(const int&, const int&);
    public:
        ManageFiles();
        ~ManageFiles() {
            if(fin.is_open())
                fin.close();
            if(fout.is_open())
                fout.close();
        }
        void readJobsFromFile(const string&, vector<string>&, vector<int>&, vector<int>&);
        void writeJobsToFile(const string&, const unsigned short int&);   //size min = 100, max =  9000
};

#endif 