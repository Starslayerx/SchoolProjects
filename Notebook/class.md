## this参数
  众所周知, this指向调用该函数的对象, 通过运算符 "->" 访问成员变量, 虽然我们平时可以直接在成员函数中调用成员变量, 但是其实编译器会自动帮我们加上this->. 但有些时候必须要自己手动加上, 例如成员函数和成员变量同名的时候.  此外,静态成员函数不能够使用this, 因为静态成员函数并不作用于某个对象, 因此静态成员函数的参数数量就是自己写的参数数量, 而其他函数都会多一个this参数.
this被声明为这样` ClassName const this`, 因此不能对this本身进行赋值操作, 同样也不能改变this的指向.
### this的使用场景
1. 解决成员变量和成员函数名字冲突
2. 返回调用对象的自引用
3. 通过成员函数实现对象间的交互
4. 成员函数销毁对象自身 ......

## 成员函数
成员函数可以写在类外面, 要用作用于符号指明函数来自哪个类
```cpp
int Classname::function() const {return this->number_variable;}
```
### const成员函数
```cpp
// 两种 const 成员函数的写法
void fun(int a，int b) const{}
void const fun(int a,int b){}
// const 本质修饰的是谁？
void fun(const Class *this, int a, int b){}
```
由上可见const修饰的是`this->a`和`this->b`

- 在函数参数列表后面加上const将成员函数声明为const类型, 这里会隐式修改this的指针类型, 故const成员函数无法更改对象中的变量, 只能读取变量, 值得注意的是虽然不能改变成员变量的值, 但如果成员变量是一个指针, 并没有规定不能改变这个指针指向变量的值, 这点要注意
- const函数可以访问非const对象的非const和const成员,也可以访问const对象的所有成员; 而非const成员函数只能访问非const成员中的数据,不能访问const类中的任意数据
- const成员函数可以被具有相同形参的成员函数重载, 这种情况下, 类的常量性决定调用哪一个函数：const对象调用const函数, 非const对象调用非const函数

其次，关于const变量，也不能在类内初始化，必须在构造函数中初始化

## 构造函数 和 析构函数 constructor & destructor 
既然上面谈到了const, 就顺便说一下, 析构函数不能声明为const类型的, 且没有返回类型, 函数和类使用相同的名字,可以有参数; 对于析构函数, 不能有参数也不能有返回值
```cpp
// 构造函数初始化变量, 使用引用避免复制浪费内存
Class_name(int &x) : a(x) { }
```
### 构造函数
隐含生成的构造函数

- 如果类中没有定义构造汉斯，编译器会自动生成一个默认构造函数
- 参数列表为空，不为数据成员赋初始值
- 如果内中定义了成员的初始值，则使用类内定义的初始值
- 基本数据类型的初始化值是不确定的

如果定义了默认构造函数，但还是希望编译器生成默认构造函数，可以使用`default`关键字
```cpp
class Clock
{
	public:
	Clock() = default;	// 指示编译器提供默认构造函数
	Clock(int h, int m, int s);	// 构造函数
}
```
- 下面讨论一下构造函数初始化的方式, 我们现定义一个简单的类
```cpp
class Circle{
public:
	string type;	// 圆类的类型(比如椭圆)
	Circle(string);
}
```
有两种初始化方式
```cpp
// 初始化列表
Circle::Circle(string x) : type{x} {}
```
或在构造函数内初始化
```cpp
Circle::Circle(string x) {
	type = x;
}
```
这两中方法都可以，不过第一种方法是初始化，第二种是赋值
### 构造函数的几种形式
1. 默认构造函数
2. 移动构造函数
3. 拷贝(复制)构造函数
4. 一般数构造函数(就是带参数的那种)
5. 继承构造函数
6. 委托构造函数

#### 默认构造函数 synthesized default constructor
默认构造函数是没有自定义函数时编译器自己合成的构造函数,这种构造有两类：一类什么也不做叫无用构造函数*(tirvial constructor)*就像这样`Classname() {}`,还有一类可以对类的变量进行初始化*(no-tirvial constructor)*


- 初始化的方法会直接调用一次string类型的*复制构造函数*。
- 而赋值的方法会先调用一次string类型的*构造函数*，然后再调用一次string类型的"*=*"运算符。

#### 委托构造函数 delegating constructors
c++11为了利于代码维护，减少重复代码，引入打委托构造函数。委托构造函数可以将初始化委托给其他构造函数。

```cpp
Clock(int x, int y, int z) : h{x}, m{y}, s{z} {}
// 默认构造函数调用了上面的构造函数
Clock:Clock(0, 0, 0) {}
```
委托构造函数保持了代码的一致性，以后要改代码会比较方便

#### 复制构造函数
复制构造函数是用另一个以及实现的对象来**初始化**这个类
- 复制构造函数的参数必须为引用类型,一般会加上const，防止引用指向的对象被修改
```cpp
// 复制构造函数
类名 (const 类名 &对象名);
```
**默认复制构造函数**

