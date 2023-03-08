# 《C++ Primer》笔记

## 1.标准库IO对象

- **cin:**标准输入，可以跳过空格、制表符、换行符等等
- **cout:**标准输出
- **cerr:**标准错误
- **clog:**用于输出程序运行时的一般信息

## 2.C++算数类型

**float:**6位有效数字

**double:**10位有效数字

**long double:**10位有效数字

```cpp
bool b=42;//非0，即真
int i=b;//真，值为1
```

不要混用带符号和无符号的变量，会转成unsigned变量

## 3.复合类型

- **引用：**为对象起的别名，引用本身不是对象，所以不能定义引用的引用。
- **指针：**指针是对地址的封装，本身就是一个对象。

**void*：**纯粹的地址封装，与类型无关。可以用于存放任意类型的地址

## 4.const限定符

```cpp
const int buffSize=512;
bufSize=512;//错误，试图向const对象写值

const对象初始化(其他时候不能出现在等号左边)
const int j=get_size();//正确：运行时初始化
const int j=42;//正确：编译时初始化
const int k;//错误：k是一个未经初始化的常量

const int bb=0;
void* a=bb;//在编译时，会把bb编程常量，因为0很特殊

int bb=0;
void* a=bb;//错误：bb可改，不安全

默认状态下，const对象仅在文件内有效，如果想在多个文件直接共享const对象，必须在变量的定义前添加extern关键字
//file_1.cc定义并初始化了一个常量，该常量能被其他文件访问
extern const int bufSize=fcn();
//file_1.h头文件
extern const int bufSize;

可以通过一个常量的引用(const int&)指向一个非常量(int)，但是不能通过一个非常量的引用(int&)指向一个常量(const int)
    
double dval=3.14;
const int &ri=dval;//允许，当作一个int常量来用就行了
int &ri=dval;//错误：因为ri实际上指向的是编译器生成的中间值((int)double)，当中间值是临时的，所以ri引用是无效的
```

## 5.contexpr和常量表达式

```cpp
常量表达式：值不会改变并且在编译过程中就能得到的计算结果的表达式
const int max_files=20;//是
const int limit=max_files+1;//是
int staff_size=27;//不是
const int sz=get_size();//不是

constexpr变量：一定是一个常量、必须用常量表达式初始化
constexpr int mf=20;
constexpr int limit=mf+1;
constexpr int sz=size();//只有当size是一个constexpr函数时才正确

自定义类型、IO库、string等类型不能被定义为constexpr

限定符constexpr仅对指针有效（只修饰顶层），对指针所指的对象无关
constexpr int *np=nullptr;//常量指针
int j=0;
constexpr int i=42;
//i和j必须定义在函数之外
constexpr const int*p=&i;//p是常量指针，指向常量
constexpr int *p1=&j;//p1是常量指针，指向遍历j
```

## 6.auto、decltype

```cpp
auto：顶层const会被忽略，底层const不会被忽略
    
decltype：选择并返回操作数的数据类型，只要数据类型，不要其值
decltype(*p)推导出来的类型是&
变量如果加上括号，decltype的结果将是&
```

