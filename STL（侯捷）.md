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
