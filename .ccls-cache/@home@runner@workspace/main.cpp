#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cstdlib>

using namespace std;

void clearScreen() {
    cout<<"";
}

class GreenCityCalculator {
private:
    string cityName;
    int population;
    double energyConsumption;
    double wasteGenerated;
    double transportEmissions;
    double greenSpacePercentage;

public:
    // Constructor
    GreenCityCalculator() {
        cityName = "";
        population = 0;
        energyConsumption = 0.0;
        wasteGenerated = 0.0;
        transportEmissions = 0.0;
        greenSpacePercentage = 0.0;
    }

    // Function to collect user input
    void collectCityData() {
        clearScreen();
        cout << "\nEnter your city name: ";
        cin.ignore(); // Clear input buffer
        getline(cin, cityName);

        cout << "Enter city population: ";
        cin >> population;

        cout << "Enter annual energy consumption (MWh): ";
        cin >> energyConsumption;

        cout << "Enter annual waste generated (tons): ";
        cin >> wasteGenerated;

        cout << "Enter annual transport emissions (CO2 tons): ";
        cin >> transportEmissions;

        cout << "Enter current green space percentage (%): ";
        cin >> greenSpacePercentage;
    }

    // Function to calculate sustainability metrics
    void calculateSustainabilityMetrics() {
        clearScreen();
        cout << "\n=== SUSTAINABILITY ANALYSIS FOR " << cityName << " ===" << endl;
        cout << fixed << setprecision(2);

        // Energy efficiency per capita
        double energyPerCapita = energyConsumption / population;
        cout << "Energy consumption per capita: " << energyPerCapita << " MWh/person" << endl;

        // Waste generation per capita
        double wastePerCapita = wasteGenerated / population;
        cout << "Waste generation per capita: " << wastePerCapita << " tons/person" << endl;

        // Transport emissions per capita
        double emissionsPerCapita = transportEmissions / population;
        cout << "Transport emissions per capita: " << emissionsPerCapita << " tons CO2/person" << endl;

        // Green space adequacy (WHO recommends 9m?person minimum)
        double cityArea = population * 0.001; // Estimated city area in km?
        double greenSpaceArea = (cityArea * greenSpacePercentage) / 100;
        double greenSpacePerPerson = (greenSpaceArea * 1000000) / population; // Convert to m?
        cout << "Green space per person: " << greenSpacePerPerson << " m?person" << endl;

        // Calculate sustainability score
        calculateSustainabilityScore(energyPerCapita, wastePerCapita, emissionsPerCapita, greenSpacePerPerson);
    }

    // Function to calculate overall sustainability score
    void calculateSustainabilityScore(double energyPC, double wastePC, double emissionsPC, double greenSpacePC) {
        cout << "\n=== SUSTAINABILITY SCORE BREAKDOWN ===" << endl;

        int energyScore = 0, wasteScore = 0, emissionsScore = 0, greenSpaceScore = 0;

        // Energy scoring (lower is better)
        if (energyPC <= 5.0) energyScore = 25;
        else if (energyPC <= 10.0) energyScore = 20;
        else if (energyPC <= 15.0) energyScore = 15;
        else if (energyPC <= 20.0) energyScore = 10;
        else energyScore = 5;

        // Waste scoring (lower is better)
        if (wastePC <= 0.3) wasteScore = 25;
        else if (wastePC <= 0.5) wasteScore = 20;
        else if (wastePC <= 0.8) wasteScore = 15;
        else if (wastePC <= 1.2) wasteScore = 10;
        else wasteScore = 5;

        // Emissions scoring (lower is better)
        if (emissionsPC <= 2.0) emissionsScore = 25;
        else if (emissionsPC <= 4.0) emissionsScore = 20;
        else if (emissionsPC <= 6.0) emissionsScore = 15;
        else if (emissionsPC <= 8.0) emissionsScore = 10;
        else emissionsScore = 5;

        // Green space scoring (higher is better)
        if (greenSpacePC >= 15.0) greenSpaceScore = 25;
        else if (greenSpacePC >= 12.0) greenSpaceScore = 20;
        else if (greenSpacePC >= 9.0) greenSpaceScore = 15;
        else if (greenSpacePC >= 6.0) greenSpaceScore = 10;
        else greenSpaceScore = 5;

        int totalScore = energyScore + wasteScore + emissionsScore + greenSpaceScore;

        cout << "Energy Efficiency Score: " << energyScore << "/25" << endl;
        cout << "Waste Management Score: " << wasteScore << "/25" << endl;
        cout << "Transport Emissions Score: " << emissionsScore << "/25" << endl;
        cout << "Green Space Score: " << greenSpaceScore << "/25" << endl;
        cout << "----------------------------------------" << endl;
        cout << "TOTAL SUSTAINABILITY SCORE: " << totalScore << "/100" << endl;

        provideSustainabilityRating(totalScore);
    }

    // Function to provide sustainability rating and recommendations
    void provideSustainabilityRating(int score) {
        cout << "\n=== SUSTAINABILITY RATING ===" << endl;

        if (score >= 80) {
            cout << "Rating: EXCELLENT - " << cityName << " is a model green city!" << endl;
            cout << "Your city demonstrates outstanding sustainable practices." << endl;
        } else if (score >= 65) {
            cout << "Rating: GOOD - " << cityName << " is on the right track!" << endl;
            cout << "Your city shows strong commitment to sustainability with room for improvement." << endl;
        } else if (score >= 50) {
            cout << "Rating: MODERATE - " << cityName << " has potential for improvement." << endl;
            cout << "Your city needs focused efforts in key sustainability areas." << endl;
        } else if (score >= 35) {
            cout << "Rating: POOR - " << cityName << " requires significant improvements." << endl;
            cout << "Urgent action needed to implement sustainable urban practices." << endl;
        } else {
            cout << "Rating: CRITICAL - " << cityName << " needs immediate intervention." << endl;
            cout << "Major sustainability reforms required across all sectors." << endl;
        }

        provideSmartCityRecommendations(score);
    }

