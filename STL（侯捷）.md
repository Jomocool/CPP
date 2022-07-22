# STL

## 1.C++ Standard Libraty和Standard Template Library的区别

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/1.png)



## 2.STL体系结构基础介绍

### 2.1六大部件

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/2.png)

### 2.2六大部件的关系

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/3.png)

一般不会写分配器，默认使用默认分配器

### 2.3复杂度，Complexity，Big-oh

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/4.png)

### 2.4前闭后开区间

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/5.png)

### 2.5range-based for statement

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/6.png)

### 2.6auto keyword

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/7.png)

## 3.容器之分类与各种测试

### 3.1容器  —  结构与分类

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/8.png)

​         序列式容器                                      关联式容器                    无序容器

**Array：**初始空间设多大就是多大，而不是根据元素的多少来分配空间。（前闭后闭）

**Vector：**根据插入多少元素来分配空间。（前闭后开）

**Deque：**前后都可以插入元素。（前开后开）

**List：**双向环状链表。（两个指针）

**Forward-list：**单向链表。（一个指针）

**Set/Multiset：**高度平衡二叉树，key和value无分别。

**Map/Multimap**：和Set的唯一区别就是，key和value区分开，可通过key来找元素，而Map不能有重复的元素，Multimap可以有重复的元素，Set也同理。

**Hash Table：**由不同篮子组成，每个篮子代表不同的链表。

### 3.2测试程序辅助函数

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/9.png)

### 3.3使用容器array

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/10.png)
Array必须先设置一个确定的空间大小

clock():程序从运行开始到调用该函数的时间

### 3.4使用容器vector

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/11.png)

size()：真正的元素个数

capacity()：容量

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/12.png)

### 3.5使用容器list

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/13.png)

### 3.6使用容器forward_list

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/14.png)

### 3.6使用容器slist

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/15.png)

**slist：**单向链表

### 3.7使用容器deque

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/16.png)

![image text](https://github.com/Jomocool/C-/blob/main/img-storage/18.png)

### 3.8使用容器stack

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/19.png)

### 3.9使用容器queue

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/20.png)

### 3.10使用容器multiset

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/21.png)

### 3.11使用容器multimap

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/22.png)

### 3.12使用容器unordered_multiset

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/23.png)

### 3.13使用容器unordered_multimap

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/24.png)



### 3.14使用容器set

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/25.png)

### 3.15使用容器map

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/26.png)

### 3.16使用容器unordered_set

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/27.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/28.png)

### 3.17使用容器unordered_map

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/29.png)



## 4.分配器之测试

### 4.1使用分配器allocater

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/30.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/31.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/32.png)



## 5.源代码之分布（VC，GCC）

### 5.1标准库版本，Visual C++

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/33.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/34.png)

### 5.2标准库版本，GNU C++

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/35.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/36.png)

## 6.OOP（面向对象编程） vs. GP（泛式编程）

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/37.png)

sort在类里

list的迭代器是连续的，而sort算法只有无需迭代器

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/38.png)

sort在类外

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/39.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/40.png)



## 7.技术基础：操作符重载and模板（泛化，全特化，偏特化）

### 7.1操作符重载

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/41.png)

### 7.2Class Templates，类模板

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/42.png)

### 7.3Function Templates，函数模板

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/43.png)

### 7.4Member Templates，成员模板

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/44.png)

### 7.5Specialization，特化

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/45.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/46.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/47.png)

### 7.6Partial Specialization，偏特化

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/48.png)

泛化：传入的是任意的type

偏特化：传入的是任意type的指针



## 8.分配器

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/49.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/50.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/51.png)

allocate调用operator new，然后operator new调用malloc

deallocate调用operator delete，然后operator delete调用free

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/52.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/53.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/54.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/55.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/56.png)

额外开销：cookie（夹心饼干），红色，上下两块，各占4个字节，总共八个字节

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/57.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/58.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/59.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/60.png)
