/*
ZW for CS 32 - not for distribution - lab04- first redesign - playing with hierarchy
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <iomanip>
#include "dataAQ.h"
#include "demogData.h"
#include "comboDemogData.h"
#include "comboHospitalData.h"
#include "countyDemogData.h"
#include "comboHospitalData.h"
#include "hospitalData.h"
#include "cityHospitalData.h"
#include "parse.h"

using namespace std;

int main() {

	dataAQ theAnswers;


    cout << std::setprecision(2) << std::fixed;

    //read in the helper file to map city to county
    theAnswers.read_csvCityCounty("simple_uscities.csv");

    //read in the hospital data
    std::vector<shared_ptr<placeData>> theHospitalData = read_csv(
            "hospitals.csv", HOSPITAL);
   
    //read in the demographic data
    std::vector<shared_ptr<placeData>> theCountyDemogData = read_csv(
            "county_demographics.csv", DEMOG); 

    //create the state demographic data
    theAnswers.createStateDemogData((std::vector<shared_ptr<demogData>>&)theCountyDemogData);

    //create the state hospital data
    theAnswers.createStateHospData((std::vector<shared_ptr<hospitalData>>&)theHospitalData);

     //create the county hospital data   
    theAnswers.createCountyHospData((std::vector<shared_ptr<hospitalData>>&)theHospitalData);
    cout << "there are this many counties w hosp data: " << theAnswers.allCountyHData.size() << endl;

    //same as lab03 but using new types
    std::vector<comboHospitalData*> ShospHighToLow;
    theAnswers.sortHospRatingHighLow((std::vector<comboHospitalData *>& )ShospHighToLow, "state");
    cout << "the 10 state with highest hospital ratings sorted on overall: " << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << ShospHighToLow.at(i)->getRegion() << " " << ShospHighToLow.at(i)->getName();
        cout <<  " overall hospital rating: " << ShospHighToLow.at(i)->getOverallRate() << endl;
    }

    std::vector<comboHospitalData*> ChospLowHigh;
    theAnswers.sortHospRatingLowHigh((std::vector<comboHospitalData *>& )ChospLowHigh, "state");
    cout << "the 10 state with lowest hospital ratings sorted on overall: " << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << ChospLowHigh.at(i)->getRegion() << " " << ChospLowHigh.at(i)->getName();
        cout <<  " overall hospital rating: " << ChospLowHigh.at(i)->getOverallRate() << endl;
    }

    std::vector<comboDemogData*> povertyLevelLowToHigh;
    theAnswers.sortDemogPovLevelLowHigh((std::vector<demogData *>& )povertyLevelLowToHigh);
    cout << "the 10 states with lowest level of persons below the poverty line: " << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << povertyLevelLowToHigh.at(i)->getName();
        cout << " persons below poverty level: " << povertyLevelLowToHigh.at(i)->getBelowPoverty() << endl;
    }
    
    std::vector<comboDemogData*> povertyLevelHighLow;
    theAnswers.sortDemogPovLevelHighLow((std::vector<demogData *>& )povertyLevelHighLow);
    cout << "the 10 states with highest level of persons below the poverty line: "  << endl;
    for (int i=0; i < 10; i++) {
        cout << i<< " " << povertyLevelHighLow.at(i)->getName();
        cout << " persons below poverty level: " << povertyLevelHighLow.at(i)->getBelowPoverty() << endl;
    }

    /* NEW - sorted hospital county info by state - Specifically, CA */
    std::vector<comboHospitalData*> CAhospHighToLow;
    theAnswers.sortHospRatingHighLowForState((std::vector<comboHospitalData *>& )CAhospHighToLow, "CA");
    cout << "the California counties with highest hospital ratings sorted on overall: " << endl;
    for (int i=0; i < 10; i++) {
        cout <<  *(CAhospHighToLow.at(i)) << endl;
    }

    return 0;
}

