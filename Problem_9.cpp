#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// Trie Node
struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode() {
        for (int i = 0; i < 26; ++i)
            children[i] = nullptr;
        isEndOfWord = false;
    }
};

// Function to insert a word into the trie
void insert(TrieNode* root, const string& word) {
    TrieNode* node = root;
    for (char c : word) {
        int index = c - 'A'; // Assuming uppercase letters only
        if (!node->children[index])
            node->children[index] = new TrieNode();
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

// Function to search for words on the board using backtracking
void searchWord(int i, int j, vector<vector<char>>& board, TrieNode* root, string& word,
    vector<string>& result, unordered_set<string>& seen) {
    // Base case: If the current cell is out of bounds or already visited, return
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '\0')
        return;

    char temp = board[i][j];
    int index = temp - 'A'; // Assuming uppercase letters only
    if (root->children[index]) {
        // Append the current character to the word
        word.push_back(temp);
        root = root->children[index];

        // If the word is found in the dictionary and not already seen, add it to the result
        if (root->isEndOfWord && seen.find(word) == seen.end()) {
            result.push_back(word);
            seen.insert(word);
        }

        // Mark the current cell as visited
        board[i][j] = '\0';

        // Explore all eight adjacent cells recursively
        searchWord(i + 1, j, board, root, word, result, seen);
        searchWord(i - 1, j, board, root, word, result, seen);
        searchWord(i, j + 1, board, root, word, result, seen);
        searchWord(i, j - 1, board, root, word, result, seen);
        searchWord(i + 1, j + 1, board, root, word, result, seen);
        searchWord(i + 1, j - 1, board, root, word, result, seen);
        searchWord(i - 1, j + 1, board, root, word, result, seen);
        searchWord(i - 1, j - 1, board, root, word, result, seen);

        // Backtrack: Restore the original character and unmark the cell
        board[i][j] = temp;
    }
}

// Function to find words on the board using the given dictionary
vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary) {
    vector<string> result;
    if (board.empty() || dictionary.empty()) return result;

    // Construct the trie from the dictionary
    TrieNode* root = new TrieNode();
    for (const string& word : dictionary)
        insert(root, word);

    int m = board.size(), n = board[0].size();
    unordered_set<string> seen;

    // Search for words on the board starting from each cell
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            string word = "";
            searchWord(i, j, board, root, word, result, seen);
        }
    }

    return result;
}

int main() {
    int R = 3, C = 3;
    vector<vector<char>> board = { {'C','A','P'},
                                   {'A','N','D'},
                                   {'T','I','E'} };
    vector<string> dictionary = { "CAT" };
    vector<string> result = wordBoggle(board, dictionary);
    for (const string& word : result)
        cout << word << " ";
    cout << endl;

    return 0;
}
