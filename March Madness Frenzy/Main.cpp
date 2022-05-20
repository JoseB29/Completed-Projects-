/* ---------------------------------------------
Program Name: March Madness Frenzy
System: Mac using Visual Studio Code
Author: Bolanos Jose
---------------------------------------------
*/

#include <iostream> //input and output
#include <fstream>    //used for reading in files
#include <vector>     //allows us to use vectors
#include <cassert>    
#include <cctype>     
#include <string>   //used for strig functions
#include <algorithm>  //used to find stuff like common occurences
#include <sstream>    //used to split lines by commas

using namespace std;

//------------------- BELOW ARE SOME UTILITY FUNCTIONS -------------------//

//startingMenuText() will display starting menu text
void startingMenuText () 
{
    cout << "Program 5: March Madness Frenzy\n" << 
    "CS 141, Spring 2022, UIC\n\n" << 
    "This program reads in data from NCAA Basketball Tournaments (aka March\n" << 
    "Madness). It provides overall information regarding the data, allows you to\n" << 
    "see the path taken to the championship, uses rankings of teams to determine\n" << 
    "which region is expected to win at a given round and to find the best underdog\n" <<
    "team, and calculates point differences within the games. You can also compare\n" <<
    "the actual brackets to your own predictions!\n\n" << 
    "Enter the name of the file with the data for the NCAA tournament:\n";
}  

//----------------------------------------------------------------------------------------------------------------//

// secondMenuStartingText() will display second menu text
void secondMenuStartingText ()
{
    cout << "Select a menu option:\n" << 
   "   1. Display overall information about the data\n" << 
   "   2. Display the path of the winning team to the championship\n" << 
   "   3. Determine which region is expected to win the championship based on a \n" << "given round\n" <<
   "   4. Identify the best underdog within a given round\n" <<
   "   5. Find the shoo-in and nail-biting games within a given round, or overall \n" << 
   "   6. Compare the actual brackets to your predicted brackets\n" << 
   "   7. Exit \n" << 
   "Your choice --> ";

}     

//----------------------------------------------------------------------------------------------------------------//

/* roundSelectionV1() will display the round options for menu option 3*/
void roundSelectionV1() 
{
    cout << "Enter a round to be evaluated:\n" //display round options
    <<"   Select 2 for round 2\n" << "   Select 3 for round 3 'Sweet 16'\n" << 
    "   Select 4 for round 4 'Elite 8'\n" << "   Select 5 for round 5 'Final 4'\n" << "Your choice --> ";
}

//----------------------------------------------------------------------------------------------------------------//

/* roundSelectionV2() will display the round option for menu option 4 */
void roundSelectionV2() 
{
    cout << "Enter a round to be evaluated:\n" //display round options
    << "   Select 2 for round 2\n" << "   Select 3 for round 3 'Sweet 16'\n" << 
    "   Select 4 for round 4 'Elite 8'\n" << "   Select 5 for round 5 'Final 4'\n" << "   Select 6 for round 6 'Championship'\n"
    << "Your choice --> ";
}

//----------------------------------------------------------------------------------------------------------------//

/* roundSelectionV3() will display the round option for menu option 5 */
void roundSelectionV3() 
{
    cout << "Enter a round to be evaluated:\n" //display round options
    << "   Select 1 for round 1\n" << "   Select 2 for round 2\n" << "   Select 3 for round 3 'Sweet 16'\n" << 
    "   Select 4 for round 4 'Elite 8'\n" << "   Select 5 for round 5 'Final 4'\n" << "   Select 6 for round 6 'Championship'\n" 
    << "   Select 7 for the overall tournament\n" << "Your choice --> ";
}

//----------------------------------------------------------------------------------------------------------------//

//this class will be used to read in the data from the csv files
class OverallBracketInfo
{       
  private:
  string region;    //used for region
  int rank1;    //used for rank 1
  string team1;    //used for team 1
  int score1;   //used for score 1
  int rank2;    //used for rank 2
  string team2;     //used for team 2  
  int score2;    //used for score 2
  string winningTeam;   //used winning team;
  int roundNumber;   //used for roundNumber
  int gameNumber;   //used for game number

  public:
    //below are the setters and getters for the variables provided above
    void setRegion(string region) { this->region = region;}
    string getRegion() {return region;}

    int setRank1(int rank1) { this->rank1 = rank1;}
    int getRank1() {return rank1;}

