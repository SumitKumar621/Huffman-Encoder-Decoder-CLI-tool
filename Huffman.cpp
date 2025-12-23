#include <bits/stdc++.h>
using namespace std;

/* ---------- Node class ---------- */
class Node {
public:
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

/* ---------- Min-heap comparator ---------- */
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

/* ---------- Huffman Coding class ---------- */
class HuffmanCoding {
private:
    unordered_map<char, string> codes;
    unordered_map<string, char> reverse_mapping;

    unordered_map<char, int> buildFrequencyDict(const string& text) {
        unordered_map<char, int> freq;
        for (char c : text) freq[c]++;
        return freq;
    }

    priority_queue<Node*, vector<Node*>, Compare>
    buildHeap(const unordered_map<char, int>& freq) {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (auto& p : freq)
            pq.push(new Node(p.first, p.second));
        return pq;
    }

    Node* buildTree(priority_queue<Node*, vector<Node*>, Compare>& pq) {
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();

            Node* merged = new Node('\0', left->freq + right->freq);
            merged->left = left;
            merged->right = right;

            pq.push(merged);
        }
        return pq.top();
    }

    void buildCodesHelper(Node* root, string curr) {
        if (!root) return;

        if (root->ch != '\0') {
            codes[root->ch] = curr;
            reverse_mapping[curr] = root->ch;
            return;
        }

        buildCodesHelper(root->left, curr + "0");
        buildCodesHelper(root->right, curr + "1");
    }

public:
    void buildCodes(Node* root) {
        buildCodesHelper(root, "");
    }

    string encodeText(const string& text) {
        string encoded;
        for (char c : text)
            encoded += codes[c];
        return encoded;
    }

    string decodeText(const string& encoded) {
        string curr = "", decoded = "";
        for (char bit : encoded) {
            curr += bit;
            if (reverse_mapping.count(curr)) {
                decoded += reverse_mapping[curr];
                curr = "";
            }
        }
        return decoded;
    }

    pair<string, Node*> compress(const string& text) {
        auto freq = buildFrequencyDict(text);
        auto pq = buildHeap(freq);
        Node* root = buildTree(pq);
        buildCodes(root);
        string encoded = encodeText(text);
        return {encoded, root};
    }

    string decompress(const string& encoded_text) {
        return decodeText(encoded_text);
    }
};

/* ---------- MAIN  ---------- */
int main() {
    string text;

    cout << "Enter text to compress: ";
    getline(cin, text);

    HuffmanCoding hc;

    auto result = hc.compress(text);
    string encoded = result.first;

    cout << "\nEncoded Text:\n" << encoded << endl;

    string decoded = hc.decompress(encoded);

    cout << "\nDecoded Text:\n" << decoded << endl;

    ofstream encodedFile("encoded_output.txt");
    encodedFile << encoded;
    encodedFile.close();

    ofstream decodedFile("decoded_output.txt");
    decodedFile << decoded;
    decodedFile.close();

    cout << "\nEncoded and decoded data saved to files.\n";

    return 0;
}