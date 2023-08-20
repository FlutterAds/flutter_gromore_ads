<p align="center">
<a href="https://github.com/FlutterAds"><img src="https://raw.githubusercontent.com/FlutterAds/site/master/logo/flutterads_logo.png" alt="logo"/></a>
</p>
<h3 align="center">一款优质的 Flutter 广告插件（GroMore、穿山甲）</h3>

<p align="center">
<a href="https://pub.dev/packages/flutter_gromore_ads"><img src=https://img.shields.io/badge/version-v1.3.0-success></a>
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

- ✅ 开屏广告
- ✅ 插屏广告
- ✅ 横幅广告
- 🤴信息流[Pro 版本](example/README.md)
- 🤴激励视频[Pro 版本](example/README.md)

## 入门使用

### 引入依赖

``` Dart
dependencies:
  flutter_gromore_ads: ^1.3.3
```

> 下面 `导入 SDK` 是必须的配置，千万别省略了，仔细看文档来配置。

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
FlutterGromoreAds.showSplashAd(
  posId,
  timeout: 3.5,
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
FlutterGromoreAds.showInterstitialFullAd(
    posId,
    muted: false,
);
```

### 全屏视频

``` Dart
/// [posId] 广告位 id
/// [orientation] 期望视频的播放方向，1：VERTICAL 2：HORIZONTAL
FlutterGromoreAds.showFullVideoAd(
    posId,
    orientation: 1,
);
```


### 设置广告事件监听

``` Dart
FlutterGromoreAds.onEventListener((event) {
    _adEvent = 'adId:${event.adId} action:${event.action}';
    if (event is AdErrorEvent) {
    // 错误事件
    _adEvent += ' errCode:${event.errCode} errMsg:${event.errMsg}';
    }
    debugPrint('onEventListener:$_adEvent');
});
```
### 事件列表
|事件|说明|
|-|-|
|onAdLoaded|广告加载成功|
|onAdPresent|广告填充|
|onAdExposure|广告曝光|
|onAdClosed|广告关闭（开屏计时结束或者用户点击关闭）|
|onAdClicked|广告点击|
|onAdSkip|广告跳过|
|onAdComplete|广告播放或计时完毕|
|onAdError|广告错误|
|onAdReward|获得广告激励|

### 导入 SDK 

#### Android

- 引入依赖

|参考示例|官方文档|
|--|--|
|[build.gradle](https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/example/android/app/build.gradle)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=75&docId=604de8b510af03004cbcbf69&osType=android#_1-1sdk包的导入)|

打开 `android/app/build.gradle` 添加依赖，需要哪个添加哪个，`Adapter` 和 `SDK` 要成对添加

``` gradle
dependencies {
    //GroMore_sdk adapter
    implementation "com.gromore.cn:gdt-adapter:4.482.1352.1"  //gdt adapter
    implementation 'com.qq.e.union:union:4.482.1352'// 广点通广告 SDK
    implementation "com.gromore.cn:pangle-adapter:4.7.1.2.1" //穿山甲 adapter
    implementation 'com.pangle.cn:ads-sdk-pro:4.7.1.2'//穿山甲广告 SDK
    // 其他参考官方文档 引入即可
}
```

> 这里通过远程仓库导入你也可以按照官方示例中的 `aar` 导入依赖

- 添加配置文件

> 本插件内已经将可以内置的配置都内置了，只需要添加特有的配置接口，官方文档仅作为参考

|参考示例|官方文档|
|--|--|
|[AndroidManifest.xml](https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/example/android/app/src/main/AndroidManifest.xml)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=75&docId=604de8b510af03004cbcbf69&osType=android#_1-2-2-androidmanifest-xml-第三方adn相关配置)|

打开 `android/app/src/main/AndroidManifest.xml` 添加对应的配置文件，与上面的 SDK 对应

``` xml
<!-- GDT start================== -->
<!-- targetSDKVersion >= 24时才需要添加这个provider。provider的authorities属性的值为${applicationId}.fileprovider，请开发者根据自己的${applicationId}来设置这个值，例如本例中applicationId为"com.qq.e.union.demo"。 -->
<provider
    android:name="com.qq.e.comm.GDTFileProvider"
    android:authorities="${applicationId}.gdt.fileprovider"
    android:exported="false"
    android:grantUriPermissions="true">
    <meta-data
        android:name="android.support.FILE_PROVIDER_PATHS"
        android:resource="@xml/gdt_file_path" />
</provider>

<activity
    android:name="com.qq.e.ads.PortraitADActivity"
    android:configChanges="keyboard|keyboardHidden|orientation|screenSize"
    android:screenOrientation="portrait" />
<activity
    android:name="com.qq.e.ads.LandscapeADActivity"
    android:configChanges="keyboard|keyboardHidden|orientation|screenSize"
    android:screenOrientation="landscape"
    tools:replace="android:screenOrientation" />

<!-- 声明SDK所需要的组件 -->
<service
    android:name="com.qq.e.comm.DownloadService"
    android:exported="false" />
<!-- 请开发者注意字母的大小写，ADActivity，而不是AdActivity -->

<activity
    android:name="com.qq.e.ads.ADActivity"
    android:configChanges="keyboard|keyboardHidden|orientation|screenSize" />
<!-- GDT end================== -->


<!-- Pangle start================== -->

<provider
    android:name="com.bytedance.sdk.openadsdk.TTFileProvider"
    android:authorities="${applicationId}.TTFileProvider"
    android:exported="false"
    android:grantUriPermissions="true">
    <meta-data
        android:name="android.support.FILE_PROVIDER_PATHS"
        android:resource="@xml/pangle_file_paths" />
</provider>

<provider
    android:name="com.bytedance.sdk.openadsdk.multipro.TTMultiProvider"
    android:authorities="${applicationId}.TTMultiProvider"
    android:exported="false" />

<!-- Pangle end================== -->

<!-- 其他广告配置参考官方文档添加即可================== -->	
```

- 动态请求权限（仅 Android）

> 必要权限已添加，其他权限`参考示例`和`官方文档`酌情添加即可。

``` Dart
bool result = await FlutterGromoreAds.requestPermissionIfNecessary;
```

#### iOS

- 引入依赖

|参考示例|官方文档|
|--|--|
|[example](https://github.com/FlutterAds/flutter_gromore_ads/blob/master/example/ios)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=79&docId=618372e19e41cf0042bc0016&osType=ios)|

1、将下载的 `SDK` 中的 `Ads-Mediation-CN` 及其其他所需要的 `Adapter` 复制到 `ios/Frameworks` 下，参考 [ios/Frameworks](https://github.com/FlutterAds/flutter_gromore_ads/tree/master/example/ios/Frameworks)

<img width="480" alt="image" src="https://user-images.githubusercontent.com/8764899/147381759-02ed1659-dc0a-4f18-b1dd-50c788c764af.png">

2、修改 `ios/Podfile` 引入 `SDK`，参考 [Podfile](https://github.com/FlutterAds/flutter_gromore_ads/blob/master/example/ios/Podfile)

<img width="480" alt="image" src="https://user-images.githubusercontent.com/8764899/147381808-165f56d3-256e-4146-b57b-e4372d630bd4.png">


- 添加配置文件

打开 `ios/Runner/Info.plist` 添加如下配置，参考 [Info.plist](https://github.com/FlutterAds/flutter_gromore_ads/blob/56f8ac69747b7c123024511755d79d667cbc5ede/example/ios/Runner/Info.plist#L25-L31)

``` xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
<key>NSUserTrackingUsageDescription</key>
<string>为了向您提供更优质、安全的个性化服务及内容，需要您允许使用相关权限</string>
```

- 请求应用跟踪透明度授权（仅 iOS）
此步骤必须要做，不然上架审核时候会被拒绝
``` Dart
bool result = await FlutterGromoreAds.requestIDFA;
```


## 分支说明
|分支|说明|
|-|-|
|develop|开发分支，接受 PR|
|master|稳定分支|

## 更新日志
[查看 Releases 版本日志](https://github.com/FlutterAds/flutter_gromore_ads/releases)

## 遇到问题
如果你遇到问题请提 [Issues](https://github.com/FlutterAds/flutter_gromore_ads/issues) 给我（提问前建议先搜索尝试，没有再提问）

## 支持开源

- 开源不易，需要花费大量休息时间加班熬夜来维护，你可以通过下方二维码赞赏支持我。
- 用爱发电，给本项目点个免费的 [Star](https://github.com/FlutterAds/flutter_gromore_ads) ⭐️ 也是非常好的支持。

<a href="https://raw.githubusercontent.com/yy1300326388/yy1300326388/main/images/pay_qr_code/pay_qr_code.png">
    <img width="300" alt="coffee" src="https://raw.githubusercontent.com/yy1300326388/yy1300326388/main/images/pay_qr_code/pay_qr_code.png">
</a>

### 支持名单

|支持者|金额|备注|
|--|--|--|
|歌**|88|大佬 666|
|Co**|66|大佬 888|
|At**|200|大佬给力，帮我节省了很多时间|

## FlutterAds 广告插件系列
|插件|描述|
|-|-|
|[flutter_qq_ads](https://github.com/FlutterAds/flutter_qq_ads)|腾讯广告、广点通、优量汇 Flutter 广告插件|
|[flutter_pangle_ads](https://github.com/FlutterAds/flutter_pangle_ads)|字节跳动、穿山甲 Flutter 广告插件|
|[flutter_gromore_ads](https://github.com/FlutterAds/flutter_gromore_ads)|字节跳动、穿山甲、GroMore 聚合 Flutter 广告插件|

