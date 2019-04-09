# 万物皆可RSS 配置

> 想法来源于[熊猫小A](https://blog.imalan.cn)的博客。


### 能做哪些事情？

可以把**任何有RSS源网站内容可以聚合在时光机页面内**。比如微博、微信公众号、（前两个需要RSShub的开源服务支持）另一个博客的内容等等。

**对代码不了解的伙伴们直接看下一个说明（简单配置微博），后面的都不要看了！！**


### 简单配置微博

```json
{"id":"weibo","name":"微博","url":"https://rsshub.app/weibo/user/5631723091"}
```

直接把上面的代码复制到配置框中，`https://rsshub.app/weibo/user/5631723091` 最后的一串数字`5631723091`是你的微博UID，打开你的微博的主页的地址中有的

### 配置项填写

* `id` ：rss标识符，任何字母（id**请勿重复**）。
    * 比如微博，可以是`weibo`
* `name` ：rss内容标题，一般是中文。如果是`微博`，就直接填`微博`
* `url` ：rss源地址
    * 比如微博，就是`https://rsshub.app/weibo/user/5631723091`（这个源有时候不稳定，可以用另一个）或者`https://rsshub.app/weibo/user2/5631723091`
    * 比如别的博客内容：一般的博客系统都支持生成RSS订阅地址的，比如我的博客就是`https://www.ihewro.com/feed/`
    * 只要是RSS源地址，都是支持的
* `img` （非必填项）：代表该栏目的图片，以头像形式显示。建议是正方形的。填写图片的url地址即可
* `type`（非必填项）：显示的内容形式

    * `discription` 仅显示文章摘要（有的RSS源摘要中包含整个文章内容）（不填的话，默认是这个）
    * `title` 仅显示文章标题
    * `mix` 显示标题+摘要 （暂不支持）

### RSS 源禁止跨域怎么办？

最简单的解决办法是：在原有的RSS源地址前面加上`https://cors-anywhere.herokuapp.com/`

**举例**：


`https://api.fanfou.com/statuses/user_timeline/~k40sgjV_6kg.rss`  该源是禁止跨域的，所有无法请求到（浏览器可以正常访问，但是无法通过代码获取数据），修改后的源地址为：

`https://cors-anywhere.herokuapp.com/https://api.fanfou.com/statuses/user_timeline/~k40sgjV_6kg.rss`

填`url`属性就填后者即可。（可能速度会有些影响）

