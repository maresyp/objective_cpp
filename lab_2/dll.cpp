#include <iostream>

class node { 
    public: 
        int id; 
        node * next;
        node *prev;

        node(int id) {
            this->id = id;
            this->next = nullptr;
            this->prev = nullptr;
        }
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
        bool push_after_id(int id, node *n_ptr) {
            // Return true on succes else false
            if (this -> head != nullptr){
                node *_node = this->head;
                do {
                    if (_node->id == id) {
                        // insert new node
                        n_ptr->next = _node->next;
                        if (_node->next != nullptr) {
                            _node->next->prev = n_ptr;
                        }
                        n_ptr->prev = _node;
                        _node->next = n_ptr;
                        if (this->tail == _node) this->tail = n_ptr;
                        return true;
                    }
                    _node = _node->next;
                } while (_node != nullptr);
            }
            return false;
        }
        bool delete_by_id(int id) {
            if (this -> head != nullptr) {
                node *_node = this->head;
                do {
                    if (_node->id == id) {
                        // delete this node
                        if (_node->prev != nullptr) {
                            _node->prev = _node->next;
                        } else {
                            this->head = _node->next;
                        }
                        if (this->tail == _node) {
                            this->tail = _node->prev;
                        }
                        delete _node;
                        return true;
                    }
                } while (_node != nullptr);
            }
            return false;
        }  
        void display() {
            if (this -> head != nullptr) {
                node * tmp_node = this -> head;
                do {
                    std::cout << tmp_node -> id << " ";
                    tmp_node = tmp_node -> next;
                } while (tmp_node != nullptr);
                std::cout << std::endl;
            }
        }
        void display_reverse() {
            if (this->head != nullptr) {
                node *tmp_node = this->tail;
                do {
                    std::cout << tmp_node->id << " ";
                    tmp_node = tmp_node->prev;
                } while (tmp_node != nullptr);
                std::cout << std::endl;
            }
        }
        bool is_empty() {
            if (this -> head == nullptr) return true;
            return false;
        }
        int size() {
            if (this->head == nullptr) return 0;
            node *_node = this->head;
            int counter = 0;
            do {
                _node = _node->next;
                counter++;
            } while (_node != nullptr);
            return counter;
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
        node *get_head() {
            return this->head;
        }
        node *get_tail() {
            return this->tail;
        }
        void sort() {
            // sort nodes by their id
            if (this->head != nullptr) {
                node *_node;
                bool changed;
                do {
                    _node = this->head;
                    changed = false;
                    while (_node->next != nullptr) {
                        if (_node->id > _node->next->id) {
                            std::swap(_node->id, _node->next->id);
                            changed = true;
                        }
                        _node = _node->next;
                    }
                } while (changed);
            }
        }
};

int main() {
    doubly_linked_list dll = doubly_linked_list();
    dll.push_back(12);
    dll.push_after_id(12, new node(5));
    dll.push_after_id(12, new node(0));
    dll.push_after_id(12, new node(7));
    std::cout << "Head -> " << dll.get_head()->id << std::endl;
    dll.display();
    dll.sort();
    std::cout << "After sort" << std::endl;
    std::cout << "Display -> ";
    dll.display();
    std::cout << "Reverse -> ";
    dll.display_reverse();
    std::cout << "Head -> " << dll.get_head()->id << std::endl;
    std::cout << "Tail -> " << dll.get_tail()->id << std::endl;
    dll.clear();
    return 0;
}