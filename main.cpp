#include <iostream>
#include <json/value.h>
#include <json/json.h>
#include <fstream>
#include <string>
#include <typeinfo>
#include <boost/algorithm/string.hpp>
#include <algorithm>

using namespace std;

int len;

class entry
{
    public:

        string name;
        string sapID;
        string gender;
        string dateOfBirth;
        string interests;
        string program;
        string branch;
        string commitees;
        int noOfCommitees;
} e[100];

void init()
{
    // Using fstream to get file pointer
    ifstream file("db.json");
    Json::Value actualJson;
    Json::Reader reader;
    Json::FastWriter fastWriter;

    // Using reader to parse json
    reader.parse(file, actualJson);
    len = actualJson.size();

    for (int i=0; i<len; i++)
    {
        string name = fastWriter.write(actualJson[i]["Name"]);
        string sap_id = fastWriter.write(actualJson[i]["SAP ID"]);
        string gender = fastWriter.write(actualJson[i]["Gender"]);
        string date_of_birth = fastWriter.write(actualJson[i]["Date Of Birth"]);
        string interests = fastWriter.write(actualJson[i]["Interests"]);
        string program = fastWriter.write(actualJson[i]["Program"]);
        string branch = fastWriter.write(actualJson[i]["Branch"]);
        string commitees = fastWriter.write(actualJson[i]["Commitees"]);
        e[i].name = name;
        e[i].sapID = sap_id;
        e[i].gender = gender;
        e[i].dateOfBirth = date_of_birth;
        e[i].interests = interests;
        e[i].program = program;
        e[i].branch = branch;
        e[i].commitees = commitees;

        std::string::difference_type n = std::count(commitees.begin(), commitees.end(), ',');
        e[i].noOfCommitees = n+1;
    }
}

void Clear()
{
    cout << "\x1B[2J\x1B[H";
    cout << "\x1B[2J\x1B[H";
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
    cout << "3 - Date Of Birth\n";
    cout << "4 - Interests\n";
    cout << "5 - Program\n";
    cout << "6 - Branch\n";
    cout << "7 - Commitees\n";
    cout << "8 - Students in more than 2 commitees\n";
    cout << "\n";
    cout << "Type 10 to EXIT\n";
    cout << "\n";
    cout << "Type here: ";
    cin >> input;
    return input;
}

void search(string field)
{
    Clear();
    string key;
    cout << "Enter " << field << " to search: ";
    cin >> key;
    cout << "\n\n";
    bool found = false;
    int count = 0;
    for (int i = 0; i < len; i++)
    {
        string tempName; 
        if (field == "name")
        {
            tempName = e[i].name;
        }
        else if (field == "SAP ID")
            {
                tempName = e[i].sapID; 
            }
        else if (field == "date of birth")
            {
                tempName = e[i].dateOfBirth;
            }
        else if (field == "interests")
            {
                tempName = e[i].interests;
            }
        else if (field == "program")
            {
                tempName = e[i].program;
            }
        else if (field == "branch")
            {
                tempName = e[i].branch;
            }
        else if (field == "commitees")
            {
                tempName = e[i].commitees;
            }

        boost::algorithm::to_lower(tempName);
        boost::algorithm::to_lower(key);
        if (strstr(tempName.c_str(), key.c_str()))
        {
            found = true;
            count++;
            cout << endl;
            cout << endl;
            cout << count << ". " << endl;
            cout << endl;
            cout << "Name: " << e[i].name << endl;
            cout << "SAP ID: " << e[i].sapID << endl;
            cout << "Gender: " << e[i].gender << endl;
            cout << "Date Of Birth: " << e[i].dateOfBirth << endl;
            cout << "Interests: " << e[i].interests << endl;
            cout << "Program: " << e[i].program << endl;
            cout << "Branch: " << e[i].branch<< endl;
            cout << "Commitees: " << e[i].commitees << endl;

            if (e[i].noOfCommitees > 2)
                {
                    cout << "**  THIS STUDENT IS IN MORE THAN 2 COMMITEES  **" << endl << endl;
                }
        }
    }
    if (!found)
    {
        cout << "No students matching the search :/\n\n";
    }
}

int main()
{
    bool f = false;
    int c = 0;
    init();
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
            search("name");
            break;

        case 2:
            search("SAP ID");
            break;

        case 3:
            search("date of birth");
            break;

        case 4:
            search("interests");
            break;

        case 5:
            search("program");
            break;

        case 6:
            search("branch");
            break;

        case 7:
            search("commitees");
            break;

        case 8:
            for (int i = 0; i < len; i++)
            {
                if (e[i].noOfCommitees > 2)
                {
                    f = true;
                    c++;
                    cout << endl;
                    cout << endl;
                    cout << c << ". " << endl;
                    cout << endl;
                    cout << "Name: " << e[i].name << endl;
                    cout << "SAP ID: " << e[i].sapID << endl;
                    cout << "Gender: " << e[i].gender << endl;
                    cout << "Date Of Birth: " << e[i].dateOfBirth << endl;
                    cout << "Interests: " << e[i].interests << endl;
                    cout << "Program: " << e[i].program << endl;
                    cout << "Branch: " << e[i].branch<< endl;
                    cout << "Commitees: " << e[i].commitees << endl;
                }
            }
            if (!f)
            { 
                cout << "No students matching the search :/\n\n";
            }
            break;

        default:
            cout << "\n\n\nWrong input!\nTry again...\n";
            break;
    }
}
