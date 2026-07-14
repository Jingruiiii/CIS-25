#include <iostream>
#include <fstream> //file library for reading csv file
#include <vector> //for storing data
#include <string> //for string manipulation
#include <iomanip> //for formatting output

//defining a class to hold player performance data
class worldCupPlayerPerformance {
public:
    // Defining member variables for player performance data
    std::string player_id;
    std::string player_name;
    std::string age;
    std::string nationality;
    std::string team;

    // Constructor: to inilialize the player performance data
    worldCupPlayerPerformance(std::string Id, std::string Name, std::string Age, std::string Nationality, std::string Team) {
        player_id = Id;
        player_name = Name;
        age = Age;
        nationality = Nationality;
        team = Team;
    }

    // definig a function to display the player performance data
    void viewdetails() {
        std::cout << std::left //make the output left-aligned
                  << std::setw(15) << player_id //set width for each column
                  << std::setw(25) << player_name
                  << std::setw(5)  << age
                  << std::setw(15) << nationality
                  << std::setw(15) << team << "\n";
    }
}; // The end of the class definition

//The main function starts
int main() {
    std::ifstream file("fifa_world_cup_2026_player_performance.csv"); //open the csv file
    if (!file.is_open()) {
        std::cerr << "File cannot be opened!\n"; //check if the file is opened successfully
        return 1; //exit the program with an error code
    }

    std::vector<std::string> first10Rows; //defining a vector to hold the first 10 rows of data
    std::string row;
    
    std::getline(file, row); //skip the first row, since it's a header

    //loop through the first 10 rows and extract the data
    for (int i = 0; i < 10 && std::getline(file, row); i++) {
        first10Rows.push_back(row);
    }

    file.close(); //close the file

    std::vector<worldCupPlayerPerformance> playerList;

    //loop through each row and extract the coloumns
    for (int i = 0; i < first10Rows.size(); i++) {
        std::string rowText = first10Rows[i];
        std::string id, name, age, nation, team;

        for (int j = 0; j < 5; j++) {
            int index = rowText.find(","); //find the position of the next comma
        
            std::string text = rowText.substr(0, index); //extract the text before the comma
            
            //match the column index to the corresponding variable
            if (j == 0){
                id = text;
            }
            else if (j == 1) {
                name = text;
            }
            else if (j == 2) {
                age = text;
            }
            else if (j == 3) {
                nation = text;
            }
            else if (j == 4) {
                team = text;
            }
            // update the rowText
            rowText = rowText.substr(index + 1);
        }

        worldCupPlayerPerformance currPlayer(id, name, age, nation, team);//Initiate a player object
        playerList.push_back(currPlayer); //add the player object to the player list
    }

    //displaying the header for the player performance data
    std::cout << std::left
              << std::setw(15) << "player_id"
              << std::setw(25) << "player_name"
              << std::setw(5)  << "age"
              << std::setw(15) << "nationality"
              << std::setw(15) << "team" << "\n";
    std::cout << "----------------------------------------------------------------------------\n";
    
    // displaying the data
    for (int i = 0; i < playerList.size(); i++) {
        playerList[i].viewdetails();
    }
  
    
    return 0;
}