#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include <string>
#include <typeinfo>
#include <boost/algorithm/string.hpp>

using namespace std;

int main()
{
    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    int count = 0;
    //Converting JSON to String
    for (int i=0; i < 7; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        //Search by name
        string key = "nnisarg";
        string tempName = name;
        boost::algorithm::to_lower(tempName);
        boost::algorithm::to_lower(key);
        if (strstr(tempName.c_str(), key.c_str()))
        {
            count++;
            cout << count << ". " << endl;
            cout << endl;
            cout << "Name: " << name << endl;
            cout << "SAP ID: " << sap_id << endl;
            cout << "Gender: " << gender << endl;
            cout << "Date Of Birth: " << date_of_birth << endl;
            cout << "Interests: " << interests << endl;
            cout << endl;
        }
    }

    return 0;
}