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

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/61.png)

## 9.容器之间的实现关系与分类

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/62.png)



![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/63.png)

## 10.深度探索list

### 10.1G2.9容器list

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/64.png)

除了array和vector，其他容器的iterator都要是类，因为需要智能指针

### 10.2list's iterator

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/65.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/66.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/67.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/68.png)

### 10.3G4.9容器list

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/69.png)





## 11.迭代器的设计原则和Iterator Traits的作用与设计

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/70.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/71.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/72.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/73.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/74.png)



## 12.vector深度探索

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/75.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/76.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/77.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/78.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/79.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/80.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/81.png)



## 13.array、forward_list深度探索

### 13.1array

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/82.png)

array不可扩充

### 13.2forward_list

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/83.png)



## 14.deque、queue和stack深度探索

### 14.1deque

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/84.png)

本质：vector

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/85.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/86.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/87.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/88.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/\89.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/90.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/91.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/92.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/93.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/94.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/95.png)

扩充后，将旧容器的元素copy到新容器的中段

### 14.2queue

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/96.png)

### 14.3stack

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/97.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/98.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/99.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/100.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/101.png)



## 15.RB-tree深度探索

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/102.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/103.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/104.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/105.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/106.png)



## 16.set、multiset深度探索

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/107.png)

### 16.1set

根据key排序

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/108.png)

### 16.2set，in VC6

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/109.png)

### 16.3multiset

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/110.png)

优先使用容器自身提供的算法，因为是特化的，更适合该容器



## 17.map、multimap深度探索

### 17.1容器map

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/111.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/112.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/113.png)

### 17.2multimap

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/114.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/115.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/116.png)



## 18.hashtable深度探索

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/117.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/118.png)

55%53=2，2%53=2，于是这两个元素都放到2号位，串联起来

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/119.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/120.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/121.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/122.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/123.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/124.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/125.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/126.png)

## 19.unordered容器概念

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/127.png)

只是名字换了而已



## 20.算法的形式

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/128.png)



## 21.迭代器的分类（category）

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/129.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/130.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/131.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/132.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/133.png)



## 22.迭代器分类（category）对算法的影响

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/134.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/135.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/136.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/137.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/138.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/139.png)

先用某个函数判断出迭代器种类，然后根据迭代器种类调用相对应的算法，提高了算法的效率

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/140.png)

并非强制，只是暗示



## 23.算法源代码剖析（11个例子）

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/141.png)

### 23.1accumulate

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/142.png)

### 23.2for_each

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/143.png)

### 23.3repalce,replace_if,replace_copy

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/144.png)

### 23.4count,count_if

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/145.png)

### 23.5find,find_if

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/146.png)

### 23.6sort

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/147.png)

### 23.7关于reverse iterator,rbegin(),rend()

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/148.png)

### 23.8binary_search

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/149.png)



## 24.仿函数和函数对象

### 24.1仿函数functors

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/150.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/151.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/152.png)

小括号产生临时对象

### 24.2仿函数functors的可适配（adaptable）条件

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/153.png)

条件：继承去回答问题

### 24.3函数对象

函数对象：仿函数临时创造的对象

## 25.存在多种Adapter

适配器：把东西记起来，以便后面使用

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/154.png)

### 25.1容器适配器

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/155.png)

### 25.2函数适配器

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/\156.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/157.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/158.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/159.png)

### 25.3迭代器适配器

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/160.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/161.png)

### 25.3X适配器:ostream_iterator

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/162.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/163.png)

![image-20220724201957037](D:\Code(Github)\C-\img-storage\164.png)



## 26.一个万用的hash function

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/165.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/167.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/168.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/169.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/170.png)



## 27.Tuple

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/171.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/172.png)

t.head()->第一个元素

t.tail()->第一个后面的所有元素

t.tail().head()->第二个元素



## 28.type traits

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/173.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/174.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/175.png)



## 29.type traits实现

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/176.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/177.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/178.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/179.png)



## 30.cout

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/180.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/181.png)



## movable元素对于容器速度效能的影响

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/182.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/183.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/184.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/185.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/186.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/187.png)

![image-text](https://github.com/Jomocool/C-/blob/main/img-storage/188.png)
