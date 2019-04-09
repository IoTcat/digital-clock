主题内置了大量的网页图标 (非图片格式)，方便在 [自定义栏目](/customize)中使用。

## 可用图标

!> handsome v4.3.1 由原来的`fa fa-` 修改为`fontello fontello-`，是为了避免与fontawesome库冲突，你可以自行引入该图标库，以便使用更多图标，但是会带来一定的加载体积。[引入更多图标](https://handsome.ihewro.com/#/functions?id=%E6%B7%BB%E5%8A%A0%E8%87%AA%E5%AE%9A%E4%B9%89%E5%9B%BE%E6%A0%87)

**1. 主题内置的iconfont图标：**

![](https://ws4.sinaimg.cn/large/006tNc79ly1ftr34y793vj31gc0vc75i.jpg)


**2. 主题内置的fontello图标：** 

![](https://ws2.sinaimg.cn/large/006tNc79ly1ftr336pqdnj31kw0jlaca.jpg)

**3. bootcss自带的Glyphicons字体图标：** 详细见[Glyphicons 字体图标](http://v3.bootcss.com/components/#glyphicons)

?> 第一项和第二项的图标很少，如果找不到相应图标，建议在第三项的图标库中寻找 

## 使用方法

举个例子：

```html

<!--首页名称左侧的图标设置项，直接填写class的内容即可，如：-->

<!--iconfont图标-->
iconfont icon-xxx

<!--Glyphicons图标-->
glyphicon glyphicon-eur

<!--fontello图标-->
fontello fontello-xxx


<!--下面三种是一般的HTML用法，一般是使用不到的-->

<!--iconfont图标-->
<i class="iconfont icon-xxx"></i>

<!--Glyphicons图标-->
<i class="glyphicon glyphicon-eur"></i>

<!--fontello图标-->
<i class="fontello fontello-xxx"></i>
```

使用用途：

* 直接修改主题内的图标，主题的所有图标都是使用的是网页图标，你可以更换图标的类名来更换图标。
  （不推荐，因为更新后会覆盖修改内容）

* 在 `自定义左侧边栏栏目` 和 `自定义顶部导航按钮` 和 `首页名称左侧的图标设置项` 中使用。

具体见：[自定义栏目](/customize)


