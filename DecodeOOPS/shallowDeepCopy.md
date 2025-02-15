# Shallow Copy vs Deep Copy in C++

## Introduction
When working with objects in C++, copying data between objects is a common operation. This can be done using **Shallow Copy** or **Deep Copy**. Understanding the difference between these two is crucial when dealing with dynamic memory allocation.

---

## 1. Shallow Copy
A **Shallow Copy** occurs when an object is copied with its pointer references intact. This means that both the original and copied objects share the same memory address for dynamically allocated data.

### Example of Shallow Copy
```cpp
#include <iostream>
using namespace std;

class ShallowCopyExample {
public:
    int* data;

    // Constructor
    ShallowCopyExample(int value) {
        data = new int(value);
    }

    // Copy Constructor (Shallow Copy)
    ShallowCopyExample(const ShallowCopyExample& other) {
        data = other.data; // Copies the pointer, not the value
    }

    // Display function
    void show() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    ShallowCopyExample obj1(10);
    ShallowCopyExample obj2 = obj1; // Shallow Copy

    obj1.show();
    obj2.show();

    // Modifying obj2 affects obj1 as well
    *obj2.data = 20;
    
    cout << "After modification:" << endl;
    obj1.show();
    obj2.show();
    
    return 0;
}
```
### Output:
```
Data: 10
Data: 10
After modification:
Data: 20
Data: 20
```
### Issues with Shallow Copy:
- Both objects point to the same memory location.
- Changes in one object affect the other.
- If one object is deleted, the other is left with a dangling pointer, leading to undefined behavior.

### Shallow Copy Diagram
```
    Object 1                Object 2 (Shallow Copy)
    +-------+               +-------+
    | data  | ------------> |  10   |  (Shared Memory)
    +-------+               +-------+
```
👉 **Same memory is shared** between `obj1` and `obj2`. Modifying one affects the other.

---

## 2. Deep Copy
A **Deep Copy** creates a completely independent copy of an object, including dynamically allocated memory. This ensures that changes in one object do not affect the other.

### Example of Deep Copy
```cpp
#include <iostream>
using namespace std;

class DeepCopyExample {
public:
    int* data;

    // Constructor
    DeepCopyExample(int value) {
        data = new int(value);
    }

    // Copy Constructor (Deep Copy)
    DeepCopyExample(const DeepCopyExample& other) {
        data = new int(*other.data); // Allocating new memory and copying the value
    }

    // Destructor
    ~DeepCopyExample() {
        delete data;
    }

    // Display function
    void show() {
        cout << "Data: " << *data << endl;
    }
};

int main() {
    DeepCopyExample obj1(10);
    DeepCopyExample obj2 = obj1; // Deep Copy

    obj1.show();
    obj2.show();

    // Modifying obj2 does not affect obj1
    *obj2.data = 20;
    
    cout << "After modification:" << endl;
    obj1.show();
    obj2.show();
    
    return 0;
}
```
### Output:
```
Data: 10
Data: 10
After modification:
Data: 10
Data: 20
```
### Advantages of Deep Copy:
- Each object maintains its own copy of dynamically allocated memory.
- Changes in one object do not affect the other.
- Prevents issues like dangling pointers and memory corruption.

### Deep Copy Diagram
```
    Object 1                Object 2 (Deep Copy)
    +-------+               +-------+
    | data  | ---> [10]     | data  | ---> [10]  (Separate Memory)
    +-------+               +-------+
```
👉 **Each object has its own copy** of the data, so changes in one do not affect the other.

---

## 3. Summary
| Feature | Shallow Copy | Deep Copy |
|---------|-------------|-----------|
| Memory Allocation | Copies pointer only | Allocates new memory |
| Independence | Shared memory | Separate memory |
| Effect of Modification | Affects both objects | Affects only one object |
| Risk | Dangling pointers, memory leaks | No such risks |

**When to use Deep Copy?**
- When your class contains dynamically allocated memory.
- To prevent unintentional changes due to shared references.
- To avoid memory corruption issues.

---

## 4. Conclusion
Understanding Shallow and Deep Copy is essential when dealing with object copying in C++. If your class uses dynamic memory, **always implement a Deep Copy to prevent unexpected behavior**. Use deep copies when objects need to be completely independent of each other.

---

Happy Coding! 🚀

