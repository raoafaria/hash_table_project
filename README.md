# Hash Table with Chaining in C++

This project implements a dynamic hash table in C++ using **chaining for collision resolution** via a custom **doubly linked list**. The implementation uses **C-style arrays only**, and supports automatic resizing (grows when full, shrinks when sparse).

---

## 🚀 Features

- ✅ Integer keys and values
- ✅ Custom doubly linked list (no STL)
- ✅ Collision resolution by chaining
- ✅ Dynamic resizing:
  - Doubles capacity when full
  - Halves capacity when 25% full
- ✅ Uses the **multiplication method** for hashing
- ✅ Clean and modular design

---

## 📁 Files

| File           | Description                                  |
|----------------|----------------------------------------------|
| `main.cpp`     | Test driver for the hash table implementation |
| `HashTable.h`  | Header file with class and struct definitions |
| `HashTable.cpp`| Implementation of hash table and linked list  |

---

## 🧠 Hash Function

Uses **Knuth’s Multiplication Method**:

```cpp
int HashTable::hashFunction(int key) const {
    const float A = 0.6180339887f; // Knuth's constant
    float frac = fmod(key * A, 1.0f);
    return (int)(capacity * frac);
}
## 🛠 How to Compile and Run
▶️ Compile
Using g++ (C++11 standard):

bash
Copy
Edit
g++ -std=c++11 main.cpp HashTable.cpp -o main.exe
💡 Make sure you're using a terminal where g++ is available (e.g., MSYS2 UCRT64, Git Bash, WSL, or Linux/macOS terminal).

▶️ Run
bash
Copy
Edit
./main.exe     # Windows
./main         # Linux / macOS (if compiled without .exe)
If you’re using VS Code, you can also create a tasks.json for automated build.