    void setTeam1(string team1) { this->team1 = team1;}
    string getTeam1() {return team1;}

    int setScore1(int score1) { this->score1 = score1;}
    int getScore1() {return score1;}

    int setRank2(int rank2) { this->rank2 = rank2;}
    int getRank2() {return rank2;}

    void setTeam2(string team2) { this->team2 = team2;}
    string getTeam2() {return team2;}

    int setScore2(int score2) { this->score2 = score2;}
    int getScore2() {return score2;}

    void setWinningTeam(string winningTeam) { this->winningTeam = winningTeam;}
    string getWinningTeam() {return winningTeam;}

    int setRoundNumber(int roundNumber) { this->roundNumber = roundNumber;}
    int getRoundNumber() {return roundNumber;}

    int setGameNumber(int gameNumber) { this->gameNumber = gameNumber;}
    int getGameNumber() {return gameNumber;}

};  //end of class definition

//----------------------------------------------------------------------------------------------------------------//

//this class will be used to diplay the chapmpionship path for menu option 2
class championshipPath {
    private:
    int round;      //will hold the round number of the game
    int gameNumber;     //will hold the game number
    string team1;   //will hold team one of the game
    string team2;   //will team two of the game
    string winningTeam;    //will hold the winning teams

    public:
    //below are the setters and getters for the variables provided above
    void setRoud(int round) {this-> round = round;}
    int getRound() {return round;}

    void setGameNumber ( int gameNumber) {this ->gameNumber = gameNumber; }
    int getGameNumber () {return gameNumber;}

    void setTeam1 (string team1) {this-> team1 = team1;}
    string getTeam1 () {return team1;}
    
    void setTeam2 (string team2) {this-> team2 = team2;}
    string getTeam2 () {return team2;}

    void setWinningTeam (string winningTeam) {this -> winningTeam = winningTeam;}
    string getWinningTeam() {return winningTeam;}

};

//----------------------------------------------------------------------------------------------------------------//

//this class will be used to hold all the information regarding the shoo-in and nail-bitting games (menu option 5)
class NailBittingGameAndShooInGamesInfo {

    private:
    string team1;   //will hold team one of the game
    string team2;   //will team two of the game
    string winningTeam;    //will hold the winning teams
    int round;      //will hold the round number of the game
    int gameNumber;     //will hold the game number
    int differenceInScore;  //will be used to hold the difference in scores

    public:     
    //below are the getters and setters for the variables provided above
    void setTeam1 (string team1) {this-> team1 = team1;}
    string getTeam1 () {return team1;}
    
    void setTeam2 (string team2) {this-> team2 = team2;}
    string getTeam2 () {return team2;}

    void setWinningTeam (string winningTeam) {this -> winningTeam = winningTeam;}
    string getWinningTeam() {return winningTeam;}

    void setRoud(int round) {this-> round = round;}
    int getRound() {return round;}

    void setGameNumber ( int gameNumber) {this ->gameNumber = gameNumber; }
    int getGameNumber () {return gameNumber;}

    void setDifferenceInScore (int differenceInScore) {this ->differenceInScore = differenceInScore;}
    int getDifferenceInScore () {return differenceInScore;}

};

//----------------------------------------------------------------------------------------------------------------//

/* openFileAndStoreInfo() reads in a file and stores it in a vector of classes. The parameters are the name of the file the user
wants to open and the vector whenre the file information will be stored */
void openFileAndStoreInfo(string fileName,  vector <OverallBracketInfo> & dataVector)
{
    ifstream aFile (fileName);      //open the file 

    if (aFile.is_open()) {}    //check that file is opened  
    else { cout << "failed to open " << endl;}

    string line;    //will hold lines as we go
    string region, rank1, team1, score1, rank2, team2, score2, winningTeam, roundNumber, gameNumber;        //hold specific data as we are reading in file
    getline(aFile, line);   //makes sure we do not read in the first line which is useless

    while (getline(aFile, line)) {    //parse everything accordingly as lines are being read in 
        OverallBracketInfo game;        //create instance of class
        stringstream sep (line);
        getline(sep, region, ',' );
        getline(sep, rank1, ',' );
        getline(sep, team1, ',' );
        getline(sep, score1, ',' );
        getline(sep, rank2, ',' );
        getline(sep, team2, ',' );
        getline(sep, score2, ',' );
        getline(sep, winningTeam, ',' );
        getline(sep, roundNumber, ',' );
        getline(sep, gameNumber, ',' );

        //use setters to assign variables to correspoding information variable
        game.setRegion(region);
        game.setRank1(stoi(rank1));
        game.setTeam1(team1);
        game.setRank2(stoi(rank2));
        game.setTeam2(team2); 
        game.setWinningTeam(winningTeam);
        game.setRoundNumber(stoi(roundNumber));
        game.setGameNumber(stoi(gameNumber));

        //check if white spaces are present, and if so take care of them to prevent erros
        if (score1 == "") {
            game.setScore1(0);
        }
        else {game.setScore1(stoi(score1));}

        if (score2 == "") {
            game.setScore2(0);
        }
        else {game.setScore2(stoi(score2));}

        dataVector.push_back(game);     //add class instace to vector 
    }
    
    aFile.close();      //close the file after we are done
}

