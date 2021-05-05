#include <iostream>
#include <fstream>
#include <sstream>
#include <cstring>
#include <vector>
using namespace std;

string str;
vector<string> things;
vector<string> date;

void init()
{
    ifstream file("to do list.txt");
    stringstream buffer;
    buffer << file.rdbuf();
    str = buffer.str();
}

void run()
{
    int index = 0;
    for(int i = 0; i < str.length(); i++){
        string temp = "";
        if(str[i] == '\n'){
            index = i + 1;
        }
        if(str[i] == '('){
            for(int j = index; j < i - 1; j++){
                temp = temp + str[j];
            }
            things.push_back(temp);
            index = i;
            temp = "";
            for(int j = index + 1; j < index + 5; j++){
                temp = temp + str[j];
            }
            date.push_back(temp);
        }
    }
}

void sorting()
{
    for(int i = 0; i < date.size(); i++){
        for(int j = i + 1; j < date.size(); j++){
            if(date[i] > date[j]){
                swap(date[i], date[j]);
                swap(things[i], things[j]);
            }
        }
    }
}

void print()
{
    for(int i = 0; i < things.size(); i++){
        cout << date[i] << " " << things[i] << endl;
    }
}

int main()
{
    init();
    run();
    sorting();
    print();
    return 0;
}
