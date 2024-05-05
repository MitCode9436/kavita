#include <iostream>
#include <string>
using namespace std;

// Structure to hold client information
struct Client {
    string name;
    string phoneNumber;
};

// Hash table implementation
class HashTable {
private:
    static const int TABLE_SIZE = 10; // Size of the hash table
    Client* table[TABLE_SIZE]; // Array of pointers to clients
public:
    HashTable() {
        // Initialize all table entries to nullptr
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Hash function
    int hash(string key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash % TABLE_SIZE;
    }

    // Insert client into hash table
    void insert(Client* client) {
        int index = hash(client->name);
        while (table[index] != nullptr) {
            // Linear probing
            index = (index + 1) % TABLE_SIZE;
            // Quadratic probing: index = (index + i^2) % TABLE_SIZE;
        }
        table[index] = client;
    }

    // Search for client by name
    Client* search(string name) {
        int index = hash(name);
        int comparisons = 1;
        while (table[index] != nullptr && table[index]->name != name) {
            // Linear probing
            index = (index + 1) % TABLE_SIZE;
            // Quadratic probing: index = (index + i^2) % TABLE_SIZE;
            comparisons++;
        }
        if (table[index] != nullptr && table[index]->name == name) {
            cout << "Number of comparisons: " << comparisons << endl;
            return table[index];
        } else {
            cout << "Number of comparisons: " << comparisons << endl;
            return nullptr;
        }
    }

    // Function to get client data from user
    void getData() {
        string name, phoneNumber;
        cout << "Enter client name: ";
        cin >> name;
        cout << "Enter phone number: ";
        cin >> phoneNumber;
        Client* newClient = new Client{name, phoneNumber};
        insert(newClient);
    }
};

int main() {
    HashTable linearProbeTable;
    HashTable quadraticProbeTable;

    // Inserting clients into the hash tables
    int numClients;
    cout << "Enter the number of clients: ";
    cin >> numClients;

    cout << "Enter client details:" << endl;
    for (int i = 0; i < numClients; ++i) {
        cout << "Client " << i + 1 << ":" << endl;
        linearProbeTable.getData();
        quadraticProbeTable.getData();
    }

    // Searching for clients in the hash tables
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;

    cout << "Searching for " << searchName << "'s number:" << endl;
    linearProbeTable.search(searchName);
    quadraticProbeTable.search(searchName);

    return 0;
}
