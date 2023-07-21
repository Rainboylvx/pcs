#!/bin/bash

# 定义任务总数
total=100

# 初始化计数器
count=0

# 打印进度条
print_progress() {
  # 计算进度
  progress=$((count * 100 / total))
  # 计算进度条长度
  filled=$((progress / 2))
  # 打印进度条
  printf "\r[%-50s] %d%%" "$(printf '#%.0s' $(seq 1 $filled))" $progress
}

# 模拟耗时任务
run_task() {
  sleep 0.1
  ((count++))
}

# 主循环
while [ $count -lt $total ]; do
  run_task
  print_progress
done

echo # 换行

