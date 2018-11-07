## 项目1 认识嵌入式系统开发
### 1.1 嵌入式系统学习线路
### 1.2 什么是嵌入式系统
### 1.3 嵌入式处理器

### 1.4 嵌入式操作系统

### 1.5 嵌入式系统结构

### 3.3 安装NFS服务
- 步骤：
1. 使用apt-get安装NFS服务
2. 启动与停止NFS服务
3. 设置NFS的主配置文件/eetc/exports
4. 使用mount命令挂载nfs文件系统
```shell
检测是否安装NFS，启动NFS服务时需要nfs-utils和portmap这两个软件包
# dpkg -l | grep -i 'nfs'
安装NFS服务器
# sudo apt-get install nfs-kernel-server
# sudo apt-get install nfs-common
启动与停止NFS服务
(/etc/init.d/nfs-kernel-server start)
    启动：service nfs-kernel-server start
    停止：service nfs-kernel-server stop
    重启：service nfs-kernel-server restart
启动NFS服务器后，可以使用ps命令查看进程
# ps -aux | grep -i 'nfs'
```
配置NFS服务







```bash
#自己操作
su -    #获取超级用户权限
apt-get install nfs-kernel-server   #安装
dpkg -l | grep -i 'nfs'     #查看是否安装
```