#include <bits/stdc++.h>
using namespace std;

string str;
vector<pair<string, string>> datas;

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
        string thing_temp = "", date_temp = "";
        if(str[i] == '\n'){
            index = i + 1;
        }
        if(str[i] == '('){
            for(int j = index; j < i - 1; j++){
                thing_temp = thing_temp + str[j];
            }
            index = i;
            for(int j = index + 1; j < index + 5; j++){
                date_temp = date_temp + str[j];
            }
            datas.push_back(make_pair(date_temp, thing_temp));
        }
    }
}

void sorting()
{
    sort(datas.begin(), datas.end());
}

string get_date()
{
    time_t t = time(0);
    tm* now = localtime(&t);
    string month = to_string(now -> tm_mon + 1), day = to_string(now -> tm_mday);
    if(month.length() == 1){
        month = "0" + month;
    }
    if(day.length() == 1){
        day = "0" + day;
    }
    return month + day;
}

void print()
{
    for(int i = 0; i < datas.size(); i++){
        if(datas[i].first == get_date()){
            cout << datas[i].first << " " << datas[i].second << " ( Due today!!! ) " << endl;
        }
        else{
            cout << datas[i].first << " " << datas[i].second << endl;
        }
    }
}

int main()
{
    init();
    run();
    sorting();
    print();
    system("pause");
    return 0;
}

