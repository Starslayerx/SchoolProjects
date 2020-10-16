不常见知识点总结
## C Primer Plus notes
### getline
- getline(char_type *__s, streamsize __n), 读取特定长度的字符串
```cpp
char name[10];
cin.getline(name, 10);
cout << name << endl;
```
## Unions
> union is a data format can hold differernt data types but only one type at a time.
```cpp
union one4all
{
    int int_val;
    long long_val;
    double double_val;
}
```
You can do this then:
```cpp
one4all pail;
pail.int_val = 15;  // store an int
pail.double_val = 15;  // store an double, but lost int
```

### Enumerations
> C++ enum facility provides an alternative to const for creating symbolic constants.
```cpp
enum color{red, orange, yellow, green, blue};
```
- It establishes red, orange and so on, as symbolic constants for intger values 0-7.
```cpp
color band;
band = blue;   // valid, blue in color
band = 100;    // not valid, 100 not in color
++band;        // C is okay but C++ not, C++ can't convert int to enum but able to convert enum to int
color = 3 + red;    // valid, 3+red in color
```
- You can set enumerator values
```cpp
enum bits{one = 1, two = 2, four = 4, eight = 8};
```

### new and delete operator
- usage:
> typeName * pointer_name = new typeName;
> delete variable_address;
```cpp
int *ps = new int; // use the memory
delete ps;          // free the memory
delete ps;          // can't delete again

int jugs = 5;
delete jugs;        // can only delete new memory
```
- using new to create dynamic arrays
usage:
> type_name * pointer_name = new type_name [num_elements];
- static building
```cpp
// static building
int * psome = new int [10];     // get a block of 10 ints
delete [] psome;        // free a dynamic arrary
```
- dynamic building
```cpp
int size;
cin >> size;
int * pz = new int [size];
delete [] pz;
```
Remember, always use delete[] if used new[] and it's safe to delete a NULL pointer.  
Similarity, you can new and delete a structure that you defined 