//----------------------------------------------------------------------------------------------------------------//

/*getRegionsOfTeams() gets all the teams in the tournament and their regions. The parameters that are passed are the vector 
that has all the data from desired document, and the two vectors that we ae going to populate with the regions and teams in the 
tournament */
void getRegionsAndTeams(vector <OverallBracketInfo> & dataVector, vector <string> & teamsInTournament, vector <string> & regionsOfTeams) {
    for (int i = 3; i < dataVector.size(); ++i) {       //loop through info vector
        if (count(regionsOfTeams.begin(), regionsOfTeams.end(), dataVector.at(i).getTeam1())) {     
        }
        else {
            //if team 1 was not found in the vector of teams before add it with its region
            teamsInTournament.push_back(dataVector.at(i).getTeam1());
            regionsOfTeams.push_back(dataVector.at(i).getRegion());
        }

        if (count(regionsOfTeams.begin(), regionsOfTeams.end(), dataVector.at(i).getTeam2())) {
        }
        else {
            //if team 2 was not found in the vector of teams before add it with its region
            teamsInTournament.push_back(dataVector.at(i).getTeam2());
            regionsOfTeams.push_back(dataVector.at(i).getRegion());
        }
    }
}

//----------------------------------------------------------------------------------------------------------------//

/* getRegions() gets all four regions that were are in the tournament. The parameters are the vector that holds all the document data and 
the vector that will be populated with the regions */
void getRegions (vector <OverallBracketInfo> & dataVector, vector <string> & regionsInTournament) {
    
    regionsInTournament.push_back(dataVector.at(3).getRegion());    //get the first region
    regionsInTournament.push_back(dataVector.at(23).getRegion());   //get the second region
    regionsInTournament.push_back(dataVector.at(33).getRegion());   //get the third region
    regionsInTournament.push_back(dataVector.at(dataVector.size()-1).getRegion());  //get the fourth region

}
//----------------------------------------------------------------------------------------------------------------//


//---------------------------BELOW ARE THE FUNCTIONS THAT WILL BE USED FOR ALL MENU OPTIONS---------------------------//


//----------------------------------------------------------------------------------------------------------------//

/* menuOptionOne() will display the proper information for menu option one when called the parameter will be 
the vector of classes with all the information from the desired opened file, and a vector with all four regions present in the file */
void menuOptionOne(vector <OverallBracketInfo> & dataVector, vector <string> & regionsInTournament) {
    int sizeOfVector = dataVector.size();       //will hold the amount of games played
    string team1;        //holds name of team as we all looping through vector below
    string team2;        //holds name of team as we all looping through vector below
    vector <string> finalFour;      //will hold the final four teams 
    string region1, region2, region3, region4;      //will hold regions found


    for (int i = 0; i < dataVector.size(); ++i) {       //loop through info vector to find final four teams
        if (dataVector.at(i).getRegion() == "Final Four") {
            team1 = dataVector.at(i).getTeam1();
            team2 = dataVector.at(i).getTeam2();
            finalFour.push_back(team1);
            finalFour.push_back(team2);
        }
    }

    cout << "Total number of games played in tournament: " << sizeOfVector << "\n";

    //now look for region of the teams found in the teams vector 
    cout << "The Final Four contestants are:\n";
    
    //look for the region of each team
    for ( int i = 0; i < finalFour.size(); ++i) {   
        for  (int x = 3; x < dataVector.size(); ++x) {
            if ( finalFour.at(i) == dataVector.at(x).getWinningTeam()) {
                //save all teams and regions in appropriate way to correspoding variable
                if (dataVector.at(x).getRegion() == regionsInTournament.at(0)) {
                    region1 =  "        " +  regionsInTournament.at(0) + " region:    " + finalFour.at(i) + "\n";
                }
                else if (dataVector.at(x).getRegion() == regionsInTournament.at(1)) {
                    region2 = "        " +  regionsInTournament.at(1) + " region:   " + finalFour.at(i) + "\n";
                }
                else if (dataVector.at(x).getRegion() == regionsInTournament.at(2)) {
                    region3 = "        " + regionsInTournament.at(2) + " region:    " + finalFour.at(i) + "\n";
                }
                else if (dataVector.at(x).getRegion() == regionsInTournament.at(3)) {
                    region4 = + "        " + regionsInTournament.at(3) + " region: " + finalFour.at(i) + "\n";
                }
                break;
            }
        }
    } 


    cout << region1 << region2 << region3 << region4 << "\n\n";     //output the output that we got from loop above

}

