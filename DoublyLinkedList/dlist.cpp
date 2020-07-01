#include "dlist.h"


// Returns the node at a particular index (0 is the head). If n >= size()
// return nullptr; if n < 0, return the head of the list.
// Must run in O(n) time.
dlist::node* dlist::at(int n) const {
    int index = 0;
    struct node * temp;
    temp = head();
    while (index != n && temp != nullptr) {
        index++;
        temp = temp -> next;
    }
    if (index == n && temp != nullptr) {
        return temp;
    } else {
        return nullptr;
    }
}


// Insert a new value, after an existing one. If previous == nullptr, then
// the list is assumed to be empty.
// Must run in O(1) time.
void dlist::insert(node *previous, int value) {
    node * newNode = new node();
    newNode -> value = value;
    if (previous == nullptr) {
        _head = newNode;
        _tail = newNode;
    } else {
        if (previous -> next == nullptr) {
            previous -> next = newNode;
            newNode -> prev = previous;
            tail = newNode;
        } else {
            temp = previous -> next;
            previous -> next = newNode;
            newNode -> previous = previous;
            newNode -> next = temp;
            temp -> previous = newNode;
        }
    }
}


// Delete the given node. Should do nothing if which == nullptr.
// Must run in O(1) time.
void dlist::remove(node* which) {

}


// Add a new element to the *end* of the list
// Must run in O(1) time.
void dlist::push_back(int value) {

}


// Add a new element to the *beginning* of the list
// Must run in O(1) time.
void dlist::push_front(int value) {

}


// Remove the first element
// Must run in O(1) time
void dlist::pop_front() {

}


// Remove the last element
// Must run in O(1) time
void dlist::pop_back() {

}


// Get the size of the list
// Should run in O(n) time at the worst
int dlist::size() const {
    struct node * x = head();
    int count = 0;
    while (x != nullptr) {
        count++;
        x = x -> next;
    }
    return count;
}


// Returns true if the list is empty
// Must run in O(1) time
bool dlist::empty() const {
    return head() == nullptr;
}


/* a == b
   Compares two lists for equality, returning true if they have the same
   elements in the same positions. (Hint: it is *not* enough to just compare
   pointers! You have to compare the values stored in the nodes.)

   Must run in O(m) time, where m is the length of the shorter of the two lists.
*/
bool operator== (const dlist& a, const dlist& b) {
    if (a.head() -> value == b.head() -> value) {
        if (a.head() -> next != nullptr && b.head() -> next != nullptr) {
            return (a.head() -> next == b.head() -> next);
        } else if (a.head() -> next == nullptr && b.head() -> next == nullptr) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}


/* a + b
   Returns a new list consisting of all the elements of a, followed by all the
   elements of b (i.e., the list concatenation).

   Must run in O(n) time in the length of the result.
*/
dlist operator+ (const dlist& a, const dlist& b) {

}


/* reverse(l)
   Returns a new list that is the *reversal* of l; that is, a new list
   containing the same elements as l but in the reverse order.

   Must run in O(n) time.
*/
dlist reverse(const dlist& l) {

}
