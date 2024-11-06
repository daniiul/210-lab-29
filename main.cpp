// COMSC-210 | 210-lab-29 | Daniil Malakhov
// Include header files for handling, data structures, strings, algorithms, etc.
#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <list>
#include <vector>
#include <ctime>

using namespace std;

// Define a function to simulate a town and its functions
    // Arguments: map of a town, number of intervals

// Define main function
int main()
{
    // Initialize a map to store information on a town, each associated with an array of lists for homes, businesses, and infrastructure development
     map <string, list<string>[3]> region;

    // Open an external file to read initial data about towns
        // If file does not open, print an error and exit
    ifstream inputFile("data.txt");

    if(!inputFile.is_open())
    {
        cout << "File failed to open!" << endl;
        return 0;
    }

    // Read data from file and populate map
        // For each line, extract town name, homes, businesses, and infrastructure developments
        // Insert each town function into its corresponding list in the array for the town
    string temp;
    string town;
    vector<string> names;
    vector<string> businesses;
    vector<string> infrastructure;
    int i = 0;
    while(getline(inputFile, temp))
    {
        if(i == 0)
        {
            town = temp;
        }
        else if(i == 1)
        {
            names.push_back(temp);
            list<string> item;
            item.push_back(temp);
            region[town][0] = item;
        }
        else if (i == 2)
        {
            businesses.push_back(temp);
            list<string> item;
            item.push_back(temp);
            region[town][1] = item;
        }
        else if (i == 3)
        {
            infrastructure.push_back(temp);
            list<string> item;
            item.push_back(temp);
            region[town][2] = item;

        }
        i++;
    }

    // Close the file
    cout << "Closing file!" << endl;
    inputFile.close();

    srand(time(0));

    // Begin a time-based simulation for changes in different towns
        // For 25 time intervals
    for(int i = 0; i < 25; i++)
    {
        int prob = rand() % 100 + 1;  // returns random number 1-100
            // Iterate through each town in map

            for (auto it : region)
            {
                // For each town, simulate changes
                    // Randomly decide if a new family moves in, business open up, or infrastructure development is to be added to the town
                        // If adding, generate or select a new family, business, or infrastructure development to add to the list
                        // If removing, select a random family, business, or infrastructure development to remove from list
                    // Print the changes for this interval, e.g., "The {family name} name moved in to {town name}" or "The {business name} has opened up in {town name}"
                if (prob <= 60)
                {
                    string name = names[rand() % names.size()];
                    cout <<  "      " << name << "family has moved to " << it.first << endl;
                }
                if (prob <= 55) {
                    string business = businesses[rand() % businesses.size()];
                    cout <<  "      " << business << " has opened up shop in " << it.first << endl;
                }
                if (prob <= 50) {
                    string infra = infrastructure[rand() % infrastructure.size()];
                    cout <<  "      " << infra << " has begun construction in " << it.first << endl;
                }
                if (prob <= 25)
                {
                    int randval = rand() % it.second[0].size();
                    auto iter = it.second[0].begin();
                    advance(iter, randval);
                    cout <<  "      " << *iter << " family has left " << it.first << endl;
                }
                if (prob <= 20)
                {
                    int randval = rand() % it.second[1].size();
                    auto iter = it.second[1].begin();
                    advance(iter, randval);
                    cout <<  "      " << *iter << " business has shut down in " << it.first << endl;
                }

            }


            // Simulate more complex town changes
            // random events impacting towns
            // earthquakes, housing crisis, recession
            if(i == 10)
            {
                cout << "major earthquake causes ruin throughout region!" << endl;
            }

            // Wait or pause briefly to simulate the passage of time between intervals
    }
    cout << "simulation complete! " << endl;
// End of main function
}
