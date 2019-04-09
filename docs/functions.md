#### 博文头图

![headerpic](https://ihewrocdn.b0.upaiyun.com/img/headerpic.png)

分为两种：
* 首页头图：首页每篇文章顶部的图片
* 文章头图：每篇文章详情页面顶部的图片

具体见上图指示。

在后台的外观设置中可以对这两部分进行个性化设置：

> **个性化首页头图样式：**

* 大版式头图
* 小版式头图

在后台`外观设置——外观设置开关`中选择。缩小版头图显示即所有文章默认显示小版式头图。

每篇文章的编辑页面都可以选择首页头图样式，这里的设置会无视掉上面设置中的效果（仅对该篇文章有效），这样就实现大版式和小版式头图交叉的效果。

> **个性化头图来源：**

在后台`主题增强功能——博客头图来源设置`中选择。提供四种方式：

* 只显示随机图片
* 显示顺序：thumb自定义字段——文章第一个附件——文章第一张图片
* 显示顺序：thumb自定义字段——文章第一个附件——文章第一张图片——随机图片(推荐)
* 显示顺序：thumb自定义字段——随机图片

以第三种为例，当thumb字段为空的时候，会寻找文章的第一个附件，附件不是图片，会继续寻找文章中第一张图片，文章中如果没有图片的话再去加载随机图片。

其他选项亦是同理。

!> 文章的随机头图的图片存放位置为： 主题目录下的`usr/img/sj`</br>
左侧边栏的随机图片的存放位置为：`usr/img/sj2`

> **个性化头图显示：**

* 不显示文章页面头图
* 不显示首页头图

在后台`外观设置——外观设置开关`选择文章页面不显示头图或首页不显示头图，将会默认不显示文章页面或者首页文章顶部的头图。

每篇文章的编辑页面底部的自定义字段中，字段名为`thumb`,当值为`no`的时候，会不显示当前文章的头图（首页头图和文章头图）（仅对当前文章有效）,这里的设置同样会无视上面的设置。


#### 灯箱插件

文章中如果某个图片不想显示灯箱效果，可以给图片标签中加入`nogallery`属性：

```html
<img nogallery src="">
```

**如果某张图片高度很大，想折叠展示，可以给图片标签加入`max`属性：**

```html
<img max src="">
```

![](https://ws4.sinaimg.cn/large/006tNc79ly1g01rzaa2cmj310k0jygoz.jpg)

#### DNS预解析

!> 这个功能即将被删除

DNS prefetching通过指定具体的URL来告知客户端未来会用到相关的资源，告诉客户端可以尽早的解析DNS。

更多详细信息，[请戳这个](https://www.linpx.com/p/small-practice-of-prefetching-dns.html)


#### 文章目录树

文章中的目录树已经内置代码，**仅当文章有h2 h3 h4标题** 才会生成目录树，并且手机端不显示目录树。

**注意**：如果文章中没有`h2`标题，只有`h3 h4`标题是不会生成目录树的。




#### 侧边栏的标签云

需要在新建文章的页面右侧填写标签，才会在首页侧边栏输出的。(回车添加当前标签)

![tagcloud](https://ihewrocdn.b0.upaiyun.com/img/tag.png)

#### 自定义摘要字数

大版式头图默认摘要字数200字，小版式头图默认摘要字数80字。你可以在`后台外观设置->自定义大版式头图摘要/自定义小版式头图摘要`来改变这两个默认值。

你还可以使用`摘要分隔符`进行自主截断内容输出，**但是自主生成的摘要不会超过默认摘要字数**。

举例：你的默认摘要字数设置为200字，使用`摘要分隔符`截断的摘要为230字，则摘要只会显示200字。

```markdown
<!--more-->
```

#### 添加自定义图标

主题已经内置的图标列表，详见[图标列表](https://handsome.ihewro.com/#/icons)

如果不能满足你的图标需求，可以使用以下方法扩充主题图标：

##### 方法一：傻瓜式扩充fontawesome图标

直接引入全套的fontawesome图标：

在主题外观设置——开发者设置——自定义输出head 头部的HTML代码，填入：

```html
<link href="https://cdn.bootcss.com/font-awesome/4.7.0/css/font-awesome.min.css" rel="stylesheet">
```

上面的fontawesome 的css文件来自bootcdn.css 公共cdn提供，你可以替换成自己的文件。

##### 方法二：自定义添加iconfont图标列表
主题内置fontello图标来自网站`http://fontello.com/`

你可以在该网站中导入主题目录下的`assets/fonts/fontello`的`config.json`，然后重新生成字体文件。

覆盖到`assets/fonts/fontello`下，并且需要修改`assets/css/handsome.css`中形如`.fontello-*:before`，替换为下载的新的标签。

（难度较大，不推荐……）


#### 文章中插入按钮

handsome支持以下类型的按钮：
*  矩形文字按钮
*  椭圆形文字按钮
*  矩形图标文字按钮

```html
[button]矩形按钮文字[/button]

[button color="succees"]矩形按钮文字[/button]

[button type="round" color="success"]椭圆形按钮文字[/button]

[button color="success" icon="glyphicon glyphicon-eur"]图标按钮文字[/button]
```

* `type`：选填，不填默认为矩形按钮。可选值：
    * `round`：椭圆形按钮   

* `color`： 选填，不填默认为success（绿色），可选值：
    * `light`：白色
    * `info`：蓝色
    * `dark`：深色
    * `success`：绿色
    *  `black`：黑色
    *  `warning`：黄色
    *  `primary`：紫色
    *  `danger`：红色
* `icon`：选填，不填默认为文字按钮，可用按钮见[图标列表](./icons)
* `url`:选填，填写点击的链接。举例：如果你的链接是`http://www.baidu.com`，请手动将`/`前面加一个反斜杆`\`，即`http:\/\/www.baidu.com`

举例：
```html
[button color="danger" icon="fontello fontello-gratipay" url="http:\/\/wpa.qq.com\/msgrd?v=3&uin=535425690&site=qq&menu=yes"]点击QQ咨询购买（√推荐）[/button]

[button color="success" icon="glyphicon glyphicon-send" url="mailto:ihewro@163.com"]ihewro#163.com[/button]
```

#### 文章内插入音乐

**点击编辑器的插入音乐图标**可以在文章内可以插入音乐歌曲地址，支持云解析和本地MP3地址两种方式：

**时光机的音乐插入按钮也是同样的操作**

> **云解析歌曲**：暂时支持解析单曲，不支持歌单，支持以下媒体：

* 网易云音乐：http://music.163.com/#/song?id=40147556
* QQ音乐：https://y.qq.com/n/yqq/song/000jDQWP4JiB3y.html
* 虾米音乐：http://www.xiami.com/song/bf08DNT3035f
* 酷狗音乐：http://www.kugou.com/song/#hash=09E8DE70A24C97B92A29F6A19F3528A2
* 百度音乐：http://music.baidu.com/song/268275324

> **本地mp3地址播放**：

* 示例：直接在输入框中输入`.mp3`结尾的地址，并填写`歌曲名`和`歌手`的名称。


```html
[hplayer title="歌曲名" author="歌手" url="http:\/\/xxx.com\/xxx.mp3" size="large" /]
```

?> 文章页面插入播放器`size`默认为`large`时光机插入播放器`size`默认为`small`</br>你也可以手动改动这个标签的内容以选择不同的播放器样式:)

#### 文章内插入视频

**点击编辑器的插入音乐图标**可以插入视频，只支持本地的视频地址的播放

**时光机的视频插入按钮也是同样的操作**

直接在输入框中输入视频的地址即可，一般以`.mp4`结尾的资源地址。

示例：

```html
[vplayer url="http://xxx.com/xxx.mp4" pic="http://xxx.com/xxx.png"]
```

* `url`：视频地址
* `pic`：视频背景图片



#### 文章内调用其他文章

**点击编辑器的调用文章的按钮**可以调用其他文章并显示。

![](https://ws2.sinaimg.cn/large/006tNc79ly1g01rxlwb8aj30ze0l8q3z.jpg)

```markdown
[post cid="1" /]
[post cid="1" cover="http:\/\/localhost\/build\/usr\/themes\/handsome\/usr\/img\/sj\/6.jpg"/]

```

* `cid`：必填，是文章的唯一编号，在后台的编辑文章的地址可以看到，比如`http://localhost/build/admin/write-post.php?cid=23`,值为23
* `cover`：可选项，调用文章显示的封面，如果不填则默认显示随机缩略图。


#### 文章内调用外链网站

!> v5.0及其以上版本支持调用外链

![](https://ws2.sinaimg.cn/large/006tNc79ly1g01ry4640lj30vi0a2jrq.jpg)

```
[post url="https:\/\/www.ihewro.com" title="友人C" intro="一个个人博客" cover="http://www.ihewro.com/img/xxx.jpg" /]
```

* `title`：必填，外链的名称/标题
* `url`：必填，外链的地址（请填写绝对地址，就是浏览器地址栏什么样的就填什么样的）
* `intro`：（可选）外链网站的简介/介绍
* `cover`：（选填）外链网站的介绍图片地址

#### 文章内插入相册

!> v5.1 版本及其以上支持

![](https://ws2.sinaimg.cn/large/006tNc79ly1g01rx4vn36j30pe0dmdgm.jpg)
**使用方法：**

```
[album](插入图片，支持图片的HTML格式或者是markdown语法都可以，支持外链或者附件上传均可)[/album]
```

**举例：**
```
//方式1（markdown语法）
[album]
![图片描述1][1]
![图片描述2][2]
[/album]
  [1]: http://xxx.com/xxx1.jpg
  [2]: http://xxx.com/xxx2.jpg
  
//方式2（markdown语法）
[album]
![图片描述1](http://xxx.com/xxx1.jpg)
![图片描述2](http://xxx.com/xxx2.jpg)
[/album]

//方式3（HTML语法）
[album]
<img src="http://xxx.com/xxx1.jpg" alt="图片描述1" />
<img src="http://xxx.com/xxx2.jpg" alt="图片描述2" />
[/album]
```

**相关问题：[typecho1.1版本编辑器无法解析HTML代码](./common-problem?id=typecho11版本编辑器无法解析html代码)**

#### 文章中使用mathJax公式

* 需要在`后台外观设置——主题增强功能`中启用`公式（MathJax）`选项。

* 语法格式：

```markdown
//块级公式：
$$ 公式内容 $$
$$    x = \dfrac{-b \pm \sqrt{b^2 - 4ac}}{2a} $$

// 行内公式：
$ 行内公式内容 $ 
\\( 行内公式内容 \\)

$\Gamma(n) = (n-1)!\quad\forall n\in\mathbb N$

\\( x = \dfrac{-b \pm \sqrt{b^2 - 4ac}}{2a}  \\)
```

#### 文章内部分隐藏回复可见

在文章使用使用
```html
[hide][/hide]
```
标签包裹住你想要隐藏的内容，游客必须先回复后才能查看隐藏内容。

## 文章内部分内容登录可见

为什么增加这样的功能呢？因为有时候一篇文章并不想完全的加密，部分内容由于隐私问题需要加密。该部分内容仅登录用户（如果是个人博客就是仅博主）可见。

在文章中使用
```html
[login]需要加密的内容[/login]
```

#### 文章中插入短代码高亮文本

```markdown
[scode type="share"]这是灰色的短代码框，常用来引用资料什么的[/scode]
[scode type="yellow"]这是黄色的短代码框，常用来做提示，引起读者注意。[/scode]
[scode type="red"]这是红色的短代码框，用于严重警告什么的。[/scode]
[scode type="lblue"]这是浅蓝色的短代码框，用于显示一些信息。[/scode]
[scode type="green"]这是绿色的短代码框，显示一些推荐信息。[/scode]
```


![](https://ws2.sinaimg.cn/large/006tNc79ly1foutefje7wj30os0g0dgc.jpg)

#### 文章中插入收缩框

示例代码：
```
[collapse title="标题" status="false"]一些文字内容[/collapse]

[collapse title="标题"]一些文字内容[/collapse]
```

其中`status`为`false` 表示默认不显示文字内容，为`true`表示默认显示内容。

不写`status` 属性，默认是展开内容的。

#### 文章内插入图集

示例代码：
```
[alubm]
[普通的图片插入，支持markdown语法和html语法，混合也可以]
[/album]
```

#### 博客时间友好格式化

> **使用效果**

```html
几小时前
几天前
几月前
几年前
```
当时间不是整小时/天/月/年 时会显示默认的时间格式

> **开启方法**

后台选择`设置——评论——评论日期格式` 内填写`natural`。

**在这里同样可以修改博客的时间格式为你需要的时间格式，值为标准的php格式。**

如标准时间格式：`Y-n-j H:i:s` 



