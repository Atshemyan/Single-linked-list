template <typename T>
class List
{
private:
    struct Node
    {
        T m_data;
        Node* m_next;
        Node(const T& data, Node* next = nullptr)      
            : m_data{data}
            , m_next{next}
            {}
    };
    Node* m_head = nullptr;
    unsigned int m_size = 0;
public:
    class Iterator
    {
        private:
            Node* m_current = nullptr;
        public:
            Iterator(Node* node)
                : m_current{node}
            {}
            Iterator() = default;

            Node& operator*() const;
            Node* operator->() const;
            Iterator& operator++(); //&
            const Iterator operator++(int); 
            bool operator==(const Iterator& rhs) const;
            bool operator!=(const Iterator& rhs) const;
            Iterator operator+(int);
    };
    List(std::initializer_list<T> il);
    List() = default;
    void push_back(const T& value);
    void push_front(const T& value);
    T front() const;
    T back() const;
    void pop_front();
    void pop_back();
    void insert(Iterator, T value);
    unsigned int size() const;
    Iterator begin() const;
    Iterator end() const;

};