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

> 下面大 `导入 SDK` 是必须配置的，千万别省略了，仔细看文档来配置。

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


### 导入 SDK 

#### Android

- 引入依赖

|参考示例|官方文档|
|--|--|
|[example](https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/example/android/app/build.gradle)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=75&docId=604de8b510af03004cbcbf69&osType=android#_1-1sdk包的导入)|

打开 `android/app/build.gradle` 添加依赖，需要哪个添加哪个，`Adapter` 和 `SDK` 要成对添加

``` gradle
dependencies {
    //GroMore_sdk adapter
    implementation "com.gromore.cn:gdt-adapter:4.422.1292.0"  //gdt adapter
    implementation 'com.qq.e.union:union:4.422.1292'// 广点通广告 SDK
    implementation "com.gromore.cn:pangle-adapter:4.0.1.9.1" //穿山甲 adapter
    implementation 'com.pangle.cn:ads-sdk-pro:4.0.1.9'//穿山甲广告 SDK
}
```

- 添加配置文件

> 本插件内已经将可以内置的配置都内置了，只需要添加特有的配置接口，官方文档仅作为参考

|参考示例|官方文档|
|--|--|
|[example](https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/example/android/app/src/main/AndroidManifest.xml)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=75&docId=604de8b510af03004cbcbf69&osType=android#_1-2-2-androidmanifest-xml-第三方adn相关配置)|

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
```

> 必要权限已添加，其他权限`参考示例`和`官方文档`酌情添加即可。



#### iOS

- 引入依赖

|参考示例|官方文档|
|--|--|
|[example](https://github.com/FlutterAds/flutter_gromore_ads/blob/develop/example/ios/Podfile)|[点击这里](https://www.csjplatform.com/union/media/union/download/detail?id=79&docId=618372e19e41cf0042bc0016&osType=ios)|

1、将下载的 `SDK` 中的 `Ads-Mediation-CN` 及其其他所需要的 `Adapter` 复制到 `ios/Frameworks` 下，参考 [ios/Frameworks](https://github.com/FlutterAds/flutter_gromore_ads/tree/develop/example/ios/Frameworks)

> ⚠️⚠️⚠️ 下面这一步非常重要

2、将 `ios/Frameworks/Ads-Mediation-CN/Ads-Mediation-CN.podspec` 中的 `#spec.ios.vendored_frameworks = 'Ads-Mediation-CN/ABUAdSDK.framework'` 注释掉，参考 [Ads-Mediation-CN.podspec 25~26 行](https://github.com/FlutterAds/flutter_gromore_ads/blob/56f8ac69747b7c123024511755d79d667cbc5ede/example/ios/Frameworks/Ads-Mediation-CN/Ads-Mediation-CN.podspec#L25-L26)

3、修改 `ios/Podfile` 引入 `SDK`，参考 [Podfile](https://github.com/FlutterAds/flutter_gromore_ads/blob/56f8ac69747b7c123024511755d79d667cbc5ede/example/ios/Podfile#L32-L37)


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




