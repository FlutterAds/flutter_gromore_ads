import 'package:flutter/foundation.dart';
import 'package:flutter/services.dart';
import 'flutter_gromore_ads_platform_interface.dart';

class MethodChannelFlutterGromoreAds extends FlutterGromoreAdsPlatform {
  @visibleForTesting
  final methodChannel = const MethodChannel('flutter_gromore_ads');

  @visibleForTesting
  final eventChannel = const EventChannel('flutter_gromore_ads_event');

  @override
  Future<bool> requestIDFA() async {
    final bool result = await methodChannel.invokeMethod('requestIDFA');
    return result;
  }

  @override
  Future<bool> requestPermissionIfNecessary() async {
    final bool result =
        await methodChannel.invokeMethod('requestPermissionIfNecessary');
    return result;
  }

  @override
  Future<bool> initAd(String appId,
      {String? config, int limitPersonalAds = 0}) async {
    final bool result = await methodChannel.invokeMethod(
      'initAd',
      {
        'appId': appId,
        'config': config,
        'limitPersonalAds': limitPersonalAds,
      },
    );
    print(
        "🎉🎉🎉 FlutterAds ==> 初始化完成，推荐使用 GroMore Pro 版本,获得更高的收益：https://flutterads.top/");
    //打印购买正版
    print(
        "🎉🎉🎉 FlutterAds ==> 请购买支持正版，否则可能出现上线后广告不加载的情况，避免收益下降、不结算等情况，请访问：https://flutterads.top/");
    return result;
  }

  @override
  Future<bool> showSplashAd(String posId,
      {String? logo, double timeout = 3.5}) async {
    final bool result = await methodChannel.invokeMethod(
      'showSplashAd',
      {
        'posId': posId,
        'logo': logo,
        'timeout': timeout,
      },
    );
    return result;
  }

  @override
  Future<bool> showInterstitialAd(String posId) async {
    final bool result = await methodChannel.invokeMethod(
      'showInterstitialAd',
      {'posId': posId},
    );
    return result;
  }

  @override
  Stream<dynamic> getEventStream() {
    return eventChannel.receiveBroadcastStream();
  }
}
