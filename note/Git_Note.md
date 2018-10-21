## Git教程
### 命令大全1
命令|含义
---|---
cd X:\obito|更改初始化目录
cd .. (cd 与 .. 之间有一空格)|返回上一级目录
cd git（进去git目录）|进入某一目录
git clone [url]|克隆（默认情况下，Git 会按照你提供的 URL 所指示的项目的名称创建你的本地项目目录。 通常就是该 URL 最后一个 / 之后的项目名称。如果你想要一个不一样的名字， 你可以在该命令后加上你想要的名称。）：git clone xxx.git "指定目录"
git add . |命令来添加当前项目的所有文件
git status -s|查看文件添加状态（直接git status而不加-s，则会输出具体的内容
git diff |命令显示已写入缓存与已修改但尚未写入缓存的改动的区别：尚未缓存的改动：`git diff` 查看已缓存的改动：` git diff --cached`查看已缓存的与未缓存的所有改动：`git diff HEAD`显示摘要而非整个 diff：`git diff --stat`
git commit -m "<注释>"|使用 -m 选项以在命令行中提供提交注释
git commit -am "<注释>"|用am跳过git add 提交缓存的繁琐流程
git reset HEAD <file> |取消缓冲区，不提交
git rm <file>|删除文件
git rm -f <file>|删除之前修改过并且已经放到暂存区域，必须要用强制删除选项 -f
git rm --cached <file>|如果把文件从暂存区域移除，但仍然希望保留在当前工作目录中，换句话说，仅是从跟踪清单中删除，使用 --cached 选项即可。之后可用 git add <file> 把文件重新添加回来
git rm –r * |递归删除，即如果后面跟的是一个目录做为参数，则会递归删除整个目录中的所有子目录和文件
 git log|查看提交历史
git log --oneline|来查看历史记录的简洁的版本
git log --oneline --graph|用于查看历史中什么时候出现了分支、合并。以下为相同的命令，开启了拓扑图选项
git log --reverse --oneline|逆向显示所有日志
git log --author|查找指定用户的提交日志：例如：git log --author=Linus --oneline **-5**
git log --oneline --before={3.weeks.ago} --after={2010-04-18} --no-merges|指定日期，可以执行几个选项：--since 和 --before，但是你也可以用 --until 和 --after
git remote|可用于查看配置了哪些远程仓库；执行时加上 -v 参数，你还可以看到每个别名的实际链接地址：git remote -v
git fetch|从远程仓库下载新分支与数据；例如：git fetch origin
git merge|从远端仓库提取数据并尝试合并到当前分支。例如：git merge origin/master

### 命令行大全2
命令|含义
--|--
mkdir|创建文件夹
touch|创建文件
cat|查看文件（无法显示中文字体）
ZZ|退出编辑
ls|列出目录内容
退出Vim编辑器|一直按住esc ,再连续按大写的z两次
q|没法输入信息时，可以用

### Git 标签
命令|含义
git tag -a v1.0 |-a 选项意为"创建一个带注解的标签"
git tag -a v0.9 <id>|例如：git tag -a v0.9 85fc7e7
git tag|查看所有标签
git tag -a <tagname> -m "runoob.com标签"|指定标签信息命令
git tag -s <tagname> -m "runoob.com标签"|PGP签名标签命令

### Git Status -s的状态
表示|含义
--|--
A|你本地新增的文件（服务器上没有）
C|文件的一个新拷贝
D|你本地删除的文件（服务器上还在）
M|文件的内容或者mode被修改了
AM|这个文件在我们将它添加到缓存之后又有改动。改动后我们再执行 git add 命令将其添加到缓存
R|文件名被修改了
T|文件的类型被修改了
U|文件没有被合并(你需要完成合并才能进行提交)
X|未知状态(很可能是遇到git的bug了，你可以向git提交bug report)
？|未被git进行管理，可以使用git add file1把file1添加进git能被git所进行管理

### Git提交
命令|含义
--|--
git push origin :<branch>|删除远程分支（注意：origin和：之间有空格） 
git push origin <branch>|本地分支同步到远程分支
git pull origin <branch>|远程分支同步到本地分支
push origin master|推送最新修改
git push -u origin master |推送至github

### 添加文件以及推送到Github的一系列步骤
```git
touch runoob-test.txt		#添加文件
git add runoob-test.txt
git commit -m ”添加到远程“
git push origin master		#推送到GitHub
```
```git
mkdir runoob-git-test		#创建测试目录
cd runoob-git-test/			#进入测试目录
echo "#菜鸟教程 Git 测试“ >> README.md		#创建README.md文件并写入目录
git init		#初始化
git add README.md		#添加文件
git commit -m "添加README.md文件”		#提交并备注信息
git remote add origin git@github.com:tianqixin?runoob-git-tset.git
git push -u origin master		#提交到Github
#git  merge origin/master		#同步master分支到本地
```

### Git代码库回滚

git代码库回滚: 指的是将代码库某分支退回到以前的某个commit id

* 本地代码库回滚：
```
git reset --hard commit-id :回滚到commit-id，讲commit-id之后提交的commit都去除
git reset --hard HEAD~3：将最近3次的提交回滚
```
* 远程代码库回滚：

这个是重点要说的内容，过程比本地回滚要复杂
应用场景：自动部署系统发布后发现问题，需要回滚到某一个commit，再重新发布
原理：先将本地分支退回到某个commit，删除远程分支，再重新push本地分支。
操作步骤：
```
git checkout the_branch
git pull
git branch the_branch_backup //备份一下这个分支当前的情况
git reset --hard the_commit_id //把the_branch本地回滚到the_commit_id
git push origin :the_branch //删除远程 the_branch
git push origin the_branch //用回滚后的本地分支重新建立远程分支
git push origin :the_branch_backup //如果前面都成功了，删除这个备份分支
```

如果使用了gerrit做远程代码中心库和code review平台，需要确保操作git的用户具备分支的push权限，并且选择了 Force Push选项（在push权限设置里有这个选项）
另外，gerrit中心库是个bare库，将HEAD默认指向了master，因此master分支是不能进行删除操作的，最好不要选择删除master分支的策略，换用其他分支。如果一定要这样做，可以考虑到gerrit服务器上修改HEAD指针。。。不建议这样搞。


远程仓库与本地文件修改发生冲突的解决方案：（未试用）
![解决方案](./photo/conflicted.png)

* Github的txt文件包含中文时可能会出现乱码的现象，可以将格式转化为UTF-8的编码格式：具体操作时，可将txt文件另保存为UTF-8编码。
* 在使用分支时，结束分支转到其他分支或者master时，必须将分支做的修改提交到缓冲区，即：Git commit -m “注释”再切换。
* $ git push origin：表示将当前分支推送到origin主机的对应分支。如果当前分支只有一个追踪分支，那么主机名都可以省略。
* $ git push 如果当前分支与多个主机存在追踪关系，那么这个时候-u选项会指定一个默认主机，这样后面就可以不加任何参数使用git push。
* $ git push -u origin master 上面命令将本地的master分支推送到origin主机，同时指定origin为默认主机，后面就可以不加任何参数使用git push了。


