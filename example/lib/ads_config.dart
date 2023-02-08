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
    if (Platform.isIOS) {
      return '5209496';
    }
    return '5216573';
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
    if (Platform.isIOS) {
      return '887383142';
    }
    return '887382967';
  }

  /// 获取插屏广告位id
  static String get interstitialId {
    if (Platform.isIOS) {
      return '945494755';
    }
    return '945493679';
  }

  /// 获取插屏全屏广告位id
  static String get interstitialFullId {
    if (Platform.isIOS) {
      return '946961656';
    }
    return '946276599';
  }

  /// 获取全屏视频广告位id(纵向)
  static String get fullVideoVerticalId {
    if (Platform.isIOS) {
      return '900546831';
    }
    return '945493676';
  }

  /// 获取全屏视频广告位id(横向)
  static String get fullVideoHorizontalId {
    if (Platform.isIOS) {
      return '945494751';
    }
    return '945493675';
  }

  /// 获取激励视频广告位id
  static String get rewardVideoId => '946584890';

  /// 获取 Banner 广告位id
  static String get bannerId => Platform.isIOS ? '102253640' : '102252466';

  /// 获取 Feed 信息流广告位 id
  static String get feedId => Platform.isIOS ? '102255258' : '102254613';
}