默认拷贝构造函数会进行对象和对象之间的拷贝，而不是字节对字节的拷贝
- 默认复制构造函数会将两个类中的数据一一对应
- 可以用delete关键字让编译器不生成默认复制构造函数
```cpp
Clock(const Clock &c) = delete;
```
在一下情况会需要使用复制构造函数:

1. 该对象通过另一个对象初始化
2. 一个对象作为函数参数,传入函数体
3. 一个对象作为函数返回值,通过函数返回

**深复制构造函数**
在类比较复杂的情况下,编译器可能无法生成正确的拷贝构造函数,这时候就需要自己编写浅拷贝构造函数, 甚至有些时候浅拷贝也无法正常工作; 尤其是涉及到拷贝指针引用或者使用`new`动态申请内存时就会出现很多问题:
例如你的成员函数有指针，然后又指向malloc一个对象，那么就会有两个指针指向同一块内存，在析构的时候就会释放两次那个内存，导致错误
```cpp
class World
{
	private:
		int length;
		int *p;
	World(const World &a)
	{
		this->length = a.length;
		this->p = a.p;
	}
}
```
例如上面这份代码片段, 这样复制会使两个指针指向同一块内存, 当销毁对象时这块内存被释放时另一个对象的指针就会变成悬空指针,当销毁另一个对象时,会导致该内存被释放两次，导致错误.
为此, 要使用深复制函数分配新的内存
```cpp
class World
{
    private:
        int length;
        int *p;
    World(const World &a)
    {
        this->length = a.length;
        this->p = new int [length];			// 分配空间
		memset(p, a.p, length * sizeof(int));		// 拷贝值到新分配的空间
    }
}
```

##### return *class*
return 一个对象时候会发生拷贝构造吗？
```cpp
Person f()
{
	Person i;
	return i;		// 注意这里返回的是一个变量而不是常量(不优化的情况)
}
int main()
{
	Person p = f();
}
```
以上这段代码至少有两次拷贝构造，但是这里return一般不会发生拷贝，这取决于编译器，这在情况下编译器一般会optimize out(优化)这段代码，减少一次拷贝直接这样
```cpp
Person p = i;
```
如果不优化的话，那代码应该是这样
```cpp
Person i;	// @temp是一个临时变量
Person @temp = i;
Person p = @temp;
```


## static 静态
在C语言中，static的全局变量是指只有在这个文件中可以被访问，而static的本地变量是指在这个函数结束时人然存在，即全局变量，不一样的是只能在这个函数内可以访问；static函数也是只有这个文件内可以访问。
c++中

- 全局对象的构造在main函数之前执行，在main结束或者exit的时候会被析构

### 静态全局变量
静态变量一般用于共享数据. 全局静态变量就是在全局变量前加上关键字static, 该变量只对该文件内可见, 且默认会被隐式初始化为0, 其他文件无法访问该变量,即使用`extern`声明也不行. 通常要在多个函数中共享数据要使用指针或者全局变量, 但这样会造成维护的困难, 这时就有了静态局部变量, 这样更加安全且节省内存.

### 静态成员
定义静态局部变量说明该变量逻辑上属于该类, 而不是该对象,并且该变量也被存储在静态存储区, 关于静态局部变量有以下要点:
1. 静态局部变量在程序运行时就存在,因此必须在类内声明，（class里面的东西都是声明而不是定义）
2. 静态局部变量必须初始化,且要到类外进行初始化,因为该变量不属于某个对象,如果允许类内初始化那就相当于每次创建一个对象就初始化一次该变量了. 在初始化时不再需要在前面加上static关键字

```cpp
class A{
	static int s; 		// 类内声明
}
int A::s = 0;		// 类外初始化(如果加了static就是说这个变量只在这个文件内可以被访问)
```
3. 静态函数不能是const, 也不能使用this指针, 理解了this这点就是理所当然的了

然而，静态成员变量可以被这样访问
```cpp
class A 
{
	public:
		static int i;
		A () { }
		void set(int i) {
			this->i = i;
		} 
};
int A::i = 10；
```
当然还可以这样
```cpp
/* i 是public类型，如果是private就都不行 */
cout << a.i << endl;		// a是一个A的对象
cout << A::i << endl;
```


## 继承
构造函数也可以继承，不过要显示声明
```cpp
class A
{
   A(int i) {}
};
class B:A
{
  B(int i) : A(i) {}
};
```
### 多态性-运行时绑定🐾
多态性（ploymorphism）支持不同对象的同一种方法，例如派生类和基类有同一种方法，一般会直接调用派生类，不过如果我们加上`virtual`关键词后,若果我们如下使用基类指针指向派生类(upcast)，那末就会调用基类的方法;与重载不同，重载是在编译时就确定了的，而多态在运行时才被确定，这种辨别和调用正确方法的程序叫“晚绑定/动态绑定 dynamic binding”


```cpp
class Fruit {
    public:
        void peel() {cout << "peeling a FRUIT" << endl;};
};

class Apple : public Fruit{
    public:
      virtual void peel() {cout << "peeling a APPLE" << endl;};
};

int main()
{
    Fruit * m;
    m = new Apple;
    m->peel();

    return 0;
}
```
> peeling a FRUIT

#### 多态的实现
