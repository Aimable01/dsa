#include <iostream>
#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <map>
using namespace std;

class CityGraph
{
private:
    struct Edge
    {
        string destination;
        int distance;
        Edge(string dest, int dist) : destination(dest), distance(dist) {}
    };

    map<string, vector<Edge>> adjacencyList;
    vector<string> cities;

    // Validation functions
    bool cityExists(const string &city) const
    {
        return find(cities.begin(), cities.end(), city) != cities.end();
    }

    bool connectionExists(const string &city1, const string &city2) const
    {
        if (!cityExists(city1) || !cityExists(city2))
            return false;

        for (const Edge &edge : adjacencyList.at(city1))
        {
            if (edge.destination == city2)
                return true;
        }
        return false;
    }

    // Helper function for Dijkstra's algorithm
    string getMinDistanceCity(const map<string, int> &distances, const map<string, bool> &visited) const
    {
        int minDistance = numeric_limits<int>::max();
        string minCity;

        for (const auto &city : cities)
        {
            if (!visited.at(city) && distances.at(city) <= minDistance)
            {
                minDistance = distances.at(city);
                minCity = city;
            }
        }

        return minCity;
    }

    // Helper function for MST (Prim's algorithm)
    string getMinKey(const map<string, int> &key, const map<string, bool> &mstSet) const
    {
        int minKey = numeric_limits<int>::max();
        string minCity;

        for (const auto &city : cities)
        {
            if (!mstSet.at(city) && key.at(city) < minKey)
            {
                minKey = key.at(city);
                minCity = city;
            }
        }

        return minCity;
    }

public:
    // Add a new city to the graph
    void addCity(const string &city)
    {
        if (city.empty())
        {
            throw invalid_argument("City name cannot be empty!");
        }

        if (cityExists(city))
        {
            throw invalid_argument("City " + city + " already exists!");
        }

        cities.push_back(city);
        adjacencyList[city] = vector<Edge>();
    }

    // Add a connection between two cities
    void addConnection(const string &city1, const string &city2, int distance)
    {
        if (city1.empty() || city2.empty())
        {
            throw invalid_argument("City names cannot be empty!");
        }

        if (distance <= 0)
        {
            throw invalid_argument("Distance must be positive!");
        }

        if (!cityExists(city1))
        {
            throw invalid_argument("City " + city1 + " does not exist!");
        }

        if (!cityExists(city2))
        {
            throw invalid_argument("City " + city2 + " does not exist!");
        }

        if (city1 == city2)
        {
            throw invalid_argument("Cannot connect a city to itself!");
        }

        if (connectionExists(city1, city2))
        {
            throw invalid_argument("Connection between " + city1 + " and " + city2 + " already exists!");
        }

        adjacencyList[city1].emplace_back(city2, distance);
        adjacencyList[city2].emplace_back(city1, distance);
    }

    // Display all cities and their connections
    void displayGraph() const
    {
        if (cities.empty())
        {
            cout << "No cities in the graph.\n";
            return;
        }

        cout << "\nCity Connections:\n";
        cout << left << setw(15) << "City" << "Connected To (Distance)\n";
        cout << string(50, '-') << "\n";

        for (const string &city : cities)
        {
            cout << left << setw(15) << city;
            if (adjacencyList.at(city).empty())
            {
                cout << "No connections";
            }
            else
            {
                for (const Edge &edge : adjacencyList.at(city))
                {
                    cout << edge.destination << "(" << edge.distance << "km) ";
                }
            }
            cout << "\n";
        }
    }

    // Find shortest path between two cities using Dijkstra's algorithm
    void findShortestPath(const string &startCity, const string &endCity) const
    {
        if (!cityExists(startCity))
        {
            throw invalid_argument("Start city " + startCity + " does not exist!");
        }

        if (!cityExists(endCity))
        {
            throw invalid_argument("End city " + endCity + " does not exist!");
        }

        if (startCity == endCity)
        {
            cout << "Start and end cities are the same. No travel needed.\n";
            return;
        }

        map<string, int> distances;
        map<string, string> previous;
        map<string, bool> visited;

        // Initialize distances
        for (const string &city : cities)
        {
            distances[city] = numeric_limits<int>::max();
            previous[city] = "";
            visited[city] = false;
        }
        distances[startCity] = 0;

        for (size_t i = 0; i < cities.size() - 1; ++i)
        {
            string current = getMinDistanceCity(distances, visited);
            visited[current] = true;

            for (const Edge &edge : adjacencyList.at(current))
            {
                if (!visited[edge.destination] &&
                    distances[current] != numeric_limits<int>::max() &&
                    distances[current] + edge.distance < distances[edge.destination])
                {
                    distances[edge.destination] = distances[current] + edge.distance;
                    previous[edge.destination] = current;
                }
            }
        }

        // Check if path exists
        if (distances[endCity] == numeric_limits<int>::max())
        {
            cout << "No path exists between " << startCity << " and " << endCity << ".\n";
            return;
        }

        // Reconstruct path
        vector<string> path;
        string current = endCity;
        while (current != "")
        {
            path.push_back(current);
            current = previous[current];
        }
        reverse(path.begin(), path.end());

        // Display results
        cout << "\nShortest Path from " << startCity << " to " << endCity << ":\n";
        cout << "Total Distance: " << distances[endCity] << "km\n";
        cout << "Path: ";
        for (size_t i = 0; i < path.size(); ++i)
        {
            if (i != 0)
                cout << " -> ";
            cout << path[i];
        }
        cout << "\n";
    }

