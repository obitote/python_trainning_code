#第二章

[TOC]

###urllib.request模块里的BaseHandler类
**BaseHandler的各种继承子类**

1. `HTTPDefaultErrorHandler` 用于处理 HTTP 响应错误，错误都会抛出 HTTPError 类型的异常。
2. `HTTPRedirectHandler` 用于处理重定向。
3. `HTTPCookieProcessor` 用于处理 Cookies。
4. `ProxyHandler` 用于设置代理，默认代理为空。
5. `HTTPPasswordMgr` 用于管理密码，它维护了用户名密码的表。
6. `HTTPBasicAuthHandler` 用于管理认证，如果一个链接打开时需要认证，那么可以用它来解决认证问题。
####认证
```Python
from urllib.request import HTTPPasswordMgrWithDefaultRealm,HTTPBasicAuthHandler,build_opener
from urllib.error import URLError

username = 'username'
password = 'password'
url = 'http://localhost:5000/'

p = HTTPPasswordMgrWithDefaultRealm()
p.add_password(None, url, username, password)
auth_handler = HTTPBasicAuthHandler(p)
opener = build_opener(auth_handler)

try:
    result = opener.open(url)
    html = result.read().decode('utf-8')
    print(html)
except URLError as e:
    print(e.reason)
```
###处理异常
**URLError**
	URLError 类来自 Urllib 库的 error 模块，它继承自 OSError 类，是 error 异常模块的基类，由 request 模块生的异常都可以通过捕获这个类来处理。它具有一个属性 reason，即返回错误的原因。
**HTTPError**
	它是 URLError 的子类，专门用来处理 HTTP 请求错误，比如认证请求失败等等。它有三个属性。
	1. `code`，返回 HTTP Status Code，即状态码，比如 404 网页不存在，500 服务器内部错误等等。
	2. `reason`，同父类一样，返回错误的原因。
	3. `headers`，返回 Request Headers。
###解析链接
**urlparse()**
	返回的结果是一个 `ParseResult` 类型的对象，它包含了六个部分，分别是 `scheme`、`netloc`、`path`、`params`、`query`、`fragment`。返回结果 `ParseResult` 实际上是一个元组，我们可以用索引顺序来获取，也可以用属性名称获取。
```python
urllib.parse.urlparse(urlstring, scheme='', allow_fragments=True)
```
1. 	urlstring，是必填项，即待解析的 URL。
2. scheme，是默认的协议（比如http、https等），假如这个链接没有带协议信息，会将这个作为默认的协议。
3. allow_fragments，即是否忽略 fragment，如果它被设置为 False，fragment 部分就会被忽略，它会被解析为 path、parameters 或者 query 的一部分，fragment 部分为空。

**urlunparse()**
**urlsplit()**
**urlunsplit()**
**urljoin()**
	利用 `urljoin()` 方法我们可以提供一个 `base_url`（基础链接），新的链接作为第二个参数，方法会分析 `base_url` 的 `scheme`、`netloc`、`path` 这三个内容对新链接缺失的部分进行补充，作为结果返回。如果这三项在新的链接里面不存在，那么就予以补充，如果新的链接存在，那么就使用新的链接的部分。`base_url` 中的 `parameters`、`query`、`fragments` 是不起作用的。
**urlencode()**
	调用 urlencode() 方法将其序列化为 URL 标准 GET 请求参数。有时为了更加方便地构造参数，我们会事先用字典来表示，要转化为 URL 的参数时只需要调用该方法即可。

```python
from urllib.parse import urlencode

params = {
    'name': 'germey',
    'age': 22
}
base_url = 'http://www.baidu.com?'
url = base_url + urlencode(params)
print(url)
```
运行结果：
```python
http://www.baidu.com?name=germey&age=22
```

**parse_qsl()**
	可以将参数转化为元组组成的列表
```python
from urllib.parse import parse_qsl

query = 'name=germey&age=22'
print(parse_qsl(query))
```
运行结果：
```python
[('name', 'germey'), ('age', '22')]
```

**quote()**
	quote() 方法可以将内容转化为 URL 编码的格式，有时候 URL 中带有中文参数的时候可能导致乱码的问题，所以我们可以用这个方法将中文字符转化为 URL 编码。
```python
from urllib.parse import quote

keyword = '壁纸'
url = 'https://www.baidu.com/s?wd=' + quote(keyword)
print(url)
```
运行结果：
```python
https://www.baidu.com/s?wd=%E5%A3%81%E7%BA%B8
```

**unquote()**
	它可以进行 URL 解码
```python
from urllib.parse import unquote

url = 'https://www.baidu.com/s?wd=%E5%A3%81%E7%BA%B8'
print(unquote(url))
```
运行结果：
```python
https://www.baidu.com/s?wd=壁纸
```
###Robots协议
	Robots 协议也被称作爬虫协议、机器人协议，它的全名叫做网络爬虫排除标准（Robots Exclusion Protocol），用来告诉爬虫和搜索引擎哪些页面可以抓取，哪些不可以抓取。它通常是一个叫做 robots.txt 的文本文件，放在网站的根目录下。
	当搜索爬虫访问一个站点时，它首先会检查下这个站点根目录下是否存在 robots.txt 文件，如果存在，搜索爬虫会根据其中定义的爬取范围来爬取。如果没有找到这个文件，那么搜索爬虫便会访问所有可直接访问的页面。
robots.txt样例
```python
User-agent: *	#'*' 代表该协议对任何的爬取爬虫有效
Disallow: /		# '/' 表示禁止所有爬虫访问任何目录，空白则表示允许所有爬虫访问任何目录
Allow: /public/	# /public/ 表示只允许爬取 public目录
```
禁止所有爬虫访问网站某些目录
```python
User-agent: *
Disallow: /private/
Disallow: /tmp/
```

**robotparser模板 **
	使用 `robotparser` 模块来解析 robots.txt。
	`robotparser` 模块提供了一个类，叫做 `RobotFileParser`。它可以根据某网站的 robots.txt 文件来判断一个爬取爬虫是否有权限来爬取这个网页。
|方法|作用|
|---|---|
|set_url()|来设置 robots.txt 文件的链接。如果已经在创建 RobotFileParser 对象时传入了链接，那就不需要再使用这个方法设置了|
|read()|读取 robots.txt 文件并进行分析，注意这个函数是执行一个读取和分析操作，如果不调用这个方法，接下来的判断都会为 False，所以一定记得调用这个方法，这个方法不会返回任何内容，但是执行了读取操作|
|parse()|用来解析 robots.txt 文件，传入的参数是 robots.txt 某些行的内容，它会按照 robots.txt 的语法规则来分析这些内容|
|can_fetch()|方法传入两个参数，第一个是 User-agent，第二个是要抓取的 URL，返回的内容是该搜索引擎是否可以抓取这个 URL，返回结果是 True 或 False|
|mtime()|返回的是上次抓取和分析 robots.txt 的时间，这个对于长时间分析和抓取的搜索爬虫是很有必要的，你可能需要定期检查来抓取最新的 robots.txt|
|modified()|同样的对于长时间分析和抓取的搜索爬虫很有帮助，将当前时间设置为上次抓取和分析 robots.txt 的时间|