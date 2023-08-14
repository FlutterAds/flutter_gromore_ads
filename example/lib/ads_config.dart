import 'dart:io';

/// 广告配置信息
class AdsConfig {
  /// 获取 Logo 资源名称
  static String get logo {
    if (Platform.isAndroid) {
      return 'flutterads_logo';
    } else {
      return 'LaunchImage';
    }
  }

  /// 获取 Logo 资源名称 2
  static String get logo2 {
    if (Platform.isAndroid) {
      return 'flutterads_logo2';
    } else {
      return 'LaunchImage2';
    }
  }

  /// 获取 App id
  static String get appId {
    return '5324024';
  }

  /// 获取 App Config
  static String get config {
    if (Platform.isIOS) {
      return 'ios_config_5209496';
    }
    return 'android_config_5216573.json';
  }

  /// 获取开屏广告位id
  static String get splashId {
    return '102420790';
  }

  /// 获取插屏广告位id
  static String get interstitialId {
    return '102421471';
  }

  /// 获取激励视频广告位id
  static String get rewardVideoId => '102421199';

  /// 获取 Banner 广告位id
  static String get bannerId => '102424305';

  /// 获取 Feed 信息流广告位 id
  static String get feedId => '102420797';

  /// 获取 Draw 信息流广告位 id
  static String get drawFeedId => '102420797';
}
