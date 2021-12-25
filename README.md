<p align="center">
<a href="https://github.com/FlutterAds"><img src="https://raw.githubusercontent.com/FlutterAds/site/master/logo/flutterads_logo.png" alt="logo"/></a>
</p>
<h3 align="center">一款优质的 Flutter 广告插件（Gromore、穿山甲）</h3>

<p align="center">
<a href="https://pub.dev/packages/flutter_gromore_ads"><img src=https://img.shields.io/badge/version-v0.0.1-success></a>
<a href="https://pub.dev/packages/flutter_gromore_ads"><img src=https://img.shields.io/badge/null_safety-v0.0.1-success></a>
<a href="https://github.com/FlutterAds/flutter_gromore_ads"><img src=https://img.shields.io/badge/platform-iOS%20%7C%20Android-brightgreen></a>
<a href="https://github.com/FlutterAds/flutter_gromore_ads/actions/workflows/flutter.yml"><img src="https://github.com/FlutterAds/flutter_gromore_ads/actions/workflows/flutter.yml/badge.svg?branch=develop"></a>
<a href="https://github.com/FlutterAds/flutter_gromore_ads"><img src=https://img.shields.io/github/stars/FlutterAds/flutter_gromore_ads?color=brightgreen></a>
<a href="https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/LICENSE"><img src=https://img.shields.io/badge/license-MIT-brightgreen></a>
</p>
<p align="center">
<a href="https://www.csjplatform.com/gromore"><img src="https://raw.githubusercontent.com/FlutterAds/site/master/images/gromore/gromore_introduce.jpeg" alt="gromore"/></a>
</p>

## 插件特点
- 🔨 接入简单快速（封装原生端配置，仅需引入即可开始）
- 📡 事件统一返回（将原生端各种重要回调事件统一返回，方便业务处理和埋点统计等需求）
- 🎁 注重优化体验（无闪烁 Logo 开屏、iOS 开屏防止事件穿透、权限申请、隐私跟踪申请等）
- 🏆 极客代码封装（原生端代码不凑合，两端统一基础框架、广告事件封装抽象、易扩展新广告形式、方便开发个性化需求）

## 支持功能
> 开发中敬请期待，可以点 Star 支持我加快开发
> 当前正在进行文档的整理和最后的测试，准备发布 1.0 版本啦 🎉

- ✅ 开屏广告
- ✅ 插屏广告
- ✅ 全屏视频
- 🔲 激励视频
- 🔲 Banner
- 🔲 信息流

## 入门使用

### 引入依赖

``` Dart
dependencies:
  flutter_gromore_ads: ^1.0.0
```

### 初始化广告

``` Dart
// 导包
import 'package:flutter_gromore_ads/flutter_gromore_ads.dart';
/// [appId] 应用ID
FlutterGromoreAds.initAd(appId);
```

### 开屏广告

- 全屏

``` Dart
/// [posId] 广告位 id
/// [logo] 如果传值则展示底部logo，不传不展示，则全屏展示
/// [timeout] 加载超时时间
/// [buttonType] 开屏广告的点击区域，1：全都可以点击 2：仅有下载 Bar 区域可以点击
FlutterGromoreAds.showSplashAd(
  posId,
  timeout: 3.5,
  buttonType: 2,
);
```


- 半屏

``` Dart
/// [posId] 广告位 id
/// [logo] 如果传值则展示底部logo，不传不展示，则全屏展示
FlutterGromoreAds.showSplashAd(
  posId,
  logo: 'flutterads_logo',
);
```

> [Logo 设置的最佳实践](https://github.com/FlutterAds/flutter_qq_ads/blob/develop/doc/SETTING_LOGO.md)

### 插屏广告

- 半插屏

``` Dart
/// [posId] 广告位 id
/// [width] 宽度
/// [height] 高度
FlutterGromoreAds.showInterstitialAd(
    posId,
    width: 300,
    height: 300,
);
```

- 全插屏

``` Dart
/// [posId] 广告位 id
/// [muted] 是否静音播放视频
FlutterGromoreAds.showInterstitialFullAd(posId,muted: false);
```

### 全屏视频

``` Dart
/// [posId] 广告位 id
/// [orientation] 期望视频的播放方向，1：VERTICAL 2：HORIZONTAL
FlutterPangleAds.showFullVideoAd(posId,orientation: 1,);
```



