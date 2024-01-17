#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

int main() {
    vector<string>group, question, ID;
    string input, group_temp, question_temp, ID_temp;

    ifstream list;
    ofstream outputFile("output.csv");
    ofstream logFile("error_log.txt");

    list.open("file_list.csv");


    for (int lineNumber = 1; getline(list, input); lineNumber++ ) {
        for (int i = 0; i < size(input); i++) { input[i] = tolower(input[i]); }

        input.erase(remove(input.begin(), input.end(), ' '), input.end()); // Removing the spaces

        // Finding the groups of files
        int start = 0;
        int end = input.find("_");

        group_temp = input.substr(start, end - start); // Select the first section as group.

        // Group Checking
        if (group_temp.find("a") != string::npos) {
            group.push_back("a");
        }
        else if (group_temp.find("b") != string::npos) {
            group.push_back("b");
        }
        else if (group_temp.find("c") != string::npos) {
            group.push_back("c");
        }
        else if (group_temp.find("d") != string::npos) {
            group.push_back("d");
        }

        // Finding questions
        start = end + 1;
        if (input.find("_", start) != string::npos) {
            end = input.find("_", start);
            question_temp = input.substr(start, end - start);
        }
        else {
            logFile << "The line " << lineNumber << " couldn't processed.";
            group.erase(group.begin()+lineNumber-1);
            continue;
        }


        for (int j = 0; j < question_temp.size(); j++) {
            if (isdigit(question_temp.at(j))) {
                question.push_back(to_string(question_temp.at(j)));
            }
        }

        // Finding ID
        start = end + 1;
        end = input.find(".", start);
        ID_temp = input.substr(start, end - start);

        for (int k = 0; k < ID_temp.size(); k++) {
            if (!isdigit(ID_temp.at(k))) {
                ID_temp.erase(ID_temp.begin() + k);
            }
            while (ID_temp.size() > 10) {
                ID_temp.pop_back();
            }
        }

        //Checking the ID's depertmant code. If do not match consider suspected and add log file
        if(ID_temp.substr(2,6) != "110110"){logFile << "Depertmant code may be wrong: " << ID_temp << endl;};
        
        ID.push_back(ID_temp);

    }

    // Merging the question numbers
    for (int a = 0; a < question.size(); a++) {
        for (int b = a + 1; b < question.size(); b++) {
            if (ID.at(a) == ID.at(b) && question.at(a).find(question.at(b)) == string::npos) {
                question.at(a) = (question.at(a)) + ' ' + (question.at(b));
                ID.erase(ID.begin() + b);
                question.erase(question.begin() + b);
                group.erase(group.begin() + b);
                b--;
            }
        }
    }

    // Write titles into the output file
    outputFile << "Student List,GroupName,QuestionsAnswered" << endl;

    // Converting string question numbers to char and write all values to output file
    for (int r = 0; r < question.size(); r++) {
        vector<char> questions;
        int start = 0;
        int end = question[r].find(" ", start);
        questions.push_back(char(stoi(question[r].substr(start, end - start))));
        start = end + 1;
        if(start == 0){
            outputFile << ID.at(r) << ',' << group.at(r) << ',' << char(34) << questions[0] << char(34) << endl;
            continue;
        }
        end = question[r].find(" ", start);
        questions.push_back(char(stoi(question[r].substr(start, end - start))));
        start = end + 1;
        sort(questions.begin(),questions.end());
        if(start == 0){
            outputFile << ID.at(r) << ',' << group.at(r) << ',' << char(34) << questions[0] << " " << questions[1]  << char(34) << endl;
            continue;
        }
        end = question[r].find(" ", start);
        questions.push_back(char(stoi(question[r].substr(start, end - start))));
        sort(questions.begin(),questions.end());
        outputFile << ID.at(r) << ',' << group.at(r) << ',' << char(34) << questions[0] << " " << questions[1] << " " << questions[2] << char(34) << endl;
    }

    // Determine ID's which are duplicated(Their number have 2 different groups)
    for(int m=0;m<ID.size();m++){
        for(int y=m+1;y<ID.size();y++){
            if(ID.at(m)==ID.at(y)){
                logFile << "Duplicated ID: " << ID.at(m) << endl;
            }
        }
    }

    list.close();
    outputFile.close();
    logFile.close();
}