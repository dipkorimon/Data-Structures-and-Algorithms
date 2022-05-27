struct TrieNode {
    map<char,TrieNode*> children;
    int prefixes;
    bool endofword;
    TrieNode() {
        prefixes=0;
        endofword=false;
    }
};
void insert(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node) {
          node=new TrieNode();
          current->children[word[i]]=node;
        }
        current=node;
        current->prefixes++;
    }
    current->endofword=true;
}
bool search(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++) {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
          return false;
        current=node;
    }
    return current->endofword;
}
int count_prefix(TrieNode *root,string word)
{
    TrieNode *current=root;
    for(int i=0;i<word.size();i++)
    {
        char ch=word[i];
        TrieNode *node=current->children[ch];
        if(!node)
        {
          return 0;
        }
        current=node;
    }
    return current->prefixes;
}

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    TrieNode *root = new TrieNode();
    while (n--) cin >> s, insert(root, s);
    while (q--) cin >> s, cout << count_prefix(root, s) << endl;
}
