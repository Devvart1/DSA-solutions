

/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */
Node*mid(Node*head) {
    if (!head)return NULL;
    Node* s = head;
    Node* f->bottom = head;
    while (f and f->bottom) {
        s = s->bottom;
        f = f->bottom->bottom;
    }
    return s;
}
void mergeSort(Node*head) {
    if (!head)return;
    Node*temp = mid(head);
    Node*midHead = temp->bottom;
    temp->next = NULL;
    mergeSort(head);
    mergeSort(midHead);
    merge(head, midHead);
    return;
}
Node* merge(Node*l1, Node*l2) {
    if (!l2)return l1;
    if (!l1)return l2;

    Node* newHead = new Node(0);
    Node*temp = newHead;
    while (l1 and l2) {
        if (l1->data > l2->data) {
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        } else {
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
        }
    }
    if (l1) {
        temp->bottom = l1;
    }
    if (l2) {
        temp->bottom = l2;
    }
    return newHead->bottom;
}


Node *flatten(Node *root)
{
    // Your code here
    Node*temp = root;
    Node*newHead = new Node(0);
    newHead->next = temp;
    while (temp) {
        if (temp->next);
        temp->next = merge(temp, temp->next);
    }
    return newHead->next;
}
