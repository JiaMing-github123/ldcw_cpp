// Green City Smart Living System - Optimized for Online Compiler
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <limits>
#include <algorithm>

using namespace std;

class GreenCityCalculator {
private:
    string cityName;
    int population;
    double energyConsumption;
    double wasteGenerated;
    double transportEmissions;
    double greenSpacePercentage;

    void pressEnterToContinue() {
        cout << "\nPress Enter to continue...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
    }

public:
    GreenCityCalculator() : cityName(""), population(0), energyConsumption(0.0), 
        wasteGenerated(0.0), transportEmissions(0.0), greenSpacePercentage(0.0) {}

    void collectCityData() {
        cout << "\nEnter your city name: ";
        cin.ignore();
        getline(cin, cityName);

        cout << "Enter city population: ";
        while (!(cin >> population) || population <= 0) {
            cout << "Invalid input. Enter a positive integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter annual energy consumption (MWh): ";
        while (!(cin >> energyConsumption) || energyConsumption < 0) {
            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter annual waste generated (tons): ";
        while (!(cin >> wasteGenerated) || wasteGenerated < 0) {
            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter annual transport emissions (CO2 tons): ";
        while (!(cin >> transportEmissions) || transportEmissions < 0) {
            cout << "Invalid input. Enter a non-negative number: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Enter current green space percentage (%): ";
        while (!(cin >> greenSpacePercentage) || greenSpacePercentage < 0 || greenSpacePercentage > 100) {
            cout << "Invalid input. Enter a value between 0 and 100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    void calculateSustainabilityMetrics() {
        cout << "\n=== SUSTAINABILITY ANALYSIS FOR " << cityName << " ===" << endl;
        cout << fixed << setprecision(2);

        double energyPerCapita = energyConsumption / population;
        double wastePerCapita = wasteGenerated / population;
        double emissionsPerCapita = transportEmissions / population;

        double cityArea = population * 0.001;
        double greenSpaceArea = (cityArea * greenSpacePercentage) / 100;
        double greenSpacePerPerson = (greenSpaceArea * 1000000) / population;

        cout << "Energy consumption per capita: " << energyPerCapita << " MWh/person" << endl;
        cout << "Waste generation per capita: " << wastePerCapita << " tons/person" << endl;
        cout << "Transport emissions per capita: " << emissionsPerCapita << " tons CO2/person" << endl;
        cout << "Green space per person: " << greenSpacePerPerson << " m^2/person" << endl;

        calculateSustainabilityScore(energyPerCapita, wastePerCapita, emissionsPerCapita, greenSpacePerPerson);
    }

    void calculateSustainabilityScore(double energyPC, double wastePC, double emissionsPC, double greenSpacePC) {
        int energyScore = (energyPC <= 5.0) ? 25 : (energyPC <= 10.0) ? 20 : (energyPC <= 15.0) ? 15 : (energyPC <= 20.0) ? 10 : 5;
        int wasteScore = (wastePC <= 0.3) ? 25 : (wastePC <= 0.5) ? 20 : (wastePC <= 0.8) ? 15 : (wastePC <= 1.2) ? 10 : 5;
        int emissionsScore = (emissionsPC <= 2.0) ? 25 : (emissionsPC <= 4.0) ? 20 : (emissionsPC <= 6.0) ? 15 : (emissionsPC <= 8.0) ? 10 : 5;
        int greenSpaceScore = (greenSpacePC >= 15.0) ? 25 : (greenSpacePC >= 12.0) ? 20 : (greenSpacePC >= 9.0) ? 15 : (greenSpacePC >= 6.0) ? 10 : 5;

        int totalScore = energyScore + wasteScore + emissionsScore + greenSpaceScore;

        cout << "\n=== SUSTAINABILITY SCORE BREAKDOWN ===" << endl;
        cout << "Energy Efficiency Score: " << energyScore << "/25" << endl;
        cout << "Waste Management Score: " << wasteScore << "/25" << endl;
        cout << "Transport Emissions Score: " << emissionsScore << "/25" << endl;
        cout << "Green Space Score: " << greenSpaceScore << "/25" << endl;
        cout << "TOTAL SUSTAINABILITY SCORE: " << totalScore << "/100" << endl;

        provideSustainabilityRating(totalScore);
    }

    void provideSustainabilityRating(int score) {
        cout << "\n=== SUSTAINABILITY RATING ===" << endl;
        if (score >= 80) cout << "Rating: EXCELLENT - Your city is a model green city!" << endl;
        else if (score >= 65) cout << "Rating: GOOD - Your city is on the right track!" << endl;
        else if (score >= 50) cout << "Rating: MODERATE - There's room for improvement." << endl;
        else if (score >= 35) cout << "Rating: POOR - Significant improvements needed." << endl;
        else cout << "Rating: CRITICAL - Immediate action required." << endl;
    }

    void displayGreenCityTips() {
        cout << "\n=== GREEN LIVING TIPS ===" << endl;
        vector<string> tips = {
            "1. Use public transport or cycle",
            "2. Recycle and reduce plastic",
            "3. Save water and electricity",
            "4. Plant trees and support green spaces",
            "5. Use energy-efficient appliances"
        };
        for (const string& tip : tips) cout << tip << endl;
    }
};

void displayMenu() {
    cout << "\n=== GREEN CITY SMART LIVING SYSTEM ===" << endl;
    cout << "1. Analyze City Sustainability" << endl;
    cout << "2. View Green Living Tips" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice (1-3): ";
}

int main() {
    GreenCityCalculator calculator;
    int choice;
    bool run = true;

    while (run) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                calculator.collectCityData();
                calculator.calculateSustainabilityMetrics();
                break;
            case 2:
                calculator.displayGreenCityTips();
                break;
            case 3:
                cout << "\nThank you for using the Green City Smart Living System!" << endl;
                run = false;
                break;
            default:
                cout << "\nInvalid choice. Please try again." << endl;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n---------------------------------------";
    }
    return 0;
}