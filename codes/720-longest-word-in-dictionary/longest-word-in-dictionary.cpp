class Solution {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;

            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root = new Node();

    void insert(string& word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    string longestWord(vector<string>& words) {

        // Build Trie
        for (string& word : words) {
            insert(word);
        }

        string ans = "";

        for (string& word : words) {
            Node* curr = root;
            bool valid = true;

            for (char ch : word) {
                int idx = ch - 'a';

                curr = curr->child[idx];

                // Every prefix must be a word
                if (!curr->isEnd) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                // Longer word is better.
                // If same length, lexicographically smaller is better.
                if (word.size() > ans.size() ||
                    (word.size() == ans.size() && word < ans)) {
                    ans = word;
                }
            }
        }

        return ans;
    }
};