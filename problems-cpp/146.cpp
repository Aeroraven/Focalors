#include <cstring>
#include <iostream>

template<class T>
class Node {
public:
    T key;
    T val;
    Node<T>* next = nullptr;
    Node<T>* prev = nullptr;
};


class LRUCache {
public:
    Node<int>* head = nullptr;
    Node<int>* tail = nullptr;
    int count = 0;
    int capacity = 0;
    Node<int>* index[10001];

    LRUCache(int capacity) {
        this->capacity = capacity;
        memset(this->index, 0, sizeof(decltype(index)));
    }

    void updateTemporalOrder(int key) {
        // if the key presents in the list, place it to the tail
        if (this->index[key]) {
            auto prev = this->index[key]->prev;
            auto next = this->index[key]->next;
            // if the key is at the tail
            if (!next) {
                return;
            }
            // if the key is at the front
            else if (!prev) {
                next->prev = nullptr;
                tail->next = this->index[key];
                this->index[key]->next = nullptr;
                this->index[key]->prev = tail;
                tail = this->index[key];
                head = next;
            }
            else {
                next->prev = prev;
                prev->next = next;
                this->index[key]->next = nullptr;
                this->index[key]->prev = tail;
                tail->next = this->index[key];
                tail = this->index[key];
            }
        }
    }

    int get(int key) {
        if (this->index[key] == nullptr) {
            //std::cout << "PRINT" <<-1 << std::endl;
            return -1;
        }
        updateTemporalOrder(key);
        //std::cout << "PRINT" << this->index[key]->val << std::endl;
        return this->index[key]->val;
    }

    void put(int key, int value) {
        // if the key presents in the list, place it to the tail
        if (this->index[key]) {
            this->index[key]->val = value;
            updateTemporalOrder(key);
        }
        // Otherwise create a new node
        else {
            auto cur = new Node<int>();
            cur->val = value;
            cur->key = key;
            this->index[key] = cur;

            if (this->head == nullptr) {
                this->head = cur;
                this->tail = cur;
            }
            else {
                this->tail->next = cur;
                cur->prev = this->tail;
                this->tail = cur;
            }

            // pop front
            if (count < capacity) {
                count++;
            }
            else {
                auto remHead = head;
                this->index[remHead->key] = nullptr;
                remHead->next->prev = nullptr;
                head = remHead->next;
                delete remHead;
            }
        }
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1); // ������ {1=1}
    lRUCache.put(2, 2); // ������ {1=1, 2=2}
    lRUCache.get(1);    // ���� 1
    lRUCache.put(3, 3); // �ò�����ʹ�ùؼ��� 2 ���ϣ������� {1=1, 3=3}
    lRUCache.get(2);    // ���� -1 (δ�ҵ�)
    lRUCache.put(4, 4); // �ò�����ʹ�ùؼ��� 1 ���ϣ������� {4=4, 3=3}
    lRUCache.get(1);    // ���� -1 (δ�ҵ�)
    lRUCache.get(3);    // ���� 3
    lRUCache.get(4);    // ���� 4
}