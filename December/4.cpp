//Question :- Stream Of Characters(https://leetcode.com/problems/stream-of-characters/)
//Difficulty : Hard
//Pre-requisites : Trie 
//If You have knowledge about Trie Data Structure then it's very simple because it's based on Trie implementation


/*Thought-Process: =>
Main Idea in this problem is to store words in reverse order in our Trie, so that to find suffix from stream of characters will become easy and efficient.

Ex : "xyz" will be store as "z -> y -> x (end)" in Trie
Now, once we build (store words) in Trie, we can easily search suffixes in stream of characters. We store all incoming characters from stream into a string, and start searching for words from end of streamString.

  Ex: streamString = "axyz" , 
  -> now we need to query so start searching from end i.e character 'z'
  -> Trie has word "zyx" stored 

  i. "z" , present so move to next character i.e 'y'
  ii. "z -> y" , Present so move to next character i.e 'x'
  iii. "z -> y -> x (end)" , Present so move to next character, but this is end of word. 

 Since we found a suffix word, return True.
Whenever we encounter a character that is not present in the Trie or Trie Node reaches NULL we return false.
And whenever we each a word end with flag=True, return true.
*/

/*

Time -Complexity: O(N * W + W * Q) ,
N -> No. of words
W -> Length of Words
Q -> No. of queries

Space-Complexity : O(N * W)
*/

struct Node {
    Node* arr[26];//store all the lowercase alphabates
    bool flag = false;
    
//this function return true if ch is already available in trie else false
    bool contains(char ch) {
        return arr[ch-'a'] != NULL;
    }
   //put a node against a char
    void put(char ch, Node* newNode) {
        arr[ch-'a'] = newNode;
    }
    //if next node is available then return it else return NULL
    Node* getNext(char ch) {
        return arr[ch-'a'];
    }
    //return value of flag-> true or false
    bool getFlag() {
        return flag;
    }
    //set flag value->true
    void setFlag() {
        flag = true;
    }
};

class StreamChecker {
    string streamString = "";
    Node* root;
public:
    
// Insert string in reverse order into Trie.
   void insert(string s) {
        Node* temp = root;
        for(int i=s.size()-1; i>=0; i--) {
            if(!temp->contains(s[i])) {
                temp->put(s[i], new Node());
            }
            temp = temp->getNext(s[i]);
        }
        temp->setFlag();  // End of string 
    }
    
    StreamChecker(vector<string>& words) {
        root = new Node();
        
        for(auto& word : words) {
            insert(word);
        }
    }
    // Seach for string from end of streamString Character by character 
    bool query(char letter) {
        streamString += letter;
        Node* temp = root;
        for(int i=streamString.size()-1; i>=0 && temp; i--) {
// Return false If char if not present or Trie Node is NULL 
          if(!temp || !temp->contains(streamString[i])) return false; 			
// Move to next character if present
            temp = temp->getNext(streamString[i]);
            if(temp->getFlag()) return true;  // Reached the end of a word , so return true
       }
    return false;
    }
};
