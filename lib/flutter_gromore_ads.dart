import 'dart:async';
import 'dart:io';

import 'package:flutter/services.dart';

import 'event/ad_event_handler.dart';

export 'event/ad_event_handler.dart';
export 'view/ad_banner_widget.dart';

/// GroMore 广告插件
class FlutterGromoreAds {
  // 方法通道
  static const MethodChannel _methodChannel =
      MethodChannel('flutter_gromore_ads');
  // 事件通道
  static const EventChannel _eventChannel =
      EventChannel('flutter_gromore_ads_event');

  ///事件回调
  ///@params onData 事件回调
  static Future<void> onEventListener(
      OnAdEventListener onAdEventListener) async {
    _eventChannel.receiveBroadcastStream().listen((data) {
      hanleAdEvent(data, onAdEventListener);
    });
  }

  /// 请求应用跟踪透明度授权(仅 iOS)
  static Future<bool> get requestIDFA async {
    if (Platform.isIOS) {
      final bool result = await _methodChannel.invokeMethod('requestIDFA');
      return result;
    }
    return true;
  }

  /// 动态请求相关权限（仅 Android）
  static Future<bool> get requestPermissionIfNecessary async {
    if (Platform.isAndroid) {
      final bool result =
          await _methodChannel.invokeMethod('requestPermissionIfNecessary');
      return result;
    }
    return true;
  }

  /// 初始化广告
  /// [appId] 应用ID
  /// [config] 配置文件名称
  /// [limitPersonalAds] 是否限制个性化广告，0：不限制 1：限制
  static Future<bool> initAd(String appId,
      {String? config, int limitPersonalAds = 0}) async {
    final bool result = await _methodChannel.invokeMethod(
      'initAd',
      {
        'appId': appId,
        'config': config,
        'limitPersonalAds': limitPersonalAds,
      },
    );
    print(
        "🎉🎉🎉 FlutterAds ==> 初始化完成，推荐使用 GroMore Pro 版本，获得更高的收益：https://flutterads.top/");
    return result;
  }

  /// 展示开屏广告
  /// [posId] 广告位 id
  /// [logo] 如果传值则展示底部logo，不传不展示，则全屏展示
  /// [timeout] 加载超时时间
  static Future<bool> showSplashAd(String posId,
      {String? logo, double timeout = 3.5}) async {
    final bool result = await _methodChannel.invokeMethod(
      'showSplashAd',
      {
        'posId': posId,
        'logo': logo,
        'timeout': timeout,
      },
    );
    return result;
  }

  /// 展示插屏广告
  /// [posId] 广告位 id
  static Future<bool> showInterstitialAd(String posId) async {
    final bool result = await _methodChannel.invokeMethod(
      'showInterstitialAd',
      {'posId': posId},
    );
    return result;
  }
}