//----------------------------------------------------------------------------------------------------------------//

/* menuOptionTwo() will display the proper information for menu option two when called
the parameter will be the vector of classes with all the information from the desired opened file*/
void menuOptionTwo (vector <OverallBracketInfo> & dataVector) {

    vector <championshipPath> winnigPathGames; //will hold all of the games
    
    //below we will find the winning team of the tournmanet by comparing scores
    string winningTeam; 
    if (dataVector.at(0).getScore1() > dataVector.at(0).getScore2()) 
    {
        winningTeam = dataVector.at(0).getTeam1();
    }
    else if (dataVector.at(0).getScore1() < dataVector.at(0).getScore2()) 
    {
        winningTeam = dataVector.at(0).getTeam2();
    } 


    cout << "Path to the championship:\n";

    //look for winning path of winning team
    for (int i = 0; i < dataVector.size(); ++i)
    {
        if ((winningTeam == dataVector.at(i).getWinningTeam()) )
        {   
            championshipPath game;      //create instance of class that will hold the info of all games that the winner of the tournment played

            //set all vars. using setters
            game.setRoud(dataVector.at(i).getRoundNumber());
            game.setGameNumber(dataVector.at(i).getGameNumber());
            game.setTeam1(dataVector.at(i).getTeam1());
            game.setTeam2(dataVector.at(i).getTeam2());
            game.setWinningTeam(winningTeam);

            winnigPathGames.push_back(game);    //add class instance to a vector of classes
        }
    }

    for (int i = 0; i < 7; ++ i) {
        for (int x = winnigPathGames.size() -1 ; x >= 0; --x)       //lopp through vector backwrds containing games that winner played
        {
            if (i == winnigPathGames.at(x).getRound()) {
                //dipslay appropriate format for eveyr game
                cout << "Round " << winnigPathGames.at(x).getRound() << ", Game "<< winnigPathGames.at(x).getGameNumber() <<": " << winnigPathGames.at(x).getTeam1() << " vs "
                << winnigPathGames.at(x).getTeam2() << ". Winner: " << winnigPathGames.at(x).getWinningTeam() << "\n";
            } 
        }
    }

    cout << "\n\n";
}// end of menu option two funtion

//----------------------------------------------------------------------------------------------------------------//

