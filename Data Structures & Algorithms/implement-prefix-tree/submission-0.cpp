class Node {
public:
    char letter;
    bool validWord;
    vector<Node*> letters;

    Node(char l) {
        letter = l;
        validWord = false;
        for (int i = 0; i < 26; i++) {
            letters.push_back(nullptr);
        }
    }
};

class PrefixTree {
public:
    Node* root;

    PrefixTree() {
        root = new Node(' ');
    }
    
    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int letter = word[i] - 'a';
            if (temp->letters[letter] == nullptr) {
                temp->letters[letter] = new Node(word[i]);
            }

            temp = temp->letters[letter];

        }
        temp->validWord = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++) {
            int letter = word[i] - 'a';
            temp = temp->letters[letter];

            if (temp == nullptr) {
                return false;
            }
        }
        if (temp->validWord) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.length(); i++) {
            int letter = prefix[i] - 'a';
            temp = temp->letters[letter];

            if (temp == nullptr) {
                return false;
            }
        }
        return true;
    }
};
