# c-NAAssn

## C++ 基础知识点目录
> 1. [变量，常量，数据类型](#variable)
> 2. [数组，字符数组](#array)
> 3. [函数，传值，传引用](#function)
> 4. [指针，动态内存, 栈，堆](#pointer)






<a name="variable"></a>

## 变量，常量，数据类型

### 常用数据类型
> 1. 字符 ```char```
> 2. 整型 ```int，unisgned int，long int，long unsigned int, short int```
> 3. 浮点型 ```float```，双精度浮点型 ```double```
> 4. 布尔 ```bool```

### 声明变量的语法
> 1. 整型变量： ```int variableName;```

### 声明常量的语法
> 1. 整型常量: ```const int variableName;```

### 宏定义
> 1. ```#define VAR_NAME 0```

<a name="array"></a>

## 数组，字符数组

### 语法
> 1. 定义数组：```int arrayName[100];```
> 2. 定义数组并赋初值：```int arrayName[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};```
> 3. 遍历数组：使用循环：```for(int i=0; i<arrayLength; ++i) { ... }```

### 关于实际长度和可用长度
```int array[10];```
```array[0] = 0;```
```array[1] = 1;```
```array[2] = 2;```
> 1. 实际长度：```3```
> 2. 可用长度: ```10```

### 字符数组
> 1. 结束符：```'\0'```
> 2. ```cstring```中的常用函数：```strcpy(arg1, arg2)```, ```strlen(arg1)```, ```strcat(arg1, arg2)```, ```strcmp(arg1, arg2)```
strcmp()的返回值：
> 3. ```<0```： 第一个参数的第一个字符比第二个参数的第一个字符小
> 4. ```=0```:  两个字符串相同
> 5. ```>0```:  第一个参数的第一个字符比第二个参数的第一个字符大
> 6. 长度为6的字符数组最多可以存储 ```5``` 个字符


<a name="function"></a>

## 函数，传值，传引用

### 语法
> 1. 定义函数: ```returnType functionName(arguments list) { ... }```
> 2. 函数声明: ```returnType functionName(arguments list);```

### 传值和传引用的区别：

> 1. 传值实际上做了一个copy的操作，传引用实际上是为原来的变量定义了新的名字
> 2. 在函数中，传引用的参数在函数结束后生命期并不会结束，但是传值的参数会结束生命期