/* getFinalFourRegions() will find most likely region to win it all if user inputs round 5 (final four). 
This functionis only used in menu option three. The parameters are the vector of classes with all the information from the desired opened file, the variable 
that will hold the possible winning region,a vector that contains all of the teams in the tournaments, a parallel vector 
with all the regions of the peviously listed teams, and a vector with only the four regions in the tournament */
void getFinalFourRegions(vector <OverallBracketInfo> & dataVector, string & possibleWinningRegion, vector <string> & regionsInTournament, vector <string> teamsInTournament, vector <string> regionsOfTeams)  {
    
    string team1, team2, lowestSeededTeam;        //will be used to hold teams 1 and 2 as we loop through through data vector
    int team1Seed = 0, team2Seed = 0;       //will be used to hold the seeds of teams 1 and 2 as we loop through data vector
    vector <string> finalFour;      //will hold all final four teans
    vector <int> seedOfFinalFour;       //will hold the ranks of the final four teams
    vector <string> possibleWinningTeams;       //will hold team/teams with the smallest seed out of all of the final four

    //loop through info vector to find final four teams and their seeds
    for (int i = 0; i < dataVector.size(); ++i) {       
        if (dataVector.at(i).getRegion() == "Final Four") {
            team1 = dataVector.at(i).getTeam1();
            team1Seed = dataVector.at(i).getRank1();

            team2 = dataVector.at(i).getTeam2();
            team2Seed = dataVector.at(i).getRank2();

            //add the info. found to the vectors that will hold the final four teams and their seeds
            finalFour.push_back(team1);
            seedOfFinalFour.push_back(team1Seed);

            finalFour.push_back(team2);
            seedOfFinalFour.push_back(team2Seed);

        }
    }
    
    //find the index position of the smallest seed
    int indexOfSmallestSeed = min_element(seedOfFinalFour.begin(),seedOfFinalFour.end()) - seedOfFinalFour.begin();
    int smallestSeed = seedOfFinalFour.at(indexOfSmallestSeed);

    //using index found above, look for possible winning teams (these are parallel vectors)
    for (int i = 0; i < finalFour.size(); ++ i) {
        if (seedOfFinalFour.at(i) == smallestSeed) {
            possibleWinningTeams.push_back(finalFour.at(i));
        }
    }

    //find the reagion of that team or teams
    if ( possibleWinningTeams.size() == 1) {     //will activate if there is no tie for smallest seed
        //look for the region 
        auto it = find(teamsInTournament.begin(), teamsInTournament.end(), possibleWinningTeams.at(0));

        //calculate index
        int indexForRegion = it - teamsInTournament.begin();
        possibleWinningRegion = regionsOfTeams.at(indexForRegion);
    }

    else {      //wil activate if there is a tie for smallest seed

        //find the teams that tied within that vector of overall teams in the torunamnet
        auto x = find(teamsInTournament.begin(), teamsInTournament.end(), possibleWinningTeams.at(0)); 
        auto i = find(teamsInTournament.begin(), teamsInTournament.end(), possibleWinningTeams.at(1));

        //calculate index of using the info we got above
        int indexforRegionOne = x - teamsInTournament.begin();
        int indexforRegionTwo = i - teamsInTournament.begin();

        /*now we look for the index position that is the smallest (that indictaes that the region is dipslayed first in the doc.
        containing all the info) */
        if (indexforRegionOne > indexforRegionTwo) {
            possibleWinningRegion = regionsOfTeams.at(indexforRegionTwo);       //set region using the index calculated above and the vector with regions
        }

        else if (indexforRegionOne < indexforRegionTwo) {
            possibleWinningRegion = regionsOfTeams.at(indexforRegionOne);       //set region using the index calculated above and the vector with regions
        }
    }

}

//----------------------------------------------------------------------------------------------------------------//

