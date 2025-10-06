// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.
struct node
{
    int val;
    node *next;
    node(int _val) : val(_val), next(nullptr) {}
};
class MyLinkedList
{
    node *head;
    int size;

public:
    MyLinkedList()
    {
        head = nullptr;
        size = 0;
    }
    int get(int index)
    {
        if (index >= size)
            return -1;
        node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->val;
    }

    void addAtHead(int val)
    {
        node *newNode = new node(val);
        newNode->next = head;
        head = newNode;
        size++;
    }

    void addAtTail(int val)
    {
        if (!head)
        {
            addAtHead(val);
            return;
        }
        node *temp = head;

        while (temp && temp->next)
            temp = temp->next;
        temp->next = new node(val);
        size++;
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        if (index == 0)
        {
            addAtHead(val);
            return;
        }
        node *temp = head;

        for (int i = 0; i < index - 1; i++)
            temp = temp->next;
        node *temp_next = temp->next;
        temp->next = new node(val);
        temp->next->next = temp_next;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        node *temp = head;
        size--;
        if (index == 0)
        {
            head = head->next;
            delete temp;
            return;
        }
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        node *toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */