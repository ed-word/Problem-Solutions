#include <bits/stdc++.h>
#define endl "\n"
#define loop(i,n) for(ll i=0; i < n; i++)
typedef long long ll;
using namespace std;


struct trie {
    unordered_map<char,trie*> children;
    bool is_word = false;     
};


trie* get_node() {
    trie* node = new trie;
    node->is_word = false;
    return node;
}


void insert(trie *root, string str) {
    trie *curr = root;
    for (auto i: str) {
        if (curr->children.count(i) == 0)
            curr->children[i] = get_node();
        curr = curr->children[i];
    }
    curr->is_word = true;
}


trie* search(trie *root, string str) {
    trie *curr = root;
    for (auto i: str) {
        if (curr->children.count(i) == 0)
            return curr;
        curr = curr->children[i];
    }
    return curr;
}


void dfs_trie_display(trie *node) {
    for (auto i: node->children) {
        cout << i.first;
        if (i.second->is_word == false)
            dfs_trie_display(i.second);
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    trie *root = get_node();
    insert(root, "hello");
    insert(root, "heya");
    trie *node = search(root, "he");
    dfs_trie_display(node);

    return 0;
}
