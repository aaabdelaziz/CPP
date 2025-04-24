# Smart Pointers in C++

Smart pointers are wrapper classes around raw pointers that automatically manage memory. They help prevent memory leaks and dangling pointers by ensuring proper cleanup of dynamically allocated memory.

---

## Why Use Smart Pointers?

- **Automatic memory management**
- **Exception safety**
- **Cleaner, safer code**
- Eliminates the need for explicit `delete`
- Prevents memory leaks and double frees

> 🔁 Smart pointers should be preferred over raw pointers whenever possible.

---

## Smart Pointer Example

Smart pointers define a policy for when an object is destroyed, removing the burden of manual memory cleanup:

```cpp
std::unique_ptr<MyObject> ptr(new MyObject());
ptr->DoSomething();
// Automatically destroyed at end of scope, even if an exception occurs
```

---

## Types of Smart Pointers

### 1. `std::unique_ptr`

- Owns a resource exclusively
- Not copyable, but **movable**
- Automatically deletes the object when it goes out of scope

```cpp
void f() {
    std::unique_ptr<MyObject> ptr(new MyObject());
    ptr->DoSomething();
} // MyObject is destroyed here
```

- Prevents multiple deletions
- Ideal when only one owner is needed

---

### 2. `std::shared_ptr`

- Implements **reference counting**
- Object is destroyed when the **last reference** goes out of scope
- Can be safely copied and passed around

```cpp
void f() {
    std::shared_ptr<MyObject> p1;
    {
        std::shared_ptr<MyObject> p2(new MyObject());
        p1 = p2; // Two references to the same object
    } // p2 destroyed, p1 still holds the object
} // p1 destroyed, object deleted
```

- Useful for objects shared across multiple owners

---

### 3. `std::weak_ptr`

- A **non-owning reference** to a `shared_ptr`
- Does **not** increase the reference count
- Prevents **circular references**

```cpp
std::shared_ptr<A> a = std::make_shared<A>();
std::shared_ptr<B> b = std::make_shared<B>();
a->b = b;
b->a = std::weak_ptr<A>(a); // Break the circular reference
```

---

## Common Pitfalls

### Dangling Heap Allocation

```cpp
std::shared_ptr<MyObject>* pp = new std::shared_ptr<MyObject>(new MyObject());
// Forgot to delete pp → Memory leak!
```

### Circular References

```cpp
struct Owner {
    std::shared_ptr<Owner> other;
};

std::shared_ptr<Owner> p1(new Owner());
std::shared_ptr<Owner> p2(new Owner());

p1->other = p2;
p2->other = p1;
// Reference count never reaches zero → Memory leak!
```

> ✅ Use `std::weak_ptr` to avoid circular references.

---

## Deprecated: `std::auto_ptr` (⚠️ Don't Use)

```cpp
std::auto_ptr<MyObject> p1(new MyObject());
std::auto_ptr<MyObject> p2 = p1; // Transfers ownership
p2->DoSomething(); // Works
p1->DoSomething(); // ❌ Likely crashes — p1 is now null
```

- `auto_ptr` is deprecated in C++11 and **removed** in C++17  
- ✅ Use `std::unique_ptr` instead

---

## Summary

| Smart Pointer     | Ownership     | Copyable | Reference Count | Use Case                                       |
|------------------|---------------|----------|------------------|------------------------------------------------|
| `unique_ptr`     | Sole          | ❌       | No               | Single ownership, fast cleanup                 |
| `shared_ptr`     | Shared        | ✅       | Yes              | Multiple owners, automatic reference counting  |
| `weak_ptr`       | Non-owning    | ✅       | No               | Avoid circular references with `shared_ptr`    |

✅ **Always prefer smart pointers in modern C++ for safer, more maintainable memory management.**
