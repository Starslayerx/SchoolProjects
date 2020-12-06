## 重载运算符
以下是重载的格式
```cpp
<返回类型说明符> operator <运算符符号>(<参数表>)
{
     <函数体>
}
```
重载运算符的规则

- 为了防止用户对标准类型进行重载，重载运算符的操作对象至少有一个是用户自定义类型
- 重载不能改变原运算符的优先级，也不能自定义运算符
- 不能重载的运算符有:
	1. 成员运算符 **.**
	2. 作用域运算符**::**
	3. 条件运算符 **? :**
	4. **sizeof**运算符
	5. **typeid**运算符
	6. 类型转换运算符 **const_cast**、**dynamic_cast**、**reinterpret_cast**、**static_cast**

### number funtctions 成员函数重载
- 成员函数的第一个参数是this
- 对于不会修改算子的运算符应该使用const类型(引用)
- 重载的类型决定于运算符左边的reciver的类型
```cpp
Ingter x(10), y(20), z;
/* 下面两种相同 */
x + y;
x.operator+(y);
```
隐式类型转换只发生在右边
```cpp
x + 3;		// okay
3 + x;		// ERROE
```
### global functions 全局函数
对于全局函数，运算符两边都可以做隐式类型转换
```cpp
/* 下面两种相同 */
x + y;
operator+(x, y);
```
函数实现如下
```cpp
class Ingter {
	public:
	int i;
	friend const Intger operator+(const Intger& left, const Intger& right);
};
const Intger operator+(const Intger& left, const Intger& right) {
	return Intger(left.i, right.i);
}
```
于是下面这几种运算都可以了
```cpp
z = x + y;
z = x + 3;
z = 3 + x;
z = 2 + 3;		//这种是拷贝构造函数，别弄混了
```

### Tips
- 下面这四种运算符必须(只能)通过成函数进行重载:
	1. = 赋值运算符
	2. () 函数调用运算符
	3. []下标运算符
	4. -> 通过指针成员访问运算符 和 ->*
- 单目运算符应该(建议)使用成员函数重载
- 其他的函数都做成非成员函数

### prototypes of operators 运算符原型
- const T operatorX(const T&l, const T&r) const;

>  +-*/ % ^ & | ~

- bool operatorX(const T&l, const T&r) const;

> ! && ||  

- T& T::operator[](int index);

> []


### operators -- and ++
- 对于前置++返回引用更加节约，对于后置++要返回当前值然后在自增，因此不能返回引用
```cpp
class Intger{
	const Intger& operator++();
	const Intger operator++(int);
	const Intger& operator--();
	const Intger operator--(int);
};
```
- 定义应该如下
```cpp
const Intger& operator++() {
	(*this) += 1;
	return *this;
}
/* int 只是用来告诉编译器这个是后置，没有任何影响 */
const Intger operator++(int) {
	Intger old(*this);
	++(*this);
	return old;
}
```
- 使用

```cpp
++x;		// calls	x.operator();
x++;		// calls	x.operator(0);
```

### rational operators 关系运算符
- 原型
```cpp
class Intger {
	public:
	...
	bool operator==(const Intger& rhs) const;
	bool operator!=(const Intger& rhs) const;
	bool operator>(const Intger& rhs) const;
	bool operator<(const Intger& rhs) const;
	bool operator>=(const Intger& rhs) const;
	bool operator<=(const Intger& rhs) const;
};
```
- 定义
注意下面这在做法，不是每个运算都非别重载，而是只对两个操作符进行了重载，这样的好处是以后再修改运算规则的时候就很方便，只用改两个就可以达到该六个的效果
```cpp
/* == and != */
bool Intger::operator==(const Intger &rhs) const {
	return rhs == *this;
}
bool Intger::operator!=(const Intger &rhs) const {
	return !(rhs == *this);
}
/* > and <, <=, >=*/
bool Intger::operator>(const Intger &rhs) const {
	return *this > rhs;
}
bool Intger::operator<(const Intger &rhs) const {
	return (rhs > *this);
}
bool Intger::operator>=(const Intger &rhs) const {
	return !(i < rhs.i);
}
bool Intger::operator<=(const Intger& rhs) const {
	return !(i > rhs.i);
}
```
当然也不用担心效率的问题，这种简单的函数，编译器会自动展开的

### operator []
- 必须是成员函数
- 只有一个参数
- 返回类型是一个引用
- 当一个类中有很多个成员时，可以用下标访问每个成员
```cpp
class Vector{
private:
	int m_size;
	int *m_array;
public:
	Vector(int size):m_size(size) {
	m_array = new int[size];
	}
	~Vector() { delete m_array; }
	int& operator[](int index) { return m_array[index]; }
};
```

### assignment operator
- 赋值运算符必须是成员函数
- 对自己做赋值然后返回自己
```cpp
T& T::operator(const T& rhs){
	/* 一定要有判断，因为指针会出问题  */
	if(this != &this) {
		//...
	}
return *this;
};
```


### operator ()
X::operator T()

- 没有返回类型，编译器会做 X——>T 类型的转换
- 没有显示的参数
下面是一个类型转换的例子
```cpp
#include 
using namespace std;

class One{
    public:
        One() { cout << "One()" << endl; }
};

class Two{
    public:
        // explicit Two(const One&) { cout << "Two()" << endl; }
        Two(const One&) { cout << "Two()" << endl; }
};

void f(Two) { }
int main()
{
    One one;
    // f(Two(one));
    f(one);

    return 0;
}
```
如上所示，One类型会被编译器自动转换成Two类型，如果不想要自动类型转换，可以在前面加上关键字`explicit`
此外，explicit还可以解决另一种情况的问题
```cpp
class Orange;	// 前向引用声明
class Apple {
	public:
		operator Orange () cosnt;
};
class Orange {
	public:
		Orange(Apple);
		// explicit Orange(Apple);
};
int main()
{
	Apple a;		// Error
}
```
如上代码中，编译会报错，因为我们有两种通过一个Apple对象获得Orange对象的方法，一个是类型转换，一个是构造函数，这样会产生ambiguous conversion，解决方法就是取消自动的类型转换，即在前面加上explicit关键字

- 不建议使用自动类型转换，这样出问题了难以察觉，可以自己写一个类型转换的函数使用

下面是一个例子，将美元类转强制换成人民币类
```cpp
#include <iostream>
using namespace std;
class RMB
{
    private:
        double rmb;
    public:
        RMB() {}
        RMB(double x) : rmb(x) { }
        void show(){
            cout << "rmb: " << rmb << "￥" << endl;
        }
};

class Dollar
{
    private:
        double dollar;
    public:
        Dollar() {}
        Dollar(double x) : dollar(x) {}
        operator RMB() {
            return RMB(dollar * 8.0);
        }
        void show(){
            cout << "dollar: " << dollar << "$" << endl;
        }
};

int main()
{
    Dollar d(10);
    d.show();
    RMB a(d);
    a.show();

    return 0;
}
```
