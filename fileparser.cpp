#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

void findOcc(ifstream& infile, string FileName);
string printLine(string FileName);

string answer;
int occNum = 0;
char FileName[256];
string SearchWord;
string temp;
int counter = 0;
int occ = 0;
vector<pair<int, int> > result;
bool repeat = false;

int main()
{
    if(!repeat){
        cout << "Input filename: ";
        cin >> FileName;
    }
    cin.ignore();
    cout << "Input search phrase: ";
    getline(cin,SearchWord);
 

    ifstream file(FileName);

    findOcc(file, FileName);
}

void findOcc(ifstream& file, string FileName){

    while(!file.eof())
    {
        getline(file,temp);
        counter++;

        if(temp.find(SearchWord) != string::npos)
        { 
            result.push_back(make_pair(occ,counter));
            occ++;
        }
    }
    
    cout << "Occurence" << setw(15) << "Line #" << "\n"<< endl;
    for(int i=0; i<result.size(); ++i)
    {
        cout << setw(5)<< result[i].first << setw(15) << result[i].second << endl;
    }


    cout << "Would you like to see a specific line? (y/n) ";
    cin>>answer;
    while(answer == "y"){
        answer = printLine(FileName);
    }
    if(answer == "n"){
        cout << "Would you like to search for a new phrase? (y/n) ";
        cin>>answer;
        if(answer == "y"){

            repeat = true;
            SearchWord = "";
            result.clear();
            counter = 0;
            occ = 0;

            main();
        }
        else{
            cout << "Would you like to enter a new file? (y/n) ";
            cin>>answer;
            if(answer == "y"){
                repeat = false;
                SearchWord = "";
                FileName = "";
                result.clear();
                counter = 0;
                occ = 0;

                main();
            }
        }
    }
}

string printLine(string FileName){
    cout << "Enter the occurence number: ";
    cin>> occNum;
    ifstream file(FileName);
    for(int i=0; i<result.size(); ++i)
        {
            
            if(result[i].first == occNum){
                
                int line_number = 1;
                string txt;
                while (!file.eof())
                {
                    getline(file, txt);
                    if (line_number == result[i].second)
                    {
                        cout << result[i].first<<" "+txt << "\n"<<endl;
                        break;
                    }
                    line_number++;
                }
            }
        }
    cout << "Would you like to see a specific line? (y/n) ";
    cin>>answer;
    return answer;
}


