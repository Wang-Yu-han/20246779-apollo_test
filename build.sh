#!/bin/bash

# 设置构建目录
BUILD_DIR="build"

# 如果构建目录存在，则清理它
if [ -d "$BUILD_DIR" ]; then
    echo "Build directory exists. Cleaning up..."
    rm -rf $BUILD_DIR/*
else
    echo "Creating build directory..."
    mkdir $BUILD_DIR
fi

# 进入构建目录
cd $BUILD_DIR

# 运行 CMake 配置
echo "Running cmake .."
cmake ..

# 如果 CMake 配置成功，开始构建
if [ $? -eq 0 ]; then
    echo "Building project..."
    make
else
    echo "CMake configuration failed!"
    exit 1
fi

# 可选：构建完成后运行可执行文件
# echo "Running the executable..."
# ./leetcode130

echo "Build completed."

cd $BUILD_DIR

./leetcode130
