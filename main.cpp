#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include <string>
#include <typeinfo>
#include <boost/algorithm/string.hpp>

using namespace std;

void Clear()
{
    cout << "\x1B[2J\x1B[H";
}


int welcome()
{
    int input;
    cout << "\n\n\t\t\tWELCOME TO ~OURSPACE~ - THE MPSTME STUDENT DATABASE\n";
    cout << "\n";
    cout << "\n";
    cout << "Type the number to search for a field\n";
    cout << "\n";
    cout << "1 - Name\n";
    cout << "2 - SAP ID\n";
    cout << "3 - Gender\n";
    cout << "4 - Date Of Birth\n";
    cout << "5 - Interests\n";
    cout << "\n";
    cout << "Type 10 to EXIT\n";
    cout << "\n";
    cout << "Type here: ";
    cin >> input;
    return input;
}


void name()
{
    Clear();

    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    //Variables
    bool found = false;
    int count = 0;
    string key;

    //Input
    cout << "Name to search: ";
    cin >> key;
    cout << "\n\n";

    cout << " \n-----------------------------------------------------------------\n\n\n";

    //Converting JSON to String
    for (int i=0; i < 100; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        //Search
        string tempName = name;
        boost::algorithm::to_lower(tempName);
        boost::algorithm::to_lower(key);
        if (strstr(tempName.c_str(), key.c_str()))
        {
            found = true;
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

    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }

    cout << " \n-----------------------------------------------------------------\n";
}


void sap_id()
{
    Clear();

    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    //Variables
    bool found = false;
    int count = 0;
    string key;

    //Input
    cout << "SAP ID to search: ";
    cin >> key;
    cout << "\n\n";

    cout << " \n-----------------------------------------------------------------\n\n\n";

    //Converting JSON to String
    for (int i=0; i < 100; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        //Search
        string tempSapID = sap_id;
        boost::algorithm::to_lower(tempSapID);
        boost::algorithm::to_lower(key);
        if (strstr(tempSapID.c_str(), key.c_str()))
        {
            found = true;
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

    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }

    cout << " \n-----------------------------------------------------------------\n";
}


void gender()
{
    Clear();

    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    //Variables
    bool found = false;
    int count = 0;
    string key;

    //Input
    cout << "Gender to search: ";
    cin >> key;
    cout << "\n\n";

    cout << " \n-----------------------------------------------------------------\n\n\n";

    //Converting JSON to String
    for (int i=0; i < 100; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        //Search
        string tempGender = gender;
        boost::algorithm::to_lower(tempGender);
        boost::algorithm::to_lower(key);
        if (strstr(tempGender.c_str(), key.c_str()))
        {
            found = true;
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

    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }

    cout << " \n-----------------------------------------------------------------\n";
}


void date_of_birth()
{
    Clear();

    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    //Variables
    bool found = false;
    int count = 0;
    string key;

    //Input
    cout << "Date Of Birth to search: ";
    cin >> key;
    cout << "\n\n";

    cout << " \n-----------------------------------------------------------------\n\n\n";

    //Converting JSON to String
    for (int i=0; i < 100; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        //Search
        string tempDateOfBirth = date_of_birth;
        boost::algorithm::to_lower(tempDateOfBirth);
        boost::algorithm::to_lower(key);
        if (strstr(tempDateOfBirth.c_str(), key.c_str()))
        {
            found = true;
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

    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }

    cout << " \n-----------------------------------------------------------------\n";
}

void interests()
{
    Clear();

    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);

    // Variables
    bool found = false;
    int count = 0;
    string key;

    // Input
    cout << "Interests to search: ";
    cin >> key;
    cout << "\n\n";

    cout << " \n-----------------------------------------------------------------\n\n\n";

    // Converting JSON to String
    for (int i = 0; i < 100; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);

        // Search
        string tempInterests = interests;
        boost::algorithm::to_lower(tempInterests);
        boost::algorithm::to_lower(key);
        if (strstr(tempInterests.c_str(), key.c_str()))
        {
            found = true;
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

    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }

    cout << " \n-----------------------------------------------------------------\n";
}


int main()
{
    Clear();
    int choice = welcome();
    Clear();
    switch (choice)
    {
        case 10:
            cout << "\n\n\nThank you for using our program :)\n";
            cout << "\n";
            break;

        case 1:
            name();
            break;
        
        case 2:
            sap_id();
            break;
        
        case 3:
            gender();
            break;
        
        case 4:
            date_of_birth();
            break;
        
        case 5:
            interests();
            break;
        
        default:
            cout << "\n\n\nWrong input!\nTry again...\n";
            break;
    }
}