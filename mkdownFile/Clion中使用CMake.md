# Clion中使用CMake

## Clion中关于CMake交叉编译的设置

### 工具：clion、cmake

#### 使用方法（以Hello World为例）

1. 仅仅单独一个main.c与CMakeLists.txt
    main.c如下：

    ``` C
    #include<stdio.h>
    int main(){
        printf("hello from t1 mian!\n");
        return 0;
    }
    ```

    CMakeLists.txt如下：

    ``` text
    CMake_minimum_required(VERSION 3.11)
    PROJECT(HELLO)
    SET(SRC_LIST main.c)
    ADD_EXECUTABLE(hello ${SRC_LIST})
    ```

    在命令行中进行编译

    ``` cmd
    cmake path/to/main.c
    make
    ```

    将会自动生成Cmake文件
    ![20201006153552](https://raw.githubusercontent.com/chen810/lolibed/master/20201006153552.png)

    ``` txt
    CMakeCache.txt
    CMakeFiles
    cmake_install.cmake
    (可执行文件)[.exe]
    Makefile
    ```

2. 将编译文件单独区分开来存入build文件
    在编译过程中将编译语句进行更改即可

    ``` cmd
    cd ./build
    cmake path/to/main.c
    make
    ```

    ![20201006154914](https://raw.githubusercontent.com/chen810/lolibed/master/20201006154914.png)
    则以下文件自动移动到build中
    ![20201006154837](https://raw.githubusercontent.com/chen810/lolibed/master/20201006154837.png)

    ``` txt
    CMakeCache.txt
    CMakeFiles
    cmake_install.cmake
    (可执行文件)[.exe]
    Makefile
    ```

3. 存在多个源文件时（额外自己写的库文件等）
    main.c如下：

    ``` C
    #include<stdio.h>
    int main(){
        printf("hello from t1 mian!\n");
        return 0;
    }
    ```

    hello.cpp

    ``` C
    #include <stdio.h>
    #include "hello.h"
    void hello(const char* name){
        printf("HELLO %s!\n",name);
    }
    ```

    hello.h

    ``` h
    #ifndef AMM_HELLO_
    #define AMM_HELLO_
    void hello(const char* name);
    #endif
    ```

    CMakeLists.txt

    ``` txt
    project(PROJECT_NAME)
    set(SRC_LIST main.c hello.c)
    add_executable(PROJECT_NAME ${SRC_LIST})
    ```

    编译方式仍然 cmake + make 后产生如下文件
    ![20201006201631](https://raw.githubusercontent.com/chen810/lolibed/master/20201006201631.png)
    依旧可以创建一个build文件夹存储以下新增的文件

    ``` txt
    CMakeCache.txt
    CMakeFiles
    cmake_install.cmake
    (可执行文件)[.exe]
    Makefile
    ```

4. 生成所需库文件（以下PROJECT_NAME=A3，LIB_NAME=hello）
    需对以下文件进行修改
    CMakeLists.txt修改如下：

    ``` txt
    project(PROJECT_NAME)   #项目名
    set(LIB_SRC hello.c)    #lib源文件
    set(APP_SRC main.c)     #main源文件
    add_library(LIB_NAME ${LIB_SRC})   #添加lib头文件
    add_executable(PROJECT_NAME ${APP_SRC}) #生成项目文件
    target_link_libraries(PROJECT_NAME LIB_NAME)   #链接文件
    ```

    编译方式同上进入build使用cmake+make，产生如下文件
    ![20201006205520](https://raw.githubusercontent.com/chen810/lolibed/master/20201006205520.png)
    相对于以上生成多生成了一个libhello.a文件
    文件命名方式以lib+LIB_NAME.a构成

5. 文件拆分放置
    将源文件与库文件分别放入src与lib中
    可执行文件放入build/bin
    生成的库文件放入build/lib
    文件结构如下：
    项目文件夹的CMakeLists.txt修改如下：

    ``` txt
    CMake_minimum_required(VERSION 3.11)
    project(PROJECT_NAME)
    add_subdirectory(src)
    add_subdirectory(lib+LIB_NAME)
    ```

    lib+LIB_NAME文件夹的CMakeLists.txt

    ``` txt
    set(LIB_SRC hello.c)
    add_library(lib+LIB_NAME ${LIB_SRC})
    set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
    set_target_properties(lib+LIB_NAME PROPERTIES OUTPUT_NAME "LIB_NAME")
    ```

    src中的CMakeLists.txt

    ``` txt
    include_directories(${PROJECT_SOURCE_DIR}/lib)
    set(APP_SRC main.c)
    set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
    add_executable(PROJECT_NAME ${APP_SRC})
    target_link_libraries(PROJECT_NAME lib+LIB_NAME)
    ```

    即可在src中写源文件，lib+LIB_NAME中写库文件
    生成的应用在build/bin,库文件在build/lib

6. 生成动态库文件
    >使用第五点生成的库文件为静态库文件，可在lib+LIB_NAME文件夹内的CMakeLists.txt中add_library项写作add_library(lib+LIB_NAME SHARED ${LIB_SRC})从而生成动态库文件
