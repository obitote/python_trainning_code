'''
import requests

data = {
    'name': 'germey',
    'age':22
}
url = 'http://httpbin.org/get'
r = requests.get(url=url, params=data)
print(r.text)
'''
'''抓取知乎发现页面
import requests
import re

headers = {
    'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_11_4) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/52.0.2743.116 Safari/537.36'
}
r = requests.get("https://www.zhihu.com/explore", headers=headers)
pattern = re.compile('explore-feed.*?question_link.*?>(.*?)</a>', re.S)
titles = re.findall(pattern, r.text)
print(titles)
'''


#获取Github的图标
import requests

r = requests.get('http://github.com/favicon.ico')
with open('favicon.ico', 'wb') as f:
    f.write(r.content)
