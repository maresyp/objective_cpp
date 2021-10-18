#include <iostream>

class node { 
    public: 
        int id; 
        node * next;
        node * prev;

        node(int id, node * prev_node) {
            this -> id = id; 
            this -> next = nullptr;
            this -> prev = prev_node;
        }  
};

class doubly_linked_list {
    private:
        node * head; 
        node * tail; 

    public:
        doubly_linked_list() {
            this -> head = nullptr;
            this -> tail = nullptr;
        }
        void push_back(int id) {
            if (is_empty()) {
                node * _node = new node(id, nullptr);
                this -> head = _node;
                this -> tail = _node;
            } else { 
                node * _node = new node(id, this -> tail);
                this -> tail -> next = _node;
                this -> tail = _node;
            }
        }
        bool push_after_id(int id) {
            // Return true on succes else false
            if (this -> head != nullptr){
                return true;
            }
            return false;
        }
        bool delete_by_id(int id) {
            if (this -> head != nullptr) {
                return true;
            } else {
                return false;
            }
        }  
        void display() {
            if (this -> head != nullptr) {
                node * tmp_node = this -> head;
                do {
                    std::cout << tmp_node -> id << " ";
                    tmp_node = tmp_node -> next;
                } while (tmp_node != nullptr);
            } 
        }
        bool is_empty() {
            if (this -> head == nullptr) return true;
            return false;
        }
        void clear(){
            if (this -> head != nullptr) {
                node * _node = this -> head;
                node * tmp_node;
                do { 
                    tmp_node = _node -> next;
                    delete _node;
                    _node = tmp_node;
                } while (tmp_node != nullptr);

                this -> head = nullptr;
                this -> tail = nullptr;
            }
        }
};

int main() {
    doubly_linked_list dll = doubly_linked_list();
    dll.push_back(12);
    dll.push_back(13);
    dll.push_back(14);
    dll.display();
    dll.clear();
    std::cout << "\n";
    dll.push_back(122);
    dll.push_back(133);
    dll.push_back(144);
    dll.display();
    dll.clear();
    return 0;
}