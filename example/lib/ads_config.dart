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

  /// 获取开屏广告位id
  static String get splashId => '102420790';

  /// 获取插屏广告位id 竖屏
  static String get interstitialId => '102421471';

  /// 获取 Banner 广告位id
  static String get bannerId => '102424305';
}