/* menuOptionThree() will display the proper information for menu option three when called
the parameter will be the vector of classes with all the information from the desired opened file, a vectro that contains all of the teams 
in the tournaments, a parallel vector with all the regions of the peviously listed teams, and a vector with only the four regions in the tournament*/
void menuOptionThree(vector <OverallBracketInfo> & dataVector, vector <string> & regionsInTournament, vector <string> teamsInTournament, vector <string> regionsOfTeams) {
    int userChoiceRound;    //used to determine what round user wants to examine
    vector <int> seedNumbers;       //vector will hold seed numbers
    int regionTwoCount = 0 , regionOneCount = 0,  regionThreeCount = 0, regionFourCount = 0;       //vars that will be holding the seed numbers

    string possibleWinningRegion;   //will be assigned to a region later on

    for (int i = 0; i < 4; ++i) {   //populate vector that will be holding seed count numbers
        seedNumbers.push_back(0);
    }

    roundSelectionV1();     //displays round options text
    cin >> userChoiceRound; //get user round choice
    cout << "Analyzing round " << userChoiceRound <<"...\n";

    if (userChoiceRound == 5) //this part will activate if the user chose round 5
    {
        getFinalFourRegions(dataVector, possibleWinningRegion, regionsInTournament, teamsInTournament, regionsOfTeams );        //call function that will do the final four calculations
    }
    else    //will actvate for any other round that is not 5
    {
        for (int i = 0; i < dataVector.size(); ++i) {       //loop through data vector
            
            if (dataVector.at(i).getRoundNumber() == userChoiceRound) {     //narrow down the serch the round that the user choose

                //below we will look for the regions that are being examined and then we will add the rank of the winning team to that regions corresponsing counter
                if (dataVector.at(i).getRegion() == regionsInTournament.at(0)){
                    if (dataVector.at(i).getScore1() > dataVector.at(i).getScore2()) {regionOneCount += dataVector.at(i).getRank1();}
                    else {regionOneCount += dataVector.at(i).getRank2();}
                }

                else if (dataVector.at(i).getRegion() == regionsInTournament.at(2)){
                    if (dataVector.at(i).getScore1() > dataVector.at(i).getScore2()) {regionThreeCount += dataVector.at(i).getRank1();}
                    else {regionThreeCount += dataVector.at(i).getRank2();}
                }

                else if (dataVector.at(i).getRegion() == regionsInTournament.at(1)){
                    if (dataVector.at(i).getScore1() > dataVector.at(i).getScore2()) {regionTwoCount += dataVector.at(i).getRank1();}
                    else {regionTwoCount += dataVector.at(i).getRank2();}
                }

                else if (dataVector.at(i).getRegion() == regionsInTournament.at(3)) {
                    if (dataVector.at(i).getScore1() > dataVector.at(i).getScore2()) {regionFourCount += dataVector.at(i).getRank1();}
                    else {regionFourCount += dataVector.at(i).getRank2();}
                }

            }
            
        }

        /* IF THE ROUND SELECTED WAS 5, THE FOLLOWING CODE WILL NOT APPLY */
        //add those counter numbers we got to a vector
        seedNumbers.at(0) = regionOneCount;
        seedNumbers.at(1) = regionTwoCount;
        seedNumbers.at(2) = regionThreeCount;
        seedNumbers.at(3) = regionFourCount;

        //look for the index of the smallest counter 
        int indexOfSmallestSeed = min_element(seedNumbers.begin(),seedNumbers.end()) - seedNumbers.begin();

        //use the index we found above and match the region using the vector we passed as a parameter that holds all of the regions in the tournaments
        if (indexOfSmallestSeed == 0) {possibleWinningRegion = regionsInTournament.at(0);}
        else if (indexOfSmallestSeed == 1) {possibleWinningRegion = regionsInTournament.at(1);}
        else if (indexOfSmallestSeed == 2) {possibleWinningRegion = regionsInTournament.at(2);}
        else if (indexOfSmallestSeed == 3) {possibleWinningRegion = regionsInTournament.at(3);}
    }


    //now we output our result
    cout << "\nThe region expected to win is: " << possibleWinningRegion;
    cout << "\n\n";
}

//----------------------------------------------------------------------------------------------------------------//

/* menuOptionFour() will display the proper information for menu option four when called
the parameter will be the vector of classes with all the information from the desired opened file*/
void menuOptionFour(vector <OverallBracketInfo> & dataVector) {
    int userChoiceRound;    //will hold user round choice
    roundSelectionV2();     //displays round options text
    cin >> userChoiceRound; //get user round choice

    vector <string> possibleUnderdogteams;      //will hold the possile underdog teams
    vector <int> underdogRanks;     //will hold the rank of the possible underdog teams

    //loop through vector with doc. information
    for (int i = 0; i < dataVector.size(); ++ i) {
        //narrow down to check the round that we are looking at
        if (dataVector.at(i).getRoundNumber() == userChoiceRound) {

            //push the ranks and teams into paralel vectors
            underdogRanks.push_back(dataVector.at(i).getRank1());
            possibleUnderdogteams.push_back( dataVector.at(i).getTeam1());

            underdogRanks.push_back(dataVector.at(i).getRank2());
            possibleUnderdogteams.push_back(dataVector.at(i).getTeam2());
        } 
    }

    //look for the index of the biggest rank
    int maxRankIndex = max_element(underdogRanks.begin(),underdogRanks.end()) - underdogRanks.begin();

    //use the index found above to display propper message
    cout << "\nThe best underdog team is " << possibleUnderdogteams.at(maxRankIndex) 
    << " which has rank " << underdogRanks.at(maxRankIndex) << ".\n\n";
    
}

//----------------------------------------------------------------------------------------------------------------//

