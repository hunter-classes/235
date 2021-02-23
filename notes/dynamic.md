## Video One: Dynamic Data Structures Intro

**Static Data Structures** are useful  (i.e. arrays), but are limited:
-hard to resize (had to copy over to a bigger array)
-removing items from array leads to holes in data set

**Dynamic Data Structures** are much more flexible:
-good for coding lists / maintaining order that do not have a "physical line" (i.e. restaurant buzzers, DMV)

**Dynamic Data Structure Example:**
Abe is first in line, and says that Sarah is after them, and then Sarah says that Tom is after them... etc. -> **elements of the list are dependent on each other!**
  -To **remove** someone from this pool of people, you would just have to redirect (i.e. If Tom is removed, Sarah could just say that Jen is after her instead)
  -To **add** someone after Abe for example (Sam), however, you would have to 1. Ask Abe who is after them, 2. Tell Sam that Sarah is after them, 3. Tell Abe that Sam is after them
Each person in the example has **TWO** pieces of information:
  -who they are **(data)**
  -who is after them **(pointer)**
With this information you could make a **class** that consists of both the data and pointer and connect each to one another!

## Video Two: Dynamic Data Structures Nodes
(Referring to code uploaded to the Linked List project!)

**main.cpp:**

`Node *p1 = new Node();`

- p1 refers to some random spot in memory
- "new Node()" makes a new block of memory for Node, puts it at some new location in memory
- ex: entire line of code returns 100, 100 is put into p1 and it will refer to the data ("what it is")

`p1->setData("hello")`
- same as *p1.setData() puts "hello" in the data spot ("what it is")

```c++
Node *p2 = new Node("World")
p1->setNext(p2)
```
- sets p2 as p1's **pointer** ("what is after them") as an address that connects back to p2's data

`p1->getNext()->getData()`

- returns "World" (p2's data)

```c++
p2 = new Node("! ")
p1->getNext()->setNext(p2)
```
- "getNext" retrieves p2's data ("World")
- "setNext" points to "!" (which is also a part of p2's data)

```c++
Node walker = p1
walker = p1->getNext()
```

- "walker = walker->getNext()" would return the same value
- shows how these lists are **linked lists**

```c++
walker = p1
while (walker != nullptr){
  cout << walker->getData() << endl
  walker = walker->getNext()
}
```

- "walks" through the entire data set and prints it
- "walker->getData()" **WILL NOT** work following this while loop because it points to null 

**(CANNOT PULL DATA FROM NULL!)**

## Video Three: Dynamic Data Structures II
**List.cpp:**
```
void List::insert(std::string data){
  Node *new_node = new Node(data);
  new_node->setNext(head);
  head=new_node;
  }
  ``````
-purpose of function: creates a new node and inserts a new node
-first links the new node in, then move the head pointer over
-"setNext(head)" points into the front of the list
-"head" is a **variable** and does not have "next" because there no node / data in there
-links l1 back to whatever new node is


**main.cpp:**

```c++
List *l1 = new List();
std::cout << l1->toString() << std::endl;
```

- returns "" because you are trying to get something from nothing
```c++
l1->insert("a");
l1->insert("b");
l1->insert("c");
std::cout << l1->toString() << std::endl;
```
- prints out as c, b, a (reverse) totally acceptable for now!

