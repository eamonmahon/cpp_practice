#include <vector>

template <typename T>
class ListNode {
    public:

        T val;
        ListNode* next;

        ListNode(T val, ListNode* next) : val(val), next(next) {}
};

template <typename T>
class LinkedList {

    private:

    ListNode<T>* head;
    ListNode<T>* tail;

    public:

    LinkedList() {
        head = new ListNode<T>(T(), nullptr);
        tail = head;
    }

    ~LinkedList() {
        while (head != nullptr) {
            ListNode<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    T get(int i) const {
        ListNode<T>* node = head->next;

        size_t count = 0;
        while (node != nullptr) {
            if (count == i) {
                return node->val;
            }
            count++;
            node = node->next;
        }
        if constexpr (std::is_same<T, int>::value) {
            return -1;
        } else {
            return T(); // Default value for other types
        }

    }
    
    void insertHead(T val) {
        ListNode<T>* newHead = new ListNode<T>(val, head->next);
        head->next = newHead;
        if (newHead->next == nullptr) {
            tail = newHead;
        }
    }

    void insertTail(T val) {
        
        tail->next = new ListNode<T>(val, nullptr);
        tail = tail->next;
    }

    bool remove(int i) {
        ListNode<T>* prev = head;
        ListNode<T>* cur = head->next;
        size_t count = 0;
        
        while (cur != nullptr) {
            if (count == i) {
                if (cur == tail) {
                    tail = prev;
                }
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur = cur->next;
            count++;
        }
        return false;

    }

    std::vector<T> getValues() const {
        std::vector<T> values;
        ListNode<T>* cur = head->next;
        while (cur != nullptr) {
            values.push_back(cur->val);
            cur = cur->next;
        }
        return values;

    }

    bool isEmpty() const {
        return head->next == nullptr;
    }

};