/* menuOptionFive() will display the proper information for menu option five when called
the parameter will be the vector of classes with all the information from the desired opened file*/
void menuOptionFive(vector <OverallBracketInfo> & dataVector) {
    int userChoiceRound, scoreDifference = 0;       //will be used to the round the user wannts to examine and the difference in scores when looping through data vector
    vector <NailBittingGameAndShooInGamesInfo> games;       //this will hold classes of all game info. with difference in scores
    vector <int> scoreDifferences;      //will hold all scores and will be used to find index of smallestand biggest score difference
    roundSelectionV3();
    cin >> userChoiceRound; //get user round choice

    //outputs appropriate message depending on round choice
    if (userChoiceRound != 7) 
    {
        cout << "Analyzing round " << userChoiceRound << "...\n\n";
    }     
    else 
    {
        cout << "Analyzing the overall tournament...\n\n";
    }

    if (userChoiceRound == 7) {     //will activate if user wants info for overall tournamnet

        for (int i = 0; i < dataVector.size(); ++i) {
            //the following decides in what order the subtractioin will take to find the difference in score and avoid negative numbers
            if (dataVector.at(i).getWinningTeam() == dataVector.at(i).getTeam1()) {
                scoreDifference = dataVector.at(i).getScore1() - dataVector.at(i).getScore2();
            }
            else if (dataVector.at(i).getWinningTeam() == dataVector.at(i).getTeam2()) {
                scoreDifference = dataVector.at(i).getScore2() - dataVector.at(i).getScore1();
            }

            NailBittingGameAndShooInGamesInfo game;     //create instance of a class

            //set appropritate variables using setters
            game.setRoud(dataVector.at(i).getRoundNumber());
            game.setGameNumber(dataVector.at(i).getGameNumber());
            game.setTeam1(dataVector.at(i).getTeam1());
            game.setTeam2(dataVector.at(i).getTeam2());
            game.setWinningTeam(dataVector.at(i).getWinningTeam());
            game.setDifferenceInScore(scoreDifference);

            games.push_back(game);      //add instance into vector
        }
    }

    else {      //will activate if the user wants to look at a specified round
        for (int i = 0; i < dataVector.size(); ++i) {
            if (dataVector.at(i).getRoundNumber() == userChoiceRound ) {        //look into the round the user chose
                //the following decides in what order the subtractioin will take to find the difference in score and avoid negative numbers
                if (dataVector.at(i).getWinningTeam() == dataVector.at(i).getTeam1()) {
                    scoreDifference = dataVector.at(i).getScore1() - dataVector.at(i).getScore2();
                }
                else if (dataVector.at(i).getWinningTeam() == dataVector.at(i).getTeam2()) {
                    scoreDifference = dataVector.at(i).getScore2() - dataVector.at(i).getScore1();
                }

                NailBittingGameAndShooInGamesInfo game;     //create instance of class 
                
                //set appropritate variables using setters
                game.setRoud(dataVector.at(i).getRoundNumber());
                game.setGameNumber(dataVector.at(i).getGameNumber());
                game.setTeam1(dataVector.at(i).getTeam1());
                game.setTeam2(dataVector.at(i).getTeam2());
                game.setWinningTeam(dataVector.at(i).getWinningTeam());
                game.setDifferenceInScore(scoreDifference);

                games.push_back(game);      //add instace into vector 
            }
        }
    }

    for (int i = 0; i < games.size(); ++ i ) {          //populate vector with all the difference in scores
        scoreDifferences.push_back(games.at(i).getDifferenceInScore());
    } 

    int maxDifferenceScoreIndex = max_element(scoreDifferences.begin(),scoreDifferences.end()) - scoreDifferences.begin();      //find biggest difference in score
    int minDifferenceScoreIndex = min_element(scoreDifferences.begin(),scoreDifferences.end()) - scoreDifferences.begin();      //find the smallest difference in scores

    //below we will use the indexes found above to diplay the shoo-in game and the nail-bitting game
    cout << "The shoo-in game was:\nRound " << games.at(maxDifferenceScoreIndex).getRound() << ", Game " << games.at(maxDifferenceScoreIndex).getGameNumber() << ": " <<
    games.at(maxDifferenceScoreIndex).getTeam1() << " vs " << games.at(maxDifferenceScoreIndex).getTeam2() << ". Winner: " << games.at(maxDifferenceScoreIndex).getWinningTeam() 
    << "\nThe difference was " << games.at(maxDifferenceScoreIndex).getDifferenceInScore() << " points.\n\n";

    cout << "The nail-biting game was:\nRound " << games.at(minDifferenceScoreIndex).getRound() << ", Game " << games.at(minDifferenceScoreIndex).getGameNumber() << ": " <<
    games.at(minDifferenceScoreIndex).getTeam1() << " vs " << games.at(minDifferenceScoreIndex).getTeam2() << ". Winner: " << games.at(minDifferenceScoreIndex).getWinningTeam() 
    << "\nThe difference was " << games.at(minDifferenceScoreIndex).getDifferenceInScore() << " points.\n\n\n";

}

