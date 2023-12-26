#include <iostream>
#include <math.h>

using namespace std;

// Variable types
// Variable for singly linked list
struct number {
    int v;           // value in the list
    number *next;    // link to the next element in the list
};                   // structure for elements in a singly linked list

// Variable for doubly linked lists
struct number2 {
    int v;            // value in the list
    number2 *prev;    // link to the previous element in the list
    number2 *next;    // link to the next element in the list
};                    // structure for elements in a doubly linked list

struct list2 {
    number2 *first;    // address of the first element in the doubly linked list
    number2 *last;     // address of the last element in the list
};                    // structure for doubly linked lists

// SINGLY LINKED LISTS

number *create_list() {
    number *head, *tail, *current;
    int x, n;
    cout << "creating a list!" << endl;
    // create list head
    cout << "Value of the list head x = "; cin >> x;
    head = new number;
    head->v = x;
    head->next = NULL;
    tail = head; // last element in the list
    cout << "Number of elements to add to the list when creating the list n = "; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Value to add to the list x = "; cin >> x;
        current = new number;
        current->v = x;
        current->next = NULL;
        tail->next = current; // establish a link between the last element and the newly added element
        tail = current;       // current becomes the last element
    }
    return head;
}

void traverse_list(number *head) {
    number *current;
    if (head == NULL)
        cout << "The list is empty!" << endl;
    else {
        current = head;
        while (current != NULL) {
            cout << current->v << " ";
            current = current->next;
        }
    }
}

number *delete_from_list(number *head) {
    int cont = 0;
    int s;
    number *current, *previous;
    do {
        if (head == NULL)
            cout << "The list is empty! There are no values to delete!" << endl;
        else {
            // delete the element with value s as many times as it appears in the list
            cout << "Value to delete s = ";
            cin >> s;
            int nrs = 0; // count how many times s was deleted from the list
            // delete value s if it is at the beginning of the list
            while (head->v == s) {
                head = head->next;
                nrs++;
                if (head == NULL)
                    break;
            }
            if (head != NULL) {
                current = head->next;
                previous = head; // previous element to the current element c
                while (current != NULL) {
                    if (current->v == s) {
                        // delete c from the list
                        previous->next = current->next;
                        nrs++;
                        current = current->next;
                    } else {
                        previous = current;
                        current = current->next;
                    }
                }
            }
            cout << "The element " << s << " was deleted " << nrs << " times" << endl;
            cout << "The remaining list is: ";
            traverse_list(head);
            cout << endl;
        }
        cout << "Continue deleting [0/1]? ";
        cin >> cont;
    } while (cont);
    return head;
}

number *add_to_list(number *head, int a) {
    int opa;
    number *new_element;
    do {
        cout << endl << "Type of addition:" << endl;
        cout << "1. Add to the beginning of the list:" << endl;
        cout << "2. Add after an element within the list:" << endl;
        cout << "3. Add to the end of the list:" << endl;
        cout << "0. End addition!" << endl;
        cout << "Addition option: "; cin >> opa;
        switch (opa) {
            case 1: // add to the beginning
                new_element = new number;
                new_element->v = a;
                new_element->next = head;
                head = new_element;
                traverse_list(head);
                cout << endl;
                break;
            case 2: // add after an element with a given value in the list
                // read the value after which the addition is made
                int y;
                number *current; // c - current element in the list
                cout << "Value after which the addition is made y = "; cin >> y;
                current = head;
                while (current != NULL) {
                    if (current->v == y) {
                        // add value a after y
                        if (current->next == NULL) // c is the last element in the list
                        {
                            new_element = new number;
                            new_element->v = a;
                            new_element->next = NULL;
                            current->next = new_element;
                            current = current->next;
                        } else // c is inside the list
                        {
                            new_element = new number;
                            new_element->v = a;
                            new_element->next = current->next;
                            current->next = new_element;
                            current = current->next;
                        }
                    }
                    current = current->next;
                }// end while *current
                traverse_list(head);
                cout << endl;
                break;
            case 3: // add to the end of the list
                number *tail;
                tail = head;
                // move the list to reach the last element
                while (tail->next != NULL)
                    tail = tail->next;
                new_element = new number;
                new_element->v = a;
                new_element->next = NULL;
                tail->next = new_element;
                traverse_list(head);
                cout << endl;
                break;
            case 0:
                cout << "End of addition!" << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }// end switch
    } while (opa);
    return head;
}

number *modify_in_list(number *head, int y, int w) {
    number *current;
    for (current = head; current != NULL; current = current->next) {
        if (current->v == y)
            current->v = w;
    }
    return head;
}

// DOUBLY LINKED LISTS

