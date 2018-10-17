## Mint快捷键
* 启动终端：Ctrl+Shift+T
* 启动网页浏览器：Ctrl+Z
* 工作区的切换：Ctrl+Alt+左/右方向键
* PrtSc – 获取整个屏幕的截图并保存到 Pictures 目录。
* Alt + PrtSc –获取当前窗口的截图并保存到 Pictures 目录。
* 呼出沙拉词典：Ctrl+Shift+S
## 软件下载
* hromium查资料等，Calibre图书馆，Mendeley文献管理，RStudio统计分析画图，Netbeans、Racket、Leksah、Emacs写代码，TexStudio+ TexLive写论文。NetEase Cloud Music听歌,官方源里的而且是stable版
* 用aria2下载
* Vim gcc
* 给的内存太少了就不同步了，直接用网页坚果云就行
* 搭各种服务，LAMP，FTP、SMTP、Squid。
配置开发环境，JDK，AndroidSDK，OpenGL，各种能装的都装上。编辑器开始用的 codeblocks，后来把 vim 配成完整的 IDE，折腾了好久 emacs 最后小拇指太短放弃了。
* PDF编辑器：master-pdf-editor [链接](https://code-industry.net/masterpdfeditor/?-about&ver=3581)
* dia:代替visio sudo apt-get install dia
## 问题
- [ ] 解决网易云音乐始终得用root权限打开的问题
- [x] 搜狗输入法乱码问题 [解决](https://blog.csdn.net/s_lisheng/article/details/79620131)
- [x] pycharm安装问题：Pycharm下载好后就文件放到/opt/目录下，然后创建一个启动器就好了（参考视频教程）
- [ ] vscode的2个插件学习
  
## 学习视频
* [Linux命令行学习](http://billie66.github.io/TLCL/book/chap02.html) 
* [网易云课堂 细说Linux-从入门到精通视频教程](https://study.163.com/course/introduction.htm?courseId=983014#/courseDetail?tab=1)
## 操作
* 挂载win10硬盘分区 [链接](https://www.jianshu.com/p/d83e7c84a496)
1. 管理员：sudo su
2. FDISK查获磁盘设备盘符：fdisk -l
3. 找到要挂载的磁盘设备,如sda6,使用ntfsfix:# sudo ntfsfix /dev/sda6
* Linux下上DR.COMS上网客户端的方法 [链接](https://jingyan.baidu.com/article/5552ef473b40f3518ffbc9f9.html)

客户端启动：开机自启动以及将启动器打包成程序
挂载硬盘：能永久挂载
注意点文件不要保存到挂载的硬盘中
邮箱客户端：Geary
添加邮箱账号并且总结过程
visio流程图绘制软件：dia图标编辑器
词典添加
用aira2下载百度网盘文件
FreeBSD
## 事项
1. 完成简历，写2个版本，并且完成简历图片
2. 投简历
3. 网易云课堂学习linux的内核及相关信息
4. 学习编写爬虫
5. 英语的学习
6. 完成以上的问题并整理

## 学习
* 阅读：阅读The Economist并记笔记
* 单词：墨墨背单词
* 听力：可可英语

### 安装Anaconda
1. 到 [此处](https://repo.continuum.io/archive)下载Linux版本的sh文件，我这里下载的是：Anaconda2-5.2.0-Linux-x86_64.sh
2. 在下载的anaconda安装包的目录下进行安装：`bash Anaconda2-5.2.0-Linux-x86_64.sh`，安装后要重启终端，anaconda才能生效。
3. 在终端下输入`python`，然后输入`import scipy`，没有报错则安装成功。
4. 在安装过程中顺带安装了VScode

### 配置Git
1. 在终端运行命令：sudo apt-get install git
2. 查看版本号：git --version
3. 备注：若不是最新可选择更新
```
更新提示：
sudo add-apt-repository ppa:git-core/ppa
sudo apt-get update
sudo apt-get install git
```
4. 配置git用户名邮箱：
```
git config --global user.name "username"
git config --global user.email "XXXX@XX.com"
```
5. 可以用`cat .gitconfig`查看配置是否生效
6. 用`ssh-keygen -t rsa -C "lgq1424484243@gmail.com"`生成新的public key(id_rsa.pub文件内容即为SSH key)
7. 之后将`/home/obito/.ssh`路径的`id_rsa.pub`的内容复制到Github的SSH页面中即可
8. (没用上)输入`chmod 700 id_rsa`，更改文件的权限，否则在git  clone的时候会报“Permissions 0664 for '*******/.ssh/id_rsa' are too open.”的错；
9. 官网上有linux的[Fork a repo教程](https://help.github.com/articles/fork-a-repo/)
10. （未验证）：Linux下无法新建一个repo，只能对github中已有的repo进行修改。所以，当要新建一个repo时，必须在github.com上新建，再通过linux下的git向此repo中新添内容

老师居然还亲自登门来询问情况，虽然只是简单几句，但我没有凑过去，说谎总是不自在的

### 配置Linux下的百度云下载：
* [软件下载地址](https://github.com/iikira/BaiduPCS-Go/releases)
* [编译 交叉编译帮助](https://github.com/iikira/BaiduPCS-Go/wiki/%E7%BC%96%E8%AF%91-%E4%BA%A4%E5%8F%89%E7%BC%96%E8%AF%91%E5%B8%AE%E5%8A%A9)
* [知乎相关问题](https://www.zhihu.com/question/49727840)
* 
### 安装Go语言
[链接](https://www.cnblogs.com/linuxprobe/p/5654380.html)
1. 在命令行中输入：sudo apt-get install golang
2. 查看当前系统安装的Go语言版本：go version
3. 由于 Go 代码必需保存在 workspace(工作区)中，所以我们必需在 Home 目录(例如 ~/workspace)创建一个workspace 目录并定义 GOPATH 环境变量指向该目录，这个目录将被 Go 工具用于保存和编辑二进制文件。:
```
mkdir ~/workspace
echo 'export GOPATH="$HOME/workspace"' >> ~/.bashrc
source ~/.bashrc
```
4. 根据不同的需要，我们可以使用 apt-get 安装 Go tools：sudo apt-cache search golang

## 问题
- [x] 问题：安装完后输入Python出来的却是2.7版本，而且pycharm的解释器也没有找到anaconda的包
- [x] 解决:[Linux系统如何将首选Python设置为anaconda里面的Python](https://blog.csdn.net/waitfou/article/details/79024075)
- [x] Linux下配置anaconda开发环境：首先打开pycharm 选择file-> default setting -> project interpreter -> conda Environment。 **注意！！！** 这里选择下面的Existing environment 并将Make available to all projects 打上勾。在interpreter 中找到你所安装的anaconda3的文件夹，我的路径是home/***/anaconda3，然后选择bin路径，找到python3.6  点击OK -> OK -> apply -> OK 这样就配置完成了。[链接](https://blog.csdn.net/qq_38957170/article/details/81199073?utm_source=blogxgwz2)
- [ ] 安装Git，建立私人repo，然后将每天的工作都上传