    // Find Minimum Spanning Tree using Prim's algorithm
    void findMST() const
    {
        if (cities.empty())
        {
            cout << "No cities in the graph.\n";
            return;
        }

        map<string, int> key;
        map<string, bool> mstSet;
        map<string, string> parent;

        // Initialize all keys as INFINITE and mstSet as false
        for (const string &city : cities)
        {
            key[city] = numeric_limits<int>::max();
            mstSet[city] = false;
        }

        // Start with first city
        key[cities[0]] = 0;
        parent[cities[0]] = "";

        for (size_t i = 0; i < cities.size() - 1; ++i)
        {
            string u = getMinKey(key, mstSet);
            mstSet[u] = true;

            for (const Edge &edge : adjacencyList.at(u))
            {
                if (!mstSet[edge.destination] && edge.distance < key[edge.destination])
                {
                    parent[edge.destination] = u;
                    key[edge.destination] = edge.distance;
                }
            }
        }

        // Display the MST
        cout << "\nMinimum Spanning Tree (MST) Connections:\n";
        cout << left << setw(15) << "Connection" << "Distance\n";
        cout << string(30, '-') << "\n";

        int totalWeight = 0;
        for (size_t i = 1; i < cities.size(); ++i)
        {
            string city = cities[i];
            int distance = 0;

            // Find the distance between city and parent[city]
            for (const Edge &edge : adjacencyList.at(city))
            {
                if (edge.destination == parent[city])
                {
                    distance = edge.distance;
                    break;
                }
            }

            cout << left << setw(15) << (parent[city] + " - " + city)
                 << distance << "km\n";
            totalWeight += distance;
        }

        cout << "\nTotal MST Weight: " << totalWeight << "km\n";
    }
};

// Function to get validated integer input
int getValidatedInt(const string &prompt, int min = 1, int max = numeric_limits<int>::max())
{
    int value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a valid number.\n";
        }
        else if (value < min || value > max)
        {
            cout << "Please enter a value between " << min << " and " << max << ".\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Function to get validated string input
string getValidatedString(const string &prompt, bool allowEmpty = false)
{
    string input;
    while (true)
    {
        cout << prompt;
        getline(cin, input);

        if (!allowEmpty && input.empty())
        {
            cout << "Input cannot be empty. Please try again.\n";
        }
        else
        {
            return input;
        }
    }
}

// Main menu function
void displayMenu()
{
    cout << "\nCity Distance Management System\n";
    cout << "1. Add City\n";
    cout << "2. Add Connection Between Cities\n";
    cout << "3. Display All Cities and Connections\n";
    cout << "4. Find Shortest Path Between Cities\n";
    cout << "5. Find Minimum Spanning Tree (MST)\n";
    cout << "6. Exit\n";
}

int main()
{
    CityGraph cityGraph;

    while (true)
    {
        displayMenu();
        int choice = getValidatedInt("Enter your choice (1-6): ", 1, 6);

        try
        {
            switch (choice)
            {
            case 1:
            {
                string city = getValidatedString("Enter city name to add: ");
                cityGraph.addCity(city);
                cout << "City " << city << " added successfully!\n";
                break;
            }
            case 2:
            {
                string city1 = getValidatedString("Enter first city name: ");
                string city2 = getValidatedString("Enter second city name: ");
                int distance = getValidatedInt("Enter distance between cities (km): ");
                cityGraph.addConnection(city1, city2, distance);
                cout << "Connection added successfully!\n";
                break;
            }
            case 3:
                cityGraph.displayGraph();
                break;
            case 4:
            {
                string startCity = getValidatedString("Enter starting city: ");
                string endCity = getValidatedString("Enter destination city: ");
                cityGraph.findShortestPath(startCity, endCity);
                break;
            }
            case 5:
                cityGraph.findMST();
                break;
            case 6:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            }
        }
        catch (const exception &e)
        {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}