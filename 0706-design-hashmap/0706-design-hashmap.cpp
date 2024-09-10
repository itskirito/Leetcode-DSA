class MyHashMap {
private:
    static const int BUCKET =1000;
    struct Node{
        int key;
        int value;
        Node(int k, int v) : key(k), value(v){}
    };

    list<Node> *table;
    

public:

    MyHashMap() 
    {
        
        table = new list<Node>[BUCKET]; 
    }
    
    void put(int key, int value) 
    {
        int i = key % BUCKET;
        auto& bucket =table[i];
        for(auto& node : bucket)
        {
            if(node.key == key)
            {
                node.value = value;
                return;
            }
        }

        bucket.emplace_back(key, value);
    }
    
    int get(int key) 
    {
        int i = key % BUCKET;
        auto& bucket = table[i];
        for(const auto& node : bucket)
        {
            if (node.key == key)
            {
                return node.value;
            }
        }

        return -1;    
    }
    
    void remove(int key) 
    {
        int i = key % BUCKET;
        auto& bucket = table[i];
        bucket.remove_if([key](const Node& node)
        {
            return node.key == key;
        });    
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */