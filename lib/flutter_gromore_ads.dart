import 'dart:io';
import 'flutter_gromore_ads_platform_interface.dart';
import 'event/ad_event_handler.dart';

export 'event/ad_event_handler.dart';
export 'view/ad_banner_widget.dart';

/// GroMore 广告插件
class FlutterGromoreAds {
  ///事件回调
  ///@params onData 事件回调
  static Future<void> onEventListener(
      OnAdEventListener onAdEventListener) async {
    FlutterGromoreAdsPlatform.instance.getEventStream().listen((data) {
      hanleAdEvent(data, onAdEventListener);
    });
  }

  /// 请求应用跟踪透明度授权(仅 iOS)
  static Future<bool> get requestIDFA async {
    if (Platform.isIOS) {
      return FlutterGromoreAdsPlatform.instance.requestIDFA();
    }
    return true;
  }

  /// 动态请求相关权限（仅 Android）
  static Future<bool> get requestPermissionIfNecessary async {
    if (Platform.isAndroid) {
      return FlutterGromoreAdsPlatform.instance.requestPermissionIfNecessary();
    }
    return true;
  }

  /// 初始化广告
  /// [appId] 应用ID
  /// [config] 配置文件名称
  /// [limitPersonalAds] 是否限制个性化广告，0：不限制 1：限制
  static Future<bool> initAd(String appId,
      {String? config, int limitPersonalAds = 0}) {
    return FlutterGromoreAdsPlatform.instance.initAd(
      appId,
      config: config,
      limitPersonalAds: limitPersonalAds,
    );
  }

  /// 展示开屏广告
  /// [posId] 广告位 id
  /// [logo] 如果传值则展示底部logo，不传不展示，则全屏展示
  /// [timeout] 加载超时时间
  static Future<bool> showSplashAd(String posId,
      {String? logo, double timeout = 3.5}) {
    return FlutterGromoreAdsPlatform.instance.showSplashAd(
      posId,
      logo: logo,
      timeout: timeout,
    );
  }

  /// 展示插屏广告
  /// [posId] 广告位 id
  static Future<bool> showInterstitialAd(String posId) {
    return FlutterGromoreAdsPlatform.instance.showInterstitialAd(posId);
  }
}