//----------------------------------------------------------------------------------------------------------------//

/* menuOptionSix() will display the proper information for menu option six when called
the parameter will be the vector of classes with all the information from the desired opened file*/
void menuOptionSix(vector <OverallBracketInfo> & dataVector) {
    string predictionFileName;      //will hold user file name input
    vector <OverallBracketInfo> predictionBracket;      //will hold all info of the prediction file the user choses
    cout << "Enter the name of the file with your predicted brackets:\n";
    cin >> predictionFileName;
    openFileAndStoreInfo(predictionFileName, predictionBracket);    //open prediction file and store in a vector

    int scoreOfPredictions = 0, numberOfCorrectPredictions = 0;     //will hold total correct guessed and 

    for ( int i = 0; i < dataVector.size(); ++i ) {     //loop though both vectors
        if (dataVector.at(i).getWinningTeam() == predictionBracket.at(i).getWinningTeam()) {
            scoreOfPredictions += 5 * dataVector.at(i).getRoundNumber();        //if winning teams is the same in the same game score will be added
            ++numberOfCorrectPredictions;       //add to overall corect game guessed counted
        }
    }

    if (scoreOfPredictions >= 250) {            //will display proper message if the target score is met
        cout << "You correctly predicted the winner for " << numberOfCorrectPredictions << " games.\n"
        << "This means that you have a score of " << scoreOfPredictions << ".\n"
        << "Great job! You could consider entering your predictions to win money!\n\n";
    }
    else {          //will display proper message if the target score is not met
        cout << "You correctly predicted the winner for " << numberOfCorrectPredictions << " games.\n"
        << "This means that you have a score of " << scoreOfPredictions << ".\n"
        << "You may want to learn more about basketball to improve your predictions next\nyear.\n\n";
    }
    
}

//----------------------------------------------------------------------------------------------------------------//

//file names for easy access
// mens_bracket_2021.csv, mens_bracket_2021_predictions1.csv, womens_bracket_2022.csv
int main () 
{
    vector <OverallBracketInfo> dataVector;        //will hold data from desired file 
    string userFileChoice;  //used to hold user choice of file
    string programStatus = "inProgress";        //controls the loop of the program
    vector <string> teamsInTournament;      //vector that will hold all teams in tournamnet 
    vector <string> regionsOfTeams;         //parallel vector for vector above that will hold region for every team in tournament
    vector <string> regionsInTournament;        //will hold the 4 reagions present in the file 
    startingMenuText();
    cin >> userFileChoice; cout << "\n";    //accept input for the file the usre wants to open and use  
    openFileAndStoreInfo(userFileChoice, dataVector);   //calls function that opens the file the user wants to use
    getRegionsAndTeams(dataVector, teamsInTournament, regionsOfTeams);   //find all teams and regions in the document
    getRegions (dataVector, regionsInTournament);

    while (programStatus == "inProgress") {
        int userFileChoiceTwo; // will be used to accept options for menu 2
        secondMenuStartingText();
        cin >> userFileChoiceTwo; cout << "\n";  //get user input for menu choice 2

        if (userFileChoiceTwo == 1) {
            menuOptionOne(dataVector, regionsInTournament);     //call function for menu option 1
        }

        else if (userFileChoiceTwo == 2) {
            menuOptionTwo(dataVector);      //call function for menu option 2
        }

        else if (userFileChoiceTwo == 3) {
            menuOptionThree(dataVector, regionsInTournament, teamsInTournament, regionsOfTeams);        //call function for menu option 3
        }

        else if (userFileChoiceTwo == 4) {
            menuOptionFour(dataVector);     //call function for menu option 4
        }

        else if (userFileChoiceTwo == 5) {
            menuOptionFive(dataVector);     //call function for menu option 5
        }

        else if (userFileChoiceTwo == 6) {
            menuOptionSix(dataVector);      //call funcrtion for menu option 6
        }

        else if (userFileChoiceTwo == 7) {
            cout << "Exiting program...\n";     //exit program and display approprite message
            exit(0);
        }

        else {
            cout << "Invalid value.  Please re-enter a value from the menu options below.\n\n";     //will activate if option chosen is invalid
        }
    }
}