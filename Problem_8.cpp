#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to check if a string represents a valid IPv4 part (0-255)
bool isValidPart(const string& part) {
    if (part.empty() || part.size() > 3 || (part.size() > 1 && part[0] == '0'))
        return false;
    int num = stoi(part);
    return num >= 0 && num <= 255;
}

// Function to generate all possible IPv4 addresses from a given string
void generateIPAddresses(string s, int start, int parts, string ip, vector<string>& result) {
    // Base case: If we have used all parts and consumed the entire string, add the IP address to the result
    if (parts == 4 && start == s.size()) {
        result.push_back(ip);
        return;
    }

    // If we have used all parts but there are still characters left in the string, return
    if (parts == 4 || start == s.size())
        return;

    // Try all possible splits of the remaining string and recursively generate IP addresses
    for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
        string part = s.substr(start, i);
        if (isValidPart(part)) {
            // Recursively generate IP addresses with the current part
            if (parts == 0)
                generateIPAddresses(s, start + i, parts + 1, part, result);
            else
                generateIPAddresses(s, start + i, parts + 1, ip + "." + part, result);
        }
    }
}

// Function to generate all possible IPv4 addresses from the given string
vector<string> genIp(string s) {
    vector<string> result;
    if (s.size() < 4 || s.size() > 12) // Length of the string should be between 4 and 12 inclusive for valid IPv4 addresses
        return { "-1" };

    generateIPAddresses(s, 0, 0, "", result);
    return result;
}

int main() {
    string s1 = "1111";
    vector<string> result1 = genIp(s1);
    for (string ip : result1)
        cout << ip << endl;

    string s2 = "55";
    vector<string> result2 = genIp(s2);
    for (string ip : result2)
        cout << ip << endl;

    return 0;
}
