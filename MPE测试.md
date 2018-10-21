
<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

1. [45](#45)
	1. [Markdown基础](#markdown基础)
	2. [数学](#数学)
	3. [图像](#图像)
	4. [目录](#目录)
	5. [导入文件](#导入文件)
	6. [幻灯片（不想使用）](#幻灯片不想使用)

<!-- /code_chunk_output -->


## 45
### Markdown基础
- 添加图片：格式：`![Alt Text](url)`：`![GitHub Logo](/images/logo.png)`
- 链接：`[GitHub](http://github.com)`
- 引用：
```
正如 Kanye West 所说：
> We're living the future so
> the present is our past.
```
- 加代码行数： {.line-numbers}
- **MPE扩展语法的表格**用不了
- 上标：30^th^
- 下标：H~2~0
- 脚注：Content[^1]
- 缩写：
*[HTML]: Hyper Text Markup Language
*[W3C]:  World Wide Web Consortium
The HTML specification
is maintained by the W3C.
- 标记：==marked==

### 数学
- `$...$` 或者 `\(...\)` 中的数学表达式将会在行内显示。
- `$$...$$` 或者 `\[...\]` 或者```math 中的数学表达式将会在块内显示。
### 图像
**有些图像不支持PDF和pandoc的导出**
**流程图的编程语言**

### 目录
- 设置：可以通过`cmd-shift-p`然后选择`Markdown Preview Enhanced: Create Toc`命令来创建`TOC`，保存后自动生成。
    - “orderedList 是否使用有序列表。
    - depthFrom, depthTo [1~6] 包含的。
    - ignoreLink 如果设置为 true，那么 TOC 将不会被超链接。
- 也可以输入`[TOC]`来创建目录；但只会在预览中显示，不会改变Markdown文件。

### 导入文件
- `@import "你的文件"`:文件名必须是英文的，不然加载不出来
- 支出的文件类型:
	- .jpeg(.jpg), .gif, .png, .apng, .svg, .bmp 文件将会直接被当作 markdown 图片被引用。
	- .csv 文件将会被转换成 markdown 表格。
	- .mermaid 将会被 mermaid 渲染。
	- .dot 文件将会被 viz.js (graphviz) 渲染。
	- .plantuml(.puml) 文件将会被 PlantUML 渲染。
	- .html 将会直接被引入。
	- .js 将会被引用为 <script src="你的 js 文件"></script>。
	- .less 和 .css 将会被引用为 style。目前 less 只支持本地文件。.css 文件将会被引用为 <link rel="stylesheet" href="你的 css 文件">。
	- .pdf 文件将会被 pdf2svg 转换为 svg 然后被引用。
	- markdown 将会被分析处理然后被引用。
	- 其他所有的文件都将被视为代码块。
- 设置图片：`@import "test.png" {width="300px" height="200px" title="图片的标题" alt="我的 alt"}

@import "dra.png"{title="多啦A梦" alt="多啦"}
- 引用在线文件:`@import "https://raw.githubusercontent.com/shd101wyy/markdown-preview-enhanced/master/LICENSE.md"
`
- 引用PDF：省略
- 强制渲染为代码块：引用文件，可以编写完随时保持更新并且看得到文件的内容
	- `@import "test.puml" {code_block=true class="line-numbers"}`
	- `@import "test.py" {class="line-numbers"}`
@import "urlerror_urllib.py"{class="line-numbers"}
- As（作为）代码块：`@import "test.json" {as="vega-lite"}`(没试过)
- 引用文件作为 Code Chunk：`@import "test.py" {cmd="python3"}`:可运行程序（不想使用这功能，感觉有点累赘）

@import "urlerror_urllib.py"{cmd="python3" class="line-numbers}

### 幻灯片（不想使用）
pandoc

[^1]:H1!This is a footnote