    // Function to provide smart city recommendations
    void provideSmartCityRecommendations(int score) {
        cout << "\n=== SMART CITY RECOMMENDATIONS ===" << endl;

        vector<string> recommendations;

        recommendations.push_back("1. Implement IoT-based smart grid systems for efficient energy distribution");
        recommendations.push_back("2. Deploy smart waste management with sensor-equipped bins");
        recommendations.push_back("3. Introduce electric public transportation and charging infrastructure");
        recommendations.push_back("4. Create smart traffic management systems to reduce emissions");
        recommendations.push_back("5. Develop urban farming and vertical gardens for food security");
        recommendations.push_back("6. Install smart water management systems to prevent wastage");
        recommendations.push_back("7. Build green buildings with smart energy management");
        recommendations.push_back("8. Implement citizen engagement apps for environmental monitoring");

        if (score < 65) {
            cout << "Priority recommendations for " << cityName << ":" << endl;
            for (int i = 0; i < min(5, (int)recommendations.size()); i++) {
                cout << recommendations[i] << endl;
            }
        } else {
            cout << "Advanced smart city features to consider:" << endl;
            for (int i = 5; i < recommendations.size(); i++) {
                cout << recommendations[i] << endl;
            }
        }
    }

    // Function to calculate potential improvements
    void calculatePotentialImprovements() {
        clearScreen();
        cout << "\n=== POTENTIAL IMPACT CALCULATOR ===" << endl;

        char choice;
        cout << "Would you like to see the potential impact of implementing smart solutions? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            clearScreen();
            cout << "\n=== POTENTIAL IMPACT ANALYSIS ===" << endl;

            // Potential energy savings (20-30% with smart grid)
            double energySavings = energyConsumption * 0.25;
            cout << "\nWith Smart Grid Implementation:" << endl;
            cout << "Potential energy savings: " << energySavings << " MWh annually" << endl;
            cout << "CO2 reduction: " << energySavings * 0.4 << " tons annually" << endl;

            // Waste reduction potential (15-25% with smart management)
            double wasteReduction = wasteGenerated * 0.20;
            cout << "\nWith Smart Waste Management:" << endl;
            cout << "Potential waste reduction: " << wasteReduction << " tons annually" << endl;
            cout << "Recycling improvement: " << wasteReduction * 0.6 << " tons annually" << endl;

            // Transport emission reduction (30-40% with smart mobility)
            double emissionReduction = transportEmissions * 0.35;
            cout << "\nWith Smart Mobility Solutions:" << endl;
            cout << "Potential emission reduction: " << emissionReduction << " tons CO2 annually" << endl;
            cout << "Air quality improvement: Significant reduction in PM2.5 and NOx levels" << endl;

            // Economic benefits
            double economicSavings = (energySavings * 100) + (wasteReduction * 150) + (emissionReduction * 50);
            cout << "\nEstimated Annual Economic Benefits: $" << economicSavings << " thousand" << endl;
        }
    }

    // Function to display green city tips
    void displayGreenCityTips() {
        clearScreen();
        cout << "\n=== GREEN LIVING TIPS FOR CITIZENS ===" << endl;
        cout << "1. Use public transportation or electric vehicles" << endl;
        cout << "2. Practice waste segregation and recycling" << endl;
        cout << "3. Install solar panels for renewable energy" << endl;
        cout << "4. Use smart home devices to monitor energy consumption" << endl;
        cout << "5. Participate in community gardening projects" << endl;
        cout << "6. Choose energy-efficient appliances" << endl;
        cout << "7. Support local sustainable businesses" << endl;
        cout << "8. Use water-saving devices and rainwater harvesting" << endl;
        cout << "9. Advocate for green policies in local government" << endl;
        cout << "10. Join environmental awareness programs" << endl;
    }
};

// Function to display program menu
void displayMenu() {
    cout << "\n=== GREEN CITY SMART LIVING SYSTEM ===" << endl;
    cout << "1. Analyze City Sustainability" << endl;
    cout << "2. Calculate Potential Improvements" << endl;
    cout << "3. View Green Living Tips" << endl;
    cout << "4. Exit Program" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    GreenCityCalculator calculator;
    int choice;
    bool dataCollected = false;
    flag: 
    do {
        clearScreen();
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                calculator.collectCityData();
                calculator.calculateSustainabilityMetrics();
                dataCollected = true;
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 2:
                if (dataCollected) {
                    calculator.calculatePotentialImprovements();
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                     goto flag; 
                } else {
                    clearScreen();
                    cout << "\n=== ERROR ===" << endl;
                    cout << "Please analyze city sustainability first (Option 1)." << endl;
                    cout << "\nPress Enter to continue...";
                    cin.ignore();
                    cin.get();
                }
                break;

            case 3:
                calculator.displayGreenCityTips();
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;

            case 4:
                clearScreen();
                cout << "\nThank you for using the Green City Smart Living Calculator!" << endl;
                cout << "Together, we can build sustainable urban futures." << endl;
                break;

            default:
                clearScreen();
                cout << "\n=== ERROR ===" << endl;
                cout << "Invalid choice. Please enter 1-4." << endl;
                cout << "\nPress Enter to continue...";
                cin.ignore();
                cin.get();
                break;
        }

    } while (choice != 4);

    return 0;
}