list2 *create_list_2() {
    number2 *current, *first, *last;
    list2 *L2;
    int x, n;
    cout << "creating a list!" << endl;
    // create list head
    cout << "Value of the list head x = "; cin >> x;

    first = new number2;
    first->v = x;
    first->prev = NULL;
    first->next = NULL;
    last = first;
    L2 = new list2;
    L2->first = first;
    L2->last = last; // last element in the list
    cout << "first element = " << L2->first->v << endl;
    cout << "Number of elements to add to the list when creating the list n = "; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "Value to add to the list x = "; cin >> x;
        // the current element is added after the last element in the list
        current = new number2;
        current->v = x;
        current->prev = L2->last;
        current->next = NULL;
        (L2->last)->next = current; // establish a link between the last element and the newly added element
        L2->last = current;         // current becomes the last element
    }
    return L2;
}

void traverse_list_2_direct(list2 *L2) {
    number2 *current;
    if (L2->first == NULL)
        cout << "The list is empty!" << endl;
    else {
        current = L2->first;
        while (current != NULL) {
            cout << current->v << " ";
            current = current->next;
        }
    }
    cout << endl;
}

void traverse_list_2_reverse(list2 *L2) {
    number2 *current;
    if (L2->last == NULL)
        cout << "The list is empty!" << endl;
    else {
        current = L2->last;
        while (current != NULL) {
            cout << current->v << " ";
            current = current->prev;
        }
    }
    cout << endl;
}

// STACK

number *create_stack() {

    int x, N;
    number *current = nullptr;

    cout << "Number of elements: ";
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << "Add element x = ";
        cin >> x;
        number *new_element = new number;
        new_element->v = x;
        new_element->next = current;
        current = new_element;
    }

    return current;

}

number *add_to_stack(number *stack_head) {

    int x;
    number *new_element;

    cin >> x;

    new_element = new number;
    new_element->v = x;
    new_element->next = stack_head;

    return new_element;

}

number *delete_from_stack(number *stack_head) {

    stack_head = stack_head->next;

    return stack_head;

}

// QUEUE

list2 *add_to_queue(list2 *queue) {

    int x;
    number2 *current;

    cin >> x;

    current = new number2;
    current->v = x;
    current->prev = queue->last;
    current->next = NULL;

    if (queue->last == NULL) {
        queue->first = current;
        queue->last = current;
    } else {
        queue->last->next = current;
        queue->last = current;
    }

    return queue;
}

list2 *delete_from_queue(list2 *queue) {

    if (queue->first == NULL) {
        // if there is no element
        return queue;
    }

    number2 *L = queue->first;

    if (L->next != NULL) {
        // if there is more than one element
        queue->first = L->next;
        L->next->prev = NULL;
    } else {
        // if there is only one element
        queue->first = NULL;
        queue->last = NULL;
    }

    return queue;
}

// CREATING AN ORDERED SINGLY LINKED LIST FROM INPUT

number *create_ordered() {

    number *L, *current, *previous, *temp;
    int n, x, OK;

    cout << "List head x = ";
    cin >> x;

    L = new number;
    L -> v = x;
    L -> next = NULL;

    n = 1;
    OK = 1;

    while(OK != 0) {

        cout << "x = ";
        cin >> x;

        current = new number;
        current -> v = x;

        if(x <= (L -> v)){

            current -> next = L;
            L = current;

        } else {

            previous = L;
            temp = L -> next;

            while(temp != NULL) {
                if((temp -> v) <= x) {

                    previous = temp;
                    temp = temp -> next;

                } else {
                    current -> next = temp;
                    previous -> next = current;
                    break;
                }
            }

            if(temp == NULL){

                current -> next = NULL;
                previous -> next = current;

            }
        }

        cout << "Continue with adding to the ordered list [1/0]?";
        cin >> OK;

    }

    return L;

}

// MERGING TWO ORDERED LISTS

number merge(number *L1, number *L2) {

    number *L, *p1, *p2, *tail, *current;
    L = new number;
    if((L1 -> v) < (L2 -> v)) {

        L -> v = L1 -> v;
        L -> next = NULL;
        p1 = L1 -> next;
        p2 = L2;

    } else {

        L -> v = L2 -> v;
        L -> next = NULL;
        p1 = L1;
        p2 = L2 -> next;

    }

    tail = L;

    while(p1 != NULL && p2 != NULL) {

        if((p1 -> v) < (p2 -> v)) {

            current = new number;
            current -> v = p1 -> v;
            current -> next = NULL;
            tail -> next = current;
            tail = current;
            p1 = p1 -> next;

        } else {

            current = new number;
            current -> v = p2 -> v;
            current -> next = NULL;
            tail -> next = current;
            tail = current;
            p2 = p2 -> next;

        }

    }

    if(p1 != NULL) {

        while(p1 != NULL) {

            current = new number;
            current -> v = p1 -> v;
            current -> next = NULL;
            tail -> next = current;
            tail = current;
            p1 = p1 -> next;

        }

    }

    if(p2 != NULL) {

        while(p2 != NULL) {

            current = new number;
            current -> v = p2 -> v;
            current -> next = NULL;
            tail -> next = current;
            tail = current;
            p2 = p2 -> next;

        }

    }

    traverse_list(L);

}

