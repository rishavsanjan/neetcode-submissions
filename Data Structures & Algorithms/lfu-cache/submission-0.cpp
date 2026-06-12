class Node {
   public:
    int key;
    int value;
    int count;

    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        count = 1;
        prev = nullptr;
        next = nullptr;
    }
};

class List {
   public:
    int size;
    Node* head;
    Node* tail;

    List() {
        size = 0;

        head = new Node(-1, -1);
        tail = new Node(-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void addFront(Node* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;

        size++;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        size--;
    }
};

class LFUCache {
   public:
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;

    int maxSize;
    int currSize;
    int minFreq;

    LFUCache(int capacity) {
        maxSize = capacity;
        currSize = 0;
        minFreq = 0;
    }

    void updateFreqList(Node* node) {
        int currFreq = node->count;

        freqList[currFreq]->removeNode(node);

        if (currFreq == minFreq && freqList[currFreq]->size == 0) {
            minFreq++;
        }

        node->count++;

        List* nextList;

        if (freqList.find(node->count) != freqList.end()) {
            nextList = freqList[node->count];
        } else {
            nextList = new List();
            freqList[node->count] = nextList;
        }

        nextList->addFront(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) {
            return -1;
        }

        Node* node = keyNode[key];

        int ans = node->value;

        updateFreqList(node);

        return ans;
    }

    void put(int key, int value) {
        if (maxSize == 0) {
            return;
        }

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];

            node->value = value;

            updateFreqList(node);

            return;
        }

        if (currSize == maxSize) {
            List* list = freqList[minFreq];

            Node* nodeToDelete = list->tail->prev;

            keyNode.erase(nodeToDelete->key);

            list->removeNode(nodeToDelete);

            currSize--;
        }

        currSize++;

        minFreq = 1;

        List* listFreq1;

        if (freqList.find(1) != freqList.end()) {
            listFreq1 = freqList[1];
        } else {
            listFreq1 = new List();
            freqList[1] = listFreq1;
        }

        Node* newNode = new Node(key, value);

        listFreq1->addFront(newNode);

        keyNode[key] = newNode;
    }
};