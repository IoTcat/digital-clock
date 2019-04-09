#### 安装完主题后，页面中间部分空白/安装后首页报错

* 依次检查主题文件夹名称是否为`handsome`
* **是否已经安装并且启用主题必要的插件links**
* **php版本5.4+，必须安装mbstring 扩展**，否则无法使用（正确检查方式是在你的服务器新建一个`test.php`，然后复制粘贴该代码`<?php phpinfo(); ?>`，最后在浏览器访问该文件可以查看服务器的php信息）
* 初次使用主题必须保证博客有一篇文章，如果一篇文章都没有的话会导致向数据库中添加view（浏览次数字段）失败
* PostgreSql 数据库安装links插件时，需要手动新建`typechos_links`表。（会在下一个版本修复）

#### 点击首页头像，显示404页面

* 需要新建“时光机”独立页面，具体方法见[独立页面](/page?id=时光机)

#### 主题内的博客头像怎么设置

* 主题头像需要设置两处：
    * 主题外观设置——初级设置——头像设置：现在在首页的左侧边栏中
    * gravatar（全球通用头像），打开后台——控制台——个人设置，点击左侧的头像，去该网站使用**你在个人设置里填写的电子邮箱地址**注册账号，并上传头像，typecho的头像会自动更新：会显示在`时光机`、`评论`、`右上角顶部`的头像处。

#### links插件无法启用，显示500错误

* 更新主题包中最新版本的links插件`1.1.2`
* 一般是由于你的`usr/plugin`没有足够的权限导致的。

如果是Linux服务器尝试，在typecho的usr目录下输入此命令：

```bash
sudo chmod -R 777 plugin
```

如果仍有问题，请联系我

#### 友链设置后前台不输出内容（使用无效）

* links插件需要填写`链接分类`来判断输出的位置，请详细阅读[友链设置文档](./plugin)

#### 无法评论，提示输入内容不符合规则

请依次检查以下内容：

* cdn缓存静态缓存了HTML页面，导致评论功能失败（cdn缓存建议只缓存静态资源文件，如css js image）
* 使用了服务器缓存功能
* 使用了数据库缓存插件
* 使用了页面代码压缩的插件
* 当你作为游客身份评论时，你的邮箱地址不能和后台已有用户的邮箱地址重复

如仍有问题，请联系我。

#### typecho1.1版本编辑器无法解析HTML代码


* typecho 1.0正式版本原生markdown解析器非常弱，可以解析HTML，但是无法解析表格。可以配合以下插件使用[typecho-plugin-Parsedown](https://github.com/kokororin/typecho-plugin-Parsedown) 或者 [typecho-markdown](https://github.com/mrgeneralgoo/typecho-markdown)(包含更多markdown语法)

!> 插件安装后请注意文件夹命名要求。安装插件后，无需任何设置，自动替换前台文章解析，支持解析表格和HTML代码。

* typecho 1.1正式版本原生markdown解析器不支持解析HTML代码，必须使用特权模式才可以解析HTML代码，示例如下：

```html
!!!
// 你的HTML代码
!!!
```
* 使用typecho开发版本（比1.1正式版本更高的版本）[下载开发版本](http://typecho.org/download)



#### 全局音乐播放器一直在加载无法播放

* PHP必须满足 PHP>=5.4
* 某些国外服务器无法云解析，请使用手动添加歌曲功能
* 服务器需要安装curl 扩展，请勿禁用`curl_exec`函数，并且curl扩展需要支持https
* 网易云会时常封禁cookie，导致解析失败，请打开主题目录下面的`libs/Get.php` 根据注释要求修改`$netease_cookie`变量。（一般有问题的话，我会在群内通知的）或者换用QQ音乐或者其他平台
* QQ音乐歌单请勿设置为私密歌单，否则无法解析

如果仍有问题，请联系我。

#### 评论区不能斗图不能显示图片 | 说说不能显示图片/音乐播放器/视频播放器

* 后台 `设置——评论——允许使用的HTML标签和属性` 里面添加html标签
```html
<img src="">
<audio class="" src="" preload>
<video src=""></video>
```

#### 评论区无法使用markdown语法

* 后台 `设置——评论——在评论中使用Markdown语法(选中)`
后台 `设置——评论——允许使用的HTML标签和属性` 里面添加markdown语法对应的html标签
```html
<blockquote><pre><code><strong><em><h5><h6><a href title><table><thead><tr><th><tbody><td>
```

#### 使用EditorMD前台文章首次不加载，刷新一次才能加载

* 主题pjax与EditorMD的前台解析js有冲突，在该插件的设置界面，将`接管前台Markdown解析并启用ToC、TeX科学公式、流程图 Flowchart、时序图 Sequence Diagram 等扩展`
选择否即可。


#### 启用插件总是显示500错误

有些插件必须修改插件的文件夹为指定的名称才能正常使用，一般插件的说明都会有提到修改插件的文件夹名称，请留意。

#### Aplayer 无法正常使用

主题内置支持云解析的文章播放器，详见[文章内插入音乐](https://handsome.ihewro.com/#/functions?id=%E6%96%87%E7%AB%A0%E5%86%85%E6%8F%92%E5%85%A5%E9%9F%B3%E4%B9%90)

如果你仍然喜欢Aplayer插件，你可以使用`MoePlayer` 作者开发的[APlayer-Typecho](https://github.com/MoePlayer/APlayer-Typecho)版本的插件，

然后在`主题的外观设置`——`pjax`——`回调函数`中填写即可：

```JavaScript
if (typeof aplayers !== 'undefined'){
    for (var i = 0; i < aplayers.length; i++) {
        try {aplayers[i].destroy()} catch(e){}
    }
}
loadMeting();
```

#### 文章首页分页数目怎么修改？/我想修改每页显示6篇文章？

在typecho的`后台——设置——阅读——每页文章数目`，修改该值即可。如果你使用头图随机缩略图的话，请保证你的主题文件夹下的`usr/sj/`随机图片数目大于每页文章数目。

#### 主题出现了问题，样式错误？无法点击？

* 配置出现了问题，切换到别的主题，然后再切换回来，这一过程会清空之前的所有配置，请提前备份。
* 修改了源代码导致了问题。删除以前的旧主题文件，然后上传新的主题文件夹
* qq上给我留言


#### 搜索框搜索提示有内容，但是最终的页面没有显示结果？

* typecho bug，详见[issue#705](https://github.com/typecho/typecho/issues/705)

* 打开 typecho 目录下面的 `var/Widget/Archive.php`文件

* 搜索`$keywords = $this->request->filter('url', 'search')->keywords;`
替换成`$keywords = $this->request->keywords;`

#### Dplayer-Typecho不能显示弹幕

* [修复官方Dplayer-Typecho插件不能连接弹幕API后端的方法](https://www.moerats.com/archives/856/#comments)


