import 'dart:async';
import 'dart:io';

import 'package:flutter/services.dart';

import 'event/ad_event_handler.dart';

export 'event/ad_event_handler.dart';
export 'view/ad_banner_widget.dart';
export 'view/ad_feed_widget.dart';

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
  static Future<bool> initAd(String appId, {String? config}) async {
    final bool result = await _methodChannel.invokeMethod(
      'initAd',
      {
        'appId': appId,
        'config': config,
      },
    );
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
  /// [width] 宽度
  /// [height] 高度
  static Future<bool> showInterstitialAd(
    String posId, {
    int width = 300,
    int height = 300,
  }) async {
    final bool result = await _methodChannel.invokeMethod(
      'showInterstitialAd',
      {
        'posId': posId,
        'width': width,
        'height': height,
      },
    );
    return result;
  }

  /// 展示插屏全屏广告
  /// [posId] 广告位 id
  /// [muted] 是否静音播放视频
  static Future<bool> showInterstitialFullAd(String posId,
      {bool muted = false}) async {
    final bool result = await _methodChannel.invokeMethod(
      'showInterstitialFullAd',
      {'posId': posId, 'muted': muted},
    );
    return result;
  }

  /// 展示全屏视频广告
  /// [posId] 广告位 id
  /// [orientation] 期望视频的播放方向，1：VERTICAL 2：HORIZONTAL
  static Future<bool> showFullVideoAd(
    String posId, {
    int orientation = 1,
  }) async {
    final bool result = await _methodChannel.invokeMethod(
      'showFullVideoAd',
      {
        'posId': posId,
        'orientation': orientation,
      },
    );
    return result;
  }

  /// 加载信息流广告列表
  /// [posId] 广告位 id
  /// [width] 宽度
  /// [height] 高度
  /// [count] 获取广告数量，建议 1~3 个
  static Future<List<int>> loadFeedAd(String posId,
      {int width = 375, int height = 0, int count = 1}) async {
    final List<dynamic> result = await _methodChannel.invokeMethod(
      'loadFeedAd',
      {
        'posId': posId,
        'width': width,
        'height': height,
        'count': count,
      },
    );
    return List<int>.from(result);
  }

  /// 清除信息流广告列表
  /// [list] 信息流广告 id 列表
  static Future<bool> clearFeedAd(List<int> list) async {
    final bool result = await _methodChannel.invokeMethod(
      'clearFeedAd',
      {
        'list': list,
      },
    );
    return result;
  }
}
