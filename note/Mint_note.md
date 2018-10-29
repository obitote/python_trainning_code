1. [Mint快捷键](#mint快捷键)
2. [软件下载](#软件下载)
3. [学习视频](#学习视频)
4. [软件配置问题](#软件配置问题)
    1. [挂载win10硬盘分区 ：链接](#挂载win10硬盘分区-链接)
    2. [Linux下上DR.COMS上网客户端的方法 链接](#linux下上drcoms上网客户端的方法-链接)
    3. [安装Anaconda](#安装anaconda)
    4. [配置Git](#配置git)
    5. [配置Linux下的百度云下载：](#配置linux下的百度云下载)
    6. [安装Go语言：链接](#安装go语言链接)
    7. [安装Texlive](#安装texlive)
5. [学习](#学习)
6. [问题](#问题)
    1. [VS code插件安装](#vs-code插件安装)
    2. [web开发](#web开发)


## Mint快捷键
* 启动终端：Ctrl+Shift+T
* 启动网页浏览器：Ctrl+Z
* 工作区的切换：Ctrl+Alt+左/右方向键
* PrtSc – 获取整个屏幕的截图并保存到 Pictures 目录。
* Alt + PrtSc –获取当前窗口的截图并保存到 Pictures 目录。
* 呼出沙拉词典：Ctrl+Shift+S
* 用 quit() or Ctrl-D (i.e. EOF)来停止终端的Python编辑模式

## 软件下载
* hromium查资料等，Calibre图书馆，Mendeley文献管理，RStudio统计分析画图，Netbeans、Racket、Leksah、Emacs写代码，TexStudio+ TexLive写论文。NetEase Cloud Music听歌,官方源里的而且是stable版
* 用aria2下载，用aira2下载百度网盘文件
* Vim gcc
* 给的内存太少了就不同步了，直接用网页坚果云就行
* 搭各种服务，LAMP，FTP、SMTP、Squid。配置开发环境，JDK，AndroidSDK，OpenGL，各种能装的都装上。编辑器开始用的 codeblocks，后来把 vim 配成完整的 IDE，折腾了好久 emacs 最后小拇指太短放弃了。
* PDF编辑器：master-pdf-editor [链接](https://code-industry.net/masterpdfeditor/?-about&ver=3581)
* dia:代替visio sudo apt-get install dia
* FreeBSD
* webstorm---最强的前端ide，没有之一
* 写论文：Rstudio因为论文里要写很多公式，可学Latex又太麻烦了，但用word里那个公式编辑器想想蛋疼。谢益辉大神在Rstudio里写的knitr包很好的解决了这个问题。里面的Rmd格式不仅支持markdown， 还支持Latex语法，最重要的是：支持导出为word格式！！！  Rmd里的#，##,……直接对应word里的一级标题，二级标题，……。我论文里75张图，在Rmd里也就75行代码，一键生成word后，图片一下子导入的那种酸爽，你们体会一下。初稿导出后在word里再做些小调整就可以了。
* krita 手绘/图片处理软件
* pencil project 原型软件
* armrok 音乐软件
* inkscape 矢量图软件
* gimp 图像处理，gimp是编辑图像用的，krita是画画用的
* rawtherapee 照片后期处理
* meld，diff 的图形化工具
* xournal, 安装`sudo apt-get install xournal`可以自由记笔记，插文字，图片，划线，涂鸦，pdf上做笔记，标注
* C、C++ -> qtcreator
* aegisub+mkvtoolnix+handbrake：字幕
* you-get - 下载网页上的视频
* Shadowsocks-qt5：科学上网工具
```
[Shadowsocks-qt5](https://github.com/shadowsocks/shadowsocks-qt5)是一个科学上网利器工具。在天朝莫谈国情，说说Shadowsocks原理就好，它是将原来 ssh 创建的 Socks5 协议拆开成 Server 端和 Client 端，两个端分别安装在境外服务器和境内设备上。

![Shadowsocks-qt5](http://upload-images.jianshu.io/upload_images/1678789-9fafbe3453c332bb.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)
sudo add-apt-repository ppa:hzwhuang/ss-qt5
sudo apt-get update
sudo apt-get install shadowsocks-qt5 -y
```
* FileZilla是一个免费开源的FTP软件
* Brackets是一款使用 HTML，CSS，JavaScript 创建的开源的针对 Web 开发的编辑器。
 
## 学习视频
* [Linux命令行学习](http://billie66.github.io/TLCL/book/chap02.html) 
* [网易云课堂 细说Linux-从入门到精通视频教程](https://study.163.com/course/introduction.htm?courseId=983014#/courseDetail?tab=1)


## 软件配置问题

### 挂载win10硬盘分区 ：[链接](https://www.jianshu.com/p/d83e7c84a496)
1. 管理员：sudo su
2. FDISK查获磁盘设备盘符：fdisk -l
3. 找到要挂载的磁盘设备,如sda6,使用ntfsfix:# sudo ntfsfix /dev/sda6

### Linux下上DR.COMS上网客户端的方法 [链接](https://jingyan.baidu.com/article/5552ef473b40f3518ffbc9f9.html)


### 安装Anaconda
1. 到 [此处](https://repo.continuum.io/archive)下载Linux版本的sh文件，我这里下载的是：Anaconda2-5.2.0-Linux-x86_64.sh
2. 在下载的anaconda安装包的目录下进行安装：`bash Anaconda2-5.2.0-Linux-x86_64.sh`，安装后要重启终端，anaconda才能生效。
3. 在终端下输入`python`，然后输入`import scipy`，没有报错则安装成功。
4. 在安装过程中顺带安装了VScode

### 配置Git
1. 在终端运行命令：sudo apt-get install git
2. 查看版本号：git --version
3. 备注：若不是最新可选择更新
```{.line-numbers}
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
11. 应该还需要安装`vim`作为编辑器。其他部分参考[链接](https://www.cnblogs.com/xd502djj/p/4448491.html)
12. 每次要进行git操作的时候，需要cd到目录中，
13. 学习更多的git命令和操作


### 配置Linux下的百度云下载：
* [软件下载地址](https://github.com/iikira/BaiduPCS-Go/releases)
* [编译 交叉编译帮助](https://github.com/iikira/BaiduPCS-Go/wiki/%E7%BC%96%E8%AF%91-%E4%BA%A4%E5%8F%89%E7%BC%96%E8%AF%91%E5%B8%AE%E5%8A%A9)
* [知乎相关问题](https://www.zhihu.com/question/49727840)
* 
### 安装Go语言：[链接](https://www.cnblogs.com/linuxprobe/p/5654380.html)
1. 在命令行中输入：sudo apt-get install golang
2. 查看当前系统安装的Go语言版本：go version
3. 由于 Go 代码必需保存在 workspace(工作区)中，所以我们必需在 Home 目录(例如 ~/workspace)创建一个workspace 目录并定义 GOPATH 环境变量指向该目录，这个目录将被 Go 工具用于保存和编辑二进制文件。:
```
mkdir ~/workspace
echo 'export GOPATH="$HOME/workspace"' >> ~/.bashrc
source ~/.bashrc
```
4. 根据不同的需要，我们可以使用 apt-get 安装 Go tools：sudo apt-cache search golang

### 安装Texlive
```
sudo apt-get install texlive
```



## 学习
* 英语：
    * 阅读：阅读The Economist并记笔记
    * 单词：墨墨背单词
    * 听力：可可英语
* 编程：
    * Linux命令行的学习
    * Leetcode刷题
    * Python cookbook
    * 数据结构
* 老师居然还亲自登门来询问情况，虽然只是简单几句，但我没有凑过去，说谎总是不自在的
* 


## 问题
- [x] 问题：安装完后输入Python出来的却是2.7版本，而且pycharm的解释器也没有找到anaconda的包
- [x] 解决:[Linux系统如何将首选Python设置为anaconda里面的Python](https://blog.csdn.net/waitfou/article/details/79024075)
- [x] Linux下配置anaconda开发环境：首先打开pycharm 选择file-> default setting -> project interpreter -> conda Environment。 **注意！！！** 这里选择下面的Existing environment 并将Make available to all projects --no-sandbox打上勾。在interpreter 中找到你所安装的anaconda3的文件夹，我的路径是home/***/anaconda3，然后选择bin路径，找到python3.6  点击OK -> OK -> apply -> OK 这样就配置完成了。[链接](https://blog.csdn.net/qq_38957170/article/details/81199073?utm_source=blogxgwz2)
- [x] 安装Git，建立私人repo，然后将每天的工作都上传
- [ ] 解决网易云音乐始终得用root权限打开的问题
- [x] 搜狗输入法乱码问题 [解决](https://blog.csdn.net/s_lisheng/article/details/79620131)
- [ ] vscode的2个插件学习
- [ ] 挂载硬盘：能永久挂载，**注意点**文件不要保存到挂载的硬盘中
- [ ] 琢磨：Markdown Preview Enhance：[链接](https://shd101wyy.github.io/markdown-preview-enhanced/#/zh-cn/)

一直说着不想从事机械行业，到头来面试的也是机械行业，大学开学是嚷嚷着不想当码农，结果临近毕业又琢磨着投软件方面的简历。人呐，想法一直都在变化。

### VS code插件安装
- 快捷键：
    - 打开显示命令面板：Ctrl + Shift + P，F1
- Markdown All in One
    - 列表可用`-`以及用`Tab`进行缩进
    - Ctrl + B	切换粗体
    - Ctrl + I	切换斜体
    - Alt + S	切换删除线
    - Ctrl+ Shift+]	切换标题（上层）
    - Ctrl+ Shift+[	切换标题（下层）
    - Ctrl + M	切换数学环境
    - Alt + C	选中/取消选中任务列表项
    - 可用命令
        - Markdown：创建目录
        - Markdown：更新目录
        - Markdown：切换代码范围
        - Markdown：将当前文档打印为HTML
- Markdown Preview Github Styling
- (disable)Markdown Preview Enhance
    - 代码块行数：{.line-numbers}
    - 表格：有这种方式：
    - CriticMarkup：语法，默认是禁止的
- view in browser:能够将所写的代码运行在浏览器上.
- Class autocomplete for HTML:自动补齐

### web开发
- vscode + tslint
- webstorm