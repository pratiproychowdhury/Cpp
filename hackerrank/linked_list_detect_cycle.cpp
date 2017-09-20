/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    int visited = 0;
    
    if (head == NULL)
        return false;
    
    Node* thisNode = head->next;
    
    while ((thisNode && visited<102)) {
        thisNode = thisNode->next;
        visited++;
    }

    if (!thisNode)
        return false;
    else
        return true;
}
