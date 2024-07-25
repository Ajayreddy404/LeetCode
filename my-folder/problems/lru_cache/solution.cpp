struct node{
    int k;
    int val;
    node* next;
    node* prev;
    node(int v, int key) : val(v), k(key), next(nullptr), prev(nullptr){
        // val = v;
        // k = key;
        // next = nullptr;
        // prev = nullptr;
    }
};

class LRUCache {
public:
    unordered_map<int, node*> mp;
    node* h;
    node* t;
    int max_cap;
    int cap;

    LRUCache(int capacity) {
        max_cap = capacity;
        h = new node(-1,-1);
        t = new node(-1,-1);
        h->next = t;
        t->prev = h;
        cap = 0;
    }
    
    int get(int key) {
        // cout<<key<<endl;
        if(mp.find(key)==mp.end())  return -1;
        node* nd = mp[key];
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;
        nd->next = h->next;
        nd->prev = h;
        h->next = nd;
        nd->next->prev = nd;
        return nd->val;
    }
    
    void put(int key, int value) {
        // cout<<key<<" "<<h->val<<endl;
        if(mp.find(key)==mp.end()){
            cap++;

            // insert at head
            node* nd = new node(value, key);
            mp[key] = nd;
            // cout<<nd->val<<" "<<h->val<<endl;
            nd->next = h->next;
            nd->prev = h;
            h->next = nd;
            nd->next->prev = nd;

            // del if cap exceeds max_cap
            if(cap>max_cap){
                cap--;
                node* nd2 = t->prev->prev;
                node* nd1 = t->prev;
                nd2->next = t;
                t->prev = nd2;
                mp.erase(nd1->k);
                delete nd1;
            }
        } else{
            mp[key]->val = value;
            int temp = get(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */