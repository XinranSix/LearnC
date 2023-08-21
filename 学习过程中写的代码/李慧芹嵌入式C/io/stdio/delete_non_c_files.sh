#!/bin/bash

# 遍历当前目录下的所有文件
for file in *; do
    # 如果文件不是以.c结尾且不是以.sh结尾
    if [ "${file##*.}" != "c" ] && [ "${file##*.}" != "sh" ]; then
        # 删除文件
        rm "$file"
        echo "删除文件: $file"
    fi
done
