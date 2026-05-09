第四章：Linux 网络编程 (TCP Echo Server)
基于 Socket API 实现的同步阻塞式服务器。客户端发送的任何消息都将由服务器原样返回。

掌握 socket(), bind(), listen(), accept() 等核心系统调用。

理解网络字节序（大端）与主机字节序（小端）的转换。

Bash
# 运行服务器
cd ch4-network
gcc server.c -o server
./server

# 另一个终端测试
nc 127.0.0.1 8888
🛠️ 环境要求
操作系统: Ubuntu (x86_64)

编译器: gcc

工具: git, netcat

📝 提交规范
本项目遵循约定式提交规范：

feat: 新实验功能

fix: 修补 bug

chore: 构建过程或辅助工具的变动
"""
