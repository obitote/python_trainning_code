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
可以使用netstat命令检查nfs端口是否已经打开
netstat -tl
```
配置NFS服务
- 在NFS的主配置文件`/etc/exports`中设置，然后启动NFS服务
- 在`exports`文件中可以定义NFS系统的输出目录（即共享目录），访问权限和允许访问的主机等参数，格式如下：
```shell
[共享的目录][主机名1或者IP1(参数1,参数2)][主机名2或IP2(参数3,参数4)]
/nfs/public 192.168.0.0/24(rw,sync) *(ro)
/nfs/public：共享目录名
192.168.0.0/24：表示所有主机
sync：设置NFS服务器同步写磁盘，这样不会轻易丢失数据
ro：设置输出的共享目录只读，与rw不能共同使用
rw：设置输出的共享目录可读写，与ro不能共同使用
```
- exports文件中“客户端主机地址”字段可以使用多种形式表示主机地址
    - 192.168.152.13：指向IP地址的主机
    - nfsclient.test.com：指定域名的主机
    - 192.169.1.0/24：指定网段中的所有主机
    - *.test.com：指定域下的所有主机
    - *：所有主机
使用mount命令挂载nfs文件系统
`mount -t nfs localhost: /opt/root_fs/mnt`

```bash
#自己操作
su -    #获取超级用户权限
apt-get install nfs-kernel-server   #安装
dpkg -l | grep -i 'nfs'     #查看是否安装
```

- dpkg -l：列出安装的软件包
- grep -i：忽略大小写
- NFS、Samba、FTP、SSH的区别