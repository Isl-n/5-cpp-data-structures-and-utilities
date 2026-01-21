# C++ Data Structures + Date & String Utilities Library

A self-built C++ library that includes:
- Custom **data structures** (Queue, Stack) implemented using a **Dynamic Array** and **Doubly Linked List**
- A **String utility** class with common operations (split, trim, replace, case conversion, etc.)
- A **Date utility** class with validation, calendars, comparisons, and date arithmetic
- Small demo-style classes like a **Queue Ticket Line** system and an **Undo/Redo string** implementation

This project was built for learning and portfolio purposes to practice **OOP**, **templates**, and **data structure implementation**.

## ✨ Highlights

### 🧵 String Utilities (`clsString`)
Includes operations such as:
- Word counting, splitting, joining
- Trimming (left/right/both)
- Replace word (case sensitive/insensitive)
- Case conversion + invert case
- Remove punctuation

### 📅 Date Utilities (`clsDate`)
Includes functionality such as:
- Date parsing (`"DD/MM/YYYY"`)
- Date validation + leap year rules
- Day-of-week calculation + month/year calendar printing
- Date comparisons (before/equal/after)
- Date arithmetic (add days/weeks/months/years, difference in days)
- Business day / vacation day calculations

### 🧱 Data Structures
Template-based wrappers built on top of your own containers:
- `clsMyQueue<T>` using a doubly linked list
- `clsMyQueueArr<T>` using a dynamic array
- `clsMyStack<T>` and `clsMyStackArr<T>` implemented using queue internals

### 🎟️ Example Project (`clsQueueLine`)
A small simulation of a ticketing queue line:
- Issue tickets with prefix + order number
- Store ticket issue time using the Date class
- Print tickets in RTL/LTR orders
- Serve next client
> A full working demo of `clsQueueLine` is included in the solution project (`main.cpp`).


### ↩️ Undo/Redo Example (`clsMyString`)
A string wrapper that supports:
- `SetValue(...)`
- `Undo()`
- `Redo()`
Implemented using two stacks.

### 🔗 Doubly Linked List (`clsDblLinkedList<T>`)
A templated doubly linked list implementation that supports:
- Insert at beginning / end
- Insert after a node or index
- Delete first / last / specific node
- Search (`Find`)
- Reverse, clear, size checks
- Access and update by index (`GetNode`, `GetItem`, `UpdateList`)


## 🗂️ Project Structure
- `clsString.h`
- `clsDate.h`
- `clsMyQueue.h`, `clsMyQueueArr.h`
- `clsMyStack.h`, `clsMyStackArr.h`
- `clsQueueLine.h`
- `clsMyString.h`
- `clsDynamicArray.h`, `clsDblLinkedList.h`



## 🧪 Usage Examples (Demo Snippets)

Below are small examples demonstrating how to use different components of the library.  
*(The Queue Line example is included directly in the solution project.)*

---

### 1️⃣ String Utilities Example

```cpp
#include <iostream>
#include "clsString.h"

int main() {
    clsString s("  hello world from c++  ");

    s.Trim();
    s.UpperFirstLetterOfEachWord();

    std::cout << s.Value << std::endl;  // Hello World From C++
    std::cout << s.CountWords() << std::endl;
}
```

### 2️⃣ Date Utilities Example

```cpp
#include <iostream>
#include "clsDate.h"

int main() {
    clsDate d("20/01/2026");

    std::cout << d.DateToString() << std::endl;
    std::cout << d.DayShortName() << std::endl;

    d.AddDays(10);
    std::cout << "After 10 days: " << d.DateToString() << std::endl;
}
```

### 3️⃣ Stack Example (Custom Stack Implementation)

```cpp
#include <iostream>
#include "clsMyStack.h"

int main() {
    clsMyStack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    std::cout << "Top element: " << myStack.Top() << std::endl;       // 30
    std::cout << "Bottom element: " << myStack.Bottom() << std::endl; // 10

    myStack.pop();
    std::cout << "After pop, top element: " << myStack.Top() << std::endl; // 20
}
```

### 4️⃣ Doubly Linked List Example

```cpp
#include <iostream>
#include "clsDblLinkedList.h"

int main() {
    clsDblLinkedList<int> list;

    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtBeginning(5);

    list.PrintList(); // 5 10 20

    list.Reverse();
    list.PrintList(); // 20 10 5
}
```




## 🚀 Build & Run
Compile with any modern C++ compiler.

Example (simple):
```bash
g++ main.cpp -o demo
./demo