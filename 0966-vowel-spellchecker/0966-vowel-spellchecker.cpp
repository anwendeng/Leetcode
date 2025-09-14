struct TrieNode {
    TrieNode* links[58]; // 'z'-'A'+1=58
    int id;
};

static constexpr int N=35000;  
static TrieNode pool[3][N];
static string Word[3][N];
static int ptr[3]={0,0,0};   // node counters
static int wid[3]={0,0,0};   // word counters

class Trie {
    int idx;
    TrieNode* newNode() {
        TrieNode* node=&pool[idx][ptr[idx]++];
        memset(node->links, 0, sizeof(node->links));
        node->id=-1;
        return node;
    }
public:
    TrieNode* root;
    Trie(int idx): idx(idx) {
        ptr[idx]=wid[idx]=0;
        root=newNode();
    }
    void insert(const string& word, const string& word0) {
        TrieNode* Node=root;
        for(char c: word) {
            int i=c-'A';
            if(Node->links[i]==NULL)
                Node->links[i]=newNode();
            Node=Node->links[i];
        }
        if(Node->id==-1) {                // only for first time
            Node->id=wid[idx]++;
            Word[idx][Node->id]=word0;    // word
        }
    }
    string search(const string& word) {
        TrieNode* Node=root;
        for(char c: word) {
            int i=c-'A';
            if(Node->links[i] == nullptr) return "";
            Node=Node->links[i];
        }
        return Node->id==-1 ? "" : Word[idx][Node->id];
    }
};

class Solution {
public:
    static constexpr unsigned vowMask=
    (1<<('A'&31))+(1<<('E'&31))+(1<<('I'&31))+(1<<('O'&31))+(1<<('U'&31));

    static string tolow(string w) {
        for(char& c : w) c=tolower(c);
        return w;
    }

    static string toDeV(string w) {
        for(char& c : w)
            if((vowMask>>(c&31))&1) c= '_';
        return w;
    }

    static vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        Trie W(0), Wlow(1), WdeV(2);

    //    cout<<ptr[0]<<","<<ptr[1]<<","<<ptr[2]<<endl;
    //    cout<<wid[0]<<","<<wid[1]<<","<<wid[2]<<endl;

        // build dictionaries
        for(const string& w : wordlist) {
            W.insert(w, w);
            string lw=tolow(w);
            string dv=toDeV(lw);
            Wlow.insert(lw, w);
            WdeV.insert(dv, w);
        }

        for(string& q : queries) {
            // exact match
            if (W.search(q)!="") continue;

            // case-insensitive
            string low=tolow(q);
            q=Wlow.search(low);
            if(q!= "") continue;

            // vowel-wildcard 
            string dev=toDeV(low);
            q=WdeV.search(dev);
        }
        return queries;
    }
};

