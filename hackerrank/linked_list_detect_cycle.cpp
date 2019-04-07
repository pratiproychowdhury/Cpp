/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

/* An better way to solve this would be to add the address of the node to a set or hash, and check for each visited node if it is 
already in the set. */
bool has_cycle(Node* head) {
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
