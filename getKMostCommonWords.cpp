#include <iostream>
#include <sstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

vector<string> getKMostCommonWords(const string& sentence, int k) {
    // Step 1: Split the sentence into words and count their frequency
    unordered_map<string, int> wordCount;
    stringstream ss(sentence);
    string word;
    
    while (ss >> word) {
        // Convert the word to lowercase (optional, if case-insensitive counting is desired)
        for (char &c : word) c = tolower(c);
        wordCount[word]++;
    }

    // Step 2: Use a min-heap to keep track of the top k frequent words
    auto comp = [&wordCount](const string& a, const string& b) {
        return wordCount[a] > wordCount[b]; // min-heap based on frequency
    };
    priority_queue<string, vector<string>, decltype(comp)> minHeap(comp);
    for (const auto& [word, count] : wordCount) {
        minHeap.push(word);
        if (minHeap.size() > k) {
            minHeap.pop(); // keep only the top k elements in the heap
        }
    }

    // Step 3: Extract the k most frequent words from the heap
    vector<string> result;
    while (!minHeap.empty()) {
        result.push_back(minHeap.top());
        minHeap.pop();
    }

//     // Optional: Reverse the result so that the most frequent words appear first
//     reverse(result.begin(), result.end());
    return result;
}

int main() {
    string sentence = "and A this a that this and a boy that a that";
    int k = 3;

    vector<string> mostCommonWords = getKMostCommonWords(sentence, k);

    cout << "The " << k << " most common words are:\n";
    for (const string& word : mostCommonWords) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