int main() {
    int op3;
    do {
        cout << endl << "DYNAMIC LISTS" << endl;
        cout << "   3.1. Singly Linked Lists" << endl;
        cout << "   3.2. Doubly Linked Lists" << endl;
        cout << "   3.3. Stacks" << endl;
        cout << "   3.4. Queues" << endl;
        cout << "   3.5. Create an ordered list of integers (from input)" << endl;
        cout << "   3.6. Merge two ordered lists of integers" << endl;
        cout << "   3.7. Addition of polynomials using dynamic lists" << endl;
        cout << "   3.8. Multiplication of polynomials using dynamic lists" << endl;
        cout << "   3.9. Checking the correctness of parentheses in an arithmetic expression using stacks" << endl;
        cout << "   3.0. Exit Chapter 3!" << endl;

        cout << "Option for Chapter 3: "; cin >> op3;
        switch (op3) {
            case 1: // Singly Linked Lists
                {
                number *list;

                // Create list
                list = create_list();
                cout << "List after creation: ";
                traverse_list(list);
                cout << endl;

                // Delete from list
                list = delete_from_list(list);
                cout << "List after deletion: ";
                traverse_list(list);
                cout << endl;

                // Add to list
                int value;
                cout << "Enter value to add: "; cin >> value;
                list = add_to_list(list, value);
                cout << "List after addition: ";
                traverse_list(list);
                cout << endl;

                // Modify element in list
                int y, w;
                cout << "Modify element at y = "; cin >> y;
                cout << "with value w = "; cin >> w;
                list = modify_in_list(list, y, w);
                cout << "List after modification: ";
                traverse_list(list);
                cout << endl;
                break;
                }

            case 2: // Doubly Linked Lists
                {
                cout << "Doubly Linked Lists" << endl;

                list2 *l2;
                l2 = create_list_2();
                traverse_list_2_direct(l2);
                traverse_list_2_reverse(l2);

                // Complete other functions
                break;
                }

            case 3: // Stacks
                {
                cout << "\nStacks\n" << endl;

                number *stack;
                stack = create_stack();

                cout << "\nStack created:\n";
                traverse_list(stack);
                cout << endl;

                cout << "\nElement to add: ";
                stack = add_to_stack(stack);
                cout << "\nStack after adding the element:\n";
                traverse_list(stack);
                cout << endl;

                cout << "\nStack after deleting an element: \n";
                stack = delete_from_stack(stack);
                traverse_list(stack);
                cout << endl;

                break;
                }

            case 4: // Queues
                {
                cout << "Queues" << endl;

                list2 *queue;
                queue = create_list_2();
                cout << "\nQueue created:\n";
                traverse_list_2_direct(queue);
                cout << endl;

                cout << "\nElement to add: ";
                queue = add_to_queue(queue);
                cout << "\nQueue after adding the element:\n";
                traverse_list_2_direct(queue);
                cout << endl;

                cout << "\nQueue after deleting an element: \n";
                queue = delete_from_queue(queue);
                traverse_list_2_direct(queue);
                cout << endl;

                break;
                }

            case 5: // Create an ordered list from input
                {
                number *ordered_list;
                ordered_list = create_ordered();
                cout << endl;
                traverse_list(ordered_list);
                cout << endl;
                break;
                }

            case 6: // Merge two ordered lists
                {
                number *ordered_list1, *ordered_list2;
                cout << "First ordered list:\n";
                ordered_list1 = create_ordered();
                cout << endl;
                traverse_list(ordered_list1);
                cout << endl;
                cout << "Second ordered list:\n";
                ordered_list2 = create_ordered();
                cout << endl;
                traverse_list(ordered_list2);
                cout << "\nMerging the two ordered lists:\n";
                merge(ordered_list1, ordered_list2);
                cout << endl;
                break;
                }

            case 7: // Addition of two polynomials

                break;

            case 0:
                {
                    cout << "End of Chapter 3!" << endl;
                    break;
                }

            default:
                {
                    cout << "Invalid option for Chapter 3!" << endl;
                    break;
                }
        } // end switch op3
    } while (op3); // end do-while Chapter 3
}
