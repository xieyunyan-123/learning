// server.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    // 1. socket(): 买手机
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. bind(): 办卡，绑定 IP 和 端口
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888); // htons: 把主机字节序转为网络大端字节序
    addr.sin_addr.s_addr = INADDR_ANY; // 监听所有网卡
    bind(lfd, (struct sockaddr*)&addr, sizeof(addr));

    // 3. listen(): 设为待机状态
    listen(lfd, 128);
    printf("服务器已启动，等待连接...\n");

    // 4. accept(): 接听电话
    int cfd = accept(lfd, NULL, NULL);
    printf("发现新客户！开始通话...\n");

    // 5. 通信
    char buf[1024];
    while (1) {
        int len = read(cfd, buf, sizeof(buf));
        if (len <= 0) break;
        printf("收到数据: %s", buf);
        write(cfd, buf, len); // Echo: 原样发回
    }

    close(cfd);
    close(lfd);
    return 0;